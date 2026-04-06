#include <stdio.h>
#include <stdlib.h>
void entrer(int **tab1, int **tab2, int *dim);
void somme(int a[], int b[], int **tab, int dim);
void resultat(int s[], int d);
int main()
{
    int *v1, *v2, *s;
    int dim;
    entrer(&v1, &v2, &dim);
    somme(v1, v2, &s, dim);
    resultat(s, dim);
    free(v1);
    free(v2);
    return 0;
}
void entrer(int **tab1, int **tab2, int *dim)
{
    int i, j;
    printf("Entrer la dimension \n");
    scanf("%d", dim);
    *tab1 = malloc(*dim * sizeof(int));
    *tab2 = malloc(*dim * sizeof(int));

    if (*tab1 == NULL || *tab2 == NULL)
    {
        exit(1);
    }
    printf("Entrer la 1er vect \n");
    fflush(stdout);
    for (i = 0; i < *dim; i++)
    {
        printf(" v1 %d =", i);
        scanf("%d", &(*tab1)[i]);
        fflush(stdout);
    }
    printf("Entrer la 2em vect \n");
    fflush(stdout);
    for (j = 0; j < *dim; j++)
    {
        printf(" v2 %d= ", j);
        scanf("%d", &(*tab2)[j]);
        fflush(stdout);
    }
}
void somme(int a[], int b[], int **tab, int dim)
{
    int i;
    *tab = malloc(dim * sizeof(int));

    if (*tab == NULL)
    {
        exit(1);
    }
    for (i = 0; i < dim; i++)
    {
        (*tab)[i] = a[i] + b[i];
    }
}
void resultat(int t[], int d)
{
    printf("La somme de v1 et V2 \n");
    fflush(stdout);
    for (int i = 0; i < d; i++)
    {
        printf(" %d \n", t[i]);
    }
}
