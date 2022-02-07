#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "matriz.h"

/**
 * @author Pedro Braghin
 * @email
 */

int main(void)
{
    regMat** mat;
    regPos inicio, final;
    int i, j;

    setlocale(LC_ALL,"pt-BR.UTF-8");

    mat = (regMat**) malloc(SIZEX * sizeof(regMat*));
    if (mat == NULL)
    {
        fprintf(stderr, "Não foi possivel alocar memoria para o programa.\n");
        exit(1);
    }

    for (i = 0; i < SIZEY; i++)
    {
        mat[i] = (regMat*) malloc(SIZEY * sizeof(regMat));
        if (mat[i] == NULL)
        {
            fprintf(stderr, "Não foi possivel alocar memoria para o programa.\n");
            exit(1);
        }
    }

    for (i = 0; i < SIZEX; i++)
    {
        for (j = 0; j < SIZEY; j++)
        {
            mat[i][j].valor = 0;
            mat[i][j].distancia_final = 0;
            mat[i][j].distancia_inicio = 0;
            mat[i][j].peso = 0;
            mat[i][j].tipo = ' ';
        }
    }
    printf("\nMatriz criada\n");

    for (i = 0; i < SIZEX; i++)
    {
        for (j = 0; j < SIZEY; j++)
        {
            printf("%02d ", mat[i][j].valor);
        }
        printf("\n");
    }
    printf("\n");

    inicializandoMatriz(mat, SIZEX, SIZEY, &inicio, &final);
    defineDistancia(mat, SIZEX, SIZEY, inicio.x, inicio.y, 1);
    defineDistancia(mat, SIZEX, SIZEY, final.x, final.y, 2);
    calculaPeso(mat, SIZEX, SIZEY);

    printf("\nValores de identicação das célulcas.\n");
    for (i = 0; i < SIZEX; i++)
    {
        for(j = 0; j < SIZEY; j++)
        {
            printf("%02d ", mat[i][j].valor);
        }
        printf("\n");
    }
    

    printf("\nDistância de cada célula até o ponto de início.\n");
    for (i = 0; i < SIZEX; i++)
    {
        for (j = 0; j < SIZEY; j++)
        {
            printf("%02d ", mat[i][j].distancia_inicio);
        }
        printf("\n");
    }

    printf("\nDistância de cada célula até o ponto de saída.\n");
    for (i = 0; i < SIZEX; i++)
    {
        for (j = 0; j < SIZEY; j++)
        {
            printf("%02d ", mat[i][j].distancia_final);
        }
        printf("\n");
    }

    
    printf("\nPeso da célula(distância inicial + distância final)\n");
    for (i = 0; i < SIZEX; i++)
    {
        for (j = 0; j < SIZEY; j++)
        {
            printf("%02d ", mat[i][j].peso);
        }
        printf("\n");
    }
    printf("Fim da execução do programa\n");
    libera(mat, SIZEY);

    return 0;
}
