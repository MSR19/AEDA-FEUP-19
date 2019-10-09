#include "Docente.h"

Docente::Docente(string nom,int cod, string mor, int tele, struct dataNascimento dataNas,
	 int cont, int sal, string cat, vector<string> dis): 
	Funcionario(nom, mor, tele, dataNas, cod, cont, sal)
{
	categoria = cat;
	disciplinas = dis;
}

string Docente::getCategoria() const {
	return categoria;
}

bool Docente::setCategoria(string categoria) {
	this->categoria = categoria;

	return this->categoria == categoria;
}

vector<string> Docente::getDisciplinas() const {
	return disciplinas;
}

bool Docente::setDisciplinas(vector<string> disciplinas) {
	this->disciplinas = disciplinas;

	return this->disciplinas == disciplinas;
}

bool Docente::addDisciplina(string disciplina) {
	vector<string>::iterator it = find(disciplinas.begin(), disciplinas.end(), disciplina);
	if (it == disciplinas.end()) disciplinas.push_back(disciplina);
	else {
		throw DisciplinaRepetida(disciplina);
		return false; 
	}

	it = find(disciplinas.begin(), disciplinas.end(), disciplina);
	if (it != disciplinas.end()) return true;
	else return false;
}

bool Docente::removeDisciplina(string disciplina) {
	vector<string>::iterator it = find(disciplinas.begin(), disciplinas.end(), disciplina);
	if (it != disciplinas.end()) disciplinas.erase(it);
	else { 
		throw NoDisciplina(disciplina);
		return false; 
	}

	it = find(disciplinas.begin(), disciplinas.end(), disciplina);
	if (it == disciplinas.end()) return true;
	else return false;
}

void Docente::showDisciplinas() const {
	cout << "Lista de disciplinas:" << endl;
	for (unsigned int i = 0; i < disciplinas.size(); i++) {
		cout << i + 1 << ": " << disciplinas[i] << endl;
	}
}

	void Docente::manage() {
		unsigned int escolha;
		do {
			system("CLS");
			cout << "Estas no docente: " << this->getNome() << " // " << this->getCodigo() << endl;
			cout << "Dados: " << " Morada: " << getMorada() << endl;
			cout << "Data de nascimento: " << getDataNascimento().ano << "/" << getDataNascimento().mes << "/" << getDataNascimento().dia << " / Telefone: " << getTelefone() << endl;
			cout << "Numero de Contribuinte: " << getContribuinte() << " / Salario: " << getSalario() << endl;
			cout << "Categoria: " << getCategoria() << endl;
			cout << "O que quer fazer?" << endl << endl;

			cout << "1: Alterar os dados do docente" << endl;
			cout << "2: Ver a lista de disciplinas lecionadas pelo docente" << endl;
			cout << "3: Voltar" << endl << endl;

			cout << "Escolha uma opcao: ";
			escolha = int_input_errorHandler();

			if (escolha == 1) {
				int escolha1;
				do {
					system("CLS");
					cout << "Estas no docente: " << this->getNome() << " // " << this->getCodigo() << endl;
					cout << "Dados: " << " Morada: " << getMorada() << endl;
					cout << "Data de nascimento: " << getDataNascimento().ano << "/" << getDataNascimento().mes << "/" << getDataNascimento().dia << " / Telefone: " << getTelefone() << endl;
					cout << "Numero de Contribuinte: " << getContribuinte() << " / Salario: " << getSalario() << endl;
					cout << "Categoria: " << getCategoria() << endl;
					cout << "O que quer fazer?" << endl << endl;

					cout << "1: Alterar o Nome" << endl;
					cout << "2: Alterar o Codigo" << endl;
					cout << "3: Alterar Data de Nascimento" << endl;
					cout << "4: Alterar Telefone" << endl;
					cout << "5: ALterar a Morada" << endl;
					cout << "6: Alterar o Numero de Contribuinte" << endl;
					cout << "7: Alterar Salario" << endl;
					cout << "8: Alterar Categoria" << endl;
					cout << "9: Alterar a lista de disciplinas" << endl;
					cout << "10: voltar" << endl << endl;

					cout << "Escolha uma opcao: ";
					escolha1 = int_input_errorHandler();

					if (escolha1 == 1) {
						system("CLS");
						string nome;
						cout << "Nome atual: " << this->getNome() << endl << endl;
						cout << "Novo nome: ";
						nome = string_input_errorHandler();
						this->setNome(nome);
					}
					else if (escolha1 == 2) {
						system("CLS");
						int codigo;
						cout << "Codigo atual: " << this->getCodigo() << endl << endl;
						cout << "Novo codigo : ";
						codigo = int_input_errorHandler();
						this->setCodigo(codigo);
					}

					else if (escolha1 == 3) {
						system("CLS");
						int ano, mes, dia;
						cout << "Data de nascimento atual: " << this->getDataNascimento().ano << "/" << getDataNascimento().mes << getDataNascimento().dia << endl << endl;
						cout << "Novo Ano: ";
						ano = int_input_errorHandler();
						cout << "Novo Mes: ";
						mes = int_input_errorHandler();
						cout << "Novo Dia: ";
						dia = int_input_errorHandler();
						struct dataNascimento novo = { ano, mes, dia };
						this->setDataNascimento(novo);
					}

					else if (escolha1 == 4) {
						system("CLS");
						int telefone;
						cout << "Telefone atual: " << this->getTelefone() << endl;
						cout << "Novo telefone: ";
						telefone = int_input_errorHandler();
						this->setTelefone(telefone);
					}

					else if (escolha1 == 5) {
						system("CLS");
						string morada;
						cout << "Morada atual: " << this->getMorada() << endl;
						cout << "Nova morada: ";
						morada = string_input_errorHandler();
						this->setMorada(morada);
					}

					else if (escolha1 == 6) {
						system("CLS");
						int cont;
						cout << "Numero de contribuinte atual: " << this->getContribuinte() << endl;
						cout << "Novo contribuinte: ";
						cont = int_input_errorHandler();
						this->setContribuinte(cont);
					}

					else if (escolha1 == 7) {
						system("CLS");
						int sal;
						cout << "Salario atual: " << this->getSalario() << endl;
						cout << "Novo salario: ";
						sal = int_input_errorHandler();
						this->setSalario(sal);
					}

					else if (escolha1 == 8) {
						system("CLS");
						string categ;
						cout << "Categoria Atual: " << getCategoria() << endl;
						cout << "Nova Categoria: ";
						categ = string_input_errorHandler();
						this->setCategoria(categ);
					}

					else if (escolha1 == 9) {
						try {
							system("CLS");
							int escolha2;
							cout << "Aqui pode alterar a lista de disciplinas que o docente leciona." << endl;
							cout << "O que pertende fazer?" << endl << endl;

							cout << "1: Limpar a lista" << endl; 
							cout << "2: Eliminar uma disciplina da lista" << endl;
							cout << "3: Adicionar uma disciplina a lista" << endl << endl;
							cout << "Escolha uma opcao: ";
							escolha2 = int_input_errorHandler();

							if (escolha2 == 1) {
								disciplinas.clear();
							}

							else if (escolha2 == 2) {
								string disc;
								cout << "Qual quer eliminar?";
								disc = string_input_errorHandler();
								this->removeDisciplina(disc);
							}

							else if (escolha2 == 3) {
								string disc;
								cout << "Qual quer adicionar?";
								disc = string_input_errorHandler();
								this->addDisciplina(disc);
							}
						}
						catch (NoDisciplina exp) {
							exp.mensagem();
						}
						catch (DisciplinaRepetida exp) {
							exp.mensagem();
						}
					}
				}while (escolha1 != 10);
			}
			
			else if (escolha == 2) {
				system("CLS");
				this->showDisciplinas();
				system("pause");
			}

		}while (escolha != 3);
	}

