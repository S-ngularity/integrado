#include "Horario.h"
#include <iomanip>

int Horario::getHora(){
	return hora;
}

void Horario::setHora(int hora){
	if(hora >= 0 && hora < 24)
		Horario::hora = hora;
	else
		throw "Hora inválida";

}

int Horario::getMinuto(){
	return minuto;
}

void Horario::setMinuto(int minuto){
	if(minuto >= 0 && minuto < 60)
		Horario::minuto = minuto;
	else
		throw "Minuto inválido";
}

void Horario::imprimeComData(){
	cout << setw(2) << setfill('0') << getDia() << "/" << setw(2) << setfill('0') << getMes() << "/" << getAno();
	cout << " ";
	cout << setw(2) << setfill('0') << getHora() << ":" << setw(2) << setfill('0') << getMinuto() ;
}

Horario::Horario(int hora, int minuto, int dia, int mes, int ano) : Data(dia, mes, ano)
{
	setHora(hora);
	setMinuto(minuto);
}

Horario::Horario(int hora, int minuto) : Data()
{
	setHora(hora);
	setMinuto(minuto);
}

Horario::Horario():
	Data()
{
	struct tm *local;
	time_t t;
	t= time(NULL);
	local=localtime(&t);

	hora = local->tm_hour;
	minuto = local->tm_min;
}

ostream &operator<<(ostream &o, Horario &h){
	o << setw(2) << setfill('0') << h.hora << ":" << setw(2) << setfill('0') << h.minuto ;

	return o;
}

//sobrecarga do operador >>
istream &operator>> (istream &i, Horario &h) {
	do{
		i >> h.hora;
		i.ignore(); // pula 1, no caso :
		i >> h.minuto;

		if(h.hora > 23 || h.hora < 0)
			cout << endl << "Hora inválida forneca um horario valido" << endl;

		if(h.minuto < 0 || h.minuto > 59)
			cout << endl << "Minuto invalido forneca um horario valido" << endl;
	}while(h.hora > 23 || h.hora < 0 || h.minuto < 0 || h.minuto > 59);

	return i;
}