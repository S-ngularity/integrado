#include "Ingresso.h"

Ingresso(Sessao &sessao, &Assento assento)
{
	Ingresso::sessao = &sessao;
	Ingresso::assento = &assento;
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

Tipo getTipo()
{
	return tipo;
}

void setTipo(Tipo novoTipo)
{
	tipo = novoTipo;
}