#include "ListaVenda.h"

Venda *ListaVenda::busca(int num){
	No<Venda>* temp = getCabeca();

	while(temp != NULL)
	{
		if(temp->getElemto()->getCodVenda() == num)
			return temp->getElemto();
		temp = temp->getProx();
	}

	throw "Venda não encontrada.";
}