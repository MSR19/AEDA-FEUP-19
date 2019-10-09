#include "Pessoa.h"

#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

class Funcionario: public Pessoa {
private:
	int contribuinte;
	int salario;
public:
	Funcionario(string nom = "<undefined_name>", string mor = "<undefined_adress>", int tele = 0, struct dataNascimento dataNas = { 0,0,0 },
		int cod = 0, int cont = 0, int sal = 0);
	int getContribuinte() const;
	bool setContribuinte(int contribu);

	int getSalario() const;
	bool setSalario(int salar);
};

#endif
