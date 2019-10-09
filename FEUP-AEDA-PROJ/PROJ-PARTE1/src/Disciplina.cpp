#include "Disciplina.h"

Disciplina::Disciplina(Pessoal* p, string nompt , int cod , string nomen, int an, int creditos, int carga,
	vector<Docente*> v , vector<Estudante*> f, string cur) {
	pessoal = p;
	codigo = cod;
	nomePortugues = nompt;
	nomeIngles = nomen;
	ano = an;
	ects = creditos; 
	cargaHoraria = carga; 
	docentes = v;
	estudantes = f;
	regente = new Docente();
	curso = cur;
}

int Disciplina::getCodigo() const{
	return codigo;
}

bool Disciplina::setCodigo(int codigo) {
	this->codigo = codigo;

	return this->codigo == codigo;
}

string Disciplina::getNomePortugues() const {
	return nomePortugues;
}

bool Disciplina::setNomePortugues(string nomePortugues) {
	this->nomePortugues = nomePortugues;

	return this->nomePortugues == nomePortugues;
}

string Disciplina::getNomeIngles() const {
	return nomeIngles;
}

bool Disciplina::setNomeIngles(string nomeIngles) {
	this->nomeIngles = nomeIngles;

	return this->nomeIngles == nomeIngles;
}

Docente* Disciplina::getRegente() const {
	return regente;
}

bool Disciplina::setRegente(Docente* regente) {
	this->regente = regente;

	return true;
}

int Disciplina::getAno() const {
	return ano;
}

bool Disciplina::setAno(int ano) {
	this->ano = ano;

	return this->ano == ano;
}

int Disciplina::getEcts() const {
	return ects;
}

bool Disciplina::setEcts(int ects) {
	this->ects = ects;

	return this->ects == ects;
}

int Disciplina::getCargaHoraria() const {
	return cargaHoraria;
}

bool Disciplina::setCargaHoraria(int cargaHoraria) {
	this->cargaHoraria = cargaHoraria;

	return this->cargaHoraria == cargaHoraria;
}

vector<Docente*> Disciplina::getDocentes() const {
	return docentes;
}

bool Disciplina::setDocentes(vector<Docente*> docentes) {
	this->docentes = docentes;

	return this->docentes == docentes;
}

bool Disciplina::addDocente(Docente* docente) {
	try {
		findDocente(docente->getNome());
	}
	catch (NoDocente exp) {
		docentes.push_back(docente);
		return true;
	}
	throw DocenteRepetido(docente->getNome());
}

bool Disciplina::removeDocente(Docente* docente) {
	vector<Docente*>::iterator it = find(docentes.begin(), docentes.end(), docente);
		if (it != docentes.end()) docentes.erase(it);
		else return false;

		it = find(docentes.begin(), docentes.end(), docente);
		if (it == docentes.end()) return true;
		else return false;
}

Docente* Disciplina::findDocente(string nomeDocente) const {
	for (unsigned int i = 0; i < docentes.size(); i++) {
		if (docentes[i]->getNome() == nomeDocente) {
			return docentes[i];
		}
	}
	throw NoDocente(nomeDocente);
}

void Disciplina::showDocentes() {
	sort(docentes.begin(), docentes.end(), ComparaDocentes());
	cout << "Lista de Docentes: " << endl;
	for (unsigned int i = 0; i < docentes.size(); i++) {
		cout << i + 1 << ":  " << docentes[i]->getNome() << endl;
	}
}


vector<Estudante*> Disciplina::getEstudantes() const {
	return estudantes;
}

bool Disciplina::setEstudantes(vector<Estudante*> estudantes) {
	this->estudantes = estudantes;

	return true;
}

bool Disciplina::addEstudante(Estudante* estudante) {
	try {
		findEstudante(estudante->getNome());
	}
	catch (NoEstudante est) {
		estudantes.push_back(estudante);
		return true;
	}
	throw EstudanteRepetido(estudante->getNome());
}

bool Disciplina::removeEstudante(Estudante* estudante) {
	vector<Estudante*>::iterator it = find(estudantes.begin(), estudantes.end(), estudante);
		if (it != estudantes.end()) estudantes.erase(it);
		else {
			throw EstudanteRepetido(estudante->getNome());
			return false;
		}

		it = find(estudantes.begin(), estudantes.end(), estudante);
		if (it == estudantes.end()) return true;
		else return false;
}

Estudante* Disciplina::findEstudante(string nomeEstudante) const {
	for (unsigned int i = 0; i < estudantes.size(); i++) {
		if (estudantes[i]->getNome() == nomeEstudante) {
			return estudantes[i];
		}
	}
	throw NoEstudante(nomeEstudante);
}

void Disciplina::showEstudantes() {
	sort(estudantes.begin(), estudantes.end(), ComparaEstudantes());
	cout << "Litas de estudantes: " << endl;
	for (unsigned int i = 0; i < estudantes.size(); i++) {
		cout << i + 1 << ":  " << estudantes[i]->getNome() << endl;
	}
}

void Disciplina::manage() {
	unsigned int escolha;
	do {
		system("CLS");
		cout << "Estas na Disciplina: " << this->getNomePortugues() << " / " << getNomeIngles() << " // " << this->getCodigo() << endl;
		cout << "Dados: " << " Ano: " << getAno() << " / ects: " << getEcts() << " / cargaHoraria: " << getCargaHoraria() << endl;
		cout << "Regente: " << this->getRegente()->getNome() << " " << this->getRegente()->getCodigo() << endl;
		cout << "O que queres fazer?" << endl << endl;

		cout << "1: Alterar Disciplina" << endl;
		cout << "2: Manage Docentes" << endl;
		cout << "3: Manage Estudantes" << endl;
		cout << "4: Voltar" << endl << endl;

		cout << "Escolha uma das opcoes: ";
		escolha = int_input_errorHandler();

		if (escolha == 1) {
			manageDisciplina();
		}

		else if (escolha == 2) {
			manageDocentes();
		}

		else if (escolha == 3) {
			manageEstudantes();
		}

	} while (escolha != 4);
}

void Disciplina::manageDisciplina() {
	unsigned int escolha;
	do {
		try {
			system("CLS");
			cout << "Estas na Disciplina: " << this->getNomePortugues() << " / " << getNomeIngles() << " // " << this->getCodigo() << endl;
			cout << "Dados: " << " Ano: " << getAno() << " / ECTS: " << getEcts() << " / cargaHoraria: " << getCargaHoraria() << endl;
			cout << "Regente: " << this->getRegente()->getNome() << " " << this->getRegente()->getCodigo() << endl;
			cout << "O que queres fazer?" << endl << endl;

			cout << "1: Alterar nome em Portugues" << endl;
			cout << "2: Alterar nome em Ingles" << endl;
			cout << "3: Alterar codigo" << endl;
			cout << "4: Alterar ano" << endl;
			cout << "5: Alterar ects" << endl;
			cout << "6: Alterar cargaHoraria" << endl;
			cout << "7: Alterar/Modificar regente" << endl;
			cout << "8: Voltar" << endl << endl;

			cout << "Escolha uma das opcoes: ";
			escolha = int_input_errorHandler();

			if (escolha == 1) {
				string nomePT;
				system("CLS");
				cout << "Nome em Portugues atual: " << this->getNomePortugues() << endl << endl;
				cout << "Nome em Portugues Codigo: ";
				nomePT = string_input_errorHandler();
				this->setNomePortugues(nomePT);
			}
			else if (escolha == 2) {
				string nomeEN;
				system("CLS");
				cout << "Nome em Ingles atual: " << this->getNomeIngles() << endl << endl;
				cout << "Nome em Ingles Codigo: ";
				nomeEN = string_input_errorHandler();
				this->setNomeIngles(nomeEN);
			}
			else if (escolha == 3) {
				int cod;
				system("CLS");
				cout << "Codigo atual: " << this->getCodigo() << endl << endl;
				cout << "Novo Codigo: ";
				cod = int_input_errorHandler();
				this->setCodigo(cod);
			}
			else if (escolha == 4) {
				int ano;
				system("CLS");
				cout << "Ano atual: " << this->getAno() << endl << endl;
				cout << "Novo Ano: ";
				ano = int_input_errorHandler();
				this->setAno(ano);
			}
			else if (escolha == 5) {
				int ects;
				system("CLS");
				cout << "ECTS atual: " << this->getEcts() << endl << endl;
				cout << "Novo ECTS: ";
				ects = int_input_errorHandler();
				this->setEcts(ects);
			}
			else if (escolha == 6) {
				int cargaHoraria;
				system("CLS");
				cout << "Carga horaria atual: " << this->getCargaHoraria() << endl << endl;
				cout << "Novo carga horaria: ";
				cargaHoraria = int_input_errorHandler();
				this->setCargaHoraria(cargaHoraria);
			}
			else if (escolha == 7) {
				int resposta;
				system("CLS");
				cout << "Regente: " << this->getRegente()->getNome() << " " << this->getRegente()->getCodigo() << endl;
				cout << "O que queres fazer?" << endl;
				cout << "1: Modificar o diretor atual" << this->getRegente()->getNome() << endl;
				cout << "2: Alterar o diretor atual, no entanto ele ja existe no sistema " << this->getRegente()->getNome() << endl;
				cout << "3: Alterar o diretor atual, no entanto ele não existe no sistema" << endl;
				cout << "Ecolha uma das opcoes: ";
				resposta = int_input_errorHandler();
				if (resposta == 1) {
					this->getRegente()->manage();
				}
				else if (resposta == 2) {
					string nome;
					system("CLS");
					cout << "Qual e o nome do novo regente?" << endl;
					nome = string_input_errorHandler();
					setRegente(pessoal->findDocente(nome));
				}
				else if (resposta == 3) {
					string nome;
					system("CLS");
					cout << "Qual e o nome do novo diretor?" << endl;
					nome = string_input_errorHandler();
					Docente* x = new Docente(nome);
					pessoal->addDocente(x);
					this->setRegente(x);
				}
			}
		}
		catch (NoDocente exp) {
			exp.mensagem();
		}
	} while (escolha != 8);
}

void Disciplina::manageDocentes() {
	unsigned int escolha;
	do {
		try {
			system("CLS");
			cout << "Estas nos Docentes da Disciplina " << this->getNomePortugues() << " / " << getNomeIngles() << endl;
			cout << "O que queres fazer?" << endl << endl;

			cout << "1: Adicionar um docente" << endl;
			cout << "2: Adicionar um  docente ja existente no pessoal" << endl;
			cout << "3: Remover um docente" << endl;
			cout << "4: Ver docente existentes" << endl;
			cout << "5: Manage docente" << endl;
			cout << "6: voltar" << endl << endl;

			cout << "Escolha uma das opcoes: ";
			escolha = int_input_errorHandler();

			if (escolha == 1) {
				string nomdoc;
				system("CLS");
				cout << "Digite o nome do docente: ";
				nomdoc = string_input_errorHandler();
				Docente* novo = new Docente(nomdoc);
				pessoal->addDocente(novo);
				addDocente(novo);
			}
			else if (escolha == 2) {
				string nomdoc;
				system("CLS");
				cout << "Digite o nome do docente: ";
				nomdoc = string_input_errorHandler();
				addDocente(pessoal->findDocente(nomdoc));
				findDocente(nomdoc)->addDisciplina(getNomePortugues());
			}
			else if (escolha == 3) {
				string nomdoc;
				system("CLS");
				cout << "Digite o nome do docente: ";
				nomdoc = string_input_errorHandler();
				if (removeDocente(findDocente(nomdoc))) 
					findDocente(nomdoc)->removeDisciplina(getNomePortugues());
			}
			else if (escolha == 4) {
				system("CLS");
				showDocentes();
				system("pause");
			}
			else if (escolha == 5) {
				string nomdoc;
				system("CLS");
				cout << "Digite o nome do docente: ";
				nomdoc = string_input_errorHandler();
				pessoal->findDocente(nomdoc)->manage();
			}
		}
		catch (NoDocente exp) {
			exp.mensagem();
		}
		catch (DocenteRepetido exp) {
			exp.mensagem();
		}
	} while (escolha != 6);
}

void Disciplina::manageEstudantes() {
	unsigned int escolha;
	do {
		try {
			system("CLS");
			cout << "Estas nos Estudantes da Disciplina " << this->getNomePortugues() << " / " << getNomeIngles() << endl;
			cout << "O que queres fazer?" << endl << endl;

			cout << "1: Adicionar um estudante" << endl;
			cout << "2: Adicionar um estudante ja existente no pessoal" << endl;
			cout << "3: Remover um estudante" << endl;
			cout << "4: Ver estudantes existentes" << endl;
			cout << "5: Manage estudante" << endl;
			cout << "6: voltar" << endl << endl;

			cout << "Escolha uma das opcoes: ";
			escolha = int_input_errorHandler();

			if (escolha == 1) {
				string nomest;
				system("CLS");
				cout << "Digite o nome do estudante: ";
				nomest = string_input_errorHandler();
				Estudante* novo = new Estudante(nomest);
				novo->addDisciplina(getNomePortugues());
				novo->setCurso(getCurso());
				pessoal->addEstudante(novo);
				addEstudante(novo);
				
			}
			else if (escolha == 2) {
				string nomest;
				system("CLS");
				cout << "Digite o nome do estudante: ";
				nomest = string_input_errorHandler();
				addEstudante(pessoal->findEstudante(nomest));
				findEstudante(nomest)->addDisciplina(getNomePortugues(), 0);
				findEstudante(nomest)->setCurso(getCurso());
			}
			else if (escolha == 3) {
				string nomest;
				system("CLS");
				cout << "Digite o nome do estudante: ";
				nomest = string_input_errorHandler();
				if (removeEstudante(findEstudante(nomest)))
					pessoal->removeEstudante(findEstudante(nomest));
			}
			else if (escolha == 4) {
				system("CLS");
				showEstudantes();
				system("pause");
			}
			else if (escolha == 5) {
				string nomest;
				system("CLS");
				cout << "Digite o nome do estudante: ";
				nomest = string_input_errorHandler();
				pessoal->findEstudante(nomest)->manage();
			}
		}
		catch (NoEstudante exp) {
			exp.mensagem();
		}
		catch (EstudanteRepetido exp) {
			exp.mensagem();
		}
	} while (escolha != 6);
}

string Disciplina::getCurso() const {
	return curso;
}

bool Disciplina::setCurso(string curso) {
	this->curso = curso;
	return true;
}
