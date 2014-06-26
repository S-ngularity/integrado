#include "ListaFileira.h"
#include <iostream>
using namespace std;

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

ListaFileira::ListaFileira():Lista<Fileira>(){}
ListaFileira::~ListaFileira(){}