#include <stdlib.h>

#include "Departamento.h"

#ifndef FACULDADE_H
#define FACULDADE_H

class Faculdade {
private:
	vector<Departamento*> departamentos;
	Pessoal* pessoal;

public:
	Faculdade();
	Faculdade(Pessoal* p, vector<Departamento*> dep = {});

	Pessoal* getPessoal() const;
	vector<Departamento*> getDepartamentos() const;
	bool setDepartamentos(vector<Departamento*> departamentos);
	bool addDepartamento(Departamento* departamento);
	bool removeDepartamento(Departamento* departamento);
	Departamento* findDepartamento(string nome) const;
	void showDepartamentos();


	void manage();
private:
	void manageDepartamentos();
	void managePessoal();
};

struct ComparaDepartamentos {
	bool operator() (const Departamento* left, const Departamento* right) const {
		if (strcmp(left->getNome().c_str(), right->getNome().c_str()) < 0) return true;
		else return false;
	}
};

#endif
