#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double f(double X);
void subdivision(int *pointeur);
double calcul(int d);
double valeur(double x);
int main() // Methode du point mulieu
{
    int n;
    double x, y;
    f(x);
    subdivision(&n);
    y = calcul(n);
    valeur(y);

    return 0;
}
void subdivision(int *pointeur)
{
    printf("Entrer le nbr de subdivision \n");
    scanf("%d", pointeur);
}
double calcul(int d)
{
    double a = 0, b = 2;
    double delta, S = 0;
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
    for (int i = 0; i < d; i++)
    {
        T[i] = X[i] + (delta / 2);
        printf(" T[%d] : %f\n", i, T[i]);
    }
    for (int i = 0; i < d; i++)
    {
        S += f(T[i]);
    }
    printf("Somme: %f\n", S);

    return (S * delta);
}
double f(double X)
{
    return (pow(X, 3) + 2 * X);
}
double valeur(double x)
{
    printf("INTEGRALE DE f(x)= x3 + 2X sur [0,2] par Methode du point Milieu : %.2f\n", x);
}