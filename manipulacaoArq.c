#include"cabecalho.h"

#include<stdlib.h>

// função responsavel por salvar as informaçoes do arquivo na struct
void lerArquivo(Medalha medalhas[], FILE *arquivo, int tamanho) {

    // for responsavel por passar em cada linha salvando as informações na struct
    for(int i=0; i<tamanho; i++){
        medalhas[i].codigo = i;// inicia o codigo e atualiza pela variavel i do for
        // responsavel por salvar cada linha
        fscanf(arquivo, " %c,%50[^,],%50[^,],%d,%c,%50[^,],%50[^,],%10[^\n]",
                            &medalhas[i].genero, medalhas[i].modalidade, medalhas[i].cidade,
                            &medalhas[i].ano, &medalhas[i].tipo, medalhas[i].nome,
                            medalhas[i].pais, medalhas[i].resultado);
    }// for
    return;
}// lerArquivo

// função responsavel por salvar as informaçoes a struct no arquivo
void escreverArquivo(Medalha medalhas[], FILE *arquivo, int tamanho){

    
    for(int i=0; i<tamanho; i++){

        // responsavel por salvar cada linha
        fprintf( arquivo,"%d,%c,%s,%s,%d,%c,%s,%s,%s\n",
                            medalhas[i].codigo,medalhas[i].genero, medalhas[i].modalidade,
                            medalhas[i].cidade, medalhas[i].ano, medalhas[i].tipo,
                            medalhas[i].nome, medalhas[i].pais, medalhas[i].resultado);
    }
    return;
}

int verificarTamanhoArq(FILE *arquivo){
    char caractere;
    int contador=1;
    while ((caractere = fgetc(arquivo)) != EOF) {
        if(caractere == '\n'){
            contador++;
        }
    }
    fseek(arquivo, SEEK_SET, 0);
    return contador;
}