#include "Sala.h"

Sala::Sala(int num, int cap) : listaFileiras()
{
	numSala = num;
	capacidade = cap;
	situacao = disponivel;
}

Sala::~Sala(){}

int Sala::getNumSala(){

	return numSala;
}

void Sala::setNumSala(int numSala)
{

	Sala::numSala = numSala;
}

int Sala::getCapacidade()
{
	return capacidade;
}

void Sala::setCapacidade(int novaCap)
{
	if(novaCap < totalAssentosAtual)
	{
		throw "Nova capacidade é menor do que quantidade de assentos. Remova assentos antes de alterar capacidade."
	}

	else
		capacidade = novaCap;
}

Situacao Sala::getSituacao()
{
	return situacao;
}

void Sala::setSituacao(Situacao alteracao)
{
	if(alteracao >= 0 && alteracao < 4)
		situacao = alteracao;

	else
		throw "Situacao inválida.";
}

int Sala::getQtdFileiras()
{
	listaFileiras.qtdeElementos();
}

void Sala::addFileirasComAssentos(int qtdeFileiras, int assentosPorFileira)
{
	Fileira *temp;

	if(totalAssentosAtual + qtdeFileiras * assentosPorFileira > getCapacidade())
	{
		throw "Essa operação excede a capacidade da sala."
	}

	else
	{
		for(int i = 0; i < qtdeFileiras; i++)
		{
			temp = new Fileira('@' + getQtdFileiras() + 1, assentosPorFileira);

			listaFileiras.insere(temp);
		}

		totalAssentosAtual += qtdeFileiras * assentosPorFileira;
	}
}

void Sala::removeFileira(char fileira)
{

	// atualizar total assentos
}

int Sala::getQtdAssentosNaFileira(char fileira)
{
	listaFileiras.busca(fileira)->getQtdeAssentos();
}

void Sala::setQtdeAssentosNaFileira(char fileira, int novaQtde)
{
	if(totalAssentosAtual - listaFileiras.busca(fileira)->getQtdeAssentos() + novaQtde > capacidade)
	{
		throw "Essa operação excede a capacidade da sala."
	}

	else
		listaFileiras.busca(fileira)->setQtdeAssentos(novaQtde);
}

bool Sala::verificaDispAssento(char fileira, int assento)
{
	listaFileiras.busca(fileira)->verificaDispAssento(assento);
}

void Sala::ocuparAssento(char fileira, int assento)
{
	listaFileiras.busca(fileira)->ocuparAssento(assento);
}

void Sala::desocuparAssento(char fileira, int assento)
{
	listaFileiras.busca(fileira)->desocuparAssento(assento);
}