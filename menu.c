#include"cabecalho.h"

#include<stdlib.h>

#define BOLD "\e[1m"
#define RESET "\e[0m"


void menuInicial(){
    
    printf(BOLD "------MENU INICIAL-----\n\n" RESET);

    printf("Lista de opções\n");
    printf("1- Inserir\n2- Listar\n3- Pesquisar\n4- Alterar\n5- Excluir\n6- Sair\n");
    printf("");




    return;
}