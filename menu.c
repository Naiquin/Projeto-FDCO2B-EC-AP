#include"cabecalho.h"

#include<stdlib.h>
#include<ctype.h>

#define BOLD "\e[1m"
#define RESET "\e[0m"

void lerString(char string[], int tamanho){
    setbuf(stdin,NULL);
    fgets(string, 10, stdin);
    string[strcspn(string,"\n")]='\0';
    setbuf(stdin,NULL);
    return;
}

void menuInicial(){
    char opcao[10];

    printf(BOLD "------MENU INICIAL-----\n\n" RESET);

    printf(BOLD "Lista de opções\n" RESET);
    printf("1- Inserir\n2- Listar\n3- Pesquisar\n4- Alterar\n5- Excluir\n6- Sair\n");
    lerString(opcao, 10);
    for (int i = 0; opcao[i] != '\0'; i++) {
        opcao[i] = toupper(opcao[i]);
    }



    return;
}

/*
    printf("Informe o genero do atleta: ");
    scanf("%", medalhas[*tamanho].);

    typedef struct{
    int codigo;
    char genero;
    char modalidade[51];
    char cidade[51];
    int ano;
    char tipo;
    char nome[51];
    char pais[51];
    char resultado[11];
} Medalha;
*/

void inserir(Medalha medalhas[], int *tamanho){
    *tamanho++;
    medalhas = realloc(medalhas, (*tamanho) * sizeof(Medalha));
    if(medalhas == NULL){
        perror("Erro ao alocar memoria ");
        exit(1);
    }

    medalhas[*tamanho].codigo = *tamanho;

    printf("Informe o genero do atleta: ");
    scanf("%c", &medalhas[*tamanho].genero);
    printf("Informe a modalidade que foi conquistada a medalha: ");
    scanf("%s", medalhas[*tamanho].modalidade);
    printf("Informe a cidade que foi conquistada a medalha: ");
    scanf("%s", medalhas[*tamanho].cidade);
    printf("Informe o ano que foi conquistada a medalha: ");
    scanf("%d", medalhas[*tamanho].ano);
    printf("Informe o genero do atleta: ");
    scanf("%c", medalhas[*tamanho].tipo);
    printf("Informe o genero do atleta: ");
    scanf("%s", medalhas[*tamanho].nome);
    printf("Informe o genero do atleta: ");
    scanf("%s", medalhas[*tamanho].pais);
    printf("Informe o genero do atleta: ");
    scanf("%s", medalhas[*tamanho].resultado);
    

    return;
}