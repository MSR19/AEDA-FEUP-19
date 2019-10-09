#include "Pessoa.h"

Pessoa::Pessoa(string nom, string mor, int tele, struct dataNascimento dataNas, int cod) {
	nome = nom;
	morada = mor;
	telefone = tele;
	data = dataNas;
	codigo = cod;
}

string Pessoa::getNome() const {
	return nome;
}

bool Pessoa::setNome(string nome) {
	this->nome = nome;

	return this->nome == nome;
}

string Pessoa::getMorada() const {
	return morada;
}

bool Pessoa::setMorada(string morada) {
	this->morada = morada;

	return this->morada == morada;
}

int Pessoa::getTelefone() const {
	return telefone;
}

bool Pessoa::setTelefone(int telefone) {
	this->telefone = telefone;

	return this->telefone == telefone;
}

struct dataNascimento Pessoa::getDataNascimento() const {
	return data;
}

bool Pessoa::setDataNascimento(struct dataNascimento date) {
	data = date;
	return true;
}

int Pessoa::getCodigo() const {
	return codigo;
}

bool Pessoa::setCodigo(int codigo) {
	this->codigo = codigo;

	return this->codigo == codigo;
}
