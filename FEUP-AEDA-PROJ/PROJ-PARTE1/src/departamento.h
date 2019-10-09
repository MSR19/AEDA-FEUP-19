#include "Curso.h"

#ifndef DEPARTAMENTO_H
#define DEPARTAMENTO_H


class Departamento {
private:
	int codigo;
	string nome;
	string morada;
	int telefone;
	Docente* diretor;
	vector<Curso*> cursos;
	Pessoal* pessoal;

public:
	Departamento(Pessoal* p, string nom = "<undefined_name>", int cod = 0, string address = "<undefined_address>", int tel = 0, vector<Curso*> v = {});

	int getCodigo() const;
	bool setCodigo(int codigo);

	string getNome() const;
	bool setNome(string nome);

	string getMorada() const;
	bool setMorada(string morada);

	int getTelefone() const;
	bool setTelefone(int telefone);

	Docente* getDiretor() const;
	bool setDiretor(Docente* diretor);

	vector<Curso*> getCursos() const;
	bool setCursos(vector<Curso*> cursos);
	bool addCurso(Curso* curso);
	bool removeCurso(Curso* curso);
	Curso* findCurso(string nome) const;
	void showCursos();

	void manage();

private:
	void manageDepartamento();
	void manageCursos();
};

struct ComparaCursos {
	bool operator() (const Curso* left, const Curso* right) const {
		if (strcmp(left->getNome().c_str(), right->getNome().c_str()) < 0) return true;
		else return false;
	}
};

#endif
