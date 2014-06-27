#include "Ingresso.h"

Ingresso::Ingresso(Sessao &sessao, Assento &assento)
{
	Ingresso::sessao = &sessao;
	Ingresso::assento = &assento;
}

int Ingresso::getCodIngresso()
{
	return codIngresso;
}

void Ingresso::setCodIngresso(int novoCod)
{
	codIngresso = novoCod;
}

Horario Ingresso::getDtIngresso()
{
	return dtIngresso;
}

void Ingresso::setDtIngresso(Horario dtIngresso)
{
	Ingresso::dtIngresso = dtIngresso;
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