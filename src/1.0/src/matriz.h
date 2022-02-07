#ifndef MATRIZ_H_INCLUDED
#define MATRIZ_H_INCLUDED

#define SIZEX 20
#define SIZEY 20

typedef struct mat{
    int distancia_final;
    int distancia_inicio;
    int peso;
    int valor;
    char tipo;
} regMat;

typedef struct pos{
    int x;
    int y;
} regPos;

void inicializandoMatriz(regMat** mat, int sizeX, int sizeY, regPos* inicio, regPos* final);
void defineDistancia(regMat** mat, int sizeX, int sizeY, int initialX, int initialY, int escolha);
void calculaPeso(regMat** mat, int sizeX, int sizeY);
void libera(regMat** mat, int sizeY);

#endif