#include "venda.h"

int Venda::codAtual = 1;

Venda::Venda(Sessao &s) : dtVenda()
{
	sessao = &s;

	codVenda = codAtual;
	codAtual++;
}

Venda::~Venda()
{
	Ingresso *temp;

	temp = listaIngressos.getPrimeiro();

	sessao->desocuparAssento(temp->getIdFileira(), temp->getIdAssento());

	listaIngressos.removeIngresso(temp->getCodIngresso());
}

int Venda::getCodVenda()
{
	return codVenda;
}

double Venda::calcularValorTotal()
{
	return listaIngressos.getValorTotal();
}

void Venda::emitirIngresso()
{
	sessao->setNumVendido(listaIngressos.qtdeElementos());
}

void Venda::addIngresso(Ingresso &ingresso)
{
	sessao->ocuparAssento(ingresso.getIdFileira(), ingresso.getIdAssento());

	listaIngressos.insere(&ingresso);
}

void Venda::removeIngresso(int cod)
{
	Ingresso *temp;

	temp = listaIngressos.busca(cod);

	sessao->desocuparAssento(temp->getIdFileira(), temp->getIdAssento());

	listaIngressos.removeIngresso(cod);
}

void Venda::listarIngressos()
{
	listaIngressos.imprimirTodos();
}