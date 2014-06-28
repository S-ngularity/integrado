#ifndef INGRESSO_H
#define INGRESSO_H

#include <iostream>
#include "Sessao.h"

typedef enum {inteiro = 0, meia} Tipo;

class Ingresso
{
private:
	static int codAtual;

	int codIngresso;

	Horario dtIngresso;
	double valor;
	Tipo tipo;
	char fileira;
	int assento;

	Sessao *sessao;

public:
	Ingresso(Tipo t, double val, Sessao &sessao, char f, int a);

	int getCodIngresso();

	Horario getDtIngresso();
	void setDtIngresso(Horario dtIngresso);

	int getNumSala();
	char getIdFileira();
	int getIdAssento();
	string getFilme();
	Horario getHorario();

	double getValor();
	void setValor(double valor);

	Tipo getTipo();
	void setTipo(Tipo novoTipo);
};

#endif