#include <stdio.h>
#include <stdlib.h>
void dimmension(char X, int *pointeur_x, int *pointeur_y);
int **entrer(char X, int a, int b);
int **somme(int **X, int **Y, int a, int b);
void resultat(int **X, int a, int b);
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
void dimmension(char X, int *pointeur_x, int *pointeur_y)
{
    printf("Entrer la ligne et col de matrice %c :\n", X);
    scanf("%d %d", pointeur_x, pointeur_y);
}

int **entrer(char X, int x, int y)
{
    int **tab = malloc(x * sizeof(int *));
    printf("Entrer la matice %c : \n", X);
    for (int i = 0; i < x; i++)
    {
        tab[i] = malloc(x * sizeof(int));
        for (int j = 0; j < y; j++)
        {
            printf("%c[%d][%d]=", X, i, j);
            scanf("%d", &tab[i][j]);
        }
    }
    printf("Voici la matrice %c : \n", X);

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            printf("%d \t", tab[i][j]);
        }
        printf("\n");
    }
    return (tab);
}
int **somme(int **X, int **Y, int a, int b)
{
    int **S = malloc(a * sizeof(int *));
    for (int i = 0; i < a; i++)
    {
        S[i] = malloc(a * sizeof(int));
        for (int j = 0; j < b; j++)
        {
            S[i][j] = X[i][j] + Y[i][j];
        }
    }
    return (S);
}
void resultat(int **X, int x, int y)
{
    printf("Voici la somme de deux matrice :\n");
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            printf("%d \t", X[i][j]);
        }
        printf("\n");
    }
}