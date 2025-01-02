#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

int usuariosCadastrados = 0;
typedef struct{
	char email[30];
	char senha[15];
}LoguinAdmin;

typedef struct{
	char nome[30];
	char email[30];
	char senha[15];
	char cpf [12];
	char endereco[100];
	char numeroTelefone[11];
}CadastroUsuario;

typedef struct{
	char email[30];
	char senha[15];
}LoguinUsuario;
void systens(){
	system("pause");
  system("cls");
}
void clearBuffer() {      // Função para apagar  os buffer de memoria
    int c;  
    while ((c = getchar()) != '\n' && c != EOF);  
} 
int entrada(){ //Função de entradas
	int resposta;
	printf("escolha:");
	scanf("%d", &resposta);
	clearBuffer();
	return resposta;
}
int verificarCpf(CadastroUsuario cliente){ //Essa função vai verificar se os cpf digitado é so numeros

	for(int i = 0; i < strlen(cliente.cpf); i++){
		if (!isdigit(cliente.cpf[i])) {
			return -1; //retorna -1 se se encontrar algum caracter
		}
	}
	return 0; //retorna 0  se forem digitos numericos	
}
int verificarNum(CadastroUsuario cliente){ //Essa função vai verificar se os numeros digitados, são so numeros

	for(int i = 0; i < strlen(cliente.numeroTelefone); i++){
		if (!isdigit(cliente.numeroTelefone[i])) {
			return -1; //retorna -1 se se encontrar algum caracter
		}
	}
	return 0; //retorna 0  se forem digitos numericos	
}
void primeiraTela(){ //Tela inicial
	printf("Olá, seja bem vindo ao hortifrut da Bet\n");
	printf("[1] Fazer loguin\n");
	printf("[2] Se cadastrar\n");
	printf("[3] Reclamar\n");
	printf("[4] Nos conhecer\n");
	printf("[5] Sair\n");	
}
void loguinAdmin(LoguinAdmin admin){ //função que faz  o  loguin administrativo
	char loguinEmail[30], loguinSenha[15];
	
	printf(" Sejá bem vindo AIMINISTRADOR \n");
	printf("Email: ");
	scanf("%s", &loguinEmail);
		
	fflush(stdin);
	printf("Senha: ");
	scanf("%s", &loguinSenha);
	fflush(stdin);
		
	if (strcmp(loguinEmail, admin.email) == 0 && strcmp(loguinSenha, admin.senha) == 0 ){
		printf("CHAMO O QUE O ADM PODE FAZER AQUI!\n");
	}else{
		printf("Email ou senha incorretos\n");
	}
}
void loguin(LoguinUsuario usuario){ //função que faz  o  loguin do ususario
	char loguinEmail[30], loguinSenha[15];
	
	if(usuariosCadastrados == 0){ //verifica se te ususarios cadastrados, se nao estiver, volta para o loop
		system("cls");
		printf("Não temos nem um cadastro no nosso banco de dados!\n");
		printf("se cadastre e retorne.\n");
		systens();
	}else {
		system("cls");
		printf("Tela de loguin\n");
		printf("Email: ");
		scanf("%s", &loguinEmail);
		clearBuffer();
		
		fflush(stdin);
		printf("Senha: ");
		scanf("%s", &loguinSenha);
		clearBuffer();
		systens();
		
		if (strcmp(loguinEmail, usuario.email) == 0 && strcmp(loguinSenha, usuario.senha) == 0 ){
			printf("CHAMO O QUE O USUARIO PODE FAZER AQUI!\n");
		}else{
			printf("Email ou senha incorretos\nTente novamente...\n");
			systens();
		}
	}
}
void cadastrarUsuario(CadastroUsuario cliente){	//Essa é a função de cadastrar usuarios
	char arroba = 0,numDigit, numSenha, numCpf, retCpf, retNum;
  
	system("cls") ;
	printf("Vamos fazer seu cadastro\n");
	printf("Me informa seu nome: ");
	scanf("%s", cliente.nome);
	do{	//cpf...  
    printf("CPF (SÓ NÚMEROS): ");  
    scanf("%11s", cliente.cpf); // Limita a entrada a 11 caracteres  
        
    clearBuffer();  
    numCpf = strlen(cliente.cpf);  
        
    retCpf = verificarCpf(cliente); // Verifica se o CPF só contém números  

    if (numCpf < 11) {  
      printf("Está faltando dígito, tente novamente!\n");  
      systens();
    } else if (numCpf > 11) {
  	  printf("Quantidade de dígitos ultrapassada!\n");
    	systens();
    } else if (retCpf != 0) {
      printf("CPF inválido! O CPF deve conter apenas números.\n");
      systens();
    } else {
      printf("CPF validado!\n");
      systens();
    }
        
  } while (numCpf != 11 || retCpf != 0);

	printf("Endereço: ");
	scanf("%s", cliente.endereco);
	clearBuffer();
	do { //telefone...
    printf("Telefone (SÓ NÚMEROS): ");  
    scanf("%11s", cliente.numeroTelefone); // Limita a entrada a 11 caracteres  
        
    clearBuffer();  
    numDigit = strlen(cliente.numeroTelefone);  
        
    retNum = verificarNum(cliente); // Verifica se o CPF só contém números  

    if (numDigit < 11) {  
      printf("Está faltando dígito, tente novamente!\n");  
      systens();
    } else if (numDigit > 11) {
  	  printf("Quantidade de dígitos ultrapassada!\n");
    	systens();
    } else if (retNum != 0) {
      printf("Numero inválido! Deve conter apenas números.\n");
      systens();
    } else {
      printf("Numero validado!\n");
      systens();
    }
        
  } while (numDigit != 11 || retNum != 0);
	do{  //email...
	
		printf("Email: ");
		scanf("%s", cliente.email);
		clearBuffer();
		
		for (int i = 0; i < strlen(cliente.email); i++) {
      if (cliente.email[i] == '@') {
        arroba = 1; // Setar flag se '@' for encontrado
				break;
      }
    }
    
    if (arroba != 1) {  //preciso imprimir dps do 'FOR', se nao repete as mensagens a todo caracter achado...
      printf("Este email é inválido! O email deve conter '@'.\n");
      systens();
    } else {
      printf("Email validado!\n");
      systens();
    }
	}while (arroba != 1);
	
	do { //senha...
  	printf("Senha (máximo 14 dígitos): ");
  	scanf("%s", cliente.senha);
		clearBuffer();
		
    numSenha = strlen(cliente.senha);
		if(numSenha > 14) {
    	printf("Ultrapassou a quantidade de dígitos permitido (maximo, 14 digitos)!\n");
   		systens();
    }else if (numSenha < 8){
    	printf("A senha tem que ter no mínimo 8 dígitos, tente novamente !\n");
    	systens();
    }else{
    	printf("Senha cadastrada!\n");
    	systens();
    }
	}while (numSenha < 8 && numSenha > 14);
	
	usuariosCadastrados ++;
}
void controle(int resposta, LoguinAdmin admin, LoguinUsuario usuario, CadastroUsuario cliente){
	switch (resposta){
		case 1:
			loguin(usuario);
			break;
		case 2:
			cadastrarUsuario(cliente);
			break;
		case 3:
			printf("Case 3\n");
			systens();
			break;
		case 4:
			printf("Case 4\n");
			systens();
			break;
		case 5:
			printf("Sua presença foi exencial, Obrigado!\n");
			exit(1);
			systens();
			break;
		case 12345678:
			printf("  LOGUIN ADMINISTRATIVO  \n");
			loguinAdmin(admin);
			systens();
			break;
			default:
				printf("Opção desconheccida!\n");
				systens();
				break;
	}
}
int main(){
	setlocale(LC_ALL,"portuguese");
	LoguinAdmin admin;
	LoguinUsuario usuario;
	CadastroUsuario cliente;
	strcpy(admin.email, "admin@gmail.com");
	strcpy(admin.senha, "12345678");
	while(1){
		primeiraTela();
		int resposta = entrada();
		controle(resposta, admin, usuario, cliente);
	}
}