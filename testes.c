
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

void salvaBinario(Medalha *medalhas,int *tamanho){

    FILE *arquivoBinario = fopen("arquivoBinario.bin","wb");
    if (arquivoBinario == NULL)
    {
        perror("Esso ao abrir o arquivo binario para salvamento.\n");
        exit(1);
    }//if erro
    printf("%d\n",tamanho);
    fwrite(medalhas,sizeof(Medalha),tamanho,arquivoBinario);
    fclose(arquivoBinario);
    free(medalhas);//libera o espaço da struct Medalhas

    return;
    
}// salvaBinario

 

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

void inserir(Medalha**medalhas,int*tamanho){
 (*tamanho)++;//realoca a memória para a nova medalha
 *medalhas = realloc(*medalhas,(*tamanho)*sizeof(Medalha));

 if(*medalhas == NULL){
    perror("Erro ao alocar memória!!");
    exit(1);//verifica se há algum erro ao realocar
 }

    int indice = *tamanho-1; //indice da nova medalha

    (*medalhas)[indice].codigo = indice;
    printf("Informe o genero do atleta: ");
    scanf("%c",&(*medalhas)[indice].genero);
     setbuf(stdin,NULL);
     printf("Informe a modalidade do atleta: ",medalhas);
     lerString((*medalhas)[indice].modalidade, 50);
     printf("Informe a cidade onde a medalha foi conquista: ",medalhas);
     lerString((*medalhas)[indice].cidade, 50);
     printf("Informe o ano onde a medalha foi conquistada: ",medalhas);
     scanf("%d",&(*medalhas)[indice].ano);
     // scanf("%i", medalhas[indice].ano);
     //printf("Informe o tipo GBD da medalha: ",medalhas);
    //lerString((*medalhas)[indice].tipo);
    //setbuf(stdin,NULL);
    printf("Informe o nome do atleta: ");
    lerString((*medalhas)[indice].nome, 50);
     printf("Informe o pais onde o atleta nasceu: ");
     lerString((*medalhas)[indice].pais, 50);
    printf("Informe o resultado do atleta: ");
    lerString((*medalhas)[indice].resultado, 50);
    
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
        printf(BGLD "CODIGO|GENERO|MODALIDADE               |CIDADE               |ANO  |TIPO|NOME                          |PAIS|RESULTADO\n" RESET);
        
        // for responsavel por passar por todos as linhas do arquivo
        for (int i = 0; i < (*tamanho); i++)
        {
            //if responsavel por verificas qual tipo de medalha é e exibir sua linha da cor ouro

            
            if (medalhas[i].tipo == tipoG)
            {
                // exibe as informacoes na cor ouro
                printf(BGLD);
            }// if ouro
            
            //if responsavel por verificas qual tipo de medalha é e exibir sua linha da cor prata 
            if (medalhas[i].tipo == tipoS)
            {
                // exibe as informacoes na cor prata
                printf(BSLV);
            }// if prata
            
            //if responsavel por verificas qual tipo de medalha é e exibir sua linha da cor bronze
            if (medalhas[i].tipo == tipoB)
            {
                // exibe as informacoes na cor bronze
                printf(BBRZ);
            }//if bronze

            printf("%6d|%6c|%-25s|%-21s|%5d|%-4c|%-30s|%-4s|%-9s\n"RESET,
                                medalhas[i].codigo,medalhas[i].genero, medalhas[i].modalidade,
                                medalhas[i].cidade, medalhas[i].ano, medalhas[i].tipo,
                                medalhas[i].nome, medalhas[i].pais, medalhas[i].resultado);
            
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
        menuInicial(medalhas,arquivo,tamanho);
        
    }//if menu

    
    
    
    return;
}// finção listar

// alterar a lista de medalhas
void alterarMedalha(Medalha *medalhas, int *tamanho,char codigo) {
    for (int i = 0; i < *tamanho; i++) {
        if (medalhas[i].codigo == codigo) {
            printf("Medalha encontrada. Digite as novas informações.\n");
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
    return;
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
           printf("Medalha excluida com sucesso.\n");
           return;
        }//if
        
    }//for
    printf("Medalha não encontrada.\n");
    return;
}//excluir

void listagem(Medalha* medalhas,int *tamanho){

    //variaveis utilizadas
    char tipoG = 'G';
    char tipoS = 'S';
    char tipoB = 'B';
    int totalPaises = 0;
    
    // struct temporaria para salvar os resultados
    typedef struct 
    {
        char pais[4];
        int ouro;
        int prata;
        int bronze;
        int pontos;
        int total;
    }Tabela;

    // pede e recebe o ano desejado
    printf("Digite o ano desejado:");
    int ano;
    scanf("%i",&ano);

    // inicializa a estrutura Tabela
    Tabela *tabela = (Tabela *)malloc(sizeof(Tabela) * 100);

  
            
                // for que passa por todas as linhas do arquivo
                for (int i = 0; i < (*tamanho); i++)
                {
                    // if que exibe apenas se o ano for  o mesmo do mair para o menor
                    if (medalhas[i].ano == ano)
                    {
                        
                        int paisPresente = 0;// variavel para verificação se o espaco esta vazil

                        for (int j = 0; j < totalPaises; j++)// for responsavel por passar por todos os paises
                        {


                            if (strcmp(tabela[j].pais,medalhas[i].pais)==0)// verifica se o pais esta na lista
                            {
                                paisPresente = 1;// variavel atestando que o pais esta na lista

                                // ifs responsaveis pos acrecentar medalha
                                if (medalhas[i].tipo == tipoG)
                                {
                                    tabela[totalPaises].ouro++;
                                    tabela[totalPaises].total++;
                                }
                                if (medalhas[totalPaises].tipo == tipoS)
                                {
                                    tabela[totalPaises].prata++;
                                    tabela[totalPaises].total++;
                                }
                                if (medalhas[i].tipo == tipoB)
                                {
                                    tabela[totalPaises].bronze++;
                                    tabela[totalPaises].total++;
                                }//if
                                break;
                            }//for
                            
                           
                        }
                            if (!paisPresente)// se o espaço esta vazio
                            {
                                strcpy(tabela[totalPaises].pais,medalhas[i].pais);// salva o nome do paiz na lista

                                // ifs responsaveis pos acrecentar medalha
                                if (medalhas[i].tipo == tipoG)
                                {
                                    tabela[totalPaises].ouro++;
                                    tabela[totalPaises].total++;
                                    
                                }
                                if (medalhas[totalPaises].tipo == tipoS)
                                {
                                    tabela[totalPaises].prata++;
                                    tabela[totalPaises].total++;
                                    
                                }
                                if (medalhas[i].tipo == tipoB)
                                {
                                    tabela[totalPaises].bronze++;
                                    tabela[totalPaises].total++;
                                }//ifs

                                totalPaises++;//acrecenta em paisesTotais

                            }//if
                    }// if exibe                    
                }// for todas as lihas

                
                

                for (int i = 0; i < totalPaises; i++)// for q passa por todos os paises
                {
                    for (int j = 0; j < totalPaises; j++)//for que verifica individual
                    {
                        // if que compara os totais e salva o maior na freente
                        if (tabela[j].total < tabela[j+1].total)
                        {
                            Tabela temp = tabela[j];
                            tabela[j] = tabela[j+1];
                            tabela[j+1] = temp;
                        } // if                 
                    }//for interno
                }// for externo
                
                // exibe cabeçalho
                printf("Pais|Ouro|prata|bronze|total|Pontos\n");

                for (int i = 0; i < totalPaises; i++)// for que exibe resultado
                {
                    
                    // resultados com cores

                    printf(BOLD);
                    printf("%-4s|"RESET,tabela[i].pais);
                    printf(BGLD);
                    printf("%-4i"RESET,tabela[i].ouro);
                    printf(BSLV);
                    printf("|%-5i"RESET,tabela[i].prata);
                    printf(BBRZ);
                    printf("|%-6i"RESET,tabela[i].bronze);
                    printf(BOLD);
                    printf("|%-5i\n"RESET,tabela[i].total);
                    
                    
                    
                }//for
                
free(tabela);

}// listagem

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

        alterarMedalha( medalhas,tamanho,codigo);

        exit(1);
        
    }else if(strcasecmp(opcao, "5") == 0 || strcasecmp(opcao, "excluir") == 0){

        int codigo;
        printf("Digite o código da medalha a ser excluída: ");
        scanf("%d",&codigo);

        excluir( medalhas,codigo,tamanho);
        exit(1);
        
        
    }else if(strcasecmp(opcao, "6") == 0 || strcasecmp(opcao, "salvar") == 0){
        printf("Escreva o nome do arquivo que quer salvar(Apenas o nome)\n");
        char nomeArquivo[21];
        scanf("%20[^\n]",nomeArquivo);
        setbuf(stdin,NULL);

        salvarCSV(medalhas,nomeArquivo,tamanho);

        exit(1);
        
    }else if(strcasecmp(opcao, "7") == 0 || strcasecmp(opcao, "sair") == 0){
        printf("Ate a proxima!!\nFim do programa...\n");

        salvaBinario(medalhas,*tamanho);

        exit(1);
        
    }//if-elses

    return;
}// funcao menuInicial

//////////////////////////////////////////////////////// main ///////////////////////////////////////////////////// 

int main(){
    
    // abre o arquivo em binario salvo na execução anterior
    FILE *arquivoBinario = fopen("arquivoBinario.bin","rb");

    // verifica se o arquivo binario existe
    if (arquivoBinario == NULL)
    {
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
        
        menuInicial(medalhas,arquivoInicial, &tamanho);

        //fecha o arquivoInicial 
        fclose(arquivoInicial);

    
    }// se o arquivo binario existir

    fseek(arquivoBinario,0,SEEK_END);
    long tamanhoArquivo = ftell(arquivoBinario);
    rewind(arquivoBinario);

    printf("&d\n",tamanhoArquivo);

    int tamanho = tamanhoArquivo/sizeof(Medalha);
    printf("&d\n",tamanho);

        Medalha *medalhas = (Medalha *)malloc(sizeof(Medalha) * tamanho);

        // verifica de ha erro na alocação dinamica da estrutura medalhas
        if(medalhas == NULL){
            perror("Erro ao alocar memoria dinamica ");
            exit(1);
        }
    medalhas = (Medalha*)malloc(tamanho* sizeof(Medalha));
    if (medalhas == NULL)
    {
       perror("Erro ao alocar memoria\n");
       exit(1);
    }//if erro

    fread(medalhas,sizeof(Medalha),tamanho,arquivoBinario);

    fclose(arquivoBinario);
       
        // exibe as boas vindas
        printf(BOLD "-------Bem-vindo-------!\n\nRepositorio de medalhas \n  dos jogos olimpicos \n      desde 1896\n" RESET);

        // chama a função que le o arquivo e passa para a struct.
        

        // chama a função que exibe o menu e verifica a opção do usuario.
        menuInicial(medalhas,arquivoBinario, &tamanho);

        //fecha o arquivoTxtAnterior 
        fclose(arquivoBinario);   

    return 0;
}// main