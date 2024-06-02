#include"cabecalho.h"

#include<stdlib.h>

#define BOLD "\e[1m"
#define RESET "\e[0m"

int main(){
    FILE *arquivo1 = fopen("medalhas.csv","r");
    if(arquivo1 == NULL){
        perror("Erro ao abrir o arquivo ");
        exit(1);
    }
    int tamanho = verificarTamanhoArq(arquivo1);
    Medalha *medalhas = (Medalha *)malloc(sizeof(Medalha) * tamanho);
    if(medalhas == NULL){
        perror("Erro ao alocar memoria dinamica ");
        exit(1);
    }
    
    printf(BOLD "Bem-vindo!" RESET);

    lerArquivo( medalhas, arquivo1, tamanho);

    //menuInicial(medalhas, &tamanho);

    fclose(arquivo1);

    FILE *arquivo2 = fopen("medalhas.txt","w");
    if(arquivo2 == NULL){
        perror("Erro ao abrir o arquivo ");
        exit(1);
    }

    escreverArquivo( medalhas, arquivo2, tamanho);

    fclose(arquivo2);
    free(medalhas);
    return 0;
}