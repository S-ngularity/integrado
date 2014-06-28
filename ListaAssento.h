#ifndef LISTAASSENTO_H
#define LISTAASSENTO_H

#include "Lista.h"
#include "Assento.h"


class ListaAssento: public Lista<Assento>
{
public:
	ListaAssento();
	ListaAssento(ListaAssento &);
	~ListaAssento();

	Assento *busca(int id);

	void imprimeListaAssentos();
	
	void operator=(ListaAssento& l);
};

#endif