#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "simpson1.h"
void subdivision(int *pointeur)
{
    printf("Entrer le nbr de subdivision \n");
    scanf("%d", pointeur);
}
double calcul(int d)
{
    double a = 0, b = 2;
    double delta, S = 0, K = 0, h;
    delta = (b - a) / d;
    printf(" deltat: %f\n", delta);
    float *X = malloc(d * sizeof(double));
    float *T = malloc(d * sizeof(double));
    X[0] = a;
    for (int i = 0; i < d; i++)
    {

        X[i + 1] = X[i] + delta;
    }
    for (int i = 0; i <= d; i++)
    {
        printf(" X[%d]: %f\n", i, X[i]);
    }
    for (int i = 1; i < d; i++)
    {
        if (i % 2 == 0)
        {
            S += f(X[i]);
        }
        else
        {
            K += f(X[i]);
        }
    }
    printf("Somme paire: %f\n", S);
    printf("Somme impaire: %f\n", K);
    return ((delta / 3) * (f(X[0]) + 4 * K + 2 * S + f(X[d])));
}
double f(double X)
{
    return (pow(X, 3) + 2 * X);
}
double valeur(double x)
{
    printf("INTEGRALE DE f(x)= x3 + 2X sur [0,2] par Methode de Simpson : %.2f\n", x);
}