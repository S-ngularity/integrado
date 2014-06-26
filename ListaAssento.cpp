#include "ListaAssento.h"

Assento *ListaAssento::busca(int id){
	No<Assento>* temp = getCabeca();

	while(temp != NULL)
	{
		if(temp->getElemto()->getIdAssento() == id)
			return temp->getElemto();
		temp = temp->getProx();
	}

	throw "Assento nao encontrado";
}

int ListaAssento::getQtdeAssentos(){
	int qtde = 0;
	No<Assento>* temp = getCabeca();

	while(temp != NULL)
	{
		qtde++;
		temp = temp->getProx();
	}

	return qtde;
}

ListaAssento::ListaAssento():Lista(){}

ListaAssento::~ListaAssento(){}
