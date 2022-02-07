#include <stdio.h>
#include "matriz.h"
#include <time.h>
#include <stdlib.h>


void inicializandoMatriz(regMat** mat, int sizeX, int sizeY, regPos* inicio, regPos* final)
{
    int i, j, x, y, terminou = 0;
    int rand1, rand2, preencheu = 0;
    srand(time(NULL));

    printf("\nMétodo inicializando matriz.\n");

    /* define todas as extermidas da matriz como paredes */
    for(i = 0; i < sizeX; i++)
    {
        mat[0][i].valor = -1;
        mat[0][i].tipo = 'W';
    }

    for(i = 0; i < sizeY; i++)
    {
        mat[i][0].valor = -1;
        mat[i][0].tipo = 'W';
    }

    for(i = 0; i < sizeX; i++)
    {
        mat[i][sizeY - 1].valor = -1;
        mat[i][sizeY - 1].tipo = 'W';
    }

    for(i = 0; i < sizeY; i++)
    {
        mat[sizeX - 1][i].valor = -1;
        mat[sizeX - 1][i].tipo = 'W';
    }

    /* define todas as celulas da matriz(com excessao das bordas), como passagem livre */
    for(i = 0; i < sizeX; i++)
    {
        for(j = 0; j < sizeY; j++)
        {
            if(mat[i][j].valor != -1)
            {
                mat[i][j].valor = 0;
                mat[i][j].tipo = 'F';
            }
        }
    }

    /* Coloca paredes aleatorias na matriz */
    for(i = 0; i < (sizeX / 3); i++)
    {
        while(preencheu == 0)
        {
            rand1 = (rand() % (sizeX - 1));
            rand2 = (rand() % (sizeY - 1));
            if(mat[rand1][rand2].valor == 0)
            {
                mat[rand1][rand2].valor = -4;
                mat[rand1][rand2].tipo = 'W';
                preencheu = 1;
            }
        }
        preencheu = 0;
    }

    /* Definindo posicoes aleatorias para uma saida */
    while(!terminou)
    {
        x = (rand() % (sizeX - 1));
        y = (rand() % (sizeY - 1));

        if(mat[x][y].valor == -1)
        {
            mat[x][y].valor = -2;
            mat[x][y].tipo = 'E';
            terminou = 1;
            final->x = x;
            final->y = y;
        }
    }

    terminou = 0;

    /* Definindo uma posicao aleatoria para ponto de inicio */
    while(!terminou)
    {
        x = (rand() % (sizeX - 1));
        y = (rand() % (sizeY - 1));

        if(mat[x][y].valor == 0)
        {
            mat[x][y].valor = -3;
            mat[x][y].tipo = 'A';
            terminou = 1;
            inicio->x = x;
            inicio->y = y;
        }
    }

    for(i = 0; i < sizeX; i++)
    {
        for(j = 0; j < sizeY; j++)
        {
            printf("%02d ", mat[i][j].valor);
        }
        printf("\n");
    }

    printf("\n");

    for(i = 0; i < sizeX; i++)
    {
        for(j = 0; j < sizeY; j++)
        {
            printf("%c ", mat[i][j].tipo);
        }
        printf("\n");
    }

    printf("\nFim do método inicializando matriz.\n");

}

void defineDistancia(regMat** mat, int sizeX, int sizeY, int initialX, int initialY, int escolha)
{
    int i = 0, j = 0, k = 0, l = 0;
    int matrixClassified[sizeX][sizeY];
    regPos initialPos;

    initialPos.x = initialX;
    initialPos.y = initialY;

    for(i = 0; i < sizeX; i++)
    {
        for(j = 0; j < sizeY; j++)
        {
            matrixClassified[i][j] = mat[i][j].valor;
        }
    }

    printf("\nMétodo define distância\n");

    for(i = 0; i < sizeY; i++)
    {
        l = k;
        /* loop that traverses an entire column */
        for(j = 0; j < sizeX; j++)
        {
            /* each condition checks an array direction so that the entire array is sorted at once */
            if (matrixClassified[initialPos.x + j][initialPos.y + i] == 0 && (initialPos.x + j < sizeX) && (initialPos.y + i < sizeY))
            {
                matrixClassified[initialPos.x + j][initialPos.y + i] = l;
            }


            if (matrixClassified[initialPos.x - j][initialPos.y - i] == 0 && (initialPos.x - j >= 0)    && (initialPos.y - i >= 0))
            {
                matrixClassified[initialPos.x - j][initialPos.y - i] = l;
            }


            if (matrixClassified[initialPos.x + j][initialPos.y - i] == 0 && (initialPos.x + j < sizeX) && (initialPos.y - i >= 0))
            {
                matrixClassified[initialPos.x + j][initialPos.y - i] = l;
            }

            
            if (matrixClassified[initialPos.x - j][initialPos.y + i] == 0 && (initialPos.x - j >= 0)    && (initialPos.y + i < sizeY))
            {
                matrixClassified[initialPos.x - j][initialPos.y + i] = l;
            }
            l++;
        }
        k++;
    }

    if(escolha == 1)
    {
        printf("\nClassificação a partir do início.\n");
        printf("Matriz não classificada\n");
        for(i = 0; i < sizeX; i++)
        {
            printf("%02d:\t", i);
            for(j = 0; j < sizeY; j++)
            {
                printf("%02d ", mat[i][j].valor);
                mat[i][j].distancia_inicio = matrixClassified[i][j];
            }
            printf("\n");
        }

        printf("\nMatriz classificada\n");
        for(i = 0; i < sizeX; i++)
        {
            printf("%02d:\t", i);
            for(j = 0; j < sizeY; j++)
            {
                printf("%02d ", mat[i][j].distancia_inicio);
            }
            printf("\n");
        }
    } else if (escolha == 2){

        printf("\nClassificação a partir do final\n");
        printf("Matriz não classificada\n");
        for(i = 0; i < sizeX; i++)
        {
            printf("%02d:\t", i);
            for(j = 0; j < sizeY; j++)
            {
                printf("%02d ", mat[i][j].valor);
                mat[i][j].distancia_final = matrixClassified[i][j];
            }
            printf("\n");
        }

        printf("\nMatriz classificada\n");
        for(i = 0; i < sizeX; i++)
        {
            printf("%02d:\t", i);
            for(j = 0; j < sizeY; j++)
            {
                printf("%02d ", mat[i][j].distancia_final);
            }
            printf("\n");
        }

    }

    printf("\nFim do metodo classificação.\n");

}


void calculaPeso(regMat** mat, int sizeX, int sizeY)
{
    int i, j;

    printf("\nMétodo calcula peso.\n");

    for(i = 0; i < sizeX; i++)
    {
        for(j = 0; j < sizeY; j++)
        {
            if(mat[i][j].distancia_final > 0 && mat[i][j].distancia_inicio > 0)
            {
                mat[i][j].peso = mat[i][j].distancia_final + mat[i][j].distancia_inicio;
            } else{
                mat[i][j].peso = mat[i][j].valor;
            }
        }
    }

    printf("\nFim do método calcula peso.\n");

}

void libera(regMat** mat, int sizeY)
{
    int i;

    for(i = 0; i < sizeY; i++)
    {
        free(*(mat + i));
    }

    free(mat);
}