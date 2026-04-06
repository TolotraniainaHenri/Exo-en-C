#include <stdio.h>
#include <stdlib.h>
void entrer(int **tab1, int **tab2, int *n) // tab1 = &v1 (tab1 contient l'adresse de v1
                                            //   *tab1 = malloc(..) hanova ny valeur ao anatin'pointeur v1 et v2
                                            // ny adresse tsy moiva
{
    int i, j;
    printf("Entrer la dimmension de vecteur \n");
    scanf("%d", n);

    *tab1 = malloc(*n * sizeof(int));
    *tab2 = malloc(*n * sizeof(int));

    if (*tab1 == NULL || *tab2 == NULL)
    {
        exit(1);
    }
    printf("Entrer la 1er vecteur \n");
    fflush(stdout); // forcer l'affichage
    for (i = 0; i < *n; i++)
    {
        printf(" v1 %d=\n ", i);
        scanf("%d", &(*tab1)[i]);
        fflush(stdout);
    }
    printf("Entrer la 2em vecteur \n");
    fflush(stdout); // forcer l'affichage
    for (i = 0; i < *n; i++)
    {
        printf(" v2 %d=\n", i);
        scanf("%d", &(*tab2)[i]);
        fflush(stdout); // forcer l'affichage
    }
}
int produit(int tab1[], int tab2[], int d)
{
    int i, S = 0;
    for (i = 0; i < d; i++)
    {
        S += tab1[i] + tab2[i];
    }
    return (S);
}
void resultat(int a)
{
    printf(" Produit scalaire de V1 et V2 est = %d\n ", a);
}
