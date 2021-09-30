/*Henrique e Leon */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <matheval.h>

#define MAX 50

double newtonRaphson(void *f, double * x0Newton) {
    /* newton raphson */
}

double secante(void *f, double * x0Secante) {
    /* secante */
}

void iteracao(void *f, double x0, double epsilon, int max_iter) {
    int i = 0;
    int ulps;
    double newton_x, newton_crit, secante_x, secante_crit, ea, er;
    double x0Newton = x0;
    double x0Secante = x0;
    do
    {
        /* testar se já atingiu valor de parada também */
        /* Newton-Raphson */
        newton_x = newtonRaphson(f, &x0Newton);

        /* testar se já atingiu valor de parada também */
        /* Secante */ 
        if (i > 0) {
            secante_x = secante(f, &x0Secante);
        }
        /* Calcular newton_crit e secante_crit */
        /* Calcular EA e ER */
        /* Imprimir */

    } while ((i <= max_iter));
}

int main() {
    /* Atribuições e declarações */
    char funcao[MAX];
    double x0, epsilon;
    int max_iter;

    printf("Digite a função, x0, epsilon e o número máximo de iterações:\n");
    scanf("%s %lf %lf %d", funcao, &x0, &epsilon, &max_iter);

    /* Obtendo função */
    void *f = evaluator_create(funcao);

    /* Encontrando raíz da função */
    iteracao(f, x0, epsilon, max_iter);

    return 0;
}