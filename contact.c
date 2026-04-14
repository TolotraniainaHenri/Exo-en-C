#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAILLE 1000
void ecriture(FILE *f);
void lire(FILE *f);
void cherche_Num(FILE *f);
int main()
{
    FILE *fichier;
    ecriture(fichier);
    lire(fichier);
    cherche_Num(fichier);
    return 0;
}
void ecriture(FILE *f)
{
    char nom[TAILLE], prenom[TAILLE], tel[TAILLE], genre[TAILLE];
    f = fopen("C:\\Doc Projet\\FICHIER\\contact.csv", "w");
    if (f == NULL)
    {
        printf("Erreur d'ouverture!");
        exit(1);
    }
    else
    {
        fprintf(f, "Nom;Prenom;Tel;Genre \n");
        for (int i = 1; i <= 2; i++)
        {
            printf(" Nom Prenom Tel  Genre: \n");
            fgets(nom, sizeof(nom), stdin);
            fgets(prenom, sizeof(prenom), stdin);
            fgets(tel, sizeof(tel), stdin);
            fgets(genre, sizeof(genre), stdin);
            // Supprimer les \n
            nom[strcspn(nom, "\n")] = 0;
            prenom[strcspn(prenom, "\n")] = 0;
            tel[strcspn(tel, "\n")] = 0;
            genre[strcspn(genre, "\n")] = 0;

            // Ecriture dans le fichier
            fprintf(f, "%s;%s;%s;%s\n", nom, prenom, tel, genre);
        }
        printf("-----------Contact enregistre !--------------------\n");
    }
    fclose(f);
}
void lire(FILE *f)
{
    char ligne[TAILLE] = "";
    f = fopen("C:\\Doc Projet\\FICHIER\\contact.csv", "r");
    if (f != NULL)
    {
        printf("---------------Voici le contenue de fichier-----------------------\n");
        while (feof(f) == 0)
        {
            fgets(ligne, TAILLE, f);
            printf("%s", ligne);
        }
        fclose(f);
    }
}
void cherche_Num(FILE *f)
{
    char chaine[TAILLE];
    char ligne[TAILLE] = "";
    char *s1, *s2, *s3, *s4;
    f = fopen("C:\\Doc Projet\\FICHIER\\contact.csv", "r");
    printf("----------------------Chercher un Num de Tel-----------------------\n");
    printf("Entrer votre Nom : \n");
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
                printf("Le num de %s est %s", s1, s3);
            }
        }
        fclose(f);
    }
}
