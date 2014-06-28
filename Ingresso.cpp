#include "Ingresso.h"

int Ingresso::codAtual = 1;

Ingresso::Ingresso(Tipo t, double val, Sessao &sessao, char f, int a)
{
	tipo = t;
	valor = val;
	fileira = f;
	assento = a;

	Ingresso::sessao = &sessao;

	codIngresso = codAtual;
	codAtual++;

	dtIngresso = Ingresso::sessao->getHorarioInicio();
}

int Ingresso::getCodIngresso()
{
	return codIngresso;
}

Horario Ingresso::getDtIngresso()
{
	return dtIngresso;
}

void Ingresso::setDtIngresso(Horario dtIngresso)
{
	Ingresso::dtIngresso = dtIngresso;
}

int Ingresso::getNumSala()
{
	return sessao->getNumSala();
}

char Ingresso::getIdFileira()
{
	return fileira;
}

int Ingresso::getIdAssento()
{
	return assento;
}

string Ingresso::getFilme()
{
	return sessao->getFilme();
}

Horario Ingresso::getHorario()
{
	return dtIngresso;
}

double Ingresso::getValor()
{
	return valor;
}

void Ingresso::setValor(double valor)
{
	Ingresso::valor = valor;
}

Tipo Ingresso::getTipo()
{
	return tipo;
}

void Ingresso::setTipo(Tipo novoTipo)
{
	tipo = novoTipo;
}