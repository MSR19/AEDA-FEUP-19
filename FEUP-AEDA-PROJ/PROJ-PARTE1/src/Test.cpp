#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <sstream>

#include "Faculdade.h"

using namespace std;

template <class T>
T* find_T_name(string name, vector<T*> v)
{
	for (unsigned int i = 0; i < v.size(); i++)
	{
		if (v[i]->getNome() == name) return v[i];
	}
	return 0;
}

template <class T>
T* find_D_name(string name, vector<T*> v)
{
	for (unsigned int i = 0; i < v.size(); i++)
	{
		if (v[i]->getNomePortugues() == name) return v[i];
	}
	return 0;
}


void importFac(ifstream *f, istringstream &ss, vector<string> &v)
{
	string dep, line;
	std::getline(*f, line); //proxima linha
	istringstream ss1(line); //ss com o conteudo de line
	while (!ss1.eof()) {
		dep = "";
		ss1 >> dep; //dep nome
		if (dep.empty()) continue;
		v.push_back(dep); //para o vetor
	}
}

Departamento* importDep(ifstream*f, istringstream &ss, Pessoal *p, vector<string> &v)
{
	string name, address, line;
	int code, phoneNum;
	ss >> name >> code >> address >> phoneNum; //variaveis de dep
	Departamento* dep = new Departamento(p, name, code, address, phoneNum); //constru�ao

	std::getline(*f, line); //proxima linha
	istringstream ss1(line); //line para ss1 
	ss1 >> name; //nome diretor
	v.push_back(name); //nome diretor na primeira posi�ao do vetor
	getline(*f, line); //nova linha
	istringstream ss2(line); //line para ss
	while (!ss2.eof())
	{
		name = "";
		ss2 >> name; //novo nome
		if (name.empty()) continue;
		v.push_back(name); //para o vetor
	}
	return dep;
}

Curso* importCur(ifstream*f, istringstream &ss, Pessoal* p, vector<string> &v)
{
	string name, type, line;
	int code;
	ss >> name >> code >> type; //variaveis de curso
	Curso* c = new Curso(p, name, code, type); //contru�ao

	std::getline(*f, line);//proxima linha
	istringstream ss1(line); //line para ss1
	ss1 >> name; //nome diretor
	v.push_back(name); //nome diretor para a primeira posi�ao do vetor
	std::getline(*f, line); //proxima linha
	istringstream ss2(line); //line para ss2 (nomes das disciplinas)
	while (!ss2.eof())
	{
		name = "";
		ss2 >> name; //novo nome
		if (name.empty() || name[0] == 32) continue;
		v.push_back(name); //para o vetor
	}
	return c;
}

Disciplina* importDis(ifstream*f, istringstream &ss, Pessoal* p, vector<string> &ve, vector<string> &vd)
{
	string namePt, nameEn, line;
	int code, year, ects, hours;
	ss >> namePt >> code >> nameEn >> year >> ects >> hours; //variaveis de disciplina
	Disciplina* d = new Disciplina(p, namePt, code, nameEn, year, ects, hours); //constru�ao

	std::getline(*f, line); //proxima linha
	istringstream ss1(line); //line para ss1
	ss1 >> namePt; //nome regente
	vd.push_back(namePt); //nome regente para primeira posi�ao do vetor docentes

	std::getline(*f, line); //proxima linha
	istringstream ss2(line); //line para ss1 (nomes dos docentes)
	while (!ss2.eof())
	{
		namePt = "";
		ss2 >> namePt; //novo nome
		if (namePt.empty()) continue;
		vd.push_back(namePt);
	}
	getline(*f, line); //proxima linha
	stringstream ss3(line); //line para ss2 (nomes dos alunos)
	while (!ss3.eof())
	{
		namePt = "";
		ss3 >> namePt;
		if (namePt.empty()) continue;
		ve.push_back(namePt);
	}
	return d;
}

Estudante* importEst(ifstream*f, istringstream &ss)
{
	string name, address, degree, line;
	int code, phoneNum, d, m, y;
	float avg;

	ss >> name >> code >> address >> phoneNum >> d >> m >> y >> degree >> avg; //variaveis de estudante
	map<string, int> disGrade; //map de disciplina e nota

	std::getline(*f, line); //proxima linha
	istringstream ss1(line); //line to ss1
	while (!ss1.eof())
	{
		string disName = "";
		int disNota;
		ss1 >> disName >> disNota;
		if (disName.empty()) continue;
		disGrade[disName] = disNota;
	}
	Estudante* e = new Estudante(name, code, address, phoneNum, { d,m,y }, degree, avg, disGrade);
	return e;
}

Docente* importDoc(ifstream*f, istringstream &ss)
{
	string name, address, category, line;
	int code, phoneNum, d, m, y, taxNum, salary;

	ss >> name >> code >> address >> phoneNum >> d >> m >> y >> taxNum >> salary >> category; //
	vector<string> dis; //vector de string com nome das mesmas
	std::getline(*f, line); //next line
	istringstream ss1(line); //line to ss1
	while (!ss1.eof())
	{
		string disNome = "";
		ss1 >> disNome;
		if (disNome.empty()) continue;
		dis.push_back(disNome);
	}
	Docente* doc = new Docente(name, code, address, phoneNum, { d, m, y }, taxNum, salary, category, dis);
	return doc;
}

NDocente* importNDo(ifstream*f, istringstream &ss)
{
	string name, address, workArea;
	int code, phoneNum, d, m, y, taxNum, salary;
	ss >> name >> code >> address >> phoneNum >> d >> m >> y >> taxNum >> salary >> workArea;
	NDocente* ndo = new NDocente(name, code, address, phoneNum, { d, m, y }, taxNum, salary, workArea);
	return ndo;
}

string bolseiro(istringstream &ss)
{
	string aux = "";
	while(!ss.eof())
	{
		string nome = "";
		ss >> nome;
		aux += nome;
	}
	return aux;
}

string candBolsa(istringstream &ss)
{
	string aux = "";
	while (!ss.eof())
	{
		string nome = "";
		ss >> nome;
		aux += nome;
	}
	return aux;
}

void importDados(Faculdade *fa)
{
	cout << "\ninicio da importacao\n";
	Pessoal* p = fa->getPessoal();
	ifstream f("FaculdadeDados.txt");
	ifstream *fp = &f;
	string line;
	string obj;

	if (!f.is_open()) return;

	vector<string> facDep;

	map<Departamento*, vector<string>> depCur; //primeiro elemento � nome do diretor
	vector<Departamento*> dep; //vector with departamentos

	map<Curso*, vector<string>> curDis; //primeiro elemento � nome do diretor
	vector<Curso*> cur; //vetor with cursos

	map<Disciplina*, vector<string>> disDoc; //primeiro elemento � nome do regente
	map<Disciplina*, vector<string>> disEst; //lista de estudantes
	vector<Disciplina*> dis; //vector with dsiciplinas

	vector<Estudante*> est; //lista estudantes
	vector<Docente*> doc; //lista docentes
	vector<NDocente*> ndo; //lista nao docentes

	vector<string> bolseiros; //lista nomes estudantes com bolsa
	vector<string> candidatosBolsa; //candidatos a bolsa
	vector<NDocente*> ndoHist; //historico de antigos nao docentes

	while (!f.eof())
	{
		std::getline(f, line);
		istringstream ss(line);
		ss >> obj;
		if (obj == "Fac")
		{
			importFac(fp, ss, facDep);
		}
		else if (obj == "Dep")
		{
			vector<string> v;
			Departamento* d = importDep(fp, ss, p, v);
			depCur[d] = v;
			dep.push_back(d);
		}
		else if (obj == "Cur")
		{
			vector<string> v;
			Curso* c = importCur(fp, ss, p, v);
			curDis[c] = v;
			cur.push_back(c);
		}
		else if (obj == "Dis")
		{
			vector<string> ve;
			vector<string> vd;
			Disciplina* d = importDis(fp, ss, p, ve, vd);
			disEst[d] = ve;
			disDoc[d] = vd;
			dis.push_back(d);
		}
		else if (obj == "Est")
		{
			Estudante* e = importEst(fp, ss);
			est.push_back(e);
		}
		else if (obj == "Doc")
		{
			Docente* d = importDoc(fp, ss);
			doc.push_back(d);
		}
		else if (obj == "NDo")
		{
			NDocente *nd = importNDo(fp, ss);
			ndo.push_back(nd);
		}
		else if (obj == "Bol")
		{
			bolseiros.push_back(bolseiro(ss));
		}
		else if (obj == "CBo")
		{
			candidatosBolsa.push_back(candBolsa(ss));
		}
		else if (obj == "NDH")
		{
			NDocente *nd = importNDo(fp, ss);
			ndoHist.push_back(nd);
		}
		obj = "";
	}
	f.close();


	//build the facultry "tree"

	//starting with the people
	p->setEstudantes(est);
	p->setRegistoEstudante();
	p->setDocentes(doc);
	p->setNDocente(ndo);


	//adding ndo historic
	for(int i = 0; i < ndoHist.size(); i++)
	{
		p->addNDocenteHistorico(ndoHist[i]);
	}

	//adding scholarship students
	for(int i = 0; i<bolseiros.size(); i++)
	{
		try{
			p->addBolseiro(p->findEstudante(bolseiros[i]));
		}
		catch (NoEstudante est) {

		}
	}

	//adding scholarship candidates
	for (int i = 0; i < candidatosBolsa.size(); i++)
	{
		try {
			p->addEstudanteBolsa(p->findEstudante(candidatosBolsa[i]));
		}
		catch (NoEstudante est)
		{

		}
	}

	//building from the bottom aka disciplinas
	map<Disciplina*, vector<string>>::iterator itDD = disDoc.begin();
	for (; itDD != disDoc.end(); itDD++)
	{
		vector<string> DD = itDD->second; //regente + docentes
		try {
			itDD->first->setRegente(p->findDocente(DD[0])); //colocar regente na disciplina
		}
		catch (NoDocente nd)
		{

		}
		DD.erase(DD.begin() + 0); //erase do regente do vetor
		for (unsigned int i = 0; i < DD.size(); i++) //iterar o vetor, sem o regente, dos docentes
		{
			try {
				itDD->first->addDocente(p->findDocente(DD[i])); //coloca los no vetor de docentes da disciplina
			}
			catch (NoDocente nd)
			{

			}
		}
	}

	map<Disciplina*, vector<string>>::iterator itDE = disEst.begin();
	for (; itDE != disEst.end(); itDE++)
	{
		vector<string> DE = itDE->second; //alunos
		for (unsigned int i = 0; i < DE.size(); i++) //iterar sobre o vetor de alunos
		{
			try {
				itDE->first->addEstudante(p->findEstudante(DE[i])); //colocar todos os alunos dentro da disciplina
			}
			catch (NoEstudante ne)
			{

			}
		}
	}

	//adicionar as respetivas disciplinas ao curso correto
	map<Curso*, vector<string>>::iterator itCD = curDis.begin();
	for (; itCD != curDis.end(); itCD++)
	{
		vector<string> CD = itCD->second; //diretor + disciplinas
		try {
			itCD->first->setDiretor(p->findDocente(CD[0])); //colocar diretor no curso
		}
		catch (NoDocente nd)
		{

		}
		cout << CD.size() << endl;
		CD.erase(CD.begin() + 0);//erase diretor
		cout << CD.size() << endl;
		for (unsigned int i = 0; i < CD.size(); i++)
		{
			try {
				itCD->first->addDisciplina(find_D_name(CD[i], dis));//colocar todas as disciplinas dentro do curso
			}
			catch (NoDisciplina nd)
			{

			}
		}
	}

	//adicionar os cursos ao departamento respetivo
	map<Departamento*, vector<string>>::iterator itDC = depCur.begin();
	for (; itDC != depCur.end(); itDC++)
	{
		vector<string> DC = itDC->second; //diretor + cursos
		try {
			itDC->first->setDiretor(p->findDocente(DC[0])); //diretor de departamento
		}
		catch (NoDocente nd)
		{

		}
		DC.erase(DC.begin() + 0); //erase diretor
		for (unsigned int i = 0; i < DC.size(); i++)
		{
			try {
				itDC->first->addCurso(find_T_name(DC[i], cur));
			}
			catch (NoCurso nc)
			{

			}
		}
	}

	//adicionar os departamentos na faculdade
	for (unsigned int i = 0; i < facDep.size(); i++)
	{
		try {
			fa->addDepartamento(find_T_name(facDep[i], dep));
		}
		catch (NoDepartamento nd)
		{

		}
	}

	cout << "\nfim da importacao\n";
	system("pause");
}


void fileFac(ofstream *f, Faculdade *fa)
{
	*f << endl;
	*f << "Fac" << endl;
	vector<Departamento*> dep = fa->getDepartamentos();
	for (unsigned int i = 0; i < dep.size(); i++)
	{
		*f << dep[i]->getNome() << " ";
	}
	*f << endl;
}

void fileDep(ofstream *f, Departamento *dp)
{
	*f << endl;
	*f << "Dep " << dp->getNome() << " " << dp->getCodigo() << " " << dp->getMorada() << " " << dp->getTelefone() << " " << endl;

	*f << dp->getDiretor()->getNome() << endl;

	vector<Curso*> cur = dp->getCursos();
	for (unsigned int i = 0; i < cur.size(); i++)
	{
		*f << cur[i]->getNome() << " ";
	}
	*f << endl;
}

void fileCur(ofstream *f, Curso *c)
{
	*f << endl;
	*f << "Cur " << c->getNome() << " " << c->getCodigo() << " " << c->getTipo() << " " << endl;

	*f << c->getDiretor()->getNome() << endl;

	vector<Disciplina*> dis = c->getDisciplinas();
	for (unsigned int i = 0; i < dis.size(); i++)
	{
		*f << dis[i]->getNomePortugues() << " ";
	}
	*f << endl;
}

void fileDis(ofstream *f, Disciplina *d)
{
	*f << endl;
	*f << "Dis " << d->getNomePortugues() << " " << d->getCodigo() << " " << d->getNomeIngles() << " " << d->getAno() << " " << d->getEcts() << " " << d->getCargaHoraria() << endl;

	*f << d->getRegente()->getNome() << endl;

	vector<Docente*> doc = d->getDocentes();
	for (unsigned int i = 0; i < doc.size(); i++)
	{
		*f << doc[i]->getNome() << " ";
	}
	*f << endl;

	vector<Estudante*> est = d->getEstudantes();
	for (unsigned int i = 0; i < est.size(); i++)
	{
		*f << est[i]->getNome() << " ";
	}
	*f << endl;
}

void fileEst(ofstream *f, Estudante *e)
{
	*f << endl;
	*f << "Est " << e->getNome() << " " << e->getCodigo() << " " << e->getMorada() << " " << e->getTelefone() << " " << e->getDataNascimento().dia << " " << e->getDataNascimento().mes << " " << e->getDataNascimento().ano << " " << e->getCurso() << " " << e->getMedia() << endl;

	map<string, int> dNota = e->getDisciplinas();
	map<string, int>::iterator it = dNota.begin();
	for (; it != dNota.end(); it++)
	{
		*f << it->first << " " << it->second << " ";
	}
	*f << endl;
}

void fileDoc(ofstream *f, Docente *d)
{
	*f << endl;
	*f << "Doc " << d->getNome() << " " << d->getCodigo() << " " << d->getMorada() << " " << d->getTelefone() << " " << d->getDataNascimento().dia << " " << d->getDataNascimento().mes << " " << d->getDataNascimento().ano << " " << d->getContribuinte() << " " << d->getSalario() << " " << d->getCategoria() << endl;

	vector<string> dis = d->getDisciplinas();
	for (unsigned int i = 0; i < dis.size(); i++)
	{
		*f << dis[i] << " ";
	}
	*f << endl;
}

void fileNDo(ofstream *f, NDocente *nd)
{
	*f << endl;
	*f << "NDo " << nd->getNome() << " " << nd->getCodigo() << " " << nd->getMorada() << " " << nd->getTelefone() << " " << nd->getDataNascimento().dia << " " << nd->getDataNascimento().mes << " " << nd->getDataNascimento().ano << " " << nd->getContribuinte() << " " << nd->getSalario() << endl;

	*f << endl;
}

void fileBol(ofstream *f, Estudante * est)
{
	*f << endl;
	*f << "Bol" << " " << est->getNome() << endl;
	*f << endl;
}

void fileCBo(ofstream *f, Estudante * est) {
	*f << endl;
	*f << "CBo" << " " << est->getNome() << endl;
	*f << endl;
}

void fileNDH(ofstream *f, NDocente *nd)
{
	*f << endl;
	*f << "NDH " << nd->getNome() << " " << nd->getCodigo() << " " << nd->getMorada() << " " << nd->getTelefone() << " " << nd->getDataNascimento().dia << " " << nd->getDataNascimento().mes << " " << nd->getDataNascimento().ano << " " << nd->getContribuinte() << " " << nd->getSalario() << endl;

	*f << endl;
}

void exportDados(Faculdade *fa)
{
	cout << "\ninicio da exportacao para ficheiro\n";
	ofstream f;
	ofstream *fp = &f;
	f.open("FaculdadeDados.txt", ios::in | ios::trunc); // creates or opens and clean file

														//faculdade info
	fileFac(fp, fa);

	//department info
	vector<Departamento*> dep = fa->getDepartamentos();
	for (unsigned int i = 0; i < dep.size(); i++)
	{
		fileDep(fp, dep[i]);
	}


	//degree info
	for (unsigned int i = 0; i < dep.size(); i++)
	{
		vector<Curso*> cur = dep[i]->getCursos();
		for (unsigned int j = 0; j < cur.size(); j++)
		{
			fileCur(fp, cur[j]);
		}
	}


	//discipline info
	for (unsigned int i = 0; i < dep.size(); i++)
	{
		vector<Curso*> cur = dep[i]->getCursos();
		for (unsigned int j = 0; j < cur.size(); j++)
		{
			vector<Disciplina*> dis = cur[j]->getDisciplinas();
			for (unsigned int k = 0; k < dis.size(); k++)
			{
				fileDis(fp, dis[k]);
			}
		}
	}

	//staff
	Pessoal *p = fa->getPessoal();

	//students
	vector<Estudante*> est = p->getEstudantes();
	for (unsigned int i = 0; i < est.size(); i++)
	{
		fileEst(fp, est[i]);
	}

	//teachers
	vector<Docente*> doc = p->getDocentes();
	for (unsigned int i = 0; i < doc.size(); i++)
	{
		fileDoc(fp, doc[i]);
	}

	//employees
	vector<NDocente*> ndo = p->getNDocentes();
	for (unsigned int i = 0; i < ndo.size(); i++)
	{
		fileNDo(fp, ndo[i]);
	}

	//scholarship students
	vector<Estudante*> bol = p->getBolseiros(); 
	for (unsigned int i = 0; i < bol.size(); i++)
	{
		fileBol(fp, bol[i]);
	}

	//scholarship candidates
	Heap_estudantes canBol = p->getEstudanteBolsa();
	while (!canBol.empty())
	{
		fileCBo(fp, canBol.top());
		canBol.pop();
	}

	//historic employees
	TahFuncionarios his = p->getHistoricoNDocente();
	for (TahFuncionarios::iterator it = his.begin(); it != his.end(); it++)
	{
		fileNDH(fp, *it);
	}

	f.close();
	cout << "\nfim da exportacao\n";
}


int main()
{	
	
	Pessoal *p = new Pessoal();
	Faculdade *f = new Faculdade(p);
	importDados(f);
	f->manage();
	exportDados(f);
	return 0;
}
