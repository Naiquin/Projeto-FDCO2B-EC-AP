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
    
    Medalha *medalhas = (Medalha *)malloc(sizeof(Medalha) * 5);

    if(medalhas == NULL){
        perror("Erro ao alocar memoria dinamica ");
        exit(1);
    }
    printf(BOLD "Bem-vindo!" RESET);

    lerArquivo(medalhas, arquivo1);

    menuInicial(medalhas, &tamanho);

    fclose(arquivo1);

    FILE *arquivo2 = fopen("medalhas.txt","w");
    if(arquivo2 == NULL){
        perror("Erro ao abrir o arquivo ");
        exit(1);
    }

    for(int i=0; i<5; i++){
        printf("\n%d,%c,%s,%s,%d,%c,%s,%s,%s\n", medalhas[i].codigo,medalhas[i].genero, medalhas[i].modalidade, medalhas[i].cidade, 
                                medalhas[i].ano, medalhas[i].tipo, medalhas[i].nome, medalhas[i].pais, medalhas[i].resultado);
    }

    for(int i=0; i<5; i++){
        fprintf( arquivo2,"%d,%c,%s,%s,%d,%c,%s,%s,%s\n", medalhas[i].codigo,medalhas[i].genero, medalhas[i].modalidade, medalhas[i].cidade, 
                                medalhas[i].ano, medalhas[i].tipo, medalhas[i].nome, medalhas[i].pais, medalhas[i].resultado);
    }

    fclose(arquivo2);
    free(medalhas);
    return 0;
}