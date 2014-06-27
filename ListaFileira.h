#ifndef LISTAFILEIRA_H
#define LISTAFILEIRA_H

#include "Lista.h"
#include "Fileira.h"


class ListaFileira: public Lista<Fileira>
{
private:
	void renameAll();

public:
	ListaFileira();
	~ListaFileira();

	Fileira *busca(char id);
	
	void removeFileira(char id);
	int getQtdeAssentos();
};

#endif