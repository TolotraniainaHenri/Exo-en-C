#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()                                   // sprintf : ecrire dans une chaine
{
    char chaine[100];
    int age = 25;
    sprintf(chaine, " Tu a %d ans !", age); // On ecrit tu a 15 ans dans une chaine
    printf("%s", chaine);                   // On affiche chaine pour verifier qu' elle contient bien cela
    return 0;
}



/*                                                  strcmp:comparer 2 chaines
int strcmp(const char *chaine1, const char *chaine2);
int main()
{
    char chaine1[] = "texte de test", chaine2[] = "texte de test";

    if (strcmp(chaine1, chaine2) == 0)
    {
        printf("Les chaine sont identiques\n");
    }
    else
    {
        printf("Les chaine sont differentes \n");
    }
    return 0;
}


/*                                              strcat: concantener 2 chaines
char *strcat(char *chaine1, const char *chaine2);
int main()
{
    char chaine1[100] = "salut", chaine2[] = "Henri";
    strcat(chaine1, chaine2); // On concatene chaine2 dans chaine1
    printf("chaine1 vaut %s \n", chaine1);
    printf("chaine2 vaut %s \n", chaine2);
    return 0;
}



/*                                                strcpy : copie une chaine dans une autre
char *strcpy(char *copieDelaChaine, const char *chaineACopie);
int main()
{
    char chaine[] = "TEXTE", copie[100] = {0};
    strcpy(copie, chaine);
    printf("chaine vaut : %s \n", chaine);
    printf("copie vaut : %s \n", copie);

    return 0;
}


/*                                                 calcul longeur d'une chaime avec fonction
int longeur_chaine(const char *chaine);
int main()
{
    char prenom[100];
    int longeur = 0;
    printf("Comment t'appelles-tu petit zero ?");
    scanf("%s", prenom);
    printf("Salut %s,je suis hereux de te reconter !\n", prenom);
    longeur = longeur_chaine(prenom);
    printf("La chaine %s fait %d caracteres de long", prenom, longeur);
    return 0;
}
int longeur_chaine(const char *chaine)
{
    int nbrCaracteres = 0;
    char caractereActuel = 0;
    do
    {
        caractereActuel = chaine[nbrCaracteres];
        nbrCaracteres++;
    } while (caractereActuel != 0);
    nbrCaracteres--;
    return (nbrCaracteres);
}


//                                             strlen : calculer la longeur d'une chaime
/*size_t strlen(const char *chain);
int main()
{
    char prenom[100];
    int longeur_chaine = 0;
    printf("Comment t'appelles-tu petit zero ?");
    scanf("%s", prenom);
    printf("Salut %s,je suis hereux de te reconter !\n", prenom);
    longeur_chaine = strlen(prenom);
    printf("La chaine %s fait %d caracteres de long", prenom, longeur_chaine);
    return 0;
}
*/