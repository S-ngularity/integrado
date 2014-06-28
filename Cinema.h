#ifndef CINEMA_H
#define CINEMA_H

#include "Horario.h"
#include "ListaSala.h"
#include "ListaSessao.h"
#include "ListaVenda.h"

#include <iostream>
using namespace std;

class Cinema{

	private:
		ListaSala listaSalas;
		ListaSessao listaSessoes;
		ListaVenda listaVendas;

		//metodos de Interface
		void telaInicial();
		void opcaoSala();
		void opcaoSessao();
		void venderIngresso();
		void cadastrarSala();
		void editarSala();
		void cadastrarSessao();
		void excluirSessao();
		void novaVenda();
		bool confirmacao();
		void clearScreen();
		//-----------------------

	public:
		Cinema(); // onde vai ler arquivos e iniciar menu
		~Cinema(); //onde vai gravar as listas em arquivos e encerrar o programa

};


#endif