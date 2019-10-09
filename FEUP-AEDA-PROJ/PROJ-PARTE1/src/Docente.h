#include "Funcionario.h"

#ifndef DOCENTE_H
#define DOCENTE_H

class Docente: public Funcionario {
private:
	string categoria;
	vector<string> disciplinas;

public:
	//Docente(string nom, string mor, int tele, string data, int cod, vector<string> dici, string cate, int con, int sal);
	//~Docente();
	Docente(string nom = "<undefined_name>",int cod = 0, string mor = "<undefined_address>", int tele = 0, struct dataNascimento dataNas = { 0,0,0 },
		 int cont = 0, int sal = 0, string cat = "<undefined_category>", vector<string> dis = {});

	string getCategoria() const;
	bool setCategoria(string categoria);

	vector<string> getDisciplinas() const;
	bool setDisciplinas(vector<string> disciplinas);
	bool addDisciplina(string disciplina);
	bool removeDisciplina(string disciplina);
	void showDisciplinas() const;

	virtual void manage();
};


#endif
