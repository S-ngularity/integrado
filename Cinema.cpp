#include "Cinema.h"
using namespace std;

Cinema::Cinema(){
	telaInicial();
}
Cinema::~Cinema(){}

void Cinema::telaInicial(){
	int opcao;

	do{
		clearScreen();
		cout << endl;
		cout << "1. Gerenciar salas" << endl << endl;
		cout << "2. Gerenciar sessões" << endl << endl;
		cout << "3. Venda" << endl << endl;
		cout << "4. Sair" << endl << endl;
		cout << "Escolha uma opcao ";
		cin >> opcao;
		cout << endl;

		switch(opcao){
			case 1:
				opcaoSala();
			break;
			case 2:
				opcaoSessao();
			break;
			case 3:
				venderIngresso();
			break;
			case 4:
			break;
			default:
				cout << "Opção inválida" << endl;
		}

		cout << endl;
	}while(opcao!=4);
	cout << endl ;
}

void Cinema::opcaoSala(){
	int opcao;

	do{
		clearScreen();
		cout << endl;
		cout << "1. Cadastrar sala" << endl << endl;
		cout << "2. Editar sala" << endl << endl;
		cout << "3. Voltar ao menu principal" << endl << endl;
		cout << "Escolha uma opção: ";
		cin >> opcao;

		cout << endl;

		switch(opcao){
			case 1:
				cadastrarSala();
			break;
			case 2:
				editarSala();
			break;
			case 3:
			break;
			default:
				cout << "Opção inválida" << endl;


		}
		cout << endl;
	}while(opcao!=3);
}

void Cinema::cadastrarSala(){
	int numSala;
	int capacidade;
	int qtdeFileiras;
	int qtdeAssentosFileira;
	int opcao;
	char idFileira;

	clearScreen();

	do{
		cout << endl << "Informe o número da sala (maior que 0): " << endl;
		cin >> numSala;
	}while(numSala <= 0);

	do{
		cout << endl << "Informe a capacidade da sala (maior que 0): " << endl;
		cin >> capacidade;
	}while(capacidade <= 0);

	clearScreen();

	Sala *salaTemp;
	salaTemp = new Sala(numSala, capacidade);

	do
	{
		cout << endl << *salaTemp << endl << endl;

		cout << "1. Adicionar fileira(s)"<< endl << endl;
		cout << "2. Excluir uma fileira" << endl << endl;
		cout << "3. Alterar número de assentos de uma fileira" << endl << endl;
		cout << "4. Alterar número da sala" << endl << endl;
		cout << "5. Confirmar" << endl << endl;
		cout << "6. Cancelar" << endl << endl;
		cout << "Escolha uma opção: ";

		cin >> opcao;

		switch(opcao)
		{
			case 1:
				clearScreen();
				cout << *salaTemp << endl;

				do{
					cout << endl << "Quantidade de fileiras (maior que 0): " << endl;
					cin >> qtdeFileiras;
				}while(qtdeFileiras <= 0);

				do{
					cout << endl <<"Quantidade de assentos por fileira (maior que 0): " << endl;
					cin >> qtdeAssentosFileira;
				}while(qtdeAssentosFileira <= 0);
				
				try{
					salaTemp->addFileirasComAssentos(qtdeFileiras, qtdeAssentosFileira);
					clearScreen();
					cout << "Fileira(s) adicionada com sucesso." << endl << endl << endl;
				} // catch(bad_alloc) / catch(const char *s) do erro de exceder capacidade ?

				catch(const char *s) {clearScreen(); cout << endl << s << endl << endl << endl; }
			break;

			case 2:
				clearScreen();
				cout << *salaTemp << endl;

				cout << "Informe fileira: " << endl;
				cin >> idFileira;

				try{
					salaTemp->removeFileira(idFileira);
					clearScreen();
					cout << "Fileira " << idFileira << " removida com sucesso." << endl << endl << endl;
				}

				catch(const char *s) {clearScreen(); cout << endl << s << endl << endl << endl; }
			break;

			case 3:
				clearScreen();
				cout << *salaTemp << endl;

				cout << "Informe fileira: "<< endl;
				cin >> idFileira;

				do{
					cout << "Informe novo número de assentos (maior que 0): " << endl;
					cin >> qtdeAssentosFileira;
				}while(qtdeAssentosFileira <= 0);

				try{
					salaTemp->setQtdeAssentosNaFileira(idFileira, qtdeAssentosFileira);
					clearScreen();
					cout << "Fileira alterada com sucesso." << endl << endl << endl;
				}// catch(bad_alloc) / catch(const char *s) do erro de exceder capacidade ?

				catch(const char *s) {clearScreen(); cout << endl << s << endl << endl << endl; }
			break;

			case 4:
				clearScreen();
				cout << *salaTemp << endl;

				do{
					cout << endl << "Informe o novo número da sala (maior que 0): " << endl;
					cin >> numSala;
				}while(numSala <= 0);

				salaTemp->setNumSala(numSala);
				clearScreen();
			break;

			case 5:
				listaSalas.insere(salaTemp); // catch(bad_alloc) ?
			break;

			case 6:
				delete salaTemp;
			break;

			default:
				cout << "Opção inválida." << endl << endl << endl;
		}
	}while(opcao != 5 && opcao != 6);
}

void Cinema::editarSala(){
	int opcao;

	int numSala, novaQtd, novaCapacidade;;

	char idFileira;

	Sala *salaEscolhida;

	do{		
		clearScreen();
		cout << "Salas existentes:" << endl << endl;
		listaSalas.imprimirListaSala();

		do{
			do{
				cout << endl << "Informe o número da sala (0 para voltar): " << endl;
				cin >> numSala;
			}while(numSala < 0);

			if(numSala == 0)
				break;

			try{
				salaEscolhida = NULL;
				salaEscolhida = listaSalas.busca(numSala);
				clearScreen();
			}

			catch(const char *s) { cout << endl << s << endl << endl << endl; }
		}while(salaEscolhida == NULL);

		if(numSala == 0)
			break;

		do{
			cout << *salaEscolhida << endl << endl;

			cout << "1. Adicionar uma fileira" << endl << endl;
			cout << "2. Alterar número de assentos de uma fileira" << endl << endl;
			cout << "3. Excluir uma fileira" << endl << endl;
			cout << "4. Alterar capacidade da sala" << endl << endl;
			cout << "5. Alterar a situação da sala" << endl << endl;
			cout << "6. Excluir sala" << endl << endl;
			cout << "7. Editar outra sala" << endl << endl;
			cout << "8. Voltar ao menu sala" << endl << endl;
			cout << "Escolha uma opcao ";
			cin >> opcao;

			cout << endl;

			switch(opcao){
				case 1:
					do{
						cout << endl <<"Quantidade de assentos na fileira (maior que 0): " << endl;
						cin >> novaQtd;
					}while(novaQtd <= 0);
				
					try{
						salaEscolhida->addFileirasComAssentos(1, novaQtd);
						clearScreen();
						cout << "Fileira(s) adicionada com sucesso." << endl << endl << endl;
					} // catch(bad_alloc) / catch(const char *s) do erro de exceder capacidade ?

					catch(const char *s) {clearScreen(); cout << endl << s << endl << endl << endl; }
				break;

				case 2:
					clearScreen();
					cout << *salaEscolhida << endl;

					cout << "Informe fileira: "<< endl;
					cin >> idFileira;

					do{
						cout << "Informe novo número de assentos (maior que 0): " << endl;
						cin >> novaQtd;
					}while(novaQtd <= 0);

					try{
						salaEscolhida->setQtdeAssentosNaFileira(idFileira, novaQtd);
						clearScreen();
						cout << "Fileira alterada com sucesso." << endl << endl << endl;
					}// catch(bad_alloc) / catch(const char *s) do erro de exceder capacidade ?

					catch(const char *s) {clearScreen(); cout << endl << s << endl << endl << endl; }
				break;

				case 3:
					clearScreen();
					cout << *salaEscolhida << endl;

					cout << "Informe fileira: "<< endl;
					cin >> idFileira;

					try{
						salaEscolhida->removeFileira(idFileira);
						clearScreen();
						cout << "Fileira " << idFileira << " removida com sucesso." << endl << endl << endl;
					}

					catch(const char *s) {clearScreen(); cout << endl << s << endl << endl << endl; }
				break;

				case 4:
					clearScreen();
					cout << *salaEscolhida << endl;

					cout << "Informe nova capacidade: " << endl;
					cin >> novaCapacidade;

					try{
						salaEscolhida->setCapacidade(novaCapacidade);
						clearScreen();
						cout << "Capacidade alterada com sucesso." << endl << endl << endl;
					} // catch(const char *s) do erro de exceder capacidade ?

					catch(const char *s) {clearScreen(); cout << endl << s << endl << endl << endl; }
				break;

				case 5:
					clearScreen();
					cout << *salaEscolhida << endl;

					int opcSituacao;

					cout << endl << "Opções" << endl;
					cout << " 1. Disponível" << endl << endl;
					cout << " 2. Manutenção de equipamento" << endl << endl;
					cout << " 3. Reforma" << endl << endl;
					cout << " 4. Manutenção geral" << endl << endl;

					cout << endl << "Informe a nova situação da sala: " << endl;
					cin >> opcSituacao;

					switch(opcSituacao)
					{
						case 1:
							salaEscolhida->setSituacao(disponivel);
							clearScreen();
							cout << endl << "Situacao da sala alterada com sucesso." << endl << endl << endl;
						break;

						case 2:
							salaEscolhida->setSituacao(manuEquipamento);
							clearScreen();
							cout << endl << "Situacao da sala alterada com sucesso." << endl << endl << endl;
						break;

						case 3:
							salaEscolhida->setSituacao(reforma);
							clearScreen();
							cout << endl << "Situacao da sala alterada com sucesso." << endl << endl << endl;
						break;

						case 4:
							salaEscolhida->setSituacao(manuGeral);
							clearScreen();
							cout << endl << "Situacao da sala alterada com sucesso." << endl << endl << endl;
						break;

						default:
							clearScreen();
							cout << endl << "Situacao inválida." << endl << endl << endl;
					}
				break;

				case 6:
					clearScreen();
					cout << *salaEscolhida << endl;

					if(confirmacao())
					{
						listaSalas.removerSala(numSala);
						cout << "Sala removida com sucesso." << endl << endl << endl;
					}
					
					else
					{
						clearScreen();
						opcao = 0;
					}
				break;

				case 7:
				break;

				case 8:
				break;

				default:
					cout << "Opção inválida." << endl << endl << endl;
			}

			cout << endl;

		}while(opcao != 6 && opcao != 7 && opcao != 8);

	}while(opcao != 6 && opcao != 7);

}

void Cinema::opcaoSessao(){
	int opcao;

	do{
		clearScreen();
		listaSessoes.imprimirTodas();

		cout << endl;
		cout << "1. Cadastrar sessão" << endl << endl;
		cout << "2. Excluir sessão" << endl << endl;
		cout << "3. Voltar ao Menu Principal" << endl << endl;
		cout << "Escolha uma opção: ";
		cin >> opcao;

		//salaEscolhida = listaSalas.busca(numSala);

		switch(opcao)
		{
			case 1:
				cadastrarSessao();
			break;

			case 2:
				excluirSessao();
			break;

			case 3:
			break;

			default:
				cout << "Opção inválida." << endl << endl << endl;
		}
	}while(opcao != 3);
}

void Cinema::cadastrarSessao(){
	Sessao *novaSessao;
	Sala *salaEscolhida;
	int numSala;
	Horario hInicio, hFim;
	string filme;

	clearScreen();

	cout << "Informe o nome do filme ";
	cin >> filme;

	cout << endl << "Informe o horário de início (hh:mm): " << endl;
	cin >> hInicio;

	cout << endl << "Informe o horário de fim (hh:mm): " << endl;
	cin >> hFim;

	//listarSalasDisponiveis // salas que tem um período livre de pelo menos tanto quanto o período entre hInicio e hFim // FUCKING HARD MODE

	do{
		cout << endl << endl << "Salas: " << endl;
		listaSalas.imprimirListaSala();

		do{
			cout << "Informe o número da sala para a sessão (0 para voltar): " << endl;
			cin >> numSala;
		}while(numSala < 0);

		if(numSala == 0)
			break;

		try{
			salaEscolhida = NULL;
			salaEscolhida = listaSalas.busca(numSala);
		}

		catch(const char *s) { cout << endl << endl << endl << s << endl << endl; }
	}while(salaEscolhida == NULL);

	// confirmar se sala escolhida tem período disponível, se não mostrar erro // HARD MODE (dica no txt da interface)

	if(numSala != 0)
	{
		try{ novaSessao = new Sessao(filme, hInicio, hFim, salaEscolhida); }
		catch(const char *s) { cout << endl << s << endl << endl << endl; }

		listaSessoes.insere(novaSessao); //INSERIR ORDENADO (por hInicio -- util para se for checar se há período na sala)
	}
}

void Cinema::excluirSessao()
{
	int codSessao;
	Sessao *sessaoEscolhida;

	clearScreen();

	listaSessoes.imprimirTodas();

	do{
		do{
			cout << endl << "Informe o código da sessão a excluir (0 para voltar): " << endl;
			cin >> codSessao;
		}while(codSessao < 0);

		if(codSessao == 0)
			break;

		try{
			sessaoEscolhida = NULL;
			sessaoEscolhida = listaSessoes.busca(codSessao);
		}

		catch(const char *s) { cout << endl << s << endl << endl << endl; }
	}while(sessaoEscolhida == NULL);

	if(codSessao != 0)
		listaSessoes.removeSessao(codSessao);
}

void Cinema::venderIngresso(){
	int opcao;

	do{
		clearScreen();
		listaSessoes.imprimirDisponiveis();

		cout << "1. Iniciar nova venda: " << endl << endl;
		cout << "2. Voltar ao menu principal" << endl << endl;
		cout << "Escolha uma opção: ";
		cin >> opcao;
		cout << endl;

		switch(opcao){
			case 1:
				novaVenda();
			break;

			case 2:
			break;

			default:
				cout << "Opção inválida." << endl << endl << endl;
		}
		cout << endl;
	}while(opcao != 2);
}

void Cinema::novaVenda(){
	Venda *novaVenda;
	Sessao *sessaoEscolhida;
	Ingresso *tempIngresso;
	int opcao;
	int codSessao;

	clearScreen();
	listaSessoes.imprimirDisponiveis();
	cout << endl << endl << endl;

	do{
		do{
			cout << endl << "Informe o código da sessão (0 para voltar): " << endl;
			cin >> codSessao;
		}while(codSessao < 0);

		if(codSessao == 0)
			break;

		try{
			sessaoEscolhida = NULL;
			sessaoEscolhida = listaSessoes.busca(codSessao);
		}

		catch(const char *s) { cout << endl << s << endl << endl << endl; }
	}while(sessaoEscolhida == NULL);

	if(codSessao == 0)
		return;

	novaVenda = new Venda(*sessaoEscolhida);

	do{
		clearScreen();
		sessaoEscolhida->imprimirSala();

		novaVenda->listarIngressos();
		cout << endl;

		cout << "Valor total: R$" << novaVenda->calcularValorTotal() << endl << endl << endl;

		cout << "1. Adicionar novo ingresso" << endl << endl;
		cout << "2. Remover ingresso" << endl << endl;
		cout << "3. Confirmar venda" << endl << endl;
		cout << "4. Cancelar venda" << endl << endl;
		cout << "Escolha uma opcao ";
		cin >> opcao;
		cout << endl;

		switch(opcao){
			case 1:
				clearScreen();

				sessaoEscolhida->imprimirSala();

				char idFileira;
				int idAssento;
				bool disponivel;

				do{
					cout << endl;

					cout << "Informe a fileira: ";
					cin >> idFileira;

					cout << endl << "Informe o assento: ";
					cin >> idAssento;

					try{
						disponivel = sessaoEscolhida->verificaDispAssento(idFileira, idAssento);
					}

					catch(const char *s) {cout << endl << s << endl << endl << endl; }

					if(!disponivel)
						cout << "Assento indisponível. Selecione outro:" << endl << endl;
				}while(!disponivel);

				Tipo tipo;
				int opcaoTipo;

				do{
					cout << endl << endl;
					cout << "Informe o tipo do ingresso: " << endl;
					cout << "  1. Inteiro" << endl;
					cout << "  2. Meio" << endl;
					cin >> opcaoTipo;

					switch(opcaoTipo)
					{
						case 1:
							tipo = inteiro;
						break;

						case 2:
							tipo = meia;
						break;						

						default:
							cout << endl << "Tipo inválido." << endl << endl;
					}
				}while(opcaoTipo != 1 && opcaoTipo != 2);

				float valor;

				do{
					cout << endl << endl;
					cout << "Informe o valor do ingresso: ";
					cin >> valor;

					if(valor < 0)
						cout << "Valor inválido." << endl << endl;
				}while(valor < 0);

				tempIngresso = new Ingresso(tipo, valor, *sessaoEscolhida, idFileira, idAssento);

				novaVenda->addIngresso(*tempIngresso);

				tempIngresso = NULL;
			break;

			case 2:
				clearScreen();
				novaVenda->listarIngressos();

				int codIngresso;
	
				do{
					cout << "Remover ingresso número (0 para voltar): " << endl;
					cin >> codIngresso;
				}while(codIngresso < 0);

				if(codIngresso == 0)
					break;

				try{
					novaVenda->removeIngresso(codIngresso);
					clearScreen();
					cout << "Ingresso removido com sucesso." << endl << endl << endl;
				}

				catch(const char *s) {clearScreen(); cout << endl << endl << endl << s << endl << endl; }
			break;

			case 3:
				novaVenda->emitirIngresso();
				listaVendas.insere(novaVenda);
			break;

			case 4:
				delete novaVenda;
			break;

			default:
				cout << "Opcao inválida." << endl;
		}
	}while(opcao != 3 && opcao != 4);
}

bool Cinema::confirmacao(){
	char confirmacao;

	do
	{
		cout << "Digite s para sim e n para não: " << endl;
		cin >> confirmacao;

		if(confirmacao == 's' || confirmacao == 'S')
		{
			cout << "Operacao concluída." << endl;
			return true;

		}

		else if(confirmacao == 'n' || confirmacao == 'N')
		{
			cout << "Operacao cancelada." << endl;
			return false;
		}

		else
			cout << "Entrada inválida." << endl;
	}while(1);
}

void Cinema::clearScreen()
{
	cout << string( 100, '\n' );
}