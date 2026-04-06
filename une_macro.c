#include <stdio.h>
#include <stdlib.h>
#define MAJEUR(age, nom)                     \
    if (age >= 18)                           \
        printf("Vous etes majeurs %s", nom); \
    else                                     \
        printf("Vous etes mineur");
int main()
{
    MAJEUR(12, "Kotobe");
    return 0;
}
/*
#define COUCOU()                      \
    printf("coucou \n");              \
    printf("je m'apppelle Henri\n "); \
    printf("J'aime langage C ");      \
    printf("Okey");
int main()
{
    COUCOU(); // tsy mety rehefa tsy misy point virgule
    return 0;
}
    */