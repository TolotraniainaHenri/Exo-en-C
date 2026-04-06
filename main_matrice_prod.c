#include <stdio.h>
#include <stdlib.h>
#include "matrice_prod.h"
int main()
{
    int a, b, c, d;
    int **A, **B, **P;
    dimmension('A', &a, &b); // on envoie l'adresse de a , b sur la fonct dimm
    dimmension('B', &c, &d);
    if (b == c)
    {
        A = remplir_matrice('A', a, b);
        B = remplir_matrice('B', c, d);
        P = produit_matrice(A, B, a, b, c, d);
        afficher(P, a, d);
    }
    else
    {
        printf("Impossible! il faut que dim col A = dim col B \n");
    }
}