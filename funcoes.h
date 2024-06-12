#ifndef CABECALHO_H
#define CABECALHO_H

#include <stdio.h>



void lerArquivo(Medalha medalhas[], FILE *arquivo, int tamanho);

void escreverArquivo(Medalha medalhas[], FILE *arquivo, int tamanho);

void lerBinario(Medalha medalhas[],FILE* arquivo, int *tamanho);

void salvaBinario(Medalha medalhas[],int *tamanho);

void salvarCSV(Medalha medalhas[], char *nomeArquivo,int *tamanho);

int verificarTamanhoArq(FILE *arquivo);

void lerString(char string[], int tamanho);

void inserir(Medalha medalhas[],int *tamanho);

void pesquisar(Medalha *medalhas,int *tamanho);

void listar(Medalha medalhas[],FILE* arquivo ,int *tamanho);

void excluir(Medalha medalhas[],int codigo,int *tamanho);

void menuInicial(Medalha medalhas[],FILE *arquivo, int *tamanho);

#endif // CABECALHO_H