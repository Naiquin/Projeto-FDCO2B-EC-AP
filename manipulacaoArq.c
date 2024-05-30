#include"cabecalho.h"

#include<stdlib.h>

void lerArquivo(Medalha medalhas[], FILE *arquivo){

    for(int i=0; i<2394; i++){
        fscanf(arquivo, "%c,%s,%s,%d,%c,%s,%s,%s", &medalhas[i].genero, medalhas[i].modalidade, medalhas[i].cidade, 
                                &medalhas[i].ano, &medalhas[i].tipo, medalhas[i].nome, medalhas[i].pais, medalhas[i].resultado);
        medalhas[i].codigo = i;
    }

    return;
}

void verificarTamanhoArq(){
    return;
}