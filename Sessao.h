#ifndef SESSAO_H
#define SESSAO_H

#include <iostream>
using std::string;
#include "Sala.h"
#include "Horario.h"

class Sessao{

//---------Atributos----------------------------------
	private:
		Horario horario; //horario possui data também
		bool encerrada;
		int numVendido;
		string filme;
		Sala *sala;

//-----------Metodos------------------------------------
	public:
		bool getStatus(); //retorna encerrada
		void setStatus(bool encerrada); //altera encerrada

		Horario getHorario(); //discutir implementacao
		void setHorario(Horario novoHorario);

		//Data getData();
		//void setData(Data novaData); // precisa?

		bool getDisponivel();

		void setNumVendido(int numVendido);

		string getFilme();
		void setFilme(string nomeFilme);

		Sala * getSala();
		//void alteraSalaSessao(Sala &sal);


//----------Construtores e Destrutores--------------------------------
	public:
		Sessao(string filme, Sala *sal, int dia, int mes, int ano, int hora, int min);
		Sessao(string filme, Sala *sal, int hora, int min); //Com data corrente no sistema
};

#endif