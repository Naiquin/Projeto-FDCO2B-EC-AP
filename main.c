#include"cabecalho.h"//cabeçalho das funções criadas para esse programa

#include<stdlib.h>

#define BOLD "\e[1m"
#define RESET "\e[0m"

int main(){

    // abre o arquivo1 "medalhas.csv" em leitura do modo texto 
    FILE *arquivo1 = fopen("medalhas.csv","r");

    // if responsavel por verificar erro ao abrir o arquivo
    if(arquivo1 == NULL){
        perror("Erro ao abrir o arquivo ");
        exit(1);
    }

    // chama a função que verifica quantas linhas o arquivo possue 
    // e salva na variavel tamanho
    int tamanho = verificarTamanhoArq(arquivo1);

    // inicializa a estrutura medalha e aloca dinamicamente o tamanho 
    // de acordo com o numero de linha do arquivo
    Medalha *medalhas = (Medalha *)malloc(sizeof(Medalha) * tamanho);

    // verifica de ha erro na alocação dinamica da estrutura medalhas
    if(medalhas == NULL){
        perror("Erro ao alocar memoria dinamica ");
        exit(1);
    }
    
    // exibe as boas vindas
    printf(BOLD "Bem-vindo!" RESET);

    // chama a função que le o arquivo e passa para a struct.
    lerArquivo( medalhas, arquivo1, tamanho);

    // chama a função que exibe o menu e verifica a opção do usuario.
    menuInicial(medalhas, &tamanho);

    //fecha o arquivo1 
    fclose(arquivo1);

    // abre o arquivo2 "medalhas.txt" em escrita no modo texto
    FILE *arquivo2 = fopen("medalhas.txt","w");

    // verifica se ha erro ao abrir/criar o arquivo 
    if(arquivo2 == NULL){
        perror("Erro ao abrir o arquivo ");
        exit(1);
    }

    //chama a função que salva os informações da struct no arquivo "medalhas.txt"
    escreverArquivo( medalhas, arquivo2, tamanho);

    // fecha o arquivo
    fclose(arquivo2);

    // libera o espaço da struct Medalhas
    free(medalhas);
    return 0;
}// main