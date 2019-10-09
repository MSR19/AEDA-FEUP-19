
#include "Faculdade.h"

Faculdade::Faculdade() {	
}

Faculdade::Faculdade(Pessoal* p, vector<Departamento*> dep) {
	pessoal = p;
	departamentos = dep;
}


Pessoal* Faculdade::getPessoal() const
{
	return pessoal;
}

vector<Departamento*> Faculdade::getDepartamentos() const {
	return departamentos;
}

bool Faculdade::setDepartamentos(vector<Departamento*> departamentos) {
	this->departamentos = departamentos;

	return this->departamentos == departamentos;
}

bool Faculdade::addDepartamento(Departamento* departamento) {
	try {
		findDepartamento(departamento->getNome());
	}
	catch (NoDepartamento exp) {
		departamentos.push_back(departamento);
		return true;
	}
	throw DepartamentoRepetido(departamento->getNome());
}

bool Faculdade::removeDepartamento(Departamento* departamento) {
	vector<Departamento*>::iterator it = find(departamentos.begin(), departamentos.end(), departamento);
	if (it != departamentos.end())
		departamentos.erase(it);
	else return false;

	it = find(departamentos.begin(), departamentos.end(), departamento);
	if (it == departamentos.end()) return true;
	else return false;
}

Departamento* Faculdade::findDepartamento(string nome) const {
	for (unsigned int i = 0; i < departamentos.size(); i++) {
		if (departamentos[i]->getNome() == nome) {
			return departamentos[i];
		}
	}
	throw NoDepartamento(nome);
}

void Faculdade::showDepartamentos() {
	sort( departamentos.begin(), departamentos.end(), ComparaDepartamentos());
	cout << "Lista de departamentos: " << endl;
	for (unsigned int i = 0; i < departamentos.size(); i++) {
		cout << i + 1 << ":  " << departamentos[i]->getNome() << endl;
	}
}

void Faculdade::manage() {
	unsigned int escolha;
	do {
		system("CLS");
		cout << "Estas em: Faculdade" << endl;
		cout << "O que queres fazer?" << endl << endl;

		cout << "1: Manage departamentos" << endl;
		cout << "2: Manage funcionarios" << endl;
		cout << "3: Sair e exportar para ficheiro" << endl << endl;
		cout << "Escolha uma das opcoes: ";
		escolha = int_input_errorHandler();

		if (escolha == 1) {
			manageDepartamentos();
		}
		if (escolha == 2) {
			managePessoal();
		}
	}while(escolha != 3);

	return;
}

void Faculdade::manageDepartamentos() {
	unsigned int escolha;
	do {
		try {
			system("CLS");
			cout << "Estas em: Lista de departamentos" << endl;
			cout << "O que queres fazer?" << endl << endl;

			cout << "1: Adicionar um departamento" << endl;
			cout << "2: Remover um departamento" << endl;
			cout << "3: Ver os departamentos disponiveis" << endl;
			cout << "4: Gerir um departamento" << endl;
			cout << "5: Voltar" << endl << endl;

			cout << "Escolha uma das opcoes: ";
			escolha = int_input_errorHandler();

			if (escolha == 1) {
				string nomeDepartamento;
				system("CLS");
				cout << "Digite o nome do departamento: ";
				nomeDepartamento = string_input_errorHandler();
				Departamento* novo = new Departamento(pessoal, nomeDepartamento);
				addDepartamento(novo);
			}
			else if (escolha == 2) {
				string nomeDepartamento;
				system("CLS");
				cout << "Digite o nome do departamento: ";
				nomeDepartamento = string_input_errorHandler();
				removeDepartamento(findDepartamento(nomeDepartamento));

			}
			else if (escolha == 3) {
				system("CLS");
				showDepartamentos();
				system("pause");
			}
			else if (escolha == 4) {
				string nomeDepartamento;
				system("CLS");
				cout << "Digite o nome do departamento: ";
				nomeDepartamento = string_input_errorHandler();
				findDepartamento(nomeDepartamento)->manage();
			}
		}
		catch (NoDepartamento exp) {
			exp.mensagem();
		}
		catch (DepartamentoRepetido exp) {
			exp.mensagem();
		}
	} while (escolha!= 5);
	return;
}

void Faculdade::managePessoal() {
	pessoal->manage();
}
