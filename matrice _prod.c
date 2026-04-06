#include <stdio.h>
#include <stdlib.h>

int **remplir_matrice(char X, int x, int y)
{
    int **tab = malloc(x * sizeof(int *));
    printf("Entrer la matrice %c \n ", X);
    for (int i = 0; i < x; i++)
    {
        tab[i] = malloc(x * sizeof(int));
        for (int j = 0; j < y; j++)
        {
            printf("%c[%d][%d] =", X, i, j);
            scanf("%d", &tab[i][j]);
        }
    }
    printf(" Matrice %c :\n", X);
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            printf("%d\t", tab[i][j]);
        }
        printf("\n");
    }
    return (tab);
}
void dimmension(char X, int *pointeur_x, int *ponteur_y)
{
    int a, b;
    printf("Entrer la nbr de ligne et colone de matrice %c \n", X); // on modifie la valeur sur l'adresse
    scanf("%d %d", pointeur_x, ponteur_y);
}
int **produit_matrice(int **X, int **Y, int a, int b, int c, int d)
{
    int **P = malloc(a * sizeof(int *));
    for (int i = 0; i < a; i++)
    {
        P[i] = malloc(a * sizeof(int));
        for (int j = 0; j < d; j++)
        {
            P[i][j] = 0;
            for (int k = 0; k < b; k++)
            {
                P[i][j] += X[i][k] * Y[k][j];
            }
        }
    }

    return (P);
}
void afficher(int **X, int a, int d)
{
    printf(" Voici le  produit de marice  A * B : \n");
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < d; j++)
        {
            printf("%d\t", X[i][j]);
        }
        printf("\n");
    }
}
