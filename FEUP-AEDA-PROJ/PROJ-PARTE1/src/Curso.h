#include "Disciplina.h"

#ifndef CURSO_H
#define CURSO_H

class Curso {
private:
	string tipo;
	int codigo;
	string nome;
	Docente* diretor;
	vector<Disciplina*> disciplinas;
	Pessoal* pessoal;

public:
	//Curso();
	Curso(Pessoal* p, string nom = "<undefined_name>", int cod = 0,string tip = "<undefined_type>",  vector<Disciplina*> v = {});
	//exceptions?

	string getTipo() const;
	bool setTipo(string tipo);

	int getCodigo() const;
	bool setCodigo(int codigo);

	string getNome() const;
	bool setNome(string nome);

	Docente* getDiretor() const;
	bool setDiretor(Docente* diretor);

	vector<Disciplina*> getDisciplinas() const;
	bool setDisciplinas(vector<Disciplina*> disciplinas);
	bool addDisciplina(Disciplina* disciplina);
	bool removeDisciplina(Disciplina* disciplina);
	Disciplina* findDisciplinaPT(string nomeDisciplina) const;
	Disciplina* findDisciplinaEN(string nomeDisciplina) const;
	void showDisciplinas();

	void manage();
private:
	void manageCurso();
	void manageDisciplinas();
};

struct ComparaDisciplinas {
	bool operator() (const Disciplina* left, const Disciplina* right) const {
		if (left->getAno() < right->getAno()) return true;
		if ((strcmp(left->getNomePortugues().c_str(), right->getNomePortugues().c_str()) <0) && left->getAno() == right->getAno()) return true;
		return false;
	}
};

#endif
