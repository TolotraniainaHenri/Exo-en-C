#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define Pi 3.14
#define TAILLE 1000
void ecriture(FILE *f);
void lire(FILE *f);
void recherche(FILE *f);
int main()
{
    FILE *fichier;
    ecriture(fichier);
    lire(fichier);
    recherche(fichier);
    return 0;
}
void ecriture(FILE *f)
{
    float x;
    f = fopen("C:\\Doc Projet\\FICHIER\\teste.csv", "w");
    if (f == NULL)
    {
        printf("Erreur d'ouverture!");
        exit(1);
    }
    else
    {
        fprintf(f, "Voici la Table trigo\n");
        for (int i = 0; i <= 360; i++)
        {
            x = i * Pi / 180;
            fprintf(f, "%d;sin(%d)=;%.3f;cos(%d)=;%.3f\n", i, i, sin(x), i, cos(i));
        }
    }

    fclose(f);
}
void lire(FILE *f)
{
    char ligne[TAILLE] = "";
    f = fopen("C:\\Doc Projet\\FICHIER\\teste.csv", "r");
    if (f != NULL)
    {
        while (feof(f) == 0)
        {
            fgets(ligne, TAILLE, f);
            printf("%s", ligne);
        }
        fclose(f);
    }
}
void recherche(FILE *f)
{
    char chaine[TAILLE];
    char ligne[TAILLE] = "";
    char *s1, *s2, *s3, *s4;
    f = fopen("C:\\Doc Projet\\FICHIER\\teste.csv", "r");
    printf("Chercher un ligne : \n");
    scanf("%s", &chaine);
    if (f != NULL)
    {
        while (feof(f) == 0)
        {
            fgets(ligne, TAILLE, f);
            s1 = strtok(ligne, ";");
            s2 = strtok(NULL, ";");
            s3 = strtok(NULL, ";");
            s4 = strtok(NULL, ";");
            if (strcmp(s1, chaine) == 0)
            {
                printf("%s;%s;%s;%s", s1, s2, s3, s4);
            }
        }
        fclose(f);
    }
}
