#include "Sala.h"
#include <iomanip>

const string Sala::stringSituacao[4] = {"disponivel", "manutenção de equipamento", "reforma", "manutenção geral"};

Sala::Sala(int num, int cap) : listaFileiras()
{
	numSala = num;
	capacidade = cap;
	situacao = disponivel;
	totalAssentosAtual = 0;
}

Sala::Sala(Sala &s) : listaFileiras(s.listaFileiras)
{
	situacao = s.situacao;
	numSala = s.numSala;
	capacidade = s.capacidade;
	totalAssentosAtual = s.totalAssentosAtual;
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
		throw "Nova capacidade é menor do que quantidade de assentos. Remova assentos antes de alterar capacidade.";
	}

	else
		capacidade = novaCap;
}

int Sala::getTotalAssentos()
{
	return totalAssentosAtual;
}

Situacao Sala::getSituacao()
{
	return situacao;
}

string Sala::getStringSituacao()
{
	Situacao temp;
	temp = getSituacao();
	switch(temp){
		case 0:
			return stringSituacao[0];

		case 1:
			return stringSituacao[1];

		case 2: 
			return stringSituacao[2];

		case 3:
			return stringSituacao[3];
	}
}

void Sala::setSituacao(Situacao alteracao)
{
	if(alteracao >= 0 && alteracao <= 3)
		situacao = alteracao;

	else
		throw "Situacao inválida.";
}

int Sala::getQtdFileiras()
{
	return listaFileiras.qtdeElementos();
}

void Sala::addFileirasComAssentos(int qtdeFileiras, int assentosPorFileira)
{
	Fileira *temp;

	if(totalAssentosAtual + qtdeFileiras * assentosPorFileira > getCapacidade())
	{
		throw "Essa operação excede a capacidade da sala.";
	}

	else
	{
		for(int i = 0; i < qtdeFileiras; i++)
		{
			temp = new Fileira('@' + getQtdFileiras() + 1, assentosPorFileira);

			listaFileiras.insere(temp);
		}

		totalAssentosAtual += qtdeFileiras * assentosPorFileira;

		//listaFileiras.renameAllAssentos();
	}
}

void Sala::removeFileira(char fileira)
{
	listaFileiras.removeFileira(fileira);
	totalAssentosAtual = listaFileiras.getQtdeAssentos();
	//listaFileiras.renameAllAssentos();
}

int Sala::getQtdAssentosNaFileira(char fileira)
{
	return listaFileiras.busca(fileira)->getQtdeAssentos();
}

void Sala::setQtdeAssentosNaFileira(char fileira, int novaQtde)
{
	if(totalAssentosAtual - listaFileiras.busca(fileira)->getQtdeAssentos() + novaQtde > capacidade)
	{
		throw "Essa operação excede a capacidade da sala.";
	}

	else
	{
		totalAssentosAtual = totalAssentosAtual - listaFileiras.busca(fileira)->getQtdeAssentos() + novaQtde;
		listaFileiras.busca(fileira)->setQtdeAssentos(novaQtde);
		//listaFileiras.renameAllAssentos();
	}
}

bool Sala::verificaDispAssento(char fileira, int assento)
{
	return listaFileiras.busca(fileira)->verificaDispAssento(assento);
}

void Sala::ocuparAssento(char fileira, int assento)
{
	listaFileiras.busca(fileira)->ocuparAssento(assento);
}

void Sala::desocuparAssento(char fileira, int assento)
{
	listaFileiras.busca(fileira)->desocuparAssento(assento);
}

ostream &operator<<(ostream &o, Sala &s){
	s.listaFileiras.imprimirListaFileira();
	o << endl << "Sala" << s.numSala << " -- Capacidade: " << s.capacidade << " -- Total de assentos: " << s.totalAssentosAtual << " -- Situação: " << s.getStringSituacao() << endl; //setw(6)

	return o;
}