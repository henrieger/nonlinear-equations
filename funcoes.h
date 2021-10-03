/*Henrique e Leon */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <matheval.h>

/*
Calcula a aproximação pelo método de Newton-Raphson.
*/
double newtonRaphson(void *f, double * x0Newton);

/*
Calcula a aproximação pelo método da Secante.
*/
double secante(void *f, double * x0Secante, double * x1Secante);

/*
Faz a iteração e chama as demais funções.
*/
void iteracao(void *f, double x0, double epsilon, int max_iter);