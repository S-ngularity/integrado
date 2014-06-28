#include "ListaAssento.h"
#include <iostream>
using namespace std;

Assento *ListaAssento::busca(int id){
	No<Assento>* temp = getCabeca();

	while(temp != NULL)
	{
		if(temp->getElemto()->getIdAssento() == id)
			return temp->getElemto();

		temp = temp->getProx();
	}

	throw "Assento não encontrado.";
}

ListaAssento::ListaAssento():Lista(){}

ListaAssento::ListaAssento(ListaAssento &l){
	No<Assento>* temp = l.getCabeca();
	Assento *a;

	while(getCabeca() != NULL)
		remove();

	while(temp != NULL)
	{
		a = new Assento(*(temp->getElemto()));
		insere(a);

		temp = temp->getProx();
	}
}

ListaAssento::~ListaAssento(){}

void ListaAssento::imprimeListaAssentos(){
	No<Assento>* temp = getCabeca();

	while(temp != NULL)
	{
		cout << *((*temp).getElemto()); // << sobrecarregado

		temp = temp->getProx();
	}
	//cout << endl;
}

void ListaAssento::operator=(ListaAssento &l){
	No<Assento>* temp = l.getCabeca();
	Assento *a;

	while(getCabeca() != NULL)
		remove();

	while(temp != NULL)
	{
		a = new Assento(*(temp->getElemto()));
		insere(a);

		temp = temp->getProx();
	}
}