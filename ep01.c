/*Henrique e Leon */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <matheval.h>

#define MAX 50

int main() {
    /* Atribuições e declarações */
    char funcao[MAX];
    double x0, epsilon;
    int max_iter;

    printf("Digite a função, x0, epsilon e o número máximo de iterações:\n");
    scanf("%s, %lf, %lf, %d", funcao, &x0, &epsilon, &max_iter);

    /* Obtendo função */
    void *f = evaluator_create(funcao);

    /* Tratando função */

    return 0;
}