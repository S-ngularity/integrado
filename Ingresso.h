#ifndef INGRESSO_H
#define INGRESSO_H

#include "Sessao.h"

typedef enum {inteiro = 0, meia} Tipo;

class Ingresso
{
private:
	Sessao *sessao;
	Assento *assento;
	Horario dtIngresso;
	double valor;
	Tipo tipo;

public:
	Ingresso(Sessao sessao, Assento assento);

	Horario getDtIngresso();
	void setDtIngresso(Horario dtIngresso);

	double getValor();
	void setValor(double valor);

	Tipo getTipo();
	void setTipo(Tipo novoTipo);
};

#endif