#include"cabecalho.h"

#include<stdlib.h>

int main(){
    FILE *arquivo = fopen("medalhas.csv","r");
    if(arquivo == NULL){
        perror("Erro ao abrir o arquivo ");
        exit(1);
    }
    
    Medalha *medalhas = (Medalha *)malloc(sizeof(Medalha) * 2394);
    if(medalhas == NULL){
        perror("Erro ao alocar memoria dinamica ");
        exit(1);
    }
    printf("Bem-vindo!");

    lerArquivo(medalhas, arquivo);

    verificarTamanhoArq();

    free(medalhas);
    fclose(arquivo);
    return 0;
}