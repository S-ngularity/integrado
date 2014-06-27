#ifndef SALA_H
#define SALA_H

#include "ListaFileira.h"
#include <iostream>

using namespace std;
typedef enum {disponivel = 0, manuEquipamento, reforma, manuGeral} Situacao;

class Sala
{
private:
	Situacao situacao;
	int numSala;
	int capacidade;
	ListaFileira listaFileiras;

	int totalAssentosAtual;

public:
	Sala(int num, int cap);
	~Sala();

	int getNumSala();
	void setNumSala(int numSala);

	int getCapacidade();
	void setCapacidade(int novaCap);

	Situacao getSituacao();
	void setSituacao(Situacao alteracao);

	int getQtdFileiras();

	void addFileirasComAssentos(int qtdeFileiras, int assentosPorFileira);
	void removeFileira(char fileira); // TO DO

	int getQtdAssentosNaFileira(char fileira);
	void setQtdeAssentosNaFileira(char fileira, int novaQtde);

	bool verificaDispAssento(char fileira, int assento);

	void ocuparAssento(char fileira, int assento);
	void desocuparAssento(char fileira, int assento);
};

#endif