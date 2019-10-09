#include"Pessoal.h"

Pessoal::Pessoal(vector<Estudante*> e, vector<Docente*> d, vector<NDocente*> nd, vector<Estudante*> bol, vector<Estudante*> candidatos, vector<NDocente*> historico) //: registoEstudantes(new Estudante("")) {
{
	estudantes = e;
	docentes = d;
	nDocentes = nd;
	bolseiros = bol;
	for (unsigned int i = 0; i != candidatos.size(); i++) addEstudanteBolsa(candidatos[i]);
	for (unsigned int i = 0; i != historico.size(); i++) addNDocenteHistorico(historico[i]);
	//setRegistoEstudante();
}

vector<Estudante*> Pessoal::getEstudantes() const {
	return estudantes;
}

bool Pessoal::setEstudantes(vector<Estudante*> estudantes) {
	this->estudantes = estudantes;

	return true;
}

bool Pessoal::addEstudante(Estudante* estudante) {
	try {
		findEstudante(estudante->getNome());
	}
	catch (NoEstudante est)
	{
		estudantes.push_back(estudante);
		addRegistoEstudante(estudante);
		return true;
	}
	throw EstudanteRepetido(estudante->getNome());
}

bool Pessoal::removeEstudante(Estudante* estudante) {
	vector<Estudante*>::iterator it = find(estudantes.begin(), estudantes.end(), estudante);
	if (it != estudantes.end()) {
		estudantes.erase(it);
		removeRegistoEstudante(*it);
	}
	else return false;

	it = find(estudantes.begin(), estudantes.end(), estudante);
	if (it == estudantes.end()) return true;
	else return false;
}

Estudante* Pessoal::findEstudante(string nomeEstudante) const {
	for (unsigned int i = 0; i < estudantes.size(); i++) {
		if (estudantes[i]->getNome() == nomeEstudante) {
			return estudantes[i];
		}
	}
	throw NoEstudante(nomeEstudante);
}

void Pessoal::showEstudantes() {
	sort(estudantes.begin(), estudantes.end(), ComparaEstudantes());
	cout << "Lista de estudantes: " << endl;
	for (unsigned int i = 0; i < estudantes.size(); i++) {
		if (i % 4 == 0) {
			cout << endl;
		}
		cout << i + 1 << ":  " << estudantes[i]->getNome() << "\t";
	}
	cout << endl;
}

vector<Docente*> Pessoal::getDocentes() const {
	return docentes;
}

bool Pessoal::setDocentes(vector<Docente*> docentes) {
	this->docentes = docentes;

	return this->docentes == docentes;
}

bool Pessoal::addDocente(Docente* docente) {
	try {
		findDocente(docente->getNome());
	}
	catch (NoDocente doc)
	{
		docentes.push_back(docente);
		return true;
	}
	throw DocenteRepetido(docente->getNome());
}

bool Pessoal::removeDocente(Docente* docente) {
	vector<Docente*>::iterator it = find(docentes.begin(), docentes.end(), docente);
	if (it != docentes.end()) docentes.erase(it);
	else return false;

	it = find(docentes.begin(), docentes.end(), docente);
	if (it == docentes.end()) return true;
	else return false;
}

Docente* Pessoal::findDocente(string nomeDocente) const{
	for (unsigned int i = 0; i < docentes.size(); i++) {
		if (docentes[i]->getNome() == nomeDocente) {
			return docentes[i];
		}
	}
	throw NoDocente(nomeDocente);
}

void Pessoal::showDocentes() {
	sort(docentes.begin(), docentes.end(), ComparaDocentes());
	cout << "Lista de Docentes: " << endl;
	for (unsigned int i = 0; i < docentes.size(); i++) {
		if (i % 4 == 0) {
			cout << endl;
		}
		cout << i + 1 << ":  " << docentes[i]->getNome() << "\t";
	}
	cout << endl;
}


vector<NDocente*> Pessoal::getNDocentes() const {
	return nDocentes;
}

bool Pessoal::setNDocente(vector<NDocente*> nDocentes) {
	this->nDocentes = nDocentes;

	return true;
}

bool Pessoal::addNDocente(NDocente* nDocente) {
	try {
		findNDocente(nDocente->getNome());
	}
	catch (NoNDocente ndo)
	{
		nDocentes.push_back(nDocente);
		return true;
	}
	throw NDocenteRepetido(nDocente->getNome());
}

bool Pessoal::removeNDocente(NDocente* nDocente) {
	vector<NDocente*>::iterator it = find(nDocentes.begin(), nDocentes.end(), nDocente);
	if (it != nDocentes.end()) nDocentes.erase(it);
	else return false;

	it = find(nDocentes.begin(), nDocentes.end(), nDocente);
	if (it == nDocentes.end()) return true;
	else return false;
}

NDocente* Pessoal::findNDocente(string nomeNDocente) const {
	for (unsigned int i = 0; i < nDocentes.size(); i++) {
		if (nDocentes[i]->getNome() == nomeNDocente) {
			return nDocentes[i];
		}
	}
	throw NoNDocente(nomeNDocente);
}

void Pessoal::showNDocente() {
	sort(nDocentes.begin(), nDocentes.end(), ComparaNDocentes());
	cout << "Lista de funcionarios: " << endl;
	for (unsigned int i = 0; i < nDocentes.size(); i++) {
		if (i % 4 == 0) {
			cout << endl;
		}
		cout << i + 1 << ":  " << nDocentes[i]->getNome() << "\t";
	}
	cout << endl;
}

void Pessoal::manage() {
	unsigned int escolha;
	do {
		system("CLS");
		cout << "Estas em: Lista de pessoal" << endl;
		cout << "O que queres fazer?" << endl << endl;

		cout << "1: Gerir a lista de estudantes" << endl;
		cout << "2: Gerir a lista de docentes" << endl;
		cout << "3: Gerir a lista de funcionarios" << endl;
		cout << "4: Gerir a lista de bolseiros e candidatos a bolsa" << endl;
		cout << "5: Gerir o historico de funcionarios" << endl;
		cout << "6: Voltar" << endl << endl;

		cout << "Escolha uma das opcoes: ";
		escolha = int_input_errorHandler();

		if (escolha == 1) {
			manageEstudantes();
		}
		else if (escolha == 2) {
			manageDocentes();
		}
		else if (escolha == 3) {
			manageNDocentes();
		}
		else if (escolha == 4) {
			manageBolsas();
		}
		else if (escolha == 5) {
			manageHistorico();
		}

	} while (escolha != 6);
}

void Pessoal::manageEstudantes() {
	unsigned int escolha;
	do {
		try {
			system("CLS");
			cout << "Estas em: Lista de estudantes" << endl;
			cout << "O que queres fazer?" << endl << endl;

			cout << "1: Adiconar um estudante" << endl;
			cout << "2: Remover um estudante" << endl;
			cout << "3: Ver os estudantes inscritos por ordem alfabetica" << endl;
			cout << "4: Ver os estudantes inscritos por cursos" << endl;
			cout << "5: Gerir um estudante" << endl;
			cout << "6: Voltar" << endl << endl;

			cout << "Escolha uma das opcoes: ";
			escolha = int_input_errorHandler();

			if (escolha == 1) {
				string nomeEstudante;
				system("CLS");
				cout << "Digite o nome do estudante: ";
				nomeEstudante = string_input_errorHandler();
				Estudante* novo = new Estudante(nomeEstudante);
				addEstudante(novo);
				//addRegistoEstudante(novo);
			}
			else if (escolha == 2) {
				string nomeEstudante;
				system("CLS");
				cout << "Digite o nome do estudante: ";
				nomeEstudante = string_input_errorHandler();
				removeEstudante(findEstudante(nomeEstudante));
				//removeRegistoEstudante(findRegistoEstudante(nomeEstudante));
			}
			else if (escolha == 3) {
				system("CLS");
				showEstudantes();
				system("pause");
			}
			else if (escolha == 4) {
				system("CLS");
				showRegistoEstudante();
				system("pause");
			}
			else if (escolha == 5) {
				bool CandidatoBolsa = true;
				string nomeEstudante;
				system("CLS");
				cout << "Digite o nome do estudante: ";
				nomeEstudante = string_input_errorHandler();
				Estudante* aux = findEstudante(nomeEstudante);
				removeRegistoEstudante(aux);
				try {
					removeEstudanteBolsa(findEstudanteBolsa(nomeEstudante));
				}
				catch (NoEstudante exp) { CandidatoBolsa = false; }
				aux->manage();
				addRegistoEstudante(aux);
				if (CandidatoBolsa) addEstudanteBolsa(aux);
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

void Pessoal::manageDocentes() {
	unsigned int escolha;
	do {
		try {
			system("CLS");
			cout << "Estas em: Lista de docentes" << endl;
			cout << "O que queres fazer?" << endl << endl;

			cout << "1: Adiconar um docente" << endl;
			cout << "2: Remover um docente" << endl;
			cout << "3: Ver os docentes inscritos" << endl;
			cout << "4: Gerir um docente" << endl;
			cout << "5: Voltar" << endl << endl;

			cout << "Escolha uma das opcoes: ";
			escolha = int_input_errorHandler();

			if (escolha == 1) {
				string nomeDocente;
				system("CLS");
				cout << "Digite o nome do docente: ";
				nomeDocente = string_input_errorHandler();
				Docente* novo = new Docente(nomeDocente);
				addDocente(novo);
			}
			else if (escolha == 2) {
				string nomeDocente;
				system("CLS");
				cout << "Digite o nome do docente: ";
				nomeDocente = string_input_errorHandler();
				removeDocente(findDocente(nomeDocente));
			}
			else if (escolha == 3) {
				system("CLS");
				showDocentes();
				system("pause");
			}
			else if (escolha == 4) {
				string nomeDocente;
				system("CLS");
				cout << "Digite o nome do docente: ";
				nomeDocente = string_input_errorHandler();
				findDocente(nomeDocente)->manage();
			}
		}
		catch (NoDocente exp) {
			exp.mensagem();
		}
		catch (DocenteRepetido exp) {
			exp.mensagem();
		}
	} while (escolha != 5);
}

void Pessoal::manageNDocentes() {
	unsigned int escolha;
	do {
		try {
			system("CLS");
			cout << "Estas em: Lista de funcionarios" << endl;
			cout << "O que queres fazer?" << endl << endl;

			cout << "1: Adiconar um funcionario" << endl;
			cout << "2: Remover um funcionario" << endl;
			cout << "3: Ver os funcionarios inscritos" << endl;
			cout << "4: Gerir um funcionario" << endl;
			cout << "5: Voltar" << endl << endl;

			cout << "Escolha uma das opcoes: ";
			escolha = int_input_errorHandler();

			if (escolha == 1) {
				string nomeNDocente;
				system("CLS");
				cout << "Digite o nome do funcionario: ";
				nomeNDocente = string_input_errorHandler();
				NDocente* novo = new NDocente(nomeNDocente);
				addNDocente(novo);
			}
			else if (escolha == 2) {
				string nomeNDocente;
				system("CLS");
				cout << "Digite o nome do funcionario: ";
				nomeNDocente = string_input_errorHandler();
				NDocente * ndo = findNDocente(nomeNDocente);
				removeNDocente(ndo);
				addNDocenteHistorico(ndo);
			}
			else if (escolha == 3) {
				system("CLS");
				showNDocente();
				system("pause");
			}
			else if (escolha == 4) {
				string nomeNDocente;
				system("CLS");
				cout << "Digite o nome do funcionario: ";
				nomeNDocente = string_input_errorHandler();
				findNDocente(nomeNDocente)->manage();
			}
		}
		catch (NoNDocente exp) {
			exp.mensagem();
		}
		catch (NDocenteRepetido exp) {
			exp.mensagem();
		}
	} while (escolha != 5);
}

void Pessoal::manageBolsas() {
	unsigned int escolha;
	do {
		try {
			system("CLS");
			cout << "Estas em: Listas de bolseiros e candidatos" << endl;
			cout << "O que queres fazer?" << endl << endl;

			cout << "1: Adiconar um candidato" << endl;
			cout << "2: Avancar a lista de candidatos" << endl;
			cout << "3: Remover um bolseiro" << endl;
			cout << "4: Remover um candidato" << endl;
			cout << "5: Ver os bolseiros" << endl;
			cout << "6: Ver os candidatos" << endl;
			cout << "7: Gerir um bolseiro" << endl;
			cout << "8: Gerir um candidato" << endl;
			cout << "9: Voltar" << endl << endl;

			cout << "Escolha uma das opcoes: ";
			escolha = int_input_errorHandler();

			if (escolha == 1) {
				string estNome;
				system("CLS");
				cout << "Digite o nome do estudante a ser candidato: ";
				estNome = string_input_errorHandler();
				addEstudanteBolsa(findEstudante(estNome));
			}
			else if (escolha == 2) {
				system("CLS");
				Estudante* top = bolsas.top();
				nextEstudanteBolsa();
				cout << "O Estudante " << top->getNome() << " foi adicionado a lista de Bolseiros!" << endl;
			}
			else if (escolha == 3) {
				string estNome;
				system("CLS");
				cout << "Digite o nome do bolseiro: ";
				estNome = string_input_errorHandler();
				removeBolseiro(findBolseiro(estNome));
			}
			else if (escolha == 4) {
				string estNome;
				system("CLS");
				cout << "Digite o nome do candidato: ";
				estNome = string_input_errorHandler();
				removeEstudanteBolsa(findEstudanteBolsa(estNome));
			}
			else if (escolha == 5) {
				system("CLS");
				showBolseiro();
				system("pause");
			}
			else if (escolha == 6) {
				system("CLS");
				showBolsa();
				system("pause");
			}
			else if (escolha == 7) {
				string estNome;
				system("CLS");
				cout << "Digite o nome do bolseiro: ";
				estNome = string_input_errorHandler();
				findBolseiro(estNome)->manage();
			}
			else if (escolha == 8) {
				string estNome;
				system("CLS");
				cout << "Digite o nome do candidato: ";
				estNome = string_input_errorHandler();
				findEstudanteBolsa(estNome)->manage();
			}
		}
		catch (NoEstudante exp) {
			exp.mensagem();
		}
		catch (EstudanteRepetido exp) {
			exp.mensagem();
		}
		catch (BolsaVazia exp) {
			exp.mensagem();
		}
		catch (BolseiroRepetido exp) {
			exp.mensagem();
		}
	} while (escolha != 9);
}

void Pessoal::manageHistorico() {
	unsigned int escolha;
	do {
		try {
			system("CLS");
			cout << "Estas em: Historico de funcionarios" << endl;
			cout << "O que queres fazer?" << endl << endl;

			cout << "1: Ver historico" << endl;
			cout << "2: Contratar funcionario antigo" << endl;
			cout << "3: Limpar o historico" << endl;
			cout << "4: Voltar" << endl << endl;

			cout << "Escolha uma das opcoes: ";
			escolha = int_input_errorHandler();

			if (escolha == 1) {
				system("CLS");
				showHistorico();
				system("pause");
			}
			else if (escolha == 2) {
				system("CLS");
				string ndNome;
				system("CLS");
				cout << "Digite o nome do funcionario: ";
				ndNome = string_input_errorHandler();
				NDocente * ndo = findNDocenteHistorico(ndNome);
				addNDocente(ndo);
				removeNDocenteHistorico(ndo);
			}
			else if (escolha == 3) {
				system("CLS");
				cleanHistorico();
				cout << "O historico foi limpo!" << endl << endl;
				system("pause");
			}
		}
		catch (NoNDocente exp) {
			exp.mensagem();
		}
		catch (NDocenteRepetido exp) {
			exp.mensagem();
		}
	} while (escolha != 4);
}

// Vector Bolseiro

vector<Estudante*> Pessoal::getBolseiros() const {
	return bolseiros;
}

bool Pessoal::setBolseiros(vector<Estudante*> bolseiros) {
	this->bolseiros = bolseiros;
	return true;
}

void Pessoal::addBolseiro(Estudante * est) {
	vector<Estudante*>::iterator it = find(bolseiros.begin(), bolseiros.end(), est);
	if (it == bolseiros.end())
	{
		bolseiros.push_back(est);
	}
}

bool Pessoal::removeBolseiro(Estudante* bolseiro) {
	vector<Estudante*>::iterator it = find(bolseiros.begin(), bolseiros.end(), bolseiro);
	if (it != bolseiros.end()) bolseiros.erase(it);
	else return false;

	it = find(bolseiros.begin(), bolseiros.end(), bolseiro);
	if (it == bolseiros.end()) return true;
	else return false;
}

Estudante* Pessoal::findBolseiro(string nomeBolseiro) const {
	for (unsigned int i = 0; i < bolseiros.size(); i++) {
		if (bolseiros[i]->getNome() == nomeBolseiro) {
			return bolseiros[i];
		}
	}
	throw NoEstudante(nomeBolseiro);
}

void Pessoal::showBolseiro() {
	sort(bolseiros.begin(), bolseiros.end(), ComparaEstudantes());
	cout << "Lista de boldeiros: " << endl;
	for (unsigned int i = 0; i < bolseiros.size(); i++) {
		if (i % 4 == 0) {
			cout << endl;
		}
		cout << i + 1 << ":  " << bolseiros[i]->getNome() << "\t";
	}
	cout << endl;
}

// Lista de prioridade candidatos bolsa

Heap_estudantes Pessoal::getEstudanteBolsa() const
{
	return bolsas;
}

void Pessoal::addEstudanteBolsa(Estudante* est) {
	findEstudante(est->getNome());
	try {
		if (findBolseiro(est->getNome()))
			throw BolseiroRepetido(est->getNome());
	}
	catch (NoEstudante exp) {
		bolsas.push(est);
		
	}
}

Estudante* Pessoal::nextEstudanteBolsa() {
	if (!bolsas.empty()) {
		Estudante* est = bolsas.top();
		bolsas.pop();
		bolseiros.push_back(est);
		return est;
	}
	throw BolsaVazia();
}

bool Pessoal::removeEstudanteBolsa(Estudante* est) {
	vector<Estudante*> pilha;
	while (!bolsas.empty()) {
		if (est != bolsas.top())
			pilha.push_back(bolsas.top());
		bolsas.pop();
	}
	for (unsigned int i = 0; i != pilha.size(); i++) {
		bolsas.push(pilha[i]);
	}
	return true;
}

Estudante* Pessoal::findEstudanteBolsa(string nomeEst) const {
	Heap_estudantes bol = bolsas;
	while (!bol.empty()) {
		if (nomeEst == bol.top()->getNome())
			return bol.top();
		bol.pop();
	}
	throw NoEstudante(nomeEst);
}

/*
bool Pessoal::atualizaEstudanteBolsa() {
	vector <Estudante*> pilha;

	while (!bolsas.empty()) {
			pilha.push_back(bolsas.top());
			bolsas.pop();
	}
	for (unsigned int i = 0; i < pilha.size(); i++) {
		bolsas.push(pilha[i]);
	}
	return true;
}
*/

void Pessoal::showBolsa() const {
	Heap_estudantes bolsa = bolsas;
	cout << "Lista de pessoas a concorrer para Bolseiros: " << endl;
	for (unsigned int i = 0; !bolsa.empty() ; i++) {
		if (i % 4 == 0) {
			cout << endl;
		}
		cout << i + 1 << ":  " << bolsa.top()->getNome() << "\t";
		bolsa.pop();
	}
	cout << endl;
}

// Historico Funcionarios

TahFuncionarios Pessoal::getHistoricoNDocente() const
{
	return historicoFuncionarios;
}

bool Pessoal::addNDocenteHistorico(NDocente* ndoc) {
	if (!presenteNDocenteHistorico(ndoc->getNome())) {
		historicoFuncionarios.insert(ndoc);
		return true;
	}
	else 
	throw NDocenteRepetido(ndoc->getNome());
}

bool Pessoal::presenteNDocenteHistorico(string nome) const{
	for (TahFuncionarios::const_iterator it = historicoFuncionarios.begin(); it != historicoFuncionarios.end(); it++) {
		if ((*it)->getNome() == nome) return true;
	}
	return false;
}

void Pessoal::cleanHistorico() {
	TahFuncionarios novoHistorico;
	historicoFuncionarios = novoHistorico;

	for (unsigned int i = 0; i < nDocentes.size(); i++) {
		addNDocenteHistorico(nDocentes[i]);
	}
}

void Pessoal::showHistorico() const {
	int i = 0;
	cout << "Lista de Funcionarios antigos e atuais: " << endl;
	for (TahFuncionarios::const_iterator it = historicoFuncionarios.begin(); it != historicoFuncionarios.end() ; it++) {
		if (i % 4 == 0) {
			cout << endl;
		}
		cout << i + 1 << ":  " << (*it)->getNome() << "\t";
		i++;
	}
	cout << endl;
}

NDocente* Pessoal::findNDocenteHistorico(string nomeND ) const {
	for (TahFuncionarios::const_iterator it = historicoFuncionarios.begin(); it != historicoFuncionarios.end(); it++) {
		if ((*it)->getNome() == nomeND) {
			NDocente* novo = *it;
			//NDocente* itnovo = new NDocente(novo);
			return novo;
		}
	}
	throw NoNDocente(nomeND);
}

void Pessoal::removeNDocenteHistorico(NDocente* ndo) {
	TahFuncionarios::iterator it = find(historicoFuncionarios.begin(), historicoFuncionarios.end(), ndo);
	if (it != historicoFuncionarios.end()) {
		historicoFuncionarios.erase(it);
	}
}

// Registo de Estudantes

bool Pessoal::setRegistoEstudante() {
	ArvoreBinariaEstudantes aux;
	registoEstudantes = aux;
	for (unsigned int i = 0; i != estudantes.size(); i++) {
		registoEstudantes.insert(estudantes[i]);
	}
	return true;
 }

bool Pessoal::addRegistoEstudante(Estudante* est) {
	//if (registoEstudantes.find(est) == NULL) {
		registoEstudantes.insert(est);
		//std::sort(registoEstudantes.begin(), registoEstudantes.end(), ComparaRegistoEstudantes());
		return true;
	}
	//else return false;
//}
/*
bool Pessoal::removeRegistoEstudante(Estudante* est) {
	if (registoEstudantes.find(est) == NULL) {
		return false;
	}
	registoEstudantes.remove(est);
	return true;
}


Estudante* Pessoal::findRegistoEstudante(string nomeEst) const {
	Estudante* novo = new Estudante(nomeEst);
	novo = registoEstudantes.find(novo);
	if (novo == NULL) throw NoEstudante(nomeEst);
	return novo;
}


void Pessoal::showRegistoEstudante() const {
	BSTItrIn<Estudante*> it(registoEstudantes);
	while (!it.isAtEnd()) {
		cout << it.retrieve()->getNome() << endl;
		it.advance();
	}
}*/

bool Pessoal::removeRegistoEstudante(Estudante* est) {
ArvoreBinariaEstudantes::iterator it = registoEstudantes.find(est);
	if (it == registoEstudantes.end()) {
		return false;
	}
	registoEstudantes.erase(it);
	return true;
}


Estudante* Pessoal::findRegistoEstudante(string nomeEst, string nomeCur) const {
	Estudante* novo = new Estudante(nomeEst);
	novo->setCurso(nomeCur);
	ArvoreBinariaEstudantes::iterator it = registoEstudantes.find(novo);
	if (it == registoEstudantes.end()) throw NoEstudante(nomeEst);
	return novo;
}

void Pessoal::showRegistoEstudante() const {
	ArvoreBinariaEstudantes::iterator it = registoEstudantes.begin();
	for (unsigned int i = 0; it != registoEstudantes.end(); it++)
	{
		i++;
		cout <<i << ":  "<<(*it)->getCurso() << " "<< (*it)->getNome() << endl;
	}

}
