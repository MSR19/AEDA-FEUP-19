#include "Curso.h"

Curso::Curso(Pessoal* p, string nom, int cod, string tip, vector<Disciplina*> v ){
	tipo = tip;
	codigo = cod;
	nome = nom;
	pessoal = p;
	disciplinas = v;
	diretor = new Docente();
}

string Curso::getTipo() const {
	return tipo;
}

bool Curso::setTipo(string tipo) {
	this->tipo = tipo;

	return true;
}

int Curso::getCodigo() const {
	return codigo;
}

bool Curso::setCodigo(int codigo) {
	this->codigo = codigo;

	return true;
}

string Curso::getNome() const {
	return nome;
}

bool Curso::setNome(string nome) {
	this->nome = nome;

	return true;
}

Docente* Curso::getDiretor() const {
	return diretor;
}

bool Curso::setDiretor(Docente* diretor) {
	this->diretor = diretor;

	return true;
}

vector<Disciplina*> Curso::getDisciplinas() const {
	return disciplinas;
}

bool Curso::setDisciplinas(vector<Disciplina*> disciplinas) {
	this->disciplinas = disciplinas;

	return this->disciplinas == disciplinas;
}

bool Curso::addDisciplina(Disciplina* disciplina) {
	try {
		findDisciplinaPT(disciplina->getNomePortugues());
		findDisciplinaEN(disciplina->getNomeIngles());
	}
	catch (NoDisciplina exp) {
		disciplina->setCurso(this->getNome());
		disciplinas.push_back(disciplina);
		return true;
	}
	if (disciplina->getNomePortugues() != "<undefined_pt_name>")
	throw DisciplinaRepetida(disciplina->getNomePortugues());
	else throw DisciplinaRepetida(disciplina->getNomeIngles());
}

bool Curso::removeDisciplina(Disciplina* disciplina) {
	vector<Disciplina*>::iterator it1 = find(disciplinas.begin(), disciplinas.end(), disciplina);
	if (it1 != disciplinas.end())
		disciplinas.erase(it1);
	else return false;

	vector<Disciplina*>::iterator it2 = find(disciplinas.begin(), disciplinas.end(), disciplina);
	if (it2 == disciplinas.end()) return true;
	else return false;
}

Disciplina* Curso::findDisciplinaPT(string nomeDisciplina) const {
	for (unsigned int i = 0; i < disciplinas.size(); i++) {
		if (disciplinas[i]->getNomePortugues() == nomeDisciplina) {
			return disciplinas[i];
		}
	}
	throw NoDisciplina(nomeDisciplina);
}

Disciplina* Curso::findDisciplinaEN(string nomeDisciplina) const {
	for (unsigned int i = 0; i < disciplinas.size(); i++) {
		if (disciplinas[i]->getNomeIngles() == nomeDisciplina) {
			return disciplinas[i];
		}
	}
	throw NoDisciplina(nomeDisciplina);
}

void Curso::showDisciplinas() {
	sort(disciplinas.begin(), disciplinas.end(), ComparaDisciplinas());
	cout << "Lista de displinas: " << endl;
	for (unsigned int i = 0; i < disciplinas.size(); i++) {
		cout << i + 1 << ":  " << disciplinas[i]->getNomePortugues() << " // "<< disciplinas[i]->getNomeIngles() << " // Ano " << disciplinas[i]->getAno()<< endl;
	}
}

void Curso::manage() {
	unsigned int escolha;
	do {
		system("CLS");
		cout << "Estas em " << this->getTipo() << " de " << this->getNome() << " // " << this->getCodigo() << endl;
		cout << "Diretor: " << this->getDiretor()->getNome() << " " << this->getDiretor()->getCodigo() << endl;
		cout << "O que queres fazer?" << endl << endl;

		cout << "1: Alterar Curso" << endl;
		cout << "2: Manage Diciplinas" << endl;
		cout << "3: Voltar" << endl << endl;

		cout << "Escolha uma das opcoes: ";
		escolha = int_input_errorHandler();

		if (escolha == 1) {
			manageCurso();
		}

		else if (escolha == 2) {
			manageDisciplinas();
		}

	} while (escolha != 3);
}

void Curso::manageCurso() {
	unsigned int escolha;
	do {
		try {
			system("CLS");
			cout << "Estas em " << this->getTipo() << " de " << this->getNome() << "  // " << this->getCodigo() << endl;
			cout << "Diretor: " << this->getDiretor()->getNome() << " " << this->getDiretor()->getCodigo() << endl;
			cout << "O que queres fazer?" << endl << endl;

			cout << "1: Alterar codigo" << endl;
			cout << "2: Alterar nome" << endl;
			cout << "3: Alterar Tipo" << endl;
			cout << "4: Alterar/Modificar diretor" << endl;
			cout << "5: Voltar" << endl << endl;

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
				int tipo;
				system("CLS");
				cout << "Tipo atual: " << getTipo() << endl << endl;

				cout << "De que tipo e o curso?" << endl;
				cout << "1: Licenciatura" << endl;
				cout << "2: Mestrado" << endl;
				cout << "3: Mestrado Integrado" << endl << endl;
				tipo = int_input_errorHandler();
				if (tipo == 1) {
					setTipo("Licenciatura");
				}
				else if (tipo == 2) {
					setTipo("Mestrado");
				}
				else if (tipo == 3) {
					setTipo("Mestrado_Integrado");
				}
			}
			else if (escolha == 4) {
				int resposta;
				system("CLS");
				cout << "Diretor atual: " << this->getDiretor()->getNome() << " " << this->getDiretor()->getCodigo() << endl;
				cout << "O que queres fazer?" << endl;
				cout << "1: Modificar o diretor atual" << this->getDiretor()->getNome() << endl;
				cout << "2: Alterar o diretor atual, no entanto ele ja existe no sistema" << this->getDiretor()->getNome() << endl;
				cout << "3: Alterar o diretor atual, no entanto ele não existe no sistema" << endl <<endl;

				cout << "Escolha uma das opcoes: ";
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
	} while (escolha != 5);
}

void Curso::manageDisciplinas() {
	unsigned int escolha2;
	do {
		try {
			system("CLS");
			cout << "Estas em " << this->getTipo() << " de " << this->getNome() << "  // " << this->getCodigo() << endl;
			cout << "O que queres fazer?" << endl << endl;

			cout << "1: Adicionar uma disciplina" << endl;
			cout << "2: Remover uma disciplina" << endl;
			cout << "3: Ver disciplinas existentes" << endl;
			cout << "4: Gerir as disciplinas" << endl;
			cout << "5: voltar" << endl << endl;

			cout << "Escolha uma das opcoes: ";
			escolha2 = int_input_errorHandler();

			if (escolha2 == 1) {
				string nomedis;
				int lingua;
				system("CLS");
				cout << "Digite o nome da discipliana: ";
				nomedis = string_input_errorHandler();
				cout << endl << "O nome esta em que lingua?" << endl;
				cout << "1: Portugues" << endl;
				cout << "2: Ingles" << endl;
				lingua = int_input_errorHandler();
				if (lingua == 1) {
					Disciplina* novo = new Disciplina(pessoal);
					novo->setNomePortugues(nomedis);
					addDisciplina(novo);
				}
				else if (lingua == 2) {
					Disciplina* novo = new Disciplina(pessoal);
					novo->setNomeIngles(nomedis);
					addDisciplina(novo);
				}
			}
			else if (escolha2 == 2) {
				string nomedis;
				int lingua;
				system("CLS");
				cout << "Digite o nome do curso: ";
				nomedis = string_input_errorHandler();
				cout << endl << "O nome esta em que lingua?" << endl;
				cout << "1: Portugues" << endl;
				cout << "2: Ingles" << endl;
				lingua = int_input_errorHandler();
				if (lingua == 1)
					removeDisciplina(findDisciplinaPT(nomedis));
				else if (lingua == 2)
					removeDisciplina(findDisciplinaEN(nomedis));
			}
			else if (escolha2 == 3) {
				system("CLS");
				showDisciplinas();
				system("pause");
			}
			else if (escolha2 == 4) {
				string nomedis;
				int lingua;
				system("CLS");
				cout << "Digite o nome da disciplina: ";
				nomedis = string_input_errorHandler();
				cout << endl << "O nome esta em que lingua?" << endl;
				cout << "1: Portugues" << endl;
				cout << "2: Ingles" << endl;
				lingua = int_input_errorHandler();
				if (lingua == 1)
					findDisciplinaPT(nomedis)->manage();
				else if (lingua == 2)
					findDisciplinaEN(nomedis)->manage();
			}
		}
		catch (NoDisciplina exp) {
			exp.mensagem();
		}
		catch (DisciplinaRepetida exp) {
			exp.mensagem();
		}
	} while (escolha2 != 5);
}

