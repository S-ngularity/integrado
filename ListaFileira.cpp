#include "ListaFileira.h"

Fileira *ListaFileira::busca(char id){
	No<Fileira>* temp = getCabeca();

	while(temp != NULL)
	{
		if(temp->getElemto()->getIdFileira() == id)
			return temp->getElemto();

		temp = temp->getProx();
	}

	throw "Fileira nao encontrada";
}

int ListaAssento::getQtdeFileiras(){
	int qtde = 0;
	No<Assento>* temp = getCabeca();

	while(temp != NULL)
	{
		qtde++;
		temp = temp->getProx();
	}

	return qtde;
}

ListaFileira::ListaFileira():Lista<Fileira>(){}
ListaFileira::~ListaFileira(){}