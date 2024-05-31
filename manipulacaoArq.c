#include"cabecalho.h"

#include<stdlib.h>

void lerArquivo(Medalha medalhas[], FILE *arquivo, int tamanho){
    for(int i=0; i<tamanho; i++){
        fscanf(arquivo, "%c,%s,%s,%d,%c,%s,%s,%s", &medalhas[i].genero, medalhas[i].modalidade, medalhas[i].cidade, 
                                &medalhas[i].ano, &medalhas[i].tipo, medalhas[i].nome, medalhas[i].pais, medalhas[i].resultado);
        medalhas[i].codigo = i;
    }

    return;
}

int verificarTamanhoArq(FILE *arquivo){
    fseek(arquivo, 0, SEEK_END);
    int tamanho = ftell(arquivo);
    fseek(arquivo, 0, SEEK_SET);
    return tamanho;
}