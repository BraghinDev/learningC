# Algoritmo para calcular a menor distância entre dois ponto em uma matriz quadrada
 - Projeto feito para aprendizagem da linguagem C
 - Dada uma matriz X por X, o algoritmo classifica a menor distância entre um ponto interno e um ponto na borda
# Funcionamento
 - Para fácil visualização, foram utilizados caracteres para representar o conteúdo da matriz:

    - F - (Free) : Define uma célula livre
    - A - (Agent): Define a ponto de partida
    - W - (Wall) : Define paredes
    - E - (Exit) : Define o ponto de chegada

 - Para cada caractere foi atribuído um valor inteiro:

    - F = 00
    - W = -1/-4
    - E = -2
    - A = -3
    Obs: o valor -4 é utilizado para identificar um obstáculo interno, e o -1 uma parede nas extremidades

 - A classificação da distância é dada de acordo com a posção da célula e o ponto de chegada.
 - Vejamos uma matriz 5x5:

    Classificação de distância a partir do ponto de início:

               4  3  2  3  4
               3  2  1  2  3
               2  1  0  1  2
               3  2  1  2  3
               4  3  2  3  4

    Inteiro identificador:

              -1 -1 -1 -1 -1
              -1  0 -1  0 -2  
              -1  0 -3  0 -1
              -1  0  0  0 -1
              -1 -3 -1 -1 -1

    Classificação de distância a partir do ponto final:
             
              5  4  5  6  7 
              4  3  4  5  6
              3  2  3  4  5
              2  1  2  3  4
              1  0  1  2  3
 
 - Para obtermos a menor distância, somamos os valores das distâncias calculada à partir dos dois pontos, inicial e final

              -1 -1 -1 -1 -1
              -1  5 -1  7 -1
              -1  3  3  5 -1
              -1  3  3  5 -1
              -1  0 -1 -1 -1
 
 - Note que os valores negativos devem ser ignorados, pois são passagens bloqueadas
 - Aagora, basta selecionar o caminho com o menor valor, partindo do ponto inicial ou do ponto final

# Considerações finais
 - Para o desenvolvimento deste algoritmo, utilizei como base o algoritmo de Dijkstra
 - A implementação desse algoritmo poderia ser realizada de uma forma muito mais simples e direta. Entretanto, a intenção 
   deste código é utilizar conceitos básicos da linguagem C para fixação durante sua aprendizagem. Para isso, foram utili
   zados os seguintes conceitos:

      - Estrutura condicional if - else
      - Estrutura de repetição for e while
      - Operadores relacionais, aritméticos, de atribuição, de incremento e lógicos
      - Matrizes
      - Cabeçalhos externos
      - Prototipação de funções
      - Diretiva de pré-processdor #define
      - Ponteiros
      - Alocação dinâmica e liberação de memória
      - Tipo abstrato de dado (TAD) com struct
      - Definição de um nome para o novo tipo de dado utilizando a palavra reservada typedef
      - Ponteiros como argumentos para funções
      - TADs como argumentos para funções
      - Números aleatórios com as funções rand e time

