#ifndef VENDA_H
#define VENDA_H

#include "Ingresso.h"
#include "ListaIngresso.h"

class Venda
{
private:
	static int codAtual;

	int codVenda;
	Horario dtVenda;
	Sessao *sessao;
	ListaIngresso listaIngressos;

public:
	Venda(Sessao &s);
	~Venda();

	int getCodVenda();

	double calcularValorTotal();

	void emitirIngresso();

	void addIngresso(Ingresso &ingresso);
	void removeIngresso(int cod);
	void removeTodosIngressos();

	void listarIngressos();
};

#endif