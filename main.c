#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
	char cpf [11];
	char endereco[100];
	char numeroTelefone[11];
}CadastroUsuario;

typedef struct{
	char email[30];
	char senha[15];
}LoguinUsuario;

void clearBuffer() {  
    int c;  
    // Lê até a nova linha ou EOF  
    while ((c = getchar()) != '\n' && c != EOF);  
} 
int entrada(){
	int resposta;
	printf("escolha:");
	scanf("%d", &resposta);
	clearBuffer();
	return resposta;
}
void primeiraTela(){
	printf("Olá, seja bem vindo ao hortifrut da Bet\n");
	printf("[1] Fazer loguin\n");
	printf("[2] Se cadastrar\n");
	printf("[3] Reclamar\n");
	printf("[4] Nos conhecer\n");
	printf("[5] Sair\n");	
}
void loguinAdmin(LoguinAdmin admin){
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
void loguin(LoguinUsuario usuario){
	char loguinEmail[30], loguinSenha[15];
	
	if(usuariosCadastrados == 0){
		printf("Não temos nem um cadastro no nosso banco de dados!\n");
		printf("se cadastre e retorne.\n");
		system("pause");
		system("cls");
	}else {
		printf("Tela de loguin\n");
		printf("Email: ");
		scanf("%s", &loguinEmail);
		
		fflush(stdin);
		printf("Senha: ");
		scanf("%s", &loguinSenha);
		fflush(stdin);
		
		if (strcmp(loguinEmail, usuario.email) == 0 && strcmp(loguinSenha, usuario.senha) == 0 ){
			printf("CHAMO O QUE O USUARIO PODE FAZER AQUI!\n");
		}else{
			printf("Email ou senha incorretos\n");
			system("pause");
		}
	}
}
void cadastrarUsuario(CadastroUsuario cliente){
	int numDigit;
    char arroba = 0;
    
	printf("Vamos fazer seu cadastro\n");
	printf("Me informa seu nome: ");
	scanf("%s", cliente.nome);
	printf("CPF(SÓ NUMEROS): ");
	scanf("%d", cliente.cpf);
	printf("Endereço: ");
	scanf("%s", cliente.endereco);
	do{
		printf("Numero (11 digitos): ");
		scanf("%d", cliente.numeroTelefone);
		
		numDigit = strlen(cliente.numeroTelefone); //obtenho o tamanho da streing com 'strlen'
		if(numDigit > 11) {
			printf("Quantidade de digitos ultrapaçada!\n");
			system("pause");
			system("cls");
		}else {
			printf("Está faltando digito, tente novamente!\n");
			system("pause");
			system("cls");
		}
	}while(numDigit != 11);
	do{
		printf("Email: ");
		scanf("%s", cliente.email);
		
		for (int i = 0; i < strlen(cliente.email); i++) {  
      if (cliente.email[i] == '@') {  
          arroba = 1; // Setar flag se '@' for encontrado       
      } else {
        printf("Este email é invalido!\n");
        system("pause");
        system("cls");
			}
    }
	}while (arroba != 1);
	printf("Senha: ");
	scanf("%s", cliente.senha);
	
}
void controle(int resposta, LoguinAdmin admin, LoguinUsuario usuario){
	switch (resposta){
		case 1:
			loguin(usuario);
			break;
		case 2:
			printf("Case 2\n");
			system("pause");
			system("cls");
			break;
		case 3:
			printf("Case 3\n");
			system("pause");
			system("cls");
			break;
		case 4:
			printf("Case 4\n");
			system("pause");
			system("cls");
			break;
		case 5:
			printf("Sua presença foi exencial, Obrigado!\n");
			exit(1);
			system("pause");
			break;
		case 12345678:
			printf("  LOGUIN ADMINISTRATIVO  \n");
			loguinAdmin(admin);
			system("pause");
			break;
			default:
				printf("Opção desconheccida!\n");
				system("pause");
				system("cls");
				break;
	}
}
int main(){
	setlocale(LC_ALL,"portuguese");
	LoguinAdmin admin;
	LoguinUsuario usuario;
	strcpy(admin.email, "admin@gmail.com");
	strcpy(admin.senha, "12345678");
	while(1){
		primeiraTela();
		int resposta = entrada();
		controle(resposta, admin, usuario);
	}
}