#include "Fileira.h"
#include <iostream>
#include <iomanip> //setw()
using namespace std;

Fileira::Fileira(char id, int qtdAssentosFileira): idFileira(id), qtdeAssentos(qtdAssentosFileira)
{
	Assento *temporario;

	for(int i = 0; i < qtdeAssentos; i++)
	{
		temporario = new Assento(idFileira, i + 1);
		listaAssentos.insere(temporario);
	}
}

Fileira::Fileira(Fileira &f) : listaAssentos(f.listaAssentos)
{
	qtdeAssentos = f.qtdeAssentos;
	idFileira = f.idFileira;
}

Fileira::~Fileira(){}

bool Fileira::verificaDispAssento(int assento)
{
	return listaAssentos.busca(assento)->verificaDisponibilidade();
}

void Fileira::ocuparAssento(int num)
{
	listaAssentos.busca(num)->ocuparAssento();
}

void Fileira::desocuparAssento(int num)
{
	listaAssentos.busca(num)->desocuparAssento();
}

char Fileira::getIdFileira()
{
	return idFileira;
}

void Fileira::setIdFileira(char id)
{
	idFileira = id;
}

int Fileira::getQtdeAssentos()
{
	return listaAssentos.qtdeElementos();
}

void Fileira::setQtdeAssentos(int novaQtde){
	int diferenca = novaQtde - qtdeAssentos;

	if(diferenca > 0)
	{
		Assento *temporario;
		for(int i = 1; i <= diferenca; i++)
		{
			temporario = new Assento(idFileira, i + 1);
			listaAssentos.insere(temporario);
			listaAssentos.renameAll();
		}
	}

	else
	{
		diferenca = -1 * diferenca;

		for(int i = 0; i < diferenca; i++)
			listaAssentos.remove();
	}

	qtdeAssentos = novaQtde;
}

/*void Fileira::renameAll(int id)
{
	listaAssentos.renameAll(id);
}*/

ostream &operator<<(ostream &o, Fileira &f){
	o << setw(2) << "-" << f.idFileira << "- ";
	f.listaAssentos.imprimeListaAssentos();
	cout << endl;
	return o;
}