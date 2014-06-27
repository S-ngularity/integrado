#ifndef LISTAFILEIRA_H
#define LISTAFILEIRA_H

#include "Lista.h"
#include "Fileira.h"


class ListaFileira: public Lista<Fileira>
{
public:
	ListaFileira();
	~ListaFileira();

	Fileira *busca(char id);
};

#endif