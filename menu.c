#include"cabecalho.h"

#include<stdlib.h>
#include<string.h>

#define BOLD "\e[1m"
#define RESET "\e[0m"

void lerString(char string[], int tamanho){
    setbuf(stdin,NULL);
    fgets(string, tamanho, stdin);
    string[strcspn(string,"\n")]='\0';
    setbuf(stdin,NULL);
    return;
}

void inserir(Medalha medalhas[], int *tamanho);
void listar(Medalha medalhas[], int *tamanho);

void menuInicial(Medalha medalhas[], int *tamanho){
    char opcao[10];
    printf(BOLD "\n------MENU INICIAL-----\n\nLista de opções\n" RESET);
    printf("1- Inserir\n2- Listar\n3- Pesquisar\n4- Alterar\n5- Excluir\n6- Sair\n");
    lerString(opcao, 10);

    if(strcasecmp(opcao, "1") == 0 || strcasecmp(opcao, "inserir") == 0){
        inserir(medalhas, tamanho);
    }else if(strcasecmp(opcao, "2") == 0 || strcasecmp(opcao, "listar") == 0){
        listar(medalhas, tamanho);
    }else if(strcasecmp(opcao, "3") == 0 || strcasecmp(opcao, "pesquisar") == 0){
        
    }else if(strcasecmp(opcao, "4") == 0 || strcasecmp(opcao, "alterar") == 0){
        
    }else if(strcasecmp(opcao, "5") == 0 || strcasecmp(opcao, "excluir") == 0){
        
    }else if(strcasecmp(opcao, "6") == 0 || strcasecmp(opcao, "sair") == 0){
        
    }

    return;
}

void inserir(Medalha medalhas[], int *tamanho){
    ((*tamanho)++);
    medalhas = realloc(medalhas, (*tamanho) * sizeof(Medalha));
    if(medalhas == NULL){
        perror("Erro ao alocar memoria ");
        exit(1);
    }

    medalhas[(*tamanho)].codigo = (*tamanho);
    printf("Informe o genero do atleta: ");
    scanf("%c", &medalhas[(*tamanho)].genero);
    printf("Informe a modalidade que foi conquistada a medalha: ");
    lerString( medalhas[(*tamanho)].modalidade, 50);
    printf("Informe a cidade que foi conquistada a medalha: ");
    lerString( medalhas[(*tamanho)].cidade, 50);
    printf("Informe o ano que foi conquistada a medalha: ");
    scanf("%d", medalhas[(*tamanho)].ano);
    printf("Informe o tipo GBD da medalha: ");
    scanf("%c", medalhas[(*tamanho)].tipo);
    printf("Informe o nome do atleta: ");
    lerString( medalhas[(*tamanho)].nome, 50);
    printf("Informe o pais onde o atleta nasceu: ");
    lerString( medalhas[(*tamanho)].pais, 50);
    printf("Informe o resultado do atleta: ");
    lerString( medalhas[(*tamanho)].resultado, 50);
    
    return;
}

void listar(Medalha medalhas[], int *tamanho){
    printf(BOLD "CODIGO\t|GENERO\t|MODALIDADE\t|CIDADE\t|ANO\t|TIPO\t|NOME\t|PAIS\t|RESULTADO\n" RESET);
    for(int i=0; i<(*tamanho); i++){
        printf("%d\t|%c\t|%s\t|%s\t|%d\t|%c\t|%s\t|%s\t|%s",
                            medalhas[i].codigo,medalhas[i].genero, medalhas[i].modalidade,
                            medalhas[i].cidade, medalhas[i].ano, &medalhas[i].tipo,
                            medalhas[i].nome, medalhas[i].pais, medalhas[i].resultado);
    }
    return;
}


