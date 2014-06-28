#ifndef LISTAVENDA_H
#define LISTAVENDA_H

#include "Lista.h"
#include "Venda.h"

class ListaVenda: public Lista<Venda>
{
public:
	Venda *busca(int num);
};

#endif