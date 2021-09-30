/*Henrique e Leon */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <matheval.h>

#define MAX 50

int main(int argc, char *argv[]) {
    /* Atribuições e declarações */
    double x0, epsilon;
    int max_iter;

    x0 = atof(argv[2]);
    epsilon = atof(argv[3]);
    max_iter = atoi(argv[4]);

    /* Obtendo função */
    void *f;
    f = evaluator_create(argv[1]);

    /* Tratando função */

    return 0;
}