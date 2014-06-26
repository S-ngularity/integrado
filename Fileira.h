#ifndef FILEIRA_H
#define FILEIRA_H

#include "ListaAssento.h"


class Fileira{

//--------Atributos----------------
	private:
		char idFileira;
		ListaAssento assento;
		int num;

	public:
		static int numFileira;


//-------Metodos----------------------

	public:
		bool verificaDisponibilidade();
		Assento *getAssento(int id);
		void setQtdeAssentos(int qtde);
		char getIdFileira();
//--------Construtores e Desrutores-----------
	public:
		Fileira(char id, int qtdAssentosFileira);//definir parametros
		~Fileira();
};
#endif