#include "ListaAssento.h"
#include <iostream>
using namespace std;

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

//void ListaAssento::renameAll(int id)
void ListaAssento::renameAll()
{
	No<Assento>* temp = getCabeca();

	int id = 1; // apagar pra nomear continuamente com as outras funções

	while(temp != NULL)
	{
		temp->getElemto()->setIdAssento(id);
		id += 1;

		temp = temp->getProx();
	}
}

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