#ifndef ASSENTO_H
#define ASSENTO_H

#include <iostream>
using namespace std;

class Assento
{

friend ostream &operator<<(ostream &o, Assento &a);

private:
	char idFileira;
	int idAssento;
	bool disponibilidade;

public:
	Assento(char idFileira, int idAssento);
	Assento(Assento &a);

	int getIdAssento();
	void setIdAssento(int id);

	char getIdFileira();

	bool verificaDisponibilidade();

	void ocuparAssento();
	void desocuparAssento();
};

#endif