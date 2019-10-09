#include "Estudante.h"

Estudante::Estudante(string nom, int cod,string mor, int tele, struct dataNascimento dataNas, 
	string c, float med, map<string, int> disc) : Pessoa(nom, mor, tele, dataNas, cod)
{
	curso = c;
	media = med;
	disciplinas = disc;
}

string Estudante::getCurso() const {
	return curso;
}

bool Estudante::setCurso(string curso) {
	this->curso = curso;

	return this->curso == curso;
}

float Estudante::getMedia() const {
	return media;
}

bool Estudante::atualizaMedia() {
	float notas = 0;
	for (map<string, int>::iterator it = disciplinas.begin(); it != disciplinas.end(); it++) {
		notas += it->second;
	}

	media = (notas / (float)disciplinas.size());

	return true;
}

map<string, int> Estudante::getDisciplinas() const {
	return disciplinas;
}

bool Estudante::setDisciplinas(map<string, int> disciplinas) {
	this->disciplinas = disciplinas;
	atualizaMedia();

	return this->disciplinas == disciplinas;
}

bool Estudante::addDisciplina(string nomeDisciplina, int nota) {
	if (disciplinas.find(nomeDisciplina) != disciplinas.end()) {
		throw DisciplinaRepetida(nomeDisciplina);
		return false;
	}
	else {
		disciplinas[nomeDisciplina] = nota;
		atualizaMedia();
		return true;
	}
}

bool Estudante::setNota(string nomeDisciplina, int nota) {
	if (disciplinas.find(nomeDisciplina) == disciplinas.end()) {
		return false;
	}
	else {
		disciplinas.find(nomeDisciplina)->second = nota;
		atualizaMedia();
		return true;
	}
}

bool Estudante::removeDisciplina(string nomeDisciplina) {
	map<string, int>::iterator it = disciplinas.find(nomeDisciplina);
	if (it != disciplinas.end()) { 
		disciplinas.erase(nomeDisciplina); 
		atualizaMedia();
	}
	else return false;

	it = disciplinas.find(nomeDisciplina);
	if (it == disciplinas.end()) return true;
	else return false;
}

void Estudante::showDisciplinas() const {
	cout << "Pauta de " << getNome() << " / " << getCodigo() << endl;
	for (map<string, int>::const_iterator it = disciplinas.begin() ; it != disciplinas.end(); it++) {
		cout << it->first << "\t" << it->second << "\t" << endl;
	}
}


void Estudante::manage() {
	unsigned int escolha;
	do {
		system("CLS");
		cout << "Estas no estudante: " << this->getNome() << " // " << this->getCodigo() << endl;
		cout << "Dados: " << " Data de nascimento: " << getDataNascimento().ano << "/" << getDataNascimento().mes << "/" << getDataNascimento().dia << " / Telemovel: " << getTelefone() << endl;
		cout << "Morada: " << getMorada() << endl;
		cout << "Curso: " << getCurso() << endl;
		cout << "Media: " << getMedia() << endl;
		cout << "O que queres fazer?" << endl << endl;

		cout << "1: Alterar nome" << endl;
		cout << "2: Alterar Codigo" << endl;
		cout << "3: Alterar Data de nascimento" << endl;
		cout << "4: Alterar Telefome" << endl;
		cout << "5: Alterar Morada" << endl;
		cout << "6: Alterar Curso" << endl;
		cout << "7: Gerir a pauta" << endl;
		cout << "8: Voltar" << endl << endl;

		cout << "Escolha uma das opcoes: ";
		escolha = int_input_errorHandler();

		if (escolha == 1) {
			string nome;
			system("CLS");
			cout << "Nome atual: " << this->getNome() << endl << endl;
			cout << "Novo nome: ";
			nome = string_input_errorHandler();
			this->setNome(nome);
		}

		else if (escolha == 2) {
			int cod;
			system("CLS");
			cout << "Codigo atual: " << this->getCodigo() << endl << endl;
			cout << "Novo Codigo: ";
			cod = int_input_errorHandler();
			this->setCodigo(cod);
		}

		else if (escolha == 3) {
			int ano, mes, dia;
			system("CLS");
			cout << "Data de nascimento atual: " << this->getDataNascimento().ano <<"/" << getDataNascimento().mes << getDataNascimento().dia << endl << endl;
			cout << "Novo Ano: ";
			ano = int_input_errorHandler();
			cout << "Novo Mes: ";
			mes = int_input_errorHandler();
			cout << "Novo Dia: ";
			dia = int_input_errorHandler();
			struct dataNascimento novo = { ano, mes, dia };
			this->setDataNascimento(novo);
		}

		else if (escolha == 4) {
			int telefone;
			system("CLS");
			cout << "Telefone atual: " << this->getTelefone() << endl;
			cout << "Novo telefone : ";
			telefone = int_input_errorHandler();
			this->setTelefone(telefone);
		}

		else if (escolha == 5) {
			string morada;
			system("CLS");
			cout << "Morada atual: " << this->getMorada() << endl << endl;
			cout << "Nova morada: ";
			morada = string_input_errorHandler();
			this->setMorada(morada);
		}

		else if (escolha == 6) {
			string curso;
			system("CLS");
			cout << "Curso atual: " << this->getCurso() << endl;
			cout << "Novo curso: ";
			curso = string_input_errorHandler();
			this->setCurso(curso);
		}

		else if (escolha == 7) {
			managePauta();
		}

	} while (escolha != 8);
}

void Estudante::managePauta() {
	unsigned int escolha;
	do {
		try {
			system("CLS");
			cout << "Estas na pauta do estudante: " << this->getNome() << " // " << this->getCodigo() << endl;
			cout << "Media: " << getMedia() << endl;
			cout << "O que queres fazer?" << endl << endl;

			cout << "1: Ver pauta" << endl;
			cout << "2: Adicionar uma cadeira" << endl;
			cout << "3: Adicionar/Alterar uma nota a uma cadeira" << endl;
			cout << "4: Voltar" << endl << endl;

			cout << "Escolha uma das opcoes: ";
			escolha = int_input_errorHandler();

			if (escolha == 1) {
				system("CLS");
				showDisciplinas();
				system("pause");
			}

			else if (escolha == 2) {
				string cadeira;
				system("CLS");
				cout << "Estas na pauta do estudante: " << this->getNome() << " // " << this->getCodigo() << endl;
				cout << "Media: " << getMedia() << endl << endl;

				cout << "Que disciplina queres adicionar?" << endl;
				cadeira = string_input_errorHandler();

				addDisciplina(cadeira);
			}

			else if (escolha == 3) {
				string cadeira;
				int nota;
				system("CLS");
				cout << "Estas na pauta do estudante: " << this->getNome() << " // " << this->getCodigo() << endl;
				cout << "Media: " << getMedia() << endl << endl;

				cout << "De que disciplina queres alterar a nota?" << endl;
				cadeira = string_input_errorHandler();

				cout << endl << "Qual e a nova nota?" << endl;
				nota = int_input_errorHandler();
				setNota(cadeira, nota);
			}
		}
		catch (NoDisciplina exp) {
			exp.mensagem();
		}
	} while (escolha != 4);
}

void Estudante::setAno(int ano) {
	this->ano = ano;
}

int Estudante::getAno() const {
	return ano;
}

bool Estudante::operator<(const Estudante* est) const {
	if (strcmp(this->getCurso().c_str(), est->getCurso().c_str()) < 0) return true;
	else if (strcmp(this->getCurso().c_str(), est->getCurso().c_str()) > 0) return false;
	else {
		if (strcmp(this->getNome().c_str(), est->getNome().c_str()) < 0) return true;
		else if (strcmp(this->getNome().c_str(), est->getNome().c_str()) > 0) return false;
		else return false;
	}
}

bool Estudante::operator==(const Estudante &est) const {
	if (this->getNome() == est.getNome()) return true;
	else return false;
}
