#include "ListaSala.h"

Sala *ListaSala::busca(int num){
	No<Sala>* temp = getCabeca();

	while(temp != NULL)
	{
		if(temp->getElemto()->getNumSala() == num)
			return temp->getElemto();
		temp = temp->getProx();
	}

	throw "Sala não encontrada.";
}

void ListaSala::removerSala(int num){
	No<Sala>* temp = getCabeca();
	No<Sala>* excluido;

	if(temp == NULL)
	{
		throw "Lista vazia, impossível remover";
	}
	//Caso de remover quando só tem um elemento
	if(temp->getProx() == NULL)
	{
		if(temp->getElemto()->getNumSala() == num)
		{
			remove();
			return;
		}
		else
			throw "Sala não encontrada.";

	}
	if(temp->getElemto()->getNumSala() == num)
	{
		excluido = getCabeca();
		setCabeca(temp->getProx());
		delete excluido;
		return;
	}
	while(temp->getProx() != NULL)
	{
		if(temp->getProx()->getElemto()->getNumSala() == num)
		{
			excluido = temp->getProx();
			temp->setProx(temp->getProx()->getProx());

			delete excluido;
			return;
		}

		temp = temp->getProx();
	}

	throw "Sala não encontrada.";

}

void ListaSala::imprimirListaSala()
{
	No<Sala>* temp = getCabeca();

	while(temp != NULL)
	{
		cout << endl << "Sala " << temp->getElemto()->getNumSala() << " -- Capacidade: " << temp->getElemto()->getCapacidade() <<
		 " -- Total de assentos: " << temp->getElemto()->getTotalAssentos() << " -- Situação: " << temp->getElemto()->getStringSituacao() << endl << endl;

		temp = temp->getProx();
	}
}