#include <stdio.h>
#include <stdlib.h>
#include "matrice_som.h"
int main()
{
    int **A, **B, **S;
    int a, b, c, d;
    dimmension('A', &a, &b);
    dimmension('B', &c, &d);
    if (a == c && b == d)
    {
        A = entrer('A', a, b);
        B = entrer('B', a, b);
        S = somme(A, B, a, b);
        resultat(S, a, b);
    }
    else
    {
        printf("Impossible!,Il faut que la matrice est la meme dimmension\n");
    }
    return 0;
}