#ifndef SESSAO_H
#define SESSAO_H

#include <iostream>
using std::string;
#include "Sala.h"
#include "Horario.h"

class Sessao{

//---------Atributos----------------------------------
	private:
		Horario horarioInicio; //horario possui data também
		Horario horarioFim;
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

		bool getDisponivel();

		void setNumVendido(int numVendido);

		string getFilme();
		void setFilme(string nomeFilme);

		Sala * getSala();
		//void alteraSalaSessao(Sala &sal);


//----------Construtores e Destrutores--------------------------------
	public:
		Sessao(string filme, Sala *sal, Horario h);
};

#endif