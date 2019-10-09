#include "Funcionario.h"

#ifndef NDOCENTE_H
#define NDOCENTE_H

class NDocente: public Funcionario {
private:
	string areaTrabalho;
public:
	NDocente(string nom = "<undefined_name>",int cod = 0, string mor = "<undefined_address>", int tele = 0, struct dataNascimento dataNas = { 0,0,0 },
		 int cont = 0, int sal = 0, string areaT = "<undefined_working_area>");
	//~NDocente();

	string getAreaTrabalho() const;
	bool setAreaTrabalho(string areaT);

	void manage();
};

#endif
