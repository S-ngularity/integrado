#ifndef LISTAINGRESSO_H
#define LISTAINGRESSO_H

#include "Lista.h"
#include "Ingresso.h"


class ListaIngresso: public Lista<Ingresso>
{
public:
	Ingresso *busca(int codigo);
};

#endif