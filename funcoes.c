/*Henrique e Leon */
#include "funcoes.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <matheval.h>
#include <string.h>

double newtonRaphson(void *f, double * x0Newton) {
    void *f_derivada;
    double funcao, funcao_derivada;
    f_derivada = evaluator_derivative_x(f);

    funcao = evaluator_evaluate_x(f, *x0Newton);
    funcao_derivada = evaluator_evaluate_x(f_derivada, *x0Newton);

    return *x0Newton - (funcao / funcao_derivada);
}

double secante(void *f, double * x0Secante, double * x1Secante) {
    double funcao0, funcao1;
    funcao1 = evaluator_evaluate_x(f, *x1Secante);
    funcao0 = evaluator_evaluate_x(f, *x0Secante);

    return *x1Secante - ((funcao1 * (*x1Secante - *x0Secante))/(funcao1 - funcao0));
}

/* Transforma um número double em int */
long long doubleToLongLong(double d)
{
    long long l;
    memcpy(&l, &d, sizeof(double));
    return l;
}

void iteracao(void *f, double x0, double epsilon, int max_iter) {
    int i = 0;
    int ulps;
    double newton_x, newton_crit, secante_x, secante_crit, ea, er;
    double x0Newton = x0;
    double x0Secante, x1Secante;
    x0Secante = x0;
    do
    {

        /* Newton-Raphson */
        /* testar se já atingiu valor de parada também */
        newton_x = newtonRaphson(f, &x0Newton);

        /* Secante */ 
        /* testar se já atingiu valor de parada também */
        if (i > 0) {
            secante_x = secante(f, &x0Secante, &x1Secante);
        }
        else {
            x1Secante = newton_x;
            secante_x = x0Secante;
        }

        /* Calcular newton_crit e secante_crit */
        /* Calcular EA e ER */
        ea = fabs(secante_x - newton_x);
        er = ea/secante_x;
        ulps = abs(doubleToLongLong(secante_x) - doubleToLongLong(newton_x));

        /* Imprimir */
        printf("%d,%1.16e,%1.16e,%1.16e,%1.16e,%d\n", i, newton_x, secante_x, ea, er, ulps);

        /* Atribuindo valores para próximas iterações */
        x0Newton = newton_x;
        if (i > 0) {
            x0Secante = x1Secante;
            x1Secante = secante_x;
        }
        
        i++;

    } while ((i <= max_iter));
}