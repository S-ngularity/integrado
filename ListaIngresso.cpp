#include "ListaIngresso.h"
#include <iomanip>

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

void ListaIngresso::removeIngresso(int cod){
	No<Ingresso>* temp = getCabeca();
	No<Ingresso>* excluido;

	if(temp == NULL)
	{
		throw "Lista Vazia , impossivel remover";
	}
	//Caso de remover quando só tem um elemento
	if(temp->getProx() == NULL)
	{
		if(temp->getElemto()->getCodIngresso() == cod)
		{
			remove();
			return;
		}
		else
			throw "Elemento nao encontrado";

	}
	if(temp->getElemto()->getCodIngresso() == cod)
	{
		excluido = getCabeca();
		setCabeca(temp->getProx());
		delete excluido;
		return;
	}
	while(temp->getProx() != NULL)
	{
		if(temp->getProx()->getElemto()->getCodIngresso() == cod)
		{
			excluido = temp->getProx();
			temp->setProx(temp->getProx()->getProx());

			delete excluido;
			return;
		}

		temp = temp->getProx();
	}

	throw "Elemento nao encontrado";
}

Ingresso *ListaIngresso::getPrimeiro()
{
	if(getCabeca() != NULL)
		return getCabeca()->getElemto();

	else
		return NULL;
}

double ListaIngresso::getValorTotal()
{
	No<Ingresso>* temp = getCabeca();
	double total = 0;

	while(temp != NULL)
	{
		total += temp->getElemto()->getValor();

		temp = temp->getProx();
	}

	return total;
}

void ListaIngresso::imprimirTodos()
{
	No<Ingresso>* temp = getCabeca();

	while(temp != NULL)
	{
		cout << endl << "Código do ingresso:" << setw(6) << temp->getElemto()->getCodIngresso();
		cout << " -- Sala: " << setw(3) << temp->getElemto()->getNumSala();
		cout << " -- Fileira: " << temp->getElemto()->getIdFileira();
		cout << " -- Assento: " << temp->getElemto()->getIdAssento();
		cout << " -- Filme: " << temp->getElemto()->getFilme() << endl << endl;
		//cout << " -- Horário: " << temp->getElemto()->getHorario();

		temp = temp->getProx();
	}
}