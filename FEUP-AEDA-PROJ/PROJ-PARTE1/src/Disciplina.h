#include "Pessoal.h"

#ifndef DISCIPLINA_H
#define DISCIPLINA_H

class Disciplina {
private:
	int codigo;
	string nomePortugues;
	string nomeIngles;
	Docente* regente;
	int ano;
	int ects;
	int cargaHoraria;
	vector<Docente*> docentes;
	vector<Estudante*> estudantes;
	Pessoal* pessoal;
	string curso;

public:
	Disciplina(Pessoal* p, string nompt = "<undefined_pt_name>", int cod = 0, string nomen = "<undefined_en_name>", int an = 0, int creditos = 0, int carga = 0,
		vector<Docente*> v = {}, vector<Estudante*> f = {}, string cur = "<undefined_curso>");

	int getCodigo() const;
	bool setCodigo(int codigo);

	string getNomePortugues() const;
	bool setNomePortugues(string nomePortugues);

	string getNomeIngles() const;
	bool setNomeIngles(string nomeIngles);

	Docente* getRegente() const;
	bool setRegente (Docente* regente);

	int getAno() const;
	bool setAno(int ano);

	int getEcts() const;
	bool setEcts(int ects);

	int getCargaHoraria() const;
	bool setCargaHoraria(int cargaHoraria);

	vector<Docente*> getDocentes() const;
	bool setDocentes(vector<Docente*> docentes);
	bool addDocente(Docente* docente);
	bool removeDocente(Docente* docente);
	Docente* findDocente(string nomeDocente) const;
	void showDocentes();

	vector<Estudante*> getEstudantes() const;
	bool setEstudantes(vector<Estudante*> estudantes);
	bool addEstudante(Estudante* estudante);
	bool removeEstudante(Estudante* estudante);
	Estudante* findEstudante(string nomeEstudante) const;
	void showEstudantes();

	void manage();

	string getCurso() const;
	bool setCurso(string curso);

private:
	void manageDisciplina();
	void manageEstudantes();
	void manageDocentes();
};

#endif
