#include <stdio.h>
#include <stdlib.h>
void entrer(int *pointeurSur_a, int *pointeurSur_b);
int som(int a, int b);
void resultat(int s);
int main()
{
    int a, b, s;
    entrer(&a, &b);
    s = som(a, b);
    resultat(s);

    return 0;
}
void entrer(int *pointeurSur_a, int *pointeurSur_b)
{
    printf(" Entrer a et b \n");
    scanf("%d", pointeurSur_a); // car pointeurSur_a= &a donc pas de '&' devant
    scanf("%d", pointeurSur_b);
}
int som(int a, int b)
{
    return (a + b);
}
void resultat(int s)
{
    printf("a + b = %d ", s);
}
