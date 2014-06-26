#include "Sala.h"

int Sala::getNumSala(){

	return numSala;
}

void Sala::setNumSala(int numSala){

	Sala::numSala = numSala;
}

int Sala::getCapacidade(){
	return capacidade;
}

void Sala::setCapacidade(int novaCap)
{
	capacidade = novaCap;
}

string Sala::getSituacao()
{
	return situacao;
}

void Sala::setSituacao(Estado alteracao)
{
	if(alteracao >= 0 && alteracao < 4)
		situacao = alteracao;

	else
		throw "Situacao invalida";
}

Sala::Sala(int num) : fila(), numSala(num)
{
	capacidade = 0;
	situacao = disponivel;
}

Sala::~Sala(){}

/*
	Fileira *temporario;

	int i;
	Fileira::numFileira = -1;
	for(i = 0; i < qtdeFileiras; i++)
	{
		temporario = new Fileira('A' + i, assentosFileira);
		fila.insere(temporario);

	}


	if(capacidade % assentosFileira > 0)
	{
		temporario = new Fileira('A' + i, capacidade % assentosFileira);
		fila.insere(temporario);
		qtdeFileiras++;

	}
*/