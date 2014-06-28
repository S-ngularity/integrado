#include "Assento.h"
#include <iomanip> //setw()

Assento::Assento(char idFileira, int idAssento)
{
	Assento::idFileira = idFileira;
	Assento::idAssento = idAssento;
	Assento::disponibilidade = true;
}

Assento::Assento(Assento &a){
	idFileira = a.idFileira;
	idAssento = a.idAssento;
	disponibilidade = a.disponibilidade;
}

bool Assento::verificaDisponibilidade()
{
	return disponibilidade;
}

void Assento::ocuparAssento()
{
	disponibilidade = false;
}

void Assento::desocuparAssento()
{
	disponibilidade = true;
}

int Assento::getIdAssento()
{
	return idAssento;
}

void Assento::setIdAssento(int id)
{
	idAssento = id;
}

char Assento::getIdFileira()
{
	return idFileira;
}

ostream &operator<<(ostream &o, Assento &a){
	if(a.disponibilidade == true)
		o << " | " << setw(3) << setfill('0') << a.idAssento<< " |" << setfill(' ');

	else
		o << " . " << setw(3) << setfill('0') << a.idAssento<< " ." << setfill(' ');

	return o;
}