#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>
#include <unordered_set>
#include <cstring>
#include "Exceptions.h"

#ifndef PESSOA_H
#define PESSOA_H

using namespace std;

struct dataNascimento
{
	int ano;
	int mes;
	int dia;
};

class Pessoa {
private:
	string nome;
	string morada;
	int telefone;
	struct dataNascimento data;
	int codigo;

public:
	Pessoa(string nom = "<undefined_name>", string mor = "<undefined_adress>", int tele = 0, struct dataNascimento dataNas = { 0,0,0 }, int cod = 0);
	//~Pessoa();
	//Pessoa(string nome);

	string getNome() const;
	bool setNome(string nome);

	string getMorada() const;
	bool setMorada(string morada);

	int getTelefone() const;
	bool setTelefone(int telefone);

	struct dataNascimento getDataNascimento() const;
	bool setDataNascimento(struct dataNascimento date);

	int getCodigo() const;
	bool setCodigo(int codigo);
};





#endif
