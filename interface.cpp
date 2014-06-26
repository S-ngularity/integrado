void opcaoSala();
void opcaoSessao();
void opcaoVenderIngresso();

int main(){
	int opcao;

	do{
		cout << "1. Sala" << endl;
		cout << "2. Sessao" << endl;
		cout << "3. Vender Ingresso" << endl;
		cout << "4. Sair";
		cout << "Escolha uma opcao ";
		cin >> opcao;
	

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
				cout << "Opcao invalida" << endl;
		}
	}while(opcao!=4);
}

void opcaoSala(){
	int opcao;

	do{
		cout << "1. Cadastrar Sala" << endl;
		cout << "2. Editar Sala" << endl;
		cout << "3. Voltar ao Menu Principal" << endl;
		cout << "Escolha uma opcao ";
		cin >> opcao;

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
				cout << "Opcao invalida" << endl;


		}
	}while(opcao!=3);
}


void cadastrarSala(){
	int codSala;
	int capacSala;
	int numAssentosFileira;
	int confirmacao;

	cout << "Informe o codigo da sala " << endl;
	cin >> codSala;

	cout << "Informe a capacidade da sala " << endl;
	cin >> capacSala;

	cout << "Informe o numero de assentos em cada fileira " << endl;
	cin >> numAssentosFileira;

	cout << "Confirme se os dados inseridos estao corretos" << endl;
	cout << "Codigo da sala: " << codSala << endl;
	cout << "Capacidade da sala: " << capacSala << endl;
	cout << "Quantidade de assentos por fileira: " << numAssentosFileira << endl;
	cout << "Digite 1 para confirmar ou 0 para sair" << endl;
	cin >> confirmacao;

	if(confirmacao == 1){
		//chamar construtor;
		cout << "Sala adicionada com sucesso" << endl;	
	}

	else
		cout << "Sala nao foi adicionada" << endl;
}

void editarSala(){
	int opcao;

	do{
		cout << "1. Listar Salas Existentes" << endl;
		cout << "2. Excluir Sala" << endl;
		cout << "3. Alterar Capacidade da Sala" << endl;
		cout << "4. Alterar Número de Asssentos por Fileira" << endl;
		cout << "5. Alterar a Disponibilidade da Sala" << endl;
		cout << "6. Voltar ao menu Sala" << endl;
		cout << "Escolha uma opcao ";
		cin >> opcao;

		switch(opcao){
			case 1:
				listarSalasExistentes();
			break;
			case 2:
				excluirSala();
			break;
			case 3:
				alterarCapacidadeDaSala();
			break;
			case 4:
				alterarNumeroAssentosFileira();
			break;
			case 5:
				alterarDisponibilidadeSala();
			break;
			case 6:
			break;
			default:
				cout << "Opcao invalida" << endl;
		}
	}while(opcao!=6);
}

void listarSalasExistentes(){
	//imprimir a lista de salas
}

void excluirSala(){
	//chama o destrutor da sala, o destrutor pode ter um cout dizendo sala excluida com sucesso
}

void alterarCapacidadeDaSala(){
	int novaCapacidade;
	cout << "Informe a nova capacidade da sala" << endl;
	cin >> novaCapacidade;
	//chamar metodo set e passar novaCapacidade
}

void alterarNumeroAssentosFileira(){
	int novaQtd;
	cout << "Informe a nova quantidade de assentos por fileira" << endl;
	cin >> novaQtd;
	//chamar metodo set e passar novaQtd
}

void alterarDisponibilidadeSala(){
	int disponibilidade;
	cout << "Informe se a sala esta disponivel ou nao. 1 para disponivel, 0 para indisponivel" 
	<< endl;
	cin >> disponibilidade;
	//chamar metodo set e passar disponibilidade
}
void opcaoSessao(){
	int opcao;

	do{
		cout << "1. Cadastrar Sessao" << endl;
		cout << "2. Editar Sessao" << endl;
		cout << "3. Voltar ao Menu Principal" << endl;
		cout << "Escolha uma opcao ";
		cin >> opcao;

		switch(opcao){
			case 1:
				cadastrarSessao();
			break;
			case 2:
				editarSessao();
			break;
			case 3:
			break;
			default:
				cout << "Opcao invalida" << endl;


		}
	}while(opcao!=3);
}

void cadastrarSessao(){
	int codFilme;
	//horario;
	int codSala;

	cout << "Informe o codigo do filme " << endl;
	cin >> codFilme;

	cout << "Informe o horario de inicio " << endl;
	cin >> //horario;

	//listarSalasDisponiveis com base no horario

	cout << "Informe codigo da sala na qual deseja cadastrar a sessao" << endl;
	cin >> codSala;

	cout << "Confirme se os dados inseridos estao corretos" << endl;
	cout << "Codigo do filme: " << codFilme << endl;
	cout << "Horario de inicio: " << /*horario*/ << endl;
	cout << "Codigo da sala: " << codSala << endl;
	cout << "Digite 1 para confirmar ou 0 para sair" << endl;
	cin >> confirmacao;

	if(confirmacao == 1){
		//chamar construtor;
		cout << "Sessao adicionada a sala: " << codSala << " com sucesso" << endl;	
	}

	else
		cout << "Sessao nao foi adicionada" << endl;


}

void editarSessao(){
	int opcao;

	do{
		cout << "1. Listar Sessoes Existentes" << endl;
		cout << "2. Excluir Sessao" << endl;
		cout << "3. Alterar Horario de Exibicao" << endl;
		cout << "4. Alterar Filme" << endl;
		cout << "5. Voltar ao menu Sessao" << endl;
		cout << "Escolha uma opcao ";
		cin >> opcao;

		switch(opcao){
			case 1:
				listarSessosExistentes();
			break;
			case 2:
				excluirSessao();
			break;
			case 3:
				alterarHorarioExibicao();
			break;
			case 4:
				alterarFilme();
			break;
			case 5:
			break;
			default:
				cout << "Opcao invalida" << endl;
		}
	}while(opcao!=5);
}

void listarSessoesExistentes(){
	//imprimir a lista de sessos
}

void excluirSessao(){
	//chama o destrutor da sessao, o destrutor pode ter um cout dizendo sessao excluida com sucesso
}

void alterarHorarioExibicao(){
	int novoHorario;
	cout << "Informe o novo horario da sessao" << endl;
	cin >> novoHorario;
	//chamar metodo set e passar novoHorario
}

void alterarFilme(){
	int novoFilme;
	cout << "Informe o novo filme que sera exibido nessa sessao" << endl;
	cin >> novoFilme;
	//chamar metodo set e passar novoFilme
}



void opcaoVenderIngresso(){
	int opcao;

	do{
		cout << "1. Listar Sessoes Disponiveis" << endl;
		cout << "2. Iniciar Compra " << endl;
		cout << "3. Voltar ao Menu Principal" << endl;
		cout << "Escolha uma opcao ";
		cin >> opcao;

		switch(opcao){
			case 1:
				listarSessoes();
			break;
			case 2:
				iniciarCompra();
			break;
			case 3:
			break;
			default:
				cout << "Opcao invalida" << endl;


		}
	}while(opcao!=3);
}

void listarSessoes(){
	//imprimir as sessoes disponiveis
}

void iniciarCompra(){
	int opcao;
	int codSessao;
	int qtdIngressos;
	int meia=0;


	do{
		cout << "1. Informar Sessao Desejada" << endl;
		cout << "2. Calcular Valor Total" << endl;
		cout << "3. Confirmar Compra" << endl;
		cout << "4. Cancelar Compra" << endl;
		cout << "5. Voltar ao menu Venda" << endl;
		cout << "Escolha uma opcao ";
		cin >> opcao;

		switch(opcao){
			case 1:
				cout << "Informe a quantidade de ingressos " << endl;
				cin >> qtdIngressos;
				try{
					codSessao = informarSessaoDesejada(qtdIngressos);
				}
				catch(string s){
					cout << s << endl;
				}
			break;
			case 2:
				calcularValorTotal(qtdIngressos, meia);
			break;
			case 3:
				confirmarCompra(int codSessao, int qtdIngressos, int meia);
			break;
			case 4:
				cancelarCompra(int meia);
			break;
			case 5:
			break;
			default:
				cout << "Opcao invalida" << endl;
		}
	}while(opcao!=5);


}

int informarSessaoDesejada(int qtdIngressos){
	int codSessao;
	//verificar se a sessao existe, se existir se esta disponivel
	//colocar throw para sessao nao existente e/ou nao disponivel

	if(qtdIngressos > //getCapacidadeDisponivel da sessao codSessao){
		throw "A quantidade de assentos e menor do que a quantidade de ingressos desejada"
	}

	cout << "Informe o codigo da sessao" << endl;
	cin >> codSessao;


	return codSessao;
}

int informarAssentos(int codSessao){
	int qtdIngressos;
	int fileira;
	int assento;


	for(int i=0; i<qtdIngressos; i++){
		cout << "Informe a fileira" << endl;
		cin >> fileira;
		cout << "Informe o assento" << endl;
		cin >> assento;
		//ocupa assento
	}

	return qtdIngressos;

}

float calcularValorTotal(int qtdIngressos, int &meia){
	int tipo; 
	float valorTotal=0;

	for(i=0; i<qtdIngressos; i++){
		cout << "Informe o tipo do ingresso, 0 para inteira ou 1 para meia";
		cin >> tipo;
		if(tipo == 0){ //inteira
			valorTotal = valorTotal + //getValorIngresso
		}
		else{
			valorTotal = valorTotal + //getValorIngresso/2
			meia++;
		}
		

	cout << "O valor total dos ingressos e: " << valorTotal << endl;

	return valorTotal;

}

void confirmarCompra(int codSessao, int qtdIngressos, int meia){

	informarAssentos(codSessao); //esse metodo ocupa assentos

	for(int i=0; i<qtdIngressos; i++){
		//chamar construtor de ingresso passando codSessao qtdIngressos e tipo
		//cada meia impresso decrementa o meia
	}
}

void cancelarCompra(int meia){
	meia=0;
	qtdIngressos=0;
}