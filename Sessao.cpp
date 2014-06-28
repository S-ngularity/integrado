#include "Sessao.h"

int Sessao::codAtual = 1;

Sessao::Sessao(string filme, Horario hI, Horario hF, Sala *sal) : horarioInicio(hI), horarioFim(hF)
{
	if(sal->getSituacao() != disponivel)
		throw "Sala indisponível";

	sala = new Sala(*sal);

	codSessao = codAtual;
	codAtual++;
	encerrada = false;
	numVendido = 0;
	Sessao::filme = filme;
}

Sessao::~Sessao()
{
	delete sala;
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

int Sessao::getNumVendido()
{
	return numVendido;
}

void Sessao::setNumVendido(int numVendido){
	if(Sessao::numVendido + numVendido > sala->getTotalAssentos())
		throw "Essa operação excede a capacidade da sala.";

	else
		Sessao::numVendido += numVendido;
}

int Sessao::getNumSala()
{
	return sala->getNumSala();
}

int Sessao::getCapacidadeSala()
{
	return sala->getCapacidade();
}

string Sessao::getFilme(){
	return filme;
}

void Sessao::setFilme(string nomeFilme){
	Sessao::filme = filme;
}

void Sessao::imprimirSala()
{
	cout << *sala << endl;
}

bool Sessao::verificaDispAssento(char fileira, int assento)
{
	return sala->verificaDispAssento(fileira, assento);
}

void Sessao::ocuparAssento(char fileira, int assento)
{
	sala->ocuparAssento(fileira, assento);
}

void Sessao::desocuparAssento(char fileira, int assento)
{
	sala->desocuparAssento(fileira, assento);
}