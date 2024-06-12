#include"funcoes.h"//cabeçalho das funções criadas para esse programa

#define BOLD "\e[1m"
#define RESET "\e[0m"

int main(){
    
    // abre o arquivo em binario salvo na execução anterior
    FILE *arquivoTxtAnterior = fopen("medalhas.txt","rb");

    // verifica se o arquivo binario existe
    if (arquivoTxtAnterior == NULL)
    {
        // se o arquivo binario não existir...

        // abre o arquivoInicial "medalhas.csv" em leitura do modo texto 
        FILE *arquivoInicial = fopen("medalhas.csv","r");

        // if responsavel por verificar erro ao abrir o arquivo
        if(arquivoInicial == NULL){
            perror("Erro ao abrir o arquivo ");
            exit(1);
        }

        // chama a função que verifica quantas linhas o arquivo possue 
        // e salva na variavel tamanho
        int tamanho = verificarTamanhoArq(arquivoInicial);

        // if responsavel por verificar erro ao abrir o arquivo
        if(arquivoInicial == NULL){
            perror("Erro ao abrir o arquivo ");
            exit(1);        
        }//if


        // inicializa a estrutura medalha e aloca dinamicamente o tamanho 
        // de acordo com o numero de linha do arquivo
        Medalha *medalhas = (Medalha *)malloc(sizeof(Medalha) * tamanho);

        // verifica de ha erro na alocação dinamica da estrutura medalhas
        if(medalhas == NULL){
            perror("Erro ao alocar memoria dinamica ");
            exit(1);
        }
        
        // exibe as boas vindas
        printf(BOLD "-------Bem-vindo-------!\n\nRepositorio de medalhas \n  dos jogos olimpicos \n      desde 1896\n" RESET);

        // chama a função que le o arquivo e passa para a struct.
        lerArquivo( medalhas, arquivoInicial, tamanho);

        // chama a função que exibe o menu e verifica a opção do usuario.
        // abre o arquivoBinario "medalhas.txt" em escrita no modo texto
        FILE *arquivoBinario = fopen("medalhas.txt","wb");

        // verifica se ha erro ao abrir/criar o arquivo 
        if(arquivoBinario == NULL){
            perror("Erro ao abrir o arquivo ");
            exit(1);
        }
        menuInicial(medalhas,arquivoBinario, &tamanho);

        //fecha o arquivoInicial 
        fclose(arquivoInicial);


    // fecha o arquivo
    fclose(arquivoBinario);
    // libera o espaço da struct Medalhas
    }// se o arquivo binario existir

        

        // chama a função que verifica quantas linhas o arquivo possue 
        // e salva na variavel tamanho
        int tamanho = verificarTamanhoArq(arquivoTxtAnterior);

        // inicializa a estrutura medalha e aloca dinamicamente o tamanho 
        // de acordo com o numero de linha do arquivo
        Medalha *medalhas = (Medalha *)malloc(sizeof(Medalha) * tamanho);

        // verifica de ha erro na alocação dinamica da estrutura medalhas
        if(medalhas == NULL){
            perror("Erro ao alocar memoria dinamica ");
            exit(1);
        }

        
        // exibe as boas vindas
        printf(BOLD "-------Bem-vindo-------!\n\nRepositorio de medalhas \n  dos jogos olimpicos \n      desde 1896\n" RESET);

        // chama a função que le o arquivo e passa para a struct.
        lerBinario( medalhas, arquivoTxtAnterior, &tamanho);

        // chama a função que exibe o menu e verifica a opção do usuario.
        menuInicial(medalhas,arquivoTxtAnterior, &tamanho);

        //fecha o arquivoTxtAnterior 
        fclose(arquivoTxtAnterior);
    
        free(medalhas);
    
    
  




    return 0;
}// main