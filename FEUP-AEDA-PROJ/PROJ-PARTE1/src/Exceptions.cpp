#include "Exceptions.h"


int int_input_errorHandler(int min, int max)
{
	// when max and min are not specified,
	// they get the max and the min values in a 16-bit number
	//cin.ignore(10000, '\n');
	int choice;
	bool inputError; //if error -> true
	do //input error handler
	{
		inputError = false;
		cin >> choice;
		if (cin.fail() || !(choice >= min && choice <= max)) //if cin error flag == true
		{
			cin.clear(); //clear cin flags
			cin.ignore(100000, '\n'); //ignore caracters
			inputError = true; //sets to true so loop repeats
			cout << "Input failed: try again!";
		}		
	} while (inputError); //if error, loop repeats
	cin.ignore(10000, '\n');
	return choice;
}

std::string string_input_errorHandler()
{
	//cin.ignore(10000, '\n');
	std::string choice;
	bool inputError;
	do
	{
		inputError = false;
		getline(cin, choice);
		if (cin.fail())
		{
			cin.ignore(100000, '\n');
			cin.clear();
			inputError = true;
			cout << "Input failed: try again!";
		}
	} while (inputError);
	//cin.ignore(10000, '\n');

	for (unsigned int i = 0; i < choice.size(); i++) {
		if (choice[i] == ' ') choice.replace(choice.begin()+i,choice.begin()+i+1,"_");
	}

	return choice;
}



// NAO DEPARTAMENTO //
NoDepartamento::NoDepartamento(string nom) { 
	nome = nom; 
}
bool NoDepartamento::mensagem() {
	cout << *this;
	system("pause");
	return true;
}
std::ostream & operator<<(std::ostream &out, NoDepartamento &dep)
{
	out << endl << "O departamento " << dep.nome << " nao existe" << endl;
	return out;
}

// DESPARTAMENTO JA EXISTENTE //
DepartamentoRepetido::DepartamentoRepetido(string nom) {
	nome = nom; 
}
bool DepartamentoRepetido::mensagem() {
	cout << *this;
	system("pause");
	return true;
}
std::ostream & operator<<(std::ostream &out, DepartamentoRepetido &dep)
{
	out << endl << "O departamento " << dep.nome << " ja existe" << endl;
	return out;
}



// NAO  CURSO //
NoCurso::NoCurso(string nom) {
	nome = nom; 
}
bool NoCurso::mensagem() {
	cout << *this;
	system("pause");
	return true;
}
std::ostream & operator<<(std::ostream &out, NoCurso &cur)
{
	out << endl << "O Curso " << cur.nome << " nao existe" << endl;
	return out;
}

// CURSO JA EXISTENTE //
CursoRepetido::CursoRepetido(string nom) { 
	nome = nom; 
}
bool CursoRepetido::mensagem() {
	cout << *this;
	system("pause");
	return true;
}
std::ostream & operator<<(std::ostream &out, CursoRepetido &cur)
{
	out << endl << "O curso " << cur.nome << " ja existe" << endl;
	return out;
}



// NAO DISCIPLINA //
NoDisciplina::NoDisciplina(string nom) {
	nome = nom; 
};
bool NoDisciplina::mensagem() {
	cout << *this;
	system("pause");
	return true;
};
std::ostream & operator<<(std::ostream &out, NoDisciplina &dis)
{
	out << endl << "A disciplina " << dis.nome << " nao existe";
	return out;
}

// DISCIPLINA JA EXISTENTE //
DisciplinaRepetida::DisciplinaRepetida(string nom) { nome = nom; };
bool DisciplinaRepetida::mensagem() {
	cout << *this;
	system("pause");
	return true;
};
std::ostream & operator<<(std::ostream &out, DisciplinaRepetida &des)
{
	out << endl << "A disciplina " << des.nome << " ja existe" << endl;
	return out;
}


// NAO DOCENTE //
NoNDocente::NoNDocente(string nom) {
	nome = nom; 
};
bool NoNDocente::mensagem() {
	cout << *this;
	system("pause");
	return true;
};
std::ostream & operator<<(std::ostream &out, NoNDocente &ndoc)
{
	out << "O funcionario " << ndoc.nome << " nao existe" << endl;
	return out;
}

// DOCENTE JA EXISTENTE //
DocenteRepetido::DocenteRepetido(string nom) {
	nome = nom; 
};
bool DocenteRepetido::mensagem() {
	cout << *this;
	system("pause");
	return true;
};
std::ostream & operator<<(std::ostream &out, DocenteRepetido &doc)
{
	out << endl << "O docente " << doc.nome << " ja existe" << endl;
	return out;
}


// NAO ESTUDANTE //
NoEstudante::NoEstudante(string nom) {
	nome = nom; 
};
bool NoEstudante::mensagem() {
	cout << *this;
	system("pause");
	return true;
};
std::ostream & operator<<(std::ostream &out, NoEstudante &est)
{
	out << "O estudante " << est.nome << " nao existe" << endl;
	return out;
}

// ESTUDANTE JA EXISTENTE //
EstudanteRepetido::EstudanteRepetido(string nom) { nome = nom; };
bool EstudanteRepetido::mensagem() {
	cout << *this;
	system("pause");
	return true;
};
std::ostream & operator<<(std::ostream &out, EstudanteRepetido &est)
{
	out << endl << "O estudante " << est.nome << " ja existe" << endl;
	return out;
}


// NAO NDOCENTE //
NoDocente::NoDocente(string nom) { nome = nom; };
bool NoDocente::mensagem() {
	cout << *this;
	system("pause");
	return true;
};
std::ostream & operator<<(std::ostream &out, NoDocente &doc)
{
	out << "O docente " << doc.nome << " nao existe" << endl;
	return out;
}

// NDOCENTE JA EXISTENTE //
NDocenteRepetido::NDocenteRepetido(string nom) { nome = nom; };
bool NDocenteRepetido::mensagem() {
	cout << *this;
	system("pause");
	return true;
};
std::ostream & operator<<(std::ostream &out, NDocenteRepetido &ndoc)
{
	out << endl << "O funcionario " << ndoc.nome << " ja existe" << endl;
	return out;
}


// Bolsa VAZIA //
BolsaVazia::BolsaVazia() {}

bool BolsaVazia::mensagem() {
	cout << *this;
	system("pause");
	return true;
}

std::ostream & operator<<(std::ostream &out, BolsaVazia &bolc)
{
	out << endl << "A bolsa esta vazia!" << endl;
	return out;
}



// Bolseiro Repetido //
BolseiroRepetido::BolseiroRepetido(string nom) {
	nome = nom;
}

bool BolseiroRepetido::mensagem() {
	cout << this;
	system("pause");
	return true;
}

std::ostream & operator<<(std::ostream &out, BolseiroRepetido &bol)
{
	out << endl << "O estudante " << bol.nome << " ja e bolseiro!" << endl;
	return out;
}