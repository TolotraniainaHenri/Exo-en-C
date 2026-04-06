#include <stdio.h>
#include <stdlib.h>
#include "produit_scal.h"
int main()
{
    int *v1, *v2; // pointeur vers des entiers
    int v, dim;
    entrer(&v1, &v2, &dim);
    v = produit(v1, v2, dim);
    resultat(v);

    free(v1);
    free(v2);
    return 0;
}