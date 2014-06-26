#include "Sala.h"

int Sala::getNumSala(){

	return numSala;
}

void Sala::setNumSala(int numSala){

	Sala::numSala = numSala;
}

int Sala::getCapacidade(){
	return capacidade;
}

void Sala::setCapacidade(int qtde){
	int diferencafileira = qtde /assentosFileira + (qtde % assentosFileira > 0) - qtdeFileiras;
	if(diferencafileira < 0)
	{
		diferencafileira = -1 * diferencafileira;
		for(int i = 0; i < diferencafileira; i++)
			fila.remove();
	}
	else
	{
		Fileira *temporario;

		for(int i = 0; i < diferencafileira; i++)
		{
			temporario = new Fileira('A' + qtdeFileiras + i, assentosFileira);
			fila.insere(temporario);
		}
	}
	capacidade = qtde;
	qtdeFileiras = capacidade / assentosFileira + (capacidade % assentosFileira > 0);
}

string Sala::getSituacao(){
	return situacao;
}

void Sala::setSituacao(Estado alteracao){
	if(alteracao >= 0 && alteracao < 4)
		situacao = alteracao;

	else
		throw "Situacao invalida";
}

/*int Sala::getQtdeAssentosFileiras(){
	return assentosFileira;
}
void Sala::setQtdeAssentosFileiras( int qtde){
	Fileira * temp;
	int difenca = capacidade / qtde + (capacidade % qtde > 0) - qtdeFileiras;

	if(difenca < 0)
	{
		difenca = -1 * difenca;
		for(int i = 0; i < difenca; i++)
			fila.remove();
	}
	else
	{
		for(int i = 0; i < difenca; i++)
		{
			temp = new Fileira('A' + qtdeFileiras + i, assentosFileira);
			fila.insere(temp);
		}
	}

	qtdeFileiras = capacidade / qtde + (capacidade % qtde > 0);

	fila.setQtdeAssentos(qtde);

	assentosFileira = qtde;
}*/

Fileira *Sala::getFileira(char id){


	return fila.busca(id);
}

Sala::Sala(int num, int capacidade, int assentosFileira):fila(), qtdeFileiras(capacidade / assentosFileira),numSala(num){
	Sala::capacidade = capacidade;
	Sala::assentosFileira = assentosFileira;
	Sala::situacao = disponivel;
	Fileira *temporario;


	int i;
	Fileira::numFileira = -1;
	for(i = 0; i < qtdeFileiras; i++)
	{
		temporario = new Fileira('A' + i, assentosFileira);
		fila.insere(temporario);

	}


	if(capacidade % assentosFileira > 0)
	{
		temporario = new Fileira('A' + i, capacidade % assentosFileira);
		fila.insere(temporario);
		qtdeFileiras++;

	}


}

Sala::~Sala(){}
