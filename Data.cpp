#include "Data.h"
#include <iomanip>

const string Data::textoMes[12] = {"janeiro", "fevereiro", "março", "abril", "maio",
										 "junho", "julho", "agosto", "setembro", "outubro",
										 "novembro", "dezembro"};

int Data::getDia(){
	return dia;
}
void Data::setDia(int dia){
	if(dia > 0 && dia < 32)
		Data::dia = dia;
	else
		throw "Dia invalido";
}
int Data::getMes(){
	return mes;
}
string Data::getStringMes(){
	return textoMes[mes - 1];
}
void Data::setMes(int mes){
	if(mes > 0 && mes < 13)
		Data::mes = mes;
	else
		throw "Mes invalido";
}
int Data::getAno(){
	return ano;
}
void Data::setAno(int ano){
	if(ano > 0)
		Data::ano = ano;
	else
		throw "Ano invalido";
}


Data::Data(int dia, int mes, int ano)
{
	setDia(dia);
	setMes(mes);
	setAno(ano);
}

Data::Data(){
	struct tm *local;
	time_t t;
	t= time(NULL);
	local=localtime(&t);

	dia = local->tm_mday;
	mes = local->tm_mon + 1;
	ano = local->tm_year + 1900;
}

ostream &operator<<(ostream &o, Data &d){
	o << setw(2) << setfill('0') << d.dia << "/" << setw(2) << setfill('0') << d.mes << "/" << d.ano;

	return o;
}

//sobrecarga do operador >>
istream &operator>> (istream &i, Data &d) {
	do{
		i >> d.dia;
		i.ignore(); // pula 1, no caso /
		i >> d.mes;
		i.ignore(); // pula 1, no caso /
		i >> d.ano;

		if(d.mes <= 0 || d.mes > 12)
			cout << "Mês Inválido, digite uma data válida!" <<endl;

		if(d.dia <= 0 || d.dia > 31)
			cout << "Dia inválido, digite uma data válida!" <<endl;

	}while(d.mes <= 0 || d.mes > 12 || d.dia <= 0 || d.dia > 31);
	
	return i;
}