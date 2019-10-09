#include "NDocente.h"
NDocente::NDocente(string nom,int cod, string mor, int tele, struct dataNascimento dataNas,
	 int cont, int sal, string areaT) :
	Funcionario(nom, mor, tele, dataNas, cod, cont, sal)
{
	areaTrabalho = areaT;
}

string NDocente::getAreaTrabalho() const
{
	return areaTrabalho;
}

bool NDocente::setAreaTrabalho(string areaT)
{
	areaTrabalho = areaT;

	return true;
}

void NDocente::manage() {
	int escolha;
	do {
		system("CLS");
		cout << "Esta no funcionario: " << this->getNome() << " // " << this->getCodigo() << endl;
		cout << "Dados: " << "Area de trbalho: " << getAreaTrabalho() << endl;
		cout << "Data de nascimento: " << getDataNascimento().ano << "/" << getDataNascimento().mes << "/" << getDataNascimento().dia << endl;
		cout << "Telefone: " << getTelefone() << " / Morada: " << getMorada() << endl;
		cout << "Numero de Contribuinte: " << getContribuinte() << " / Salario: " << getSalario() << endl;
		cout << "O que quer fazer?" << endl << endl;

		cout << "1: Alterar os dados do funcionario" << endl;
		cout << "2: Voltar" << endl << endl;

		cout << "Escolha uma opcao: ";
		escolha = int_input_errorHandler();

		if (escolha == 1) {
			int escolha3;
			do {
				system("CLS");
				cout << "Esta no funcionario: " << this->getNome() << " // " << this->getCodigo() << endl;
				cout << "Dados: " << "Area de trbalho: " << getAreaTrabalho() << endl;
				cout << "Data de nascimento: " << getDataNascimento().ano << "/" << getDataNascimento().mes << "/" << getDataNascimento().dia << endl;
				cout << "Telefone: " << getTelefone() << " / Morada: " << getMorada() << endl;
				cout << "Numero de Contribuinte: " << getContribuinte() << " / Salario: " << getSalario() << endl;
				cout << "O que quer fazer?" << endl << endl;

				cout << "1: Alterar o Nome" << endl;
				cout << "2: Alterar o Codigo" << endl;
				cout << "3: Alterar Data de Nascimento" << endl;
				cout << "4: Alterar Telefone" << endl;
				cout << "5: ALterar a Morada" << endl;
				cout << "6: Alterar o Numero de Contribuinte" << endl;
				cout << "7: Alterar Salario" << endl;
				cout << "8: Alterar area de trabalho" << endl;
				cout << "9: voltar" << endl << endl;

				cout << "Escolha uma das opcoes: ";
				escolha3 = int_input_errorHandler(); 

				if (escolha3 == 1) {
					system("CLS");
					string nome;
					cout << "Nome atual: " << this->getNome() << endl << endl;
					cout << "Novo nome: ";
					nome = string_input_errorHandler();
					this->setNome(nome);
				}
				else if (escolha3 == 2) {
					system("CLS");
					int codigo;
					cout << "Codigo atual: " << this->getCodigo() << endl << endl;
					cout << "Novo codigo : ";
					codigo = int_input_errorHandler();
					this->setCodigo(codigo);
				}

				else if (escolha3 == 3) {
					system("CLS");
					int ano, mes, dia;
					cout << "Data de nascimento atual: " << this->getDataNascimento().ano << "/" << getDataNascimento().mes << getDataNascimento().dia << endl << endl;
					cout << "Novo Ano: ";
					ano = int_input_errorHandler(1800, 2125);
					cout << "Novo Mes: ";
					mes = int_input_errorHandler(1,12);
					cout << "Novo Dia: ";
					dia = int_input_errorHandler(1, 31);
					struct dataNascimento novo = { ano, mes, dia };
					this->setDataNascimento(novo);
				}

				else if (escolha3 == 4) {
					system("CLS");
					int telefone;
					cout << "Telefone atual: " << this->getTelefone() << endl;
					cout << "Novo telefone: ";
					telefone = int_input_errorHandler();
					this->setTelefone(telefone);
				}

				else if (escolha3 == 5) {
					system("CLS");
					string morada;
					cout << "Morada atual: " << this->getMorada() << endl;
					cout << "Nova morada: ";
					morada = string_input_errorHandler();
					this->setMorada(morada);
				}

				else if (escolha3 == 6) {
					system("CLS");
					int cont;
					cout << "Numero de contribuinte atual: " << this->getContribuinte() << endl;
					cout << "Novo contribuinte: ";
					cont = int_input_errorHandler();
					this->setContribuinte(cont);
				}

				else if (escolha3 == 7) {
					system("CLS");
					int sal;
					cout << "Salario atual: " << this->getSalario() << endl;
					cout << "Novo salario: ";
					sal = int_input_errorHandler();
					this->setSalario(sal);
				}

				else if (escolha3 == 8) {
					system("CLS");
					string area;
					cout << "Area de trabalho atual: " << this->getAreaTrabalho() << endl;
					cout << "Novo area de trbalho: ";
					area = string_input_errorHandler();
					this->setAreaTrabalho(area);
				}

			} while (escolha3 != 9);
		}
		
	}while (escolha != 2);
}
