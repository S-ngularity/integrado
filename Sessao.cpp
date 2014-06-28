#include "Sessao.h"

Sessao::Sessao(string filme, Horario hI, Horario hF, Sala *sal) : horarioInicio(hI), horarioFim(hF), sala(sal)
{
	if(sala->getSituacao() != disponivel)
		throw "Sala indisponivel";

	Sessao::filme = filme;
}

Sessao::~Sessao()
{

}

int Sessao::getCodSessao()
{
	return codSessao;
}

void Sessao::setCodSessao(int novoCod)
{
	codSessao = novoCod;
}

bool Sessao::getStatus(){
	return encerrada;
}

void Sessao::setStatus(bool encerrada){
	Sessao::encerrada = encerrada;
}

Horario Sessao::getHorarioInicio(){
	return horarioInicio;
}

void Sessao::setHorarioInicio(Horario novoHorario){
	horarioInicio = novoHorario;
}

Horario Sessao::getHorarioFim(){
	return horarioFim;
}

void Sessao::setHorarioFim(Horario novoHorario){
	horarioFim = novoHorario;
}

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