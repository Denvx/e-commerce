#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <ctype.h>  
#include <locale.h>  

#define MAX_USER 2  

int usuariosCadastrados = 0;  

typedef struct {  
    char email[30];  
    char senha[15];  
} LoguinAdmin;  

typedef struct {  
    char nome[30];  
    char email[30];  
    char senha[15];  
    char cpf[12];  
    char endereco[100];  
    char numeroTelefone[11];  
} CadastroUsuario;  

CadastroUsuario usuarios[MAX_USER]; // Array global para armazenar os usuários  

void systens() {  
    system("pause");  
    system("cls");  
}  

void clearBuffer() {  
    int c;  
    while ((c = getchar()) != '\n' && c != EOF);  
}  

int entrada() { // Função de entradas  
    int resposta;  
    printf("Escolha: ");  
    scanf("%d", &resposta);  
    clearBuffer();  
    return resposta;  
}  

int verificarCpf(CadastroUsuario cliente) {  
    for (int i = 0; i < strlen(cliente.cpf); i++) {  
        if (!isdigit(cliente.cpf[i])) {  
            return -1; // Retorna -1 se encontrar algum caractere não numérico  
        }  
    }  
    return 0; // Retorna 0 se forem dígitos numéricos	  
}  

int verificarNum(CadastroUsuario cliente) {  
    for (int i = 0; i < strlen(cliente.numeroTelefone); i++) {  
        if (!isdigit(cliente.numeroTelefone[i])) {  
            return -1; // Retorna -1 se encontrar algum caractere não numérico  
        }  
    }  
    return 0; // Retorna 0 se forem dígitos numéricos	  
}  

void primeiraTela() { // Tela inicial  
    printf("Olá, seja bem-vindo ao hortifrut da Bet\n");  
    printf("[1] Fazer login\n");  
    printf("[2] Se cadastrar\n");  
    printf("[3] Reclamar\n");  
    printf("[4] Nos conhecer\n");  
    printf("[5] Sair\n");	  
}  

void loguinAdmin(LoguinAdmin admin) {  
    char loguinEmail[30], loguinSenha[15];  

    printf("Seja bem-vindo ADMINISTRADOR\n");  
    printf("Email: ");  
    scanf("%s", loguinEmail);  
    printf("Senha: ");  
    scanf("%s", loguinSenha);  

    if (strcmp(loguinEmail, admin.email) == 0 && strcmp(loguinSenha, admin.senha) == 0) {  
        printf("[1] Adicionar produtos\n");  
        printf("[2] Gerenciamento de Usuários\n");  
        printf("[3] Reclamações\n");  
        printf("[4] Gestão de Pedidos\n");  
        printf("[5] Relatório semanal\n");  
        printf("[6] Sair\n");  
        systens();  
    } else {  
        printf("Email ou senha incorretos\n");  
    }  
}  

void loguin() {  
    char loguinEmail[30], loguinSenha[15];  

    if (usuariosCadastrados == 0) {  
        printf("Não temos nenhum cadastro no nosso banco de dados!\n");  
        return;  
    }  

    printf("Tela de login\n");  
    printf("Email: ");  
    scanf("%s", loguinEmail);  
    printf("Senha: ");  
    scanf("%s", loguinSenha);  

        // Loop para verificar se o usuário e a senha estão no vetor  
    for (int i = 0; i < usuariosCadastrados; i++) {  
        if (strcmp(loguinEmail, usuarios[i].email) == 0 && strcmp(loguinSenha, usuarios[i].senha) == 0) {  
            printf("Login bem-sucedido! Bem-vindo, %s!\n", usuarios[i].nome);  
            return; // Login bem-sucedido  
        }  
    }  
    // Se não encontrar  
    printf("Email ou senha incorretos. Tente novamente...\n");  
}  

void cadastrarUsuario() { // Função de cadastrar usuários  
    if (usuariosCadastrados >= MAX_USER) {  
        printf("Limite de usuários cadastrados atingido.\n");  
        return;  
    }  

    CadastroUsuario cliente;  
    char arroba = 0;  

    system("cls");  
    printf("Vamos fazer seu cadastro\n");  
    printf("Me informe seu nome: ");  
    scanf("%s", cliente.nome);  

    do { // CPF  
        printf("CPF (SÓ NÚMEROS): ");  
        scanf("%11s", cliente.cpf);  
        
        clearBuffer();  
        int numCpf = strlen(cliente.cpf);  
        int retCpf = verificarCpf(cliente);  

        if (numCpf != 11 || retCpf != 0) {  
            printf("CPF inválido! O CPF deve conter exatamente 11 dígitos e apenas números.\n");  
            systens();  
        } else {  
            printf("CPF validado!\n");  
            systens();  
            break; // Saia do loop se o CPF for válido  
        }  
    } while (1);  

    printf("Endereço: ");  
    scanf(" %[^\n]", cliente.endereco); // Lê a linha toda  
    clearBuffer();  

    do { // Telefone  
        printf("Telefone (SÓ NÚMEROS): ");  
        scanf("%11s", cliente.numeroTelefone);  
        
        clearBuffer();  
        int numDigit = strlen(cliente.numeroTelefone);  
        int retNum = verificarNum(cliente);  

        if (numDigit != 11 || retNum != 0) {  
            printf("Número inválido! Deve conter exatamente 11 dígitos e apenas números.\n");  
            systens();  
        } else {  
            printf("Número validado!\n");  
            systens();  
            break; // Saia do loop se o número for válido  
        }  
    } while (1);  

    do { // Email  
        printf("Email: ");  
        scanf("%s", cliente.email);  
        clearBuffer();  

        arroba = 0; // Resetar a flag  
        for (int i = 0; i < strlen(cliente.email); i++) {  
            if (cliente.email[i] == '@') {  
                arroba = 1; // Setar flag se '@' for encontrado  
                break;  
            }  
        }  

        if (arroba != 1) {  
            printf("Este email é inválido! O email deve conter '@'.\n");  
            systens();  
        } else {  
            printf("Email validado!\n");  
            systens();  
            break; // Saia do loop se o email for válido  
        }  
    } while (1);  

    do { // Senha  
        printf("Senha (mínimo 8 e máximo 14 dígitos): ");  
        scanf("%s", cliente.senha);  
        clearBuffer();  

        int numSenha = strlen(cliente.senha);  
        if (numSenha < 8 || numSenha > 14) {  
            printf("A senha deve ter entre 8 e 14 dígitos. Tente novamente!\n");  
            systens();  
        } else {  
            printf("Senha cadastrada!\n");  
            systens();  
            break; // Saia do loop se a senha for válida  
        }  
    } while (1);  

    // Adiciona o novo usuário ao array de usuários  
    usuarios[usuariosCadastrados] = cliente;  
    usuariosCadastrados++; // Incrementa o contador de usuários cadastrados  
}  

void controle(int resposta, LoguinAdmin admin) {  
    switch (resposta) {  
        case 1:  
            loguin();  
            break;  
        case 2:  
            cadastrarUsuario();  
            break;  
        case 3:  
            printf("Case 3: Reclamações não implementadas ainda.\n");  
            systens();  
            break;  
        case 4:  
            printf("Case 4: Informações sobre nós não implementadas ainda.\n");  
            systens();  
            break;  
        case 5:  
            printf("Obrigado pela sua presença! Até logo!\n");  
            exit(0);  
            break;  
        case 12345678: // Login do administrador  
            loguinAdmin(admin);  
            systens();  
            break;  
        default:  
            printf("Opção desconhecida!\n");  
            systens();  
            break;  
    }  
}  

int main() {  
    setlocale(LC_ALL, "portuguese");  
    
    LoguinAdmin admin;  
    strcpy(admin.email, "admin@gmail.com");  
    strcpy(admin.senha, "12345678");  

    while (1) {  
        primeiraTela();  
        int resposta = entrada();  
        controle(resposta, admin);  
    }  

    return 0;  
}