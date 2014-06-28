#include "ListaFileira.h"

ListaFileira::ListaFileira():Lista<Fileira>(){}

ListaFileira::ListaFileira(ListaFileira &l)
{
	No<Fileira>* temp = l.getCabeca();
	Fileira *a;

	while(getCabeca() != NULL)
		remove();

	while(temp != NULL)
	{
		a = new Fileira(*(temp->getElemto()));
		insere(a);

		temp = temp->getProx();
	}
}

ListaFileira::~ListaFileira(){}

void ListaFileira::renameAll()
{
	No<Fileira>* temp = getCabeca();

	char id = 'A';

	while(temp != NULL)
	{
		temp->getElemto()->setIdFileira(id);

		temp = temp->getProx();
		id += 1;
	}
}

Fileira *ListaFileira::busca(char id){
	No<Fileira>* temp = getCabeca();

	while(temp != NULL)
	{
		if(temp->getElemto()->getIdFileira() == id)
			return temp->getElemto();

		temp = temp->getProx();
	}

	throw "Fileira não encontrada";
}

/*void ListaFileira::renameAllAssentos()
{
	No<Fileira>* temp = getCabeca();

	int id = 1;

	while(temp != NULL)
	{
		temp->getElemto()->renameAll(id);
		id += temp->getElemto()->getQtdeAssentos();

		temp = temp->getProx();
	}
}*/

void ListaFileira::removeFileira(char id){

	No<Fileira>* temp = getCabeca();
	No<Fileira>* excluido;

	if(temp == NULL)
	{
		throw "Lista vazia , impossível remover";
	}

	//Caso de remover quando só tem um elemento
	if(temp->getProx() == NULL)
	{
		if(temp->getElemto()->getIdFileira() == id)
		{
			remove();

			renameAll();
			return;
		}
		else
			throw "Fileira não encontrada.";

	}

	if(temp->getElemto()->getIdFileira() == id)
	{
		excluido = getCabeca();
		setCabeca(temp->getProx());
		delete excluido;

		renameAll();
		return;
	}

	while(temp->getProx() != NULL)
	{
		if(temp->getProx()->getElemto()->getIdFileira() == id)
		{
			excluido = temp->getProx();
			temp->setProx(temp->getProx()->getProx());

			delete excluido;

			renameAll();
			return;
		}

		temp = temp->getProx();
	}

	throw "Fileira não encontrada.";
}

int ListaFileira::getQtdeFileiras()
{
	return qtdeElementos();
}

int ListaFileira::getQtdeAssentos(){

	No<Fileira>* temp = getCabeca();
	int qtde = 0;

	while(temp != NULL)
	{
		qtde += temp->getElemto()->getQtdeAssentos();

		temp = temp->getProx();
	}

	return qtde;
}

void ListaFileira::imprimirListaFileira(){
	No<Fileira>* temp = getCabeca();

	while(temp != NULL)
	{
		cout << *((*temp).getElemto()) << endl;

		temp = temp->getProx();
	}
}