#ifndef SALA_H
#define SALA_H

#include "ListaFileira.h"
#include <iostream>

using namespace std;
typedef enum {disponivel = 0, manuEquipamento, reforma, manuGeral} Estado;

class Sala{

//--------Atributos-------------------
	private:
		Estado situacao;
		int numSala;
		int capacidade;
		ListaFileira fila;
//int qtdeFileiras;
//int assentosFileira;
//--------Metodos----------------------
	private:
		Fileira *getFileira(char id);

	public:
		int getNumSala();
		void setNumSala(int numSala);

		int getCapacidade();
		void setCapacidade(int qtde);

		Estado getSituacao();
		void setSituacao(Estado alteracao);

		void addFileira(int qtdFileiras); // TO DO
		void removeFileira(char fileira); // TO DO

		void addAssentos(char fileira, int qtdeAssentos); // TO DO
		void removeAssentos(char fileira, int qtdeRemover); // TO DO

		void ocuparAssento(char fileira, int assento); // TO DO
		void desocuparAssento(char fileira, int assento); // TO DO

		// ???? Assento* getAssento(char idFileira, int idAssento);

		//int getQtdeAssentosFileiras();
		//void setQtdeAssentosFileiras(int qtde);

//--------Construtores e Destrutores-----------------
		Sala(int num, int capacidade, int assentosFileira);
		~Sala();
};

#endif