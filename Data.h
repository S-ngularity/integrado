#ifndef DATA_H
#define DATA_H

#include <iostream>
#include <ctime>

using namespace std;

class Data{

	friend ostream &operator<<(ostream &o, Data &d); //sobrecarga out
	friend istream &operator>> (istream &i, Data &d); //sobrecarga in

//---------Atributos----------------------------------
	private:
		int dia, mes, ano;
		int hora, minuto;
		static const std::string textoMes[12];

//-----------Metodos------------------------------------
	public:
		int getDia();
		void setDia(int dia);
		int getMes();
		string getStringMes();
		void setMes(int mes);
		int getAno();
		void setAno(int ano);


//----------Construtores e Destrutores--------------------------------

	public:
		Data(int dia, int mes, int ano);//Com data informada
		Data(); // Com data do sistema

};


#endif