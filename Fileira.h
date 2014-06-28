#ifndef FILEIRA_H
#define FILEIRA_H

#include "ListaAssento.h"

class Fileira
{

friend ostream &operator<<(ostream &o, Fileira &f);

private:
	int qtdeAssentos;
	char idFileira;
	ListaAssento listaAssentos;
public:
	Fileira(char id, int qtdAssentosFileira);
	Fileira(Fileira &f);
	~Fileira();

	bool verificaDispAssento(int assento);

	void ocuparAssento(int num);
	void desocuparAssento(int num);

	int getQtdeAssentos();
	void setQtdeAssentos(int novaQtde);

	char getIdFileira();
	void setIdFileira(char id);

	//void renameAll(int id);
};

#endif