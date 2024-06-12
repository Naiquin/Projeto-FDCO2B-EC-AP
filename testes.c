
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

/////////////////////////////////////////////// Funções de gerenciamento das medalhas///////////////////////////////////////////////////////////////////////////////


// Função que lé as informacoes do arquivo
void lerArquivo(Medalha medalhas[], FILE *arquivo, int tamanho) {

    // for responsavel por passar por todas as linhas do codigo
    for(int i=0; i<tamanho; i++){

        // salva o codigo de acordo com a linha em que ela se encontra no arquivo
        medalhas[i].codigo = i;

        // Salva as informacoes de cada linha na struct separando as informacoes pelas linhas
        fscanf(arquivo, " %c,%50[^,],%50[^,],%d,%c,%50[^,],%50[^,],%10[^\n]",
                            &medalhas[i].genero, medalhas[i].modalidade, medalhas[i].cidade,
                            &medalhas[i].ano, &medalhas[i].tipo, medalhas[i].nome,
                            medalhas[i].pais, medalhas[i].resultado);
    }// for
    return;
}// lerArquivo

// Função que escreve no arquivo
void escreverArquivo(Medalha medalhas[], FILE *arquivo, int tamanho){
    for(int i=0; i<tamanho; i++){
        fprintf( arquivo,"%d,%c,%s,%s,%d,%c,%s,%s,%s\n",
                            medalhas[i].codigo,medalhas[i].genero, medalhas[i].modalidade,
                            medalhas[i].cidade, medalhas[i].ano, medalhas[i].tipo,
                            medalhas[i].nome, medalhas[i].pais, medalhas[i].resultado);
    }
    return;
}

void lerBinario(Medalha medalhas[],FILE* arquivo, int *tamanho){



   // fread(medalhas,sizeof(Medalha),(*tamanho),arquivo);
    


    // for (int i = 0; i < (* tamanho); i++)
    // {
        
    // fread(&medalhas->codigo,sizeof(int),1,arquivo);
    // fread(&medalhas->genero,sizeof(char),1,arquivo);
    // fread(medalhas->modalidade,sizeof(char),51,arquivo);
    // fread(medalhas->cidade,sizeof(char),51,arquivo);
    // fread(&medalhas->ano,sizeof(int),1,arquivo);
    // fread(&medalhas->tipo,sizeof(char),1,arquivo);
    // fread(medalhas->nome,sizeof(char),51,arquivo);
    // fread(medalhas->pais,sizeof(char),51,arquivo);
    // fread(medalhas->pais,sizeof(char),11,arquivo);
    // }

    printf("\nDados carregados do arquivo binario.\n");
    
}

void salvaBinario(Medalha medalhas[],int *tamanho){

    FILE * arquivo=fopen("medalhas.txt","wb");

    if (arquivo == NULL)
    {
        printf("Erro ao salvar arquivo...\narquivo não salvo\n\n");
        exit(1);

    }
    

 
            fwrite(&medalhas,sizeof(Medalha),tamanho,arquivo);
        
            printf("\n Arquivos salvos..\n");
            fclose(arquivo);
        

return;
 

}// salva binario

//salva as informações em formato csv com o nome dado pelo usuario
void salvarCSV(Medalha medalhas[], char *nomeArquivo,int *tamanho){

    
    char csv[4] = ".csv";
    nomeArquivo = strcat(nomeArquivo,csv);// acrecenta o .csv no nome do arquivo
    FILE *arquivo = fopen(nomeArquivo,"w");// Cria o arquivo .csv no moto texto escrita

    //ir que verifica erro na criação de arquivo
    if (arquivo == NULL)
    {
        // mensagem de erro
        printf("\nErro ao salvar o arquive em .csv\n\n");
        printf("Fim do programa, arquivo não salvo...\n");
        exit(1);// fim do programa
    }//if
    
    // for responsavel por salvar as informações no arquivo .csv 
    for (int i = 0; i < (*tamanho); i++)
    {
        // salva cada linha
        fprintf( arquivo,"%d,%c,%s,%s,%d,%c,%s,%s,%s\n",
                            medalhas[i].codigo,medalhas[i].genero, medalhas[i].modalidade,
                            medalhas[i].cidade, medalhas[i].ano, medalhas[i].tipo,
                            medalhas[i].nome, medalhas[i].pais, medalhas[i].resultado);
    }//for
    
printf("\n Arquivos salvos..\n");

}//// salvarCSV

// verifica quantas linhas tem o arquivo
int verificarTamanhoArq(FILE *arquivo){
    // variaveis usadas
    char caractere;
    int contador = 1;

    // while que para quando chega no fim do arquivo
    while ((caractere = fgetc(arquivo)) != EOF) {

        // if que verifica toda vez que aparece um \n
        if(caractere == '\n'){
            contador++;// acrecebta 1 no contador
        }//if
    }//while
    fseek(arquivo, SEEK_SET, 0);// -------não sei pq ta aqui---------
    return contador;// retorna o valor do contador
}// verificaTamanhoArq

//--------ver se ta funcionando ou nao---------
void lerString(char string[], int tamanho){

    setbuf(stdin,NULL);

    fgets(string, tamanho, stdin);

    string[strcspn(string,"\n")]='\0';

    setbuf(stdin,NULL);

    return;
}

// -------- verificar e melhorar----------
void inserir(Medalha medalhas[],int *tamanho){
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
    // scanf("%i", medalhas[(*tamanho)].ano);
    // printf("Informe o tipo GBD da medalha: ");
    // scanf("%c", medalhas[(*tamanho)].tipo);
    // setbuf(stdin,NULL);
    printf("Informe o nome do atleta: ");
    lerString( medalhas[(*tamanho)].nome, 50);
    printf("Informe o pais onde o atleta nasceu: ");
    lerString( medalhas[(*tamanho)].pais, 50);
    printf("Informe o resultado do atleta: ");
    lerString( medalhas[(*tamanho)].resultado, 50);
    
    return;
}

// pesquisa as informações de acordo com as opcoes
void pesquisar(Medalha *medalhas,int *tamanho){

    // variaver pra verificar a cor que vai ser exibido
    char tipoG = 'G';
    char tipoS = 'S';
    char tipoB = 'B';

    // pede e recebe a opção do usuario
    printf("Escolha o tipo de pesquisa\n1- por data\n2- por codigo\n3- por cidade\n");
    int escolha;
    scanf("%i",&escolha);

    // switch com a execução  
    switch (escolha)
    {
    case 1:// por data

        // pede e salva o ano de escolha do usuario
        printf("Digit o ano desejado:");
        int ano;
        scanf("%i",&ano);

        // for responsavel por passar por todas as medalhas
        for (int i = 0; i < (*tamanho); i++)
        {
            //if que verifica o ano
            if (ano == medalhas[i].ano)
            {
                if (medalhas[i].tipo == tipoG)// if que vericica o tipo da medalha
            {
                // exibe as informacoes na cor ouro
                printf(BGLD"%6d|%6c|%-25s|%-21s|%5d|%-4c|%-30s|%-4s|%-9s\n"RESET,
                                medalhas[i].codigo,medalhas[i].genero, medalhas[i].modalidade,
                                medalhas[i].cidade, medalhas[i].ano, medalhas[i].tipo,
                                medalhas[i].nome, medalhas[i].pais, medalhas[i].resultado);
            }// if ouro
            
            //if responsavel por verificas qual tipo de medalha é e exibir sua linha da cor prata 
            if (medalhas[i].tipo == tipoS)// if que vericica o tipo da medalha
            {
                // exibe as informacoes na cor prata
                printf(BSLV"%6d|%6c|%-25s|%-21s|%5d|%-4c|%-30s|%-4s|%-9s\n"RESET,
                                medalhas[i].codigo,medalhas[i].genero, medalhas[i].modalidade,
                                medalhas[i].cidade, medalhas[i].ano, medalhas[i].tipo,
                                medalhas[i].nome, medalhas[i].pais, medalhas[i].resultado);
            }// if prata
            
            //if responsavel por verificas qual tipo de medalha é e exibir sua linha da cor bronze
            if (medalhas[i].tipo == tipoB)// if que vericica o tipo da medalha
            {
                // exibe as informacoes na cor bronze
                printf(BBRZ"%6d|%6c|%-25s|%-21s|%5d|%-4c|%-30s|%-4s|%-9s\n"RESET,
                                medalhas[i].codigo,medalhas[i].genero, medalhas[i].modalidade,
                                medalhas[i].cidade, medalhas[i].ano, medalhas[i].tipo,
                                medalhas[i].nome, medalhas[i].pais, medalhas[i].resultado);
            }//if bronze
            }// }else if (/* condition */)
            //            {
            //     printf("esta ano não tem registro ou nao teve olimpiada\n");
            // }
            
            
        }
        
        break;

    case 2:// por codigo
        printf("Digit o codigo desejado:");
        int codigo;
        scanf("%i",&codigo);

        for (int i = 0; i < (*tamanho); i++)
        {
            //if responsavel por verificas qual tipo de medalha é e exibir sua linha da cor ouro
            if (medalhas[i].codigo == codigo)
            {
                // exibe as informacoes na cor ouro
                printf(BGLD"%6d|%6c|%-25s|%-21s|%5d|%-4c|%-30s|%-4s|%-9s\n"RESET,
                                medalhas[i].codigo,medalhas[i].genero, medalhas[i].modalidade,
                                medalhas[i].cidade, medalhas[i].ano, medalhas[i].tipo,
                                medalhas[i].nome, medalhas[i].pais, medalhas[i].resultado);
            }// if ouro
        }


        break;

    case 3:// ---------sera por pais
        printf("Digite o nome de uma cidade sede dos jogos:");
        char cidade[31];
        scanf("%30[^\n]",cidade);

        for (int i = 0; i < (*tamanho); i++)
        {
            
        }
        
        break;
    
    default:
        break;
    }// switch
    
    







}// pesquisar

//exibe uma lista com as opcoes do usuario
void listar(Medalha medalhas[],FILE* arquivo ,int *tamanho){

    // cores das medalhas
    char tipoG = 'G';
    char tipoS = 'S';
    char tipoB = 'B';

    inicio:// executa um panda

    // exibe o menu
    printf(BOLD "\n------MENU LISTAR-----\n\nLista de opções\n" RESET);
    printf("1 - Codigo\n");
    printf("2 - Tipo de medalha\n");
    printf("3 - Ano\n");
    printf("4 - listagem por ano\n");

    printf("5 - Voltar\n");
    printf("Digite sua opção: ");// pede a opção do usuario
    
    // salva a opcao do usuario
    int escolha;
    scanf("%i",&escolha);

    // em caso de a opção do usuario ser invalida repete o menu
    while (escolha > 4 || escolha < 1)
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
        printf(BGLD "CODIGO|GENERO|MODALIDADE               |CIDADE               |ANO  |TIPO|NOME                          |PAIS|RESULTADO\n" RESET);
        
        // for responsavel por passar por todos as linhas do arquivo
        for (int i = 0; i < (*tamanho); i++)
        {
            //if responsavel por verificas qual tipo de medalha é e exibir sua linha da cor ouro

            char* COR = BSLV;
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
    

    if (escolha == 4)
    {
        listagem(medalhas,tamanho);
    }
    


    //opção de voltar para o menu inicial
    if (escolha == 5)
    {
        menuInicial(medalhas, arquivo,tamanho);
        
    }//if menu

    
    
    
    return;
}// finção listar

// alterar a lista de medalhas
void alterarMedalha(Medalha *medalhas, int *tamanho,char codigo) {
    for (int i = 0; i < tamanho; i++) {
        if (medalhas[i].codigo == codigo) {
            printf("Digite o novo gênero (M/F): ");
            scanf(" %c", &medalhas[i].genero);
            printf("Digite a nova modalidade: ");
            scanf("%s", medalhas[i].modalidade);
            printf("Digite a nova cidade: ");
            scanf("%s", medalhas[i].cidade);
            printf("Digite o novo ano: ");
            scanf("%d", &medalhas[i].ano);
            printf("Digite o novo tipo de medalha (G/B/S): ");
            scanf(" %c", &medalhas[i].tipo);
            printf("Digite o novo nome do atleta: ");
            scanf("%s", medalhas[i].nome);
            printf("Digite o novo país de origem: ");
            scanf("%s", medalhas[i].pais);
            printf("Digite o novo resultado: ");
            scanf("%s", medalhas[i].resultado);
            printf("Medalha alterada com sucesso.\n");
            return;
        }//if
    }//for
    printf("Medalha não encontrada.\n");
}//alterarMedalha

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

void listagem(Medalha* medalhas,int *tamanho){

    printf("Digite o ano desejado:");
    int ano;
    scanf("%i",&ano);

    typedef struct 
    {
        char pais[4];
        int ouro;
        int prata;
        int bronze;
        int total;
    }Tabela;

    Tabela *tabela = (Tabela *)malloc(sizeof(Tabela) * 100);

    
    
    
    

    
            
                // for que passa por todas as linhas do arquivo
                for (int i = 0; i < (*tamanho); i++)
                {
                    // if que exibe apenas se o ano for  o mesmo do mair para o menor
                    if (medalhas[i].ano == ano)
                    {

                        for (int j = 0; j < 100; j++)
                        {

                            if (tabela[j].pais == medalhas[i].pais)
                            {
                               

                            }else if (tabela[i].pais == NULL)
                            {
                                *tabela[j].pais = medalhas[i].pais;
                            }
                            
                            
                           
                        }
                        
                        


                        printf("%6d|%6c|%-25s|%-21s|%5d|%-4c|%-30s|%-4s|%-9s\n",
                                        medalhas[i].codigo,medalhas[i].genero, medalhas[i].modalidade,
                                        medalhas[i].cidade, medalhas[i].ano, medalhas[i].tipo,
                                        medalhas[i].nome, medalhas[i].pais, medalhas[i].resultado);
                    }// if exibe

                    
                }// for todas as lihas
                
            
                
            
        
    

// for (int i = 0; i < (100); i++)
// {
//     printf("Pais - %s| ouro - %i|prata - %i|bronze - %i|total - %i|\n",
//                                         tabela[i].pais,tabela[i].ouro,tabela[i].prata,tabela[i].
//                                         bronze,tabela[i].ouro+tabela[i].prata+tabela[i].bronze);
    
    
// }




free(tabela);

}

//-------verificar e melhorar--------
void menuInicial(Medalha medalhas[],FILE *arquivo, int *tamanho){
    char opcao[10];
    printf(BOLD "\n------MENU INICIAL-----\n\nLista de opções\n" RESET);
    printf("1- Inserir\n2- Listar\n3- Pesquisar\n4- Alterar\n5- Excluir\n6- salvar\n7- sair\n");
    printf("Digite sua opção: ");
    lerString(opcao, 10);

    if(strcasecmp(opcao, "1") == 0 || strcasecmp(opcao, "inserir") == 0){
        inserir(medalhas, tamanho);
    }else if(strcasecmp(opcao, "2") == 0 || strcasecmp(opcao, "listar") == 0){
        listar(medalhas,arquivo,tamanho);
    }else if(strcasecmp(opcao, "3") == 0 || strcasecmp(opcao, "pesquisar") == 0){

        pesquisar(medalhas,tamanho);
        
    }else if(strcasecmp(opcao, "4") == 0 || strcasecmp(opcao, "alterar") == 0){
        int codigo;
        printf("Digite o código da medalha a ser alterada: ");
        scanf("%d",&codigo);

        alterarMedalha( medalhas, tamanho, codigo);

        exit(1);
        
    }else if(strcasecmp(opcao, "5") == 0 || strcasecmp(opcao, "excluir") == 0){
        
    }else if(strcasecmp(opcao, "6") == 0 || strcasecmp(opcao, "salvar") == 0){
        printf("Escreva o nome do arquivo que quer salvar(Apenas o nome)\n");
        char nomeArquivo[21];
        scanf("%20[^\n]",nomeArquivo);
        setbuf(stdin,NULL);

        salvarCSV(medalhas,nomeArquivo,tamanho);

        exit(1);
        
    }else if(strcasecmp(opcao, "7") == 0 || strcasecmp(opcao, "sair") == 0){
        printf("Ate a proxima!!\nFim do programa...\n");

        salvaBinario(medalhas,&tamanho);

        exit(1);
        
    }//if-elses

    return;
}// funcao menuInicial

//////////////////////////////////////////////////////// main ///////////////////////////////////////////////////// 

int main(){
    
    // abre o arquivo em binario salvo na execução anterior
   // FILE *arquivoTxtAnterior = fopen("medalhas.txt","rb");

    // verifica se o arquivo binario existe
   // if (arquivoTxtAnterior == NULL)
   // {
        // se o arquivo binario não existir...

        // abre o arquivoInicial "medalhas.csv" em leitura do modo texto 
        FILE *arquivoInicial = fopen("medalhas-v2.csv","r");

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
    // }// se o arquivo binario existir

        

    //     // chama a função que verifica quantas linhas o arquivo possue 
    //     // e salva na variavel tamanho
    //     int tamanho = verificarTamanhoArq(arquivoTxtAnterior);

    //     // inicializa a estrutura medalha e aloca dinamicamente o tamanho 
    //     // de acordo com o numero de linha do arquivo
    //     Medalha *medalhas = (Medalha *)malloc(sizeof(Medalha) * tamanho);

    //     // verifica de ha erro na alocação dinamica da estrutura medalhas
    //     if(medalhas == NULL){
    //         perror("Erro ao alocar memoria dinamica ");
    //         exit(1);
    //     }

        
    //     // exibe as boas vindas
    //     printf(BOLD "-------Bem-vindo-------!\n\nRepositorio de medalhas \n  dos jogos olimpicos \n      desde 1896\n" RESET);

    //     // chama a função que le o arquivo e passa para a struct.
    //     lerBinario( medalhas, arquivoTxtAnterior, &tamanho);

    //     // chama a função que exibe o menu e verifica a opção do usuario.
    //     menuInicial(medalhas,arquivoTxtAnterior, &tamanho);

    //     //fecha o arquivoTxtAnterior 
    //     fclose(arquivoTxtAnterior);
    
    //     free(medalhas);
    
    
  




    return 0;
}// main