#include "ListaIngresso.h"

Ingresso *ListaIngresso::busca(int codigo){
	No<Ingresso>* temp = getCabeca();

	while(temp != NULL)
	{
		if(temp->getElemto()->getCodIngresso() == codigo)
			return temp->getElemto();
		temp = temp->getProx();
	}

	throw "Ingresso nao encontrado";
}