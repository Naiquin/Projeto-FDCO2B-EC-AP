#include"cabecalho.h"

#include<stdlib.h>

/*
M,10000M Men,Rio,2016,G,Mohamed FARAH,USA,25:05.17
*/

void lerArquivo(Medalha medalhas[], FILE *arquivo) {
    int i = 0;
    while (fscanf(arquivo, " %c,%50[^,],%50[^,],%d,%c,%50[^,],%50[^,],%s",
                             &medalhas[i].genero, medalhas[i].modalidade, medalhas[i].cidade,
                             &medalhas[i].ano, &medalhas[i].tipo, medalhas[i].nome,
                             medalhas[i].pais, medalhas[i].resultado) == 8) {
        medalhas[i].codigo = i;
        i++;
    }
    return;
}

int verificarTamanhoArq(FILE *arquivo){
    char caractere;
    int contador=0;
    while ((caractere = fgetc(arquivo)) != EOF) {
        if(caractere == '\n'){
            contador++;
        }
    }
    fseek(arquivo, SEEK_SET, 0);
    return contador;
}