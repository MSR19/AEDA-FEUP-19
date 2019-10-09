#include "Pessoa.h"

#ifndef ESTUDANTE_H
#define ESTUDANTE_H

class Estudante: public Pessoa {
private:
	string curso;
	float media;
	map<string, int> disciplinas;
	int ano;

	bool atualizaMedia();
	void managePauta();
public:
	Estudante(string nom = "<undefined_name>", int cod = 0,string mor = "<undefined_address>", int tele = 0, struct dataNascimento dataNas = { 0,0,0 }, 
		string c = "<undefined_degree>", float med = 0, map<string, int> disc = {});
	//~Estudante();

	string getCurso() const;
	bool setCurso(string curso);

	float getMedia() const;

	map<string, int> getDisciplinas() const;
	bool setDisciplinas(map<string, int> disciplinas);
	bool addDisciplina(string nomeDisciplina, int nota = 0);
	bool setNota(string nomeDisciplina, int nota);
	bool removeDisciplina(string nomeDisciplina);
	void showDisciplinas() const;

	void manage();

	void setAno(int ano);
	int getAno() const;

	bool operator<(const Estudante* est) const;
	
	bool operator==(const Estudante& est) const;
};



#endif
