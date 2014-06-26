#ifndef LISTAFILEIRA_H
#define LISTAFILEIRA_H

#include "Lista.h"
#include "Fileira.h"


class ListaFileira: public Lista<Fileira>{

//------------Metodos-------------------------
	public:
		Fileira *busca(char id);
		void setQtdeAssentos(int qtde);

//-------------Construtor e Destrutor--------------
	public:
		ListaFileira();
		~ListaFileira();

};

#endif