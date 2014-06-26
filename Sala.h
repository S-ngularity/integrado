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

		// ???? Assento* getAssento(char idFileira, int idAssento);

		//int getQtdeAssentosFileiras();
		//void setQtdeAssentosFileiras(int qtde);

//--------Construtores e Destrutores-----------------
		Sala(int num, int capacidade, int assentosFileira);
		~Sala();
};

#endif