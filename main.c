#include"cabecalho.h"

#include<stdlib.h>

int main(){
    FILE *arquivo = fopen("medalhas.csv","r");
    if(arquivo == NULL){
        perror("Erro ao abrir o arquivo ");
        exit(1);
    }
    int tamanho = verificarTamanhoArq(arquivo);
    
    Medalha *medalhas = (Medalha *)malloc(sizeof(Medalha) * tamanho);
    if(medalhas == NULL){
        perror("Erro ao alocar memoria dinamica ");
        exit(1);
    }
    printf("Bem-vindo!");

    lerArquivo(medalhas, arquivo, tamanho);

    free(medalhas);
    fclose(arquivo);
    return 0;
}