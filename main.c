#include<stdio.h>
#include<stdlib.h>

#include"cabecalho.h"

typedef struct{
    int codigo;
    char genero;
    char modalidade[51];
    char cidade[51];
    int ano;
    char tipo;
    char nome[51];
    char pais[51];
    //void resultado;
} Medalha;

int main(){
    FILE *arquivo = fopen("medalhas.csv","r");
    if(arquivo == NULL){
        perror("Erro ao abrir o arquivo ");
        exit(1);
    }

    Medalha *medalhas;

    medalhas = (struct Medalha *)malloc(sizeof(struct Medalha));


    


    fclose(arquivo);
    return 0;
}