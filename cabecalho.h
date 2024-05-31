#ifndef CABECALHO_H
#define CABECALHO_H

#include <stdio.h>

typedef struct{
    int codigo;
    char genero;
    char modalidade[51];
    char cidade[51];
    int ano;
    char tipo;
    char nome[51];
    char pais[51];
    char resultado[11];
} Medalha;

void lerArquivo(Medalha medalhas[], FILE *arquivo, int tamanho);

int verificarTamanhoArq(FILE *arquivo);

#endif // CABECALHO_H