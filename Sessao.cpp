#include "Sessao.h"

bool Sessao::getStatus(){
	return encerrada;
}

void Sessao::setStatus(bool encerrada){
	Sessao::encerrada = encerrada;
}

Horario Sessao::getHorario(){
	return horario;
}

void Sessao::setHorario(Horario novoHorario){
	horario = novoHorario;
}

/*Data Sessao::getData(){
	return Data(horario.getDia(), horario.getMes(), horario.getAno());
}

void Sessao::setData(Data novaData){
	horario.setDia(novaData.getDia());
	horario.setMes(novaData.getMes());
	horario.setAno(novaData.getAno()));
}*/

bool Sessao::getDisponivel(){
	if(numVendido < sala->getCapacidade() && getStatus() == false) //verificar horario depois aqui também
		return true;

	return false;
}

void Sessao::setNumVendido(int numVendido){
	Sessao::numVendido += numVendido;
}

string Sessao::getFilme(){
	return filme;
}

void Sessao::setFilme(string nomeFilme){
	Sessao::filme = filme;
}

Sala * Sessao::getSala(){
	return sala;
}

Sessao::Sessao(string filme, Sala *sal, Horario h) : horario(h)
{
	if(sala->getSituacao() != disponivel)
		throw "Sala indisponivel"

	Sessao::filme = filme;
	sala = sal;
}