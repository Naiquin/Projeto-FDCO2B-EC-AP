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

// informa a existencia das funções q seram chamadas na função menuIniciar
void inserir(Medalha medalhas[], int *tamanho);
void listar(Medalha medalhas[], int *tamanho);

//função que gera e gerencia o menu
void menuInicial(Medalha medalhas[], int *tamanho){
    
    //char q recebe a opção do usuario
    char opcao[10];

    //inicio do menu
    printf(BOLD "\n------MENU INICIAL-----\n\nLista de opções\n" RESET);
    printf("1- Inserir\n2- Listar\n3- Pesquisar\n4- Alterar\n5- Excluir\n6- Sair\n");


    lerString(opcao, 10);

    //if-elses responsaveis por verificas a opção do usuario
    if(strcasecmp(opcao, "1") == 0 || strcasecmp(opcao, "inserir") == 0){
        inserir(medalhas, tamanho);
    }else if(strcasecmp(opcao, "2") == 0 || strcasecmp(opcao, "listar") == 0){
        listar(medalhas, tamanho);
    }else if(strcasecmp(opcao, "3") == 0 || strcasecmp(opcao, "pesquisar") == 0){
        
    }else if(strcasecmp(opcao, "4") == 0 || strcasecmp(opcao, "alterar") == 0){
        
    }else if(strcasecmp(opcao, "5") == 0 || strcasecmp(opcao, "excluir") == 0){
        
    }else if(strcasecmp(opcao, "6") == 0 || strcasecmp(opcao, "sair") == 0){
        
    }//if-elses.

    return;
}// menuInicial

void inserir(Medalha medalhas[], int *tamanho){

    //acrecenta +1 na variavel tamanho
    ((*tamanho)++);

    //realoca espaco para inserir o medalista
    medalhas = realloc(medalhas, (*tamanho) * sizeof(Medalha));

    //verifica se ha erro ao realocar no espaço de memoria
    if(medalhas == NULL){

        // informa o erro
        perror("Erro ao alocar memoria ");
        exit(1);
    }

    //vai para a ultima linha utilizando o numero de linhas
    medalhas[(*tamanho)].codigo = (*tamanho);

    //recebe as informações que seram salvas
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
}//inserir

//Exibe todas as linhas da lista de medalhas
void listar(Medalha medalhas[], int *tamanho){

    //cabeçalho da lista
    printf(BOLD "CODIGO|GENERO|MODALIDADE               |CIDADE               |ANO  |TIPO|NOME                          |PAIS|RESULTADO\n" RESET);
    
    // for responsavel por exibir todas as medalhas 
    for(int i=0; i<(*tamanho); i++){
        printf("%6d|%6c|%-25s|%-21s|%5d|%-4c|%-30s|%-4s|%-9s\n",
                            medalhas[i].codigo,medalhas[i].genero, medalhas[i].modalidade,
                            medalhas[i].cidade, medalhas[i].ano, medalhas[i].tipo,
                            medalhas[i].nome, medalhas[i].pais, medalhas[i].resultado);
    }// for
    return;
}// listar





void excluir(Medalha medalhas[],int codigo,int *tamanho){

    //for responsavel por passar por todas as medalhas
    for (int i = 0; i < *tamanho; i++)
    {
        // se encontras o codigo da medalaha digitada entra no "for"
        if (medalhas[i].codigo == codigo)
        {
            // for responsavel por substituir a medalha com o codigo digitado pelo proximo.
            // o proximo e substituido pelo seguinte e assim por diante.
           for (int  j = i; j < *tamanho - 1; j++)
           {
            medalhas[j] = medalhas[j +1];
           }//for
           
        }//if
        
    }//for
    return;
}//excluir
