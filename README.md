# Projeto-FDCO2B-EC-AP


Deverá permitir cadastrar
(inserir/listar ok/pesquisar/alterar/excluir ok) as medalhas obtidas por cada atleta. Essa relação
deve aumentar e diminuir dinamicamente;

◦ Deverá gerar e exibir as tabelas ordenadas de totais medalhas por edição dos jogos
olímpicos (País, Ouro, Prata, Bronze), navegando entre elas. Para isso utilize cores,
sons e sua criatividade;// falta por pais



◦ Ao sair do programa, todos os dados sobre as medalhas devem ser salvos em arquivos
binários no HD. O mesmo arquivo binário deverá ser recarregado novamente ao iniciar o
programa nas próximas vezes;


◦ Os códigos referentes a cada estrutura devem estar em um arquivo fonte (.c) separado
com seu respectivo arquivo de cabeçalho(.h). Utilize outros arquivos para organizar seu
código conforme necessidade;

◦ O programa deverá acompanhar um arquivo makefile que permita as operações básicas
de make (compilação), clean (limpeza) e run (execução);

◦ Como parte do critério de avaliação, a qualidade do código-fonte do sistema será
avaliada. Organize seu programa em arquivos .c e .h, funções. Evite o uso de variáveis
globais. O código deverá estar comentado, edentado e com bons nomes de variáveis e
funções. Siga o padrão de documentação apresentado na disciplina (Doxygen).


Defina uma estrutura Medalha contendo: Código (contador inteiro), Gênero (char),
Modalidade(string), Cidade(string), Ano(int), Tipo Medalha GBS(char), Nome
Atleta(string), Pais Origem (string), Resultado (?). ok








◦ Deverá apresentar um menu inicial com as opções disponíveis. Caso necessário,
submenus. A interface deverá ser fácil e intuitiva, seja criativo, utilize cores e beeps :) .
Trate erros do usuário com mensagens e alertas; ok

◦ Ao carregar o programa pela primeira vez, os dados iniciais de todas as medalhas deve
ser lido e carregado em um vetor de tamanho dinâmico e uma mensagem de boas
vindas será exibida ao usuário. Os dados estão disponibilizados no moodle em um
arquivo no formato .csv (valores separados por vírgula); ok

◦ O sistema deverá exibir no menu uma opção de exportar as dados das estruturas em
um arquivo texto no formato .CSV (separados por vírgula).
Observações sobre o código:ok