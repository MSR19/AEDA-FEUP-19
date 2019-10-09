#include "Departamento.h"

Departamento::Departamento(Pessoal* p, string nom, int cod, string adress, int tel, vector<Curso*> v) {
	pessoal = p;
	nome = nom;
	codigo = cod;
	morada = adress;
	telefone = tel;
	cursos = v; 
	diretor = new Docente();
}

int Departamento::getCodigo() const {
	return codigo;
}

bool Departamento::setCodigo(int codigo) {
	this->codigo = codigo;

	return true;
}

string Departamento::getNome() const {
	return nome;
}

bool Departamento::setNome(string nome) {
	this->nome = nome;

	return true;
}

string Departamento::getMorada() const {
	return morada;
}

bool Departamento::setMorada(string morada) {
	this->morada = morada;

	return true;
}

int Departamento::getTelefone() const {
	return telefone;
}

bool Departamento::setTelefone(int telefone) {
	this->telefone = telefone;

	return true;
}

Docente* Departamento::getDiretor() const {
	return diretor;
}

bool Departamento::setDiretor(Docente* diretor) {
	this->diretor = diretor;

	return true;
}

vector<Curso*> Departamento::getCursos() const {
	return cursos;
}

bool Departamento::setCursos(vector<Curso*> cursos) {
	this->cursos = cursos;

	return true;
}

bool Departamento::addCurso(Curso* curso) {
	try {
		findCurso(curso->getNome());
	}
	catch(NoCurso exp) {
		cursos.push_back(curso);
		return true;
	}
	throw CursoRepetido(curso->getNome());
}

bool Departamento::removeCurso(Curso* curso) {
	vector<Curso*>::iterator it= find(cursos.begin(), cursos.end(), curso);
	if (it != cursos.end())
		cursos.erase(it);
	else return false;

	it = find(cursos.begin(), cursos.end(), curso);
	if(it == cursos.end()) return true;
	else return false;
}

Curso* Departamento::findCurso(string nome) const {
	for (unsigned int i = 0; i < cursos.size(); i++) {
		if (cursos[i]->getNome() == nome) {
			return cursos[i];
		}
	}
	throw NoCurso(nome);
}

void Departamento::showCursos() {
	sort(cursos.begin(), cursos.end(), ComparaCursos());
	cout << "Lista de cursos:" << endl;
	for (unsigned int i = 0; i < cursos.size(); i++) {
		cout << i + 1 << ": " << cursos[i]->getNome()  <<endl;
	}
	return;
}

void Departamento::manage() {
	unsigned int escolha;
	do {
		system("CLS");
		cout << "Estas no Departamento: " << this->getNome() << " " << this->getCodigo()<< endl;
		cout << "Dados: " << this->getMorada() << " e " << this->getTelefone() << endl;
		cout << "Diretor: " << this->getDiretor()->getNome() << " " << this->getDiretor()->getCodigo() << endl;
		cout << "O que queres fazer?" << endl << endl;

		cout << "1: Alterar Departamento" << endl;
		cout << "2: Manage Cursos" << endl;
		cout << "3: Voltar" << endl << endl;
		cout << "Ecolha uma das opcoes: ";
		escolha = int_input_errorHandler();

		if (escolha == 1) {
			manageDepartamento();
		}
		else if (escolha == 2) {
			manageCursos();
		}
	} while (escolha != 3);
}

void Departamento::manageDepartamento() {
	unsigned int escolha;
	do {
		try {
			system("CLS");
			cout << "Estas no Departamento: " << this->getNome() << " // " << this->getCodigo() << endl;
			cout << "Dados: " << "Morada: " << this->getMorada() << " / Telefone: " << this->getTelefone() << endl;
			cout << "Diretor: " << getDiretor()->getNome() << " " << getDiretor()->getCodigo() << endl;
			cout << "O que queres fazer?" << endl << endl;

			cout << "1: Alterar codigo" << endl;
			cout << "2: Alterar nome" << endl;
			cout << "3: Alterar morada" << endl;
			cout << "4: Alterar telefone" << endl;
			cout << "5: Alterar/Modificar diretor" << endl;
			cout << "6: Voltar" << endl << endl;

			cout << "Escolha uma das opcoes: ";
			escolha = int_input_errorHandler();

			if (escolha == 1) {
				int cod;
				system("CLS");
				cout << "Codigo atual: " << this->getCodigo() << endl << endl;
				cout << "Novo Codigo: ";
				cod = int_input_errorHandler();
				this->setCodigo(cod);
			}
			else if (escolha == 2) {
				string nom;
				system("CLS");
				cout << "Nome atual: " << this->getNome() << endl << endl;
				cout << "Novo nome: ";
				nom = string_input_errorHandler();
				this->setNome(nom);
			}
			else if (escolha == 3) {
				string mora;
				system("CLS");
				cout << "Morada atual: " << this->getMorada() << endl << endl;
				cout << "Novo morada: ";
				mora = string_input_errorHandler();
				this->setMorada(mora);
			}
			else if (escolha == 4) {
				int tele;
				system("CLS");
				cout << "Telefone atual: " << this->getTelefone() << endl << endl;
				cout << "Novo telefone: ";
				tele = int_input_errorHandler();
				this->setTelefone(tele);
			}
			else if (escolha == 5) {
				int resposta;
				system("CLS");
				cout << "Diretor atual: " << getDiretor()->getNome() << " " << getDiretor()->getCodigo() << endl;
				cout << "O que quer fazer?" << endl;
				cout << "1: Modificar o diretor atual" << getDiretor()->getNome() << endl;
				cout << "2: Alterar o diretor atual, no entanto ele ja existe no sistema" << getDiretor()->getNome() << endl;
				cout << "3: Alterar o diretor atual, no entanto ele não existe no sistema" << endl;
				cout << "Ecolha uma das opcoes: ";
				resposta = int_input_errorHandler();
				if (resposta == 1) {
					this->getDiretor()->manage();
				}
				else if (resposta == 2) {
					string nome;
					system("CLS");
					cout << "Qual e o nome do novo diretor?" << endl;
					nome = string_input_errorHandler();
					setDiretor(pessoal->findDocente(nome));
				}
				else if (resposta == 3) {
					string nome;
					system("CLS");
					cout << "Qual e o nome do novo diretor?" << endl;
					nome = string_input_errorHandler();
					Docente* x = new Docente(nome);
					pessoal->addDocente(x);
					this->setDiretor(x);
				}
			}
		}
		catch (NoDocente exp) {
			exp.mensagem();
		}
	} while (escolha != 6);
}

void Departamento::manageCursos() {
	unsigned int escolha;
	do {
		try {
			system("CLS");
			cout << "Estas nos Cursos do Departamento " << getNome() << " // " << getCodigo() <<  endl;
			cout << "O que queres fazer?" << endl << endl;

			cout << "1: Adicionar um curso" << endl;
			cout << "2: Remover um curso" << endl;
			cout << "3: Ver os cursos existentes" << endl;
			cout << "4: Manage curso" << endl;
			cout << "5: voltar" << endl << endl;

			cout << "Escolha uma das opcoes: ";
			escolha = int_input_errorHandler();

			if (escolha == 1) {
				string nomecur;
				system("CLS");
				cout << "Digite o nome do curso: ";
				nomecur = string_input_errorHandler();
				Curso* novo = new Curso(pessoal, nomecur);
				addCurso(novo);
			}
			else if (escolha == 2) {
				string nomecur;
				system("CLS");
				cout << "Digite o nome do curso: ";
				nomecur = string_input_errorHandler();
				removeCurso(findCurso(nomecur));
			}
			else if (escolha == 3) {
				system("CLS");
				showCursos();
				system("pause");
			}
			else if (escolha == 4) {
				string nomecur;
				system("CLS");
				cout << "Digite o nome do curso: ";
				nomecur = string_input_errorHandler();
				findCurso(nomecur)->manage();
			}
		}
		catch (NoCurso exp) {
			exp.mensagem();
		}
		catch (CursoRepetido exp) {
			exp.mensagem();
		}
	} while (escolha != 5);
}
