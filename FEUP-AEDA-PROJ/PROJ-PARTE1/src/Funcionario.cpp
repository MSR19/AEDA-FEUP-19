
#include"Funcionario.h"

Funcionario::Funcionario(string nom, string mor, int tele, struct dataNascimento dataNas,
	int cod, int cont, int sal):
	Pessoa(nom, mor, tele, dataNas, cod)
{
	contribuinte = cont;
	salario = sal;
}

int Funcionario::getContribuinte() const {
	return contribuinte;
}

bool Funcionario::setContribuinte(int contribuinte) {
	this->contribuinte = contribuinte;

	return this->contribuinte == contribuinte;
}

int Funcionario::getSalario() const {
	return salario;
}

bool Funcionario::setSalario(int salario) {
	this->salario = salario;

	return this->salario == salario;
}