#include "Cinema.h"
using namespace std;

Cinema::Cinema(){
	telaInicial();
}
Cinema::~Cinema(){}

void Cinema::telaInicial(){
	int opcao;

	do{
		cout << endl;
		cout << "1. Gerenciar salas" << endl;
		cout << "2. Gerenciar sessões" << endl;
		cout << "3. Venda" << endl;
		cout << "4. Sair" << endl;
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
		cout << endl;
		cout << "1. Cadastrar sala" << endl;
		cout << "2. Editar sala" << endl;
		cout << "3. Voltar ao menu principal" << endl;
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

	cout << "Informe o número da sala: " << endl;
	cin >> numSala;

	cout << "Informe a capacidade da sala: " << endl;
	cin >> capacidade;

	//Sala salaTemp(numSala, capacidade);

	do
	{
		//clear e imprime sala, opções em baixo

		cout << endl;
		cout << "1. Adicionar fileira(s)"<< endl;
		cout << "2. Excluir uma fileira" << endl;
		cout << "3. Alterar numero de assentos de uma fileira" << endl;
		cout << "4. Confirmar" << endl;
		cout << "Escolha uma opção: ";

		cin >> opcao;

		switch(opcao)
		{
			case 1:
				cout << "Quantidade de fileiras: ";
				cin >> qtdeFileiras;

				cout << "Quantidade de assentos por fileira: " << endl;
				cin >> qtdeAssentosFileira;
				
				//salaTemp.addFileirasComAssentos(qtdeFileiras, qtdeAssentosFileira); // catch(bad_alloc) / catch(string s) do erro de exceder capacidade ?
			break;

			case 2:
				cout << "Informe fileira: " << endl;
				cin >> idFileira;

				//salaTemp.removeFileira(idFileira);
			break;

			case 3:
				cout << "Informe fileira: "<< endl;
				cin >> idFileira;

				cout << "Informe novo número de assentos: " << endl;
				cin >> qtdeAssentosFileira;

				//salaTemp.setQtdeAssentosNaFileira(idFileira, qtdeAssentosFileira); // catch(bad_alloc) / catch(string s) do erro de exceder capacidade ?
			break;

			case 4:
			//adiciona na lista // catch(bad_alloc) ?

			break;

			case 5:
			//chama destrutor do temp // delete &salaTemp?
			break;

			default:
				cout << "Opção inválida." << endl;
		}
	}while(opcao != 4 && opcao != 5);
}

void Cinema::editarSala(){
	int opcao;
	int numSala;
	//Sala *salaEscolhida;
	int idFileira, qtdeAssentosFileira;
	int novaCapacidade;

	do{
		//listarSalasExistentes();

		cout << "Informe o número da sala: " << endl;
		cin >> numSala;

		//salaEscolhida = listaSalas.busca(numSala);

		do{
			//clear e imprime sala, opções em baixo

			cout << endl;
			cout << "1. Alterar número de assentos de uma fileira" << endl;
			cout << "2. Excluir uma fileira" << endl;
			cout << "3. Alterar capacidade da sala" << endl;
			cout << "4. Alterar a situação da sala" << endl;
			cout << "5. Excluir sala" << endl;
			cout << "6. Editar outra sala" << endl;
			cout << "7. Voltar ao menu Sala" << endl;
			cout << "Escolha uma opcao ";
			cin >> opcao;

			cout << endl;

			switch(opcao){
				case 1:
					cout << "Informe fileira: "<< endl;
					cin >> idFileira;

					cout << "Informe novo número de assentos: " << endl;
					cin >> qtdeAssentosFileira;

					//salaEscolhida.setQtdeAssentosNaFileira(idFileira, qtdeAssentosFileira); // catch(bad_alloc) / catch(string s) do erro de exceder capacidade ?
				break;

				case 2:
					cout << "Informe fileira: "<< endl;
					cin >> idFileira;

					//salaEscolhida.removeFileira(idFileira);
				break;

				case 3:
					cout << "Informe nova capacidade: " << endl; // catch(string s) do erro de exceder capacidade ?
					cin >> novaCapacidade;

					//salaEscolhida.setCapacidade(novaCapacidade);
				break;

				case 4:
					int opcSituacao;
					//Situacao novaSituacao;

					cout << "Situação atual: " << endl; // INFORMAR SITUAÇÃO ATUAL AQUI

					cout << endl << "Opções" << endl;
					cout << " 1. Disponível" << endl;
					cout << " 2. Manutenção de equipamento" << endl;
					cout << " 3. Reforma" << endl;
					cout << " 4. Manutenção geral" << endl;

					cout << endl << "Informe a nova situação da sala: " << endl;
					cin >> opcSituacao;

					/*switch(opcSituacao)
					{
						case 1:
							novaSituacao = disponivel;
						break;

						case 2:
							novaSituacao = manuEquipamento;
						break;

						case 3:
							novaSituacao = reforma;
						break;

						case 4:
							novaSituacao = manuGeral;
						break;
					}*/

					//salaEscolhida.setSituacao(novaSituacao);
				break;

				case 5:
					if(confirmacao())
					{
						//listaSalas.remove(numSala);
						cout << "Sala removida com sucesso." << endl;
					}
					
					else
						opcao = 0;
				break;

				case 6:
				break;

				case 7:
				break;

				default:
					cout << "Opção inválida." << endl;
			}
			cout << endl;
		}while(opcao != 5 && opcao != 6 && opcao != 7);
	}while(opcao != 5 && opcao != 7);
}

void Cinema::opcaoSessao(){
	int opcao;
	//Sessao *novaSessao;

	do{
		cout << endl;
		cout << "1. Listar sessões existentes" << endl;
		cout << "2. Cadastrar sessão" << endl;
		cout << "3. Excluir sessão" << endl;
		cout << "4. Voltar ao Menu Principal" << endl;
		cout << "Escolha uma opção: ";
		cin >> opcao;

		//salaEscolhida = listaSalas.busca(numSala);

		switch(opcao)
		{
			case 1:
				//listarSessoesExistentes();
			break;

			case 2:
				//cadastrarSessao();
			break;

			case 3:
				//excluirSessao();
			break;

			case 4:
			break;

			default:
				cout << "Opção inválida." << endl;
		}
	}while(opcao != 4);
}

void Cinema::cadastrarSessao(){
	int numSala;
	Horario hInicio, hFim;
	string filme;

	cout << "Informe o nome do filme ";
	cin >> filme;

	cout << endl << "Informe o horário de início: " << endl;
	//cin >> hInicio;

	cout << endl << "Informe o horário de fim: " << endl;
	//cin >> hFim;

	//listarSalasDisponiveis com base no horario

	cout << endl << "Informe número da sala na qual deseja cadastrar a sessão" << endl;
	cin >> numSala;
}

void Cinema::excluirSessao()
{
	int codExcluir;

	//listarSessoesExistentes();

	cout << endl << "Informe o código da sessão a excluir: " << endl;
	cin >> codExcluir;

	//listaSessoes.remove(codExcluir);
}

void Cinema::venderIngresso(){
	int opcao;

	do{
		//listarSessoesExistentes();

		cout << "1. Iniciar nova venda: " << endl;
		cout << "2. Voltar ao menu principal" << endl;
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
				cout << "Opcao invalida" << endl;
		}
		cout << endl;
	}while(opcao != 2);
}

void Cinema::novaVenda(){
	//Venda novaVenda;
	//ListaIngresso listaIngressos;
	int opcao;
	int codSessao;
	int qtdIngressos;
	int meia=0;
	int numSessao;
	//vai precisar de uma ed pra guardar  ingressos


	do{
		//listarSessoesExistentes();
		//listarIngressosAdicionados();
		//cout << Valor total: R$ << novaVenda.calcularValorTotal() << endl;

		cout << "1. Adicionar novo ingresso" << endl;
		cout << "2. Remover ingresso" << endl;
		cout << "3. Cancelar venda" << endl;
		cout << "4. Confirmar venda" << endl;
		cout << "Escolha uma opcao ";
		cin >> opcao;
		cout << endl;

		switch(opcao){
			case 1:
				cout << "Informe numero da Sessao Desejada" << endl;
				cin >> numSessao;

				//Lista poltronas e faz um while pra escolher as poltronas e tipo de ingresso
			break;
			case 2:
				cout << "Remover ingresso número: " << endl;
				//cin << 
				//listaIngressos.remove();
			break;
			case 3:
				//confirmarCompra(int codSessao, int qtdIngressos, int meia);//Metodo da ED
			break;
			case 4:
				//cancelarCompra(int meia); // destruir Ed de ingressos
			break;
			case 5:
			break;
			default:
				cout << "Opcao invalida" << endl;
		}
	}while(opcao != 4);
}

bool Cinema::confirmacao(){
	char confirmacao;

	do
	{
		cout << "Digite s para sim e n para não: " << endl;
		cin >> confirmacao;

		if(confirmacao == 's' || confirmacao == 'S')
		{
			cout << "Operacao concluída;" << endl;
			return true;

		}

		else if(confirmacao == 'n' || confirmacao == 'N')
		{
			cout << "Operacao cancelada;" << endl;
			return false;
		}

		else
			cout << "Entrada inválida!" << endl;
	}while(1);
}