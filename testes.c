
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define BOLD "\e[1m"
#define BGLD "\e[1;38;2;218;165;32m" // Dourado Negrito
#define BSLV "\e[1;38;2;192;192;192m" // prata
#define BBRZ "\e[1;38;2;205;127;50m" // bronze
#define RESET "\e[0m"

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

void lerArquivo(Medalha medalhas[], FILE *arquivo, int tamanho) {
    for(int i=0; i<tamanho; i++){
        medalhas[i].codigo = i;
        fscanf(arquivo, " %c,%50[^,],%50[^,],%d,%c,%50[^,],%50[^,],%10[^\n]",
                            &medalhas[i].genero, medalhas[i].modalidade, medalhas[i].cidade,
                            &medalhas[i].ano, &medalhas[i].tipo, medalhas[i].nome,
                            medalhas[i].pais, medalhas[i].resultado);
    }
    return;
}

void escreverArquivo(Medalha medalhas[], FILE *arquivo, int tamanho){
    for(int i=0; i<tamanho; i++){
        fprintf( arquivo,"%d,%c,%s,%s,%d,%c,%s,%s,%s\n",
                            medalhas[i].codigo,medalhas[i].genero, medalhas[i].modalidade,
                            medalhas[i].cidade, medalhas[i].ano, medalhas[i].tipo,
                            medalhas[i].nome, medalhas[i].pais, medalhas[i].resultado);
    }
    return;
}

int verificarTamanhoArq(FILE *arquivo){
    char caractere;
    int contador = 1;
    while ((caractere = fgetc(arquivo)) != EOF) {
        if(caractere == '\n'){
            contador++;
        }
    }
    fseek(arquivo, SEEK_SET, 0);
    return contador;
}

void lerString(char string[], int tamanho){

    setbuf(stdin,NULL);

    fgets(string, tamanho, stdin);

    string[strcspn(string,"\n")]='\0';

    setbuf(stdin,NULL);

    return;
}

void inserir(Medalha medalhas[], int *tamanho);
void listar(Medalha medalhas[], int *tamanho);
void excluir(Medalha medalhas[],int codigo,int *tamanho);

void menuInicial(Medalha medalhas[], int *tamanho){
    char opcao[10];
    printf(BOLD "\n------MENU INICIAL-----\n\nLista de opções\n" RESET);
    printf("1- Inserir\n2- Listar\n3- Pesquisar\n4- Alterar\n5- Excluir\n6- Sair\n");
    printf("Digite sua opção: ");
    lerString(opcao, 10);

    if(strcasecmp(opcao, "1") == 0 || strcasecmp(opcao, "inserir") == 0){
        inserir(medalhas, tamanho);
    }else if(strcasecmp(opcao, "2") == 0 || strcasecmp(opcao, "listar") == 0){
        listar(medalhas, tamanho);
    }else if(strcasecmp(opcao, "3") == 0 || strcasecmp(opcao, "pesquisar") == 0){
        
    }else if(strcasecmp(opcao, "4") == 0 || strcasecmp(opcao, "alterar") == 0){
        
    }else if(strcasecmp(opcao, "5") == 0 || strcasecmp(opcao, "excluir") == 0){
        
    }else if(strcasecmp(opcao, "6") == 0 || strcasecmp(opcao, "sair") == 0){
        printf("Ate a proxima!!\nFim do programa...\n");
        exit(1);
        
    }

    return;
}

void inserir(Medalha medalhas[], int *tamanho){
    ((*tamanho)++);
    medalhas = realloc(medalhas, (*tamanho) * sizeof(Medalha));
    if(medalhas == NULL){
        perror("Erro ao alocar memoria ");
        exit(1);
    }

    medalhas[(*tamanho)].codigo = (*tamanho);
    
    printf("Informe o genero do atleta: ");
    scanf("%c", &medalhas[(*tamanho)].genero);
    setbuf(stdin,NULL);
    printf("Informe a modalidade que foi conquistada a medalha: ");
    lerString( medalhas[(*tamanho)].modalidade, 50);
    printf("Informe a cidade que foi conquistada a medalha: ");
    lerString( medalhas[(*tamanho)].cidade, 50);
    printf("Informe o ano que foi conquistada a medalha: ");
    scanf("%i", medalhas[(*tamanho)].ano);
    printf("Informe o tipo GBD da medalha: ");
    scanf("%c", medalhas[(*tamanho)].tipo);
    setbuf(stdin,NULL);
    printf("Informe o nome do atleta: ");
    lerString( medalhas[(*tamanho)].nome, 50);
    printf("Informe o pais onde o atleta nasceu: ");
    lerString( medalhas[(*tamanho)].pais, 50);
    printf("Informe o resultado do atleta: ");
    lerString( medalhas[(*tamanho)].resultado, 50);
    
    return;
}



void listar(Medalha medalhas[], int *tamanho){

    char tipoG = 'G';
    char tipoS = 'S';
    char tipoB = 'B';

    inicio:

    printf(BOLD "\n------MENU LISTAR-----\n\nLista de opções\n" RESET);
    printf("1 - Codigo\n");
    printf("2 - Tipo de medalha\n");
    printf("3 - Ano\n");
    printf("4 - Voltar\n");
    printf("5 - Sair\n");
    printf("Digite sua opção: ");
    

    int escolha;
    scanf("%i",&escolha);

    while (escolha > 5 || escolha < 1)
    {
        printf(BOLD "\n------MENU LISTAR-----\n\nLista de opções\n" RESET);
        printf("Digite o tipo de visualização\n");
        printf("1 - Codigo\n");
        printf("2 - Tipo de medalha\n");
        printf("3 - Ano\n");
        printf("4 - Voltar\n");
        printf("5 - Sair\n");
        printf("Digite sua opção: ");

        scanf("%i",&escolha);
        
    }
    
    

    //exibe como esta no atquivo por ordem de codigo
    if (escolha == 1)
    {
        // for responsavel por passar por todos as linhas do arquivo
        for (int i = 0; i < (*tamanho); i++)
        {
            //if responsavel por verificas qual tipo de medalha é e exibir sua linha da cor ouro
            if (medalhas[i].tipo == tipoG)
            {
                // exibe as informacoes na cor ouro
                printf(BGLD"%6d|%6c|%-25s|%-21s|%5d|%-4c|%-30s|%-4s|%-9s\n"RESET,
                                medalhas[i].codigo,medalhas[i].genero, medalhas[i].modalidade,
                                medalhas[i].cidade, medalhas[i].ano, medalhas[i].tipo,
                                medalhas[i].nome, medalhas[i].pais, medalhas[i].resultado);
            }// if ouro
            
            //if responsavel por verificas qual tipo de medalha é e exibir sua linha da cor prata 
            if (medalhas[i].tipo == tipoS)
            {
                // exibe as informacoes na cor prata
                printf(BSLV"%6d|%6c|%-25s|%-21s|%5d|%-4c|%-30s|%-4s|%-9s\n"RESET,
                                medalhas[i].codigo,medalhas[i].genero, medalhas[i].modalidade,
                                medalhas[i].cidade, medalhas[i].ano, medalhas[i].tipo,
                                medalhas[i].nome, medalhas[i].pais, medalhas[i].resultado);
            }// if prata
            
            //if responsavel por verificas qual tipo de medalha é e exibir sua linha da cor bronze
            if (medalhas[i].tipo == tipoB)
            {
                // exibe as informacoes na cor bronze
                printf(BBRZ"%6d|%6c|%-25s|%-21s|%5d|%-4c|%-30s|%-4s|%-9s\n"RESET,
                                medalhas[i].codigo,medalhas[i].genero, medalhas[i].modalidade,
                                medalhas[i].cidade, medalhas[i].ano, medalhas[i].tipo,
                                medalhas[i].nome, medalhas[i].pais, medalhas[i].resultado);
            }//if bronze
            
        }//for todas as linhas

        // retorna para o inicio da função
        goto inicio;

    }// if opção por codigo
    
    //exibe por ordem de medalhas
    if (escolha == 2)
    {
        // cabeçalho da tabela ouro
        printf(BGLD"\nMEDALHAS DE OURO\n"RESET);
        printf(BGLD "CODIGO|GENERO|MODALIDADE               |CIDADE               |ANO  |TIPO|NOME                          |PAIS|RESULTADO\n" RESET);
        
            // for responsavel por passar por todos as linhas do arquivo
            for (int i = 0; i < (*tamanho); i++)
            {
                // if que exibe apenas as medalhas de ouro
                if (medalhas[i].tipo == tipoG)
                {
                    printf(BGLD"%6d|%6c|%-25s|%-21s|%5d|%-4c|%-30s|%-4s|%-9s\n"RESET,
                                    medalhas[i].codigo,medalhas[i].genero, medalhas[i].modalidade,
                                    medalhas[i].cidade, medalhas[i].ano, medalhas[i].tipo,
                                    medalhas[i].nome, medalhas[i].pais, medalhas[i].resultado);
                }// if ouro
                
            }// for ouro

        // cabeçalho da tabela prata
        printf(BSLV"\nMEDALHAS DE PRATA\n"RESET);
        printf(BSLV "CODIGO|GENERO|MODALIDADE               |CIDADE               |ANO  |TIPO|NOME                          |PAIS|RESULTADO\n" RESET);
        
            // for responsavel por passar por todos as linhas do arquivo
            for (int i = 0; i < (*tamanho); i++)
            {
                // if que exibe apenas as medalhas de prata
                if (medalhas[i].tipo == tipoS)
                {
                    printf(BSLV"%6d|%6c|%-25s|%-21s|%5d|%-4c|%-30s|%-4s|%-9s\n"RESET,
                                    medalhas[i].codigo,medalhas[i].genero, medalhas[i].modalidade,
                                    medalhas[i].cidade, medalhas[i].ano, medalhas[i].tipo,
                                    medalhas[i].nome, medalhas[i].pais, medalhas[i].resultado);
                }//if prata
                
            }//for prata

        // cabeçalho da tabela bronze
        printf(BBRZ"\nMEDALHAS DE OURO\n"RESET);
        printf(BBRZ "CODIGO|GENERO|MODALIDADE               |CIDADE               |ANO  |TIPO|NOME                          |PAIS|RESULTADO\n" RESET);
        // for responsavel por passar por todos as linhas do arquivo
            for (int i = 0; i < (*tamanho); i++)
            {
                // if que exibe apenas as medalhas de bronze
                if (medalhas[i].tipo == tipoB)
                {
                    printf(BBRZ"%6d|%6c|%-25s|%-21s|%5d|%-4c|%-30s|%-4s|%-9s\n"RESET,
                                    medalhas[i].codigo,medalhas[i].genero, medalhas[i].modalidade,
                                    medalhas[i].cidade, medalhas[i].ano, medalhas[i].tipo,
                                    medalhas[i].nome, medalhas[i].pais, medalhas[i].resultado);
                }//if bronze
            }//for bronze

        // retorna para o inicio da função    
        goto inicio;
    }// escolha por tipo de medalha
      
    //exibe por ordem de ano
    if (escolha == 3)
    {
        // for q passa por todos os anos dos jogos
        for (int j = 2022; j > 1890;j--)
            {
                // for que passa por todas as linhas do arquivo
                for (int i = 0; i < (*tamanho); i++)
                {
                    // if que exibe apenas se o ano for  o mesmo do mair para o menor
                    if (medalhas[i].ano == j)
                    {
                        printf(BOLD"%6d|%6c|%-25s|%-21s|%5d|%-4c|%-30s|%-4s|%-9s\n"RESET,
                                        medalhas[i].codigo,medalhas[i].genero, medalhas[i].modalidade,
                                        medalhas[i].cidade, medalhas[i].ano, medalhas[i].tipo,
                                        medalhas[i].nome, medalhas[i].pais, medalhas[i].resultado);
                    }// if exibe

                    
                }// for todas as lihas
                
            
                
            }// for 

            // retorna para o inicio da função
            goto inicio;
    }// if por ano
    
    //opção de voltar para o menu inicial
    if (escolha == 4)
    {
        menuInicial(medalhas,&tamanho);
        
    }//if menu

    // opção de finalizar o programa
    if (escolha == 5)
    {
        printf("\nAte a proxima!!\nFim do programa...\n");
        exit(1);
    }// if fim
    
    
    return;
}// finção listar


void excluir(Medalha medalhas[],int codigo,int *tamanho){

    //for responsavel por passar por todas as medalhas
    for (int i = 0; i < *tamanho; i++)
    {
        // se encontras o codigo da medalaha digitada entra no "for"
        if (medalhas[i].codigo == codigo)
        {
            // for responsavel por substituir a medalha com o codigo digitado pelo proximo.
            // o proximo e substituido pelo seguinte e assim por diante.
           for (int  j = i; j < *tamanho - 1; j++)
           {
            medalhas[j] = medalhas[j +1];
           }//for
           
        }//if
        
    }//for
    return;
}//excluir


int main(){
    FILE *arquivo1 = fopen("medalhas-v2.csv","r");


    if(arquivo1 == NULL){
        perror("Erro ao abrir o arquivo ");
        exit(1);
    }
    int tamanho = verificarTamanhoArq(arquivo1);
    Medalha *medalhas = (Medalha *)malloc(sizeof(Medalha) * tamanho);
    if(medalhas == NULL){
        perror("Erro ao alocar memoria dinamica ");
        exit(1);
    }
    
    printf(BOLD "Bem-vindo!" RESET);

    lerArquivo( medalhas, arquivo1, tamanho);

    menuInicial(medalhas, &tamanho);

    fclose(arquivo1);

    FILE *arquivo2 = fopen("medalhas.txt","w");
    if(arquivo2 == NULL){
        perror("Erro ao abrir o arquivo ");
        exit(1);
    }

    escreverArquivo( medalhas, arquivo2, tamanho);

    fclose(arquivo2);
    free(medalhas);
    return 0;
}