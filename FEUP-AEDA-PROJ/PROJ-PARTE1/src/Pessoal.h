#include "Docente.h"
#include "NDocente.h"
#include "Estudante.h"
#include <set>


#ifndef PESSOAL_H
#define PESSOAL_H

//operator to compare student when applying to loan (priority queue)
struct MediaEstudante
{
	bool operator() (const Estudante* left, const Estudante* right) const {
		if ((int)left->getMedia() < (int)right->getMedia()) {
			return true;
		}
		else if (left->getMedia() == right->getMedia()) {
			if (left->getAno() < right->getAno()) {
				return true;
			}
			else if (left->getAno() == right->getAno()) {
				if (left->getDataNascimento().ano < right->getDataNascimento().ano) {
					return true;
				}
			}
		}
		return false;
	}
};


typedef priority_queue<Estudante*, vector<Estudante*>, MediaEstudante> Heap_estudantes;


//hash to store the non-teachers in an unordered set (tabela de dispersao)
struct NDHash
{
	int operator() (const NDocente* nd) const
	{
		string nome = nd->getNome();
		int hash = 0;

		for (unsigned int i = 0; i > nome.size(); i++) {
			hash = hash + (int)nome[i] * i;
		}
		return hash;
	}

	bool operator() (const NDocente* nd1, const NDocente* nd2) const
	{
		if (nd1->getNome() == nd2->getNome()) return true;
		return false;
	}
};

typedef unordered_set <NDocente*, NDHash, NDHash> TahFuncionarios;


struct ComparaRegistoEstudantes {
	bool operator() (Estudante * left, Estudante * right) const {
		if (strcmp(left->getCurso().c_str(), right->getCurso().c_str()) < 0) return true;
		else if (strcmp(left->getCurso().c_str(), right->getCurso().c_str()) > 0) return false;
		else {
			if (strcmp(left->getNome().c_str(), right->getNome().c_str()) < 0) return true;
			else if (strcmp(left->getNome().c_str(), right->getNome().c_str()) > 0) return false;
			else return false;
		}
	}
};

typedef set<Estudante*, ComparaRegistoEstudantes> ArvoreBinariaEstudantes;


class Pessoal {
private:
	vector<Estudante*> estudantes;
	vector<Estudante*> bolseiros; //Lista de pessoas que tem bolsa
	vector<Docente*> docentes;
	vector<NDocente*> nDocentes;
	Heap_estudantes bolsas;
	TahFuncionarios historicoFuncionarios;
	//BST<Estudante*> registoEstudantes;
	ArvoreBinariaEstudantes registoEstudantes;


	void manageEstudantes();
	void manageDocentes();
	void manageNDocentes();
	void manageBolsas();
	void manageHistorico();


public:
	Pessoal(vector<Estudante*> e = {}, vector<Docente*> d = {}, vector<NDocente*> nd = {}, vector<Estudante*> bol = {}, vector<Estudante*> candidatos = {}, vector<NDocente*> historico = {});

	vector<Estudante*> getEstudantes() const;
	bool setEstudantes(vector<Estudante*> estudantes);
	bool addEstudante(Estudante* estudante);
	bool removeEstudante(Estudante* estudante);
	void showEstudantes();
	Estudante* findEstudante(string nomeEstudante) const;

	vector<Estudante*> getBolseiros() const;
	bool setBolseiros(vector<Estudante*> bolseiros);
	void addBolseiro(Estudante * est);
	bool removeBolseiro(Estudante* bolseiro);
	Estudante* findBolseiro(string nomeBolseiro) const;
	void showBolseiro();
	

	vector<Docente*> getDocentes() const;
	bool setDocentes(vector<Docente*> docentes);
	bool addDocente(Docente* docente);
	bool removeDocente(Docente* docente);
	Docente* findDocente(string nomeDocente) const;
	void showDocentes();

	vector<NDocente*> getNDocentes() const;
	bool setNDocente(vector<NDocente*> nDocentes);
	bool addNDocente(NDocente* nDocente);
	bool removeNDocente(NDocente* nDocente);
	NDocente* findNDocente(string nomeNDocente) const;
	void showNDocente();

	void manage();


	Heap_estudantes getEstudanteBolsa() const;
	void addEstudanteBolsa(Estudante* est);
	Estudante* nextEstudanteBolsa();
	bool removeEstudanteBolsa(Estudante* est);
	Estudante* findEstudanteBolsa(string nomeEst) const;
	void showBolsa() const;

	bool addNDocenteHistorico(NDocente* ndoc);
	bool presenteNDocenteHistorico(string nome) const;
	void cleanHistorico();
	void showHistorico() const;
	NDocente* findNDocenteHistorico(string nomeND) const;
	void removeNDocenteHistorico(NDocente * ndo);

	TahFuncionarios getHistoricoNDocente() const;
	bool setRegistoEstudante();
	bool addRegistoEstudante(Estudante* est);
	bool removeRegistoEstudante(Estudante* est);
	void showRegistoEstudante() const; 
	Estudante* findRegistoEstudante(string nomeEst, string nomeCur) const;
};

struct ComparaEstudantes {
	bool operator() (Estudante* left, Estudante* right) const {
		if (strcmp(left->getNome().c_str(), right->getNome().c_str()) < 0) return true;
		else return false;
	}
};

struct ComparaDocentes {
	bool operator() (Docente* left, Docente* right) const {
		if (strcmp(left->getNome().c_str(), right->getNome().c_str()) < 0) return true;
		else return false;
	}
};

struct ComparaNDocentes {
	bool operator() (NDocente* left, NDocente* right) const {
		if (strcmp(left->getNome().c_str(), right->getNome().c_str()) < 0) return true;
		else return false;
	}
};



#endif
