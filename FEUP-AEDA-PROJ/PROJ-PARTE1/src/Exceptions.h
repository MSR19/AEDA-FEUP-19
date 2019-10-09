#include <iostream>
#include <string>

using namespace std;

#ifndef _EXCEPTIONS_H_
#define _EXCEPTIONS_H_


std::string string_input_errorHandler();
int int_input_errorHandler(int min = 0x80000000, int max = 0x7FFFFFFF);



// NAO DEPARTAMENTO //
class NoDepartamento {
public:
	string nome;
	NoDepartamento(string nom);
	bool mensagem();
};
std::ostream & operator<<(std::ostream &out, NoDepartamento &dep);

// DESPARTAMENTO JA EXISTENTE //
class DepartamentoRepetido {
public:
string nome;
DepartamentoRepetido(string nom);
bool mensagem();
};
std::ostream & operator<<(std::ostream &out, DepartamentoRepetido &dep);



// NAO CURSO //
class NoCurso {
public:
	std::string nome;
	NoCurso(std::string nom);
	bool mensagem();
};
std::ostream & operator<<(std::ostream &out, NoCurso &cur);

// CURSO JA EXISTENTE //
class CursoRepetido {
public:
	string nome;
	CursoRepetido(string nom);
	bool mensagem();
};
std::ostream & operator<<(std::ostream &out, CursoRepetido &cur);



// NAO DISCIPLINA //
class NoDisciplina {
public:
string nome;
NoDisciplina(string nom);
bool mensagem();
};
std::ostream & operator<<(std::ostream &out, NoDisciplina &dis);

// DISCIPLINA JA EXISTENTE //
class DisciplinaRepetida {
public:
string nome;
DisciplinaRepetida(string nom);
bool mensagem();
};
std::ostream & operator<<(std::ostream &out, DisciplinaRepetida &des);



// NAO DOCENTE //
class NoNDocente {
public:
string nome;
NoNDocente(string nom);
bool mensagem();
};
std::ostream & operator<<(std::ostream &out, NoNDocente &ndoc);

// DOCENTE JA EXISTENTE //
class DocenteRepetido {
public:
string nome;
DocenteRepetido(string nom);
bool mensagem();
};
std::ostream & operator<<(std::ostream &out, DocenteRepetido &doc);



// NAO ESTUDANTE //
class NoEstudante {
public:
	string nome;
	NoEstudante(string nom);
	bool mensagem();
};
std::ostream & operator<<(std::ostream &out, NoEstudante &est);

// ESTUDANTE JA EXISTENTE //
class EstudanteRepetido {
public:
	string nome;
	EstudanteRepetido(string nom);
	bool mensagem();
};
std::ostream & operator<<(std::ostream &out, EstudanteRepetido &est);



// NAO NDOCENTE //
class NoDocente {
public:
	string nome;
	NoDocente(string nom);
	bool mensagem();
};
std::ostream & operator<<(std::ostream &out, NoDocente &doc);

// NDOCENTE JA EXISTENTE //
class NDocenteRepetido {
public:
	string nome;
	NDocenteRepetido(string nom);
	bool mensagem();
};
std::ostream & operator<<(std::ostream &out, NDocenteRepetido &ndoc);



// Bolsa VAZIA //
class BolsaVazia {
public:
	BolsaVazia();
	bool mensagem();
};
std::ostream & operator<<(std::ostream &out, BolsaVazia &bolc);


// Bolseiro REPETIDO //
class BolseiroRepetido {
public:
	string nome;
	BolseiroRepetido(string nom);
	bool mensagem();
};

#endif
