#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <sys/resource.h>
#define NUM_POINTS 3
#define NUM_COMMANDS 2

typedef struct Ponto{
    float x;
    float y;
}Ponto;

Ponto *pontos;
int num_pontos, Maior;// Número de pontos e maior conjunto de pontos
float A, B;

float Coeficiente_Reta(float x2, float y2, float x1, float y1);
float Resolve_coef(Ponto points[4]);
void selectionSort(Ponto *arr, int n);
void Solucao();
int Busca_Maior(int *cauda);
int Interceptacao(float coef_a, float coef_b, float xa, float ya, float xb, float yb);
int File(int argc, char **argv, char *input, char *output);
void Leitura_input(char *input);
int plot();

#endif