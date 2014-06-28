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
	ListaFileira(ListaFileira &l);
	~ListaFileira();

	Fileira *busca(char id);

	//void renameAllAssentos()
	
	void removeFileira(char id);
	int getQtdeFileiras();
	int getQtdeAssentos();

	void imprimirListaFileira();
};

#endif