#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAILLE 1000
void ecriture();
void lire();
void chercher_Num();
void modifier_Num();
int main()
{

    char buffer[20];
    int choix;

    while (1)
    {
        printf("\n===== MENU =====\n");
        printf("1. Ajouter\n");
        printf("2. Lire\n");
        printf("3. Chercher\n");
        printf("4. Modifier\n");
        printf("0. Quitter\n");
        printf("Votre Choix: ");

        fgets(buffer, sizeof(buffer), stdin);
        choix = atoi(buffer);

        switch (choix)
        {
        case 1:
            ecriture();
            break;

        case 2:
            lire();
            break;

        case 3:
            chercher_Num();
            break;

        case 4:
            modifier_Num();
            break;

        case 0:
            printf("Fin du programme.\n");
            exit(0);

        default:
            printf("Choix invalide.\n");
        }
        // pause avant retour menu
        printf("\n Appuyez sur Entree pour continuer.........");
        fgets(buffer, sizeof(buffer), stdin);
    }
    return 0;
}
void ecriture()
{
    FILE *f = fopen("contact.csv", "w");
    char nom[TAILLE], prenom[TAILLE], tel[TAILLE], genre[TAILLE];
    char buffer[20];
    int choix;

    if (f == NULL)
    {
        printf("Erreur d'ouverture!");
        exit(1);
    }
    else
    {
        fprintf(f, "Nom;Prenom;Tel;Genre \n");
        printf("Entrer le nombre de personne que vous voulez enregistrer:\n");
        fgets(buffer, sizeof(buffer), stdin);
        choix = atoi(buffer); // Transforme une chaine de caracteres en nombre entier;
        for (int i = 1; i <= choix; i++)
        {
            printf(" Nom Prenom Tel  Genre: \n");
            fgets(nom, sizeof(nom), stdin);
            fgets(prenom, sizeof(prenom), stdin);
            fgets(tel, sizeof(tel), stdin);
            fgets(genre, sizeof(genre), stdin);
            // Supprimer les \n
            nom[strcspn(nom, "\n")] = '\0';
            prenom[strcspn(prenom, "\n")] = '\0';
            tel[strcspn(tel, "\n")] = '\0';
            genre[strcspn(genre, "\n")] = '\0';

            // Ecriture dans le fichier
            fprintf(f, "%s;%s;%s;%s\n", nom, prenom, tel, genre);
        }
        printf("-----------Contact enregistre !--------------------\n");
    }
    fclose(f);
}
void lire()
{
    FILE *f = fopen("contact.csv", "r");
    char ligne[TAILLE] = "";
    if (f != NULL)
    {
        printf("---------------Voici le contenue de fichier-----------------------\n");
        while (fgets(ligne, TAILLE, f))
        {
            printf("%s", ligne);
        }
        fclose(f);
    }
}
void chercher_Num()
{
    FILE *f = fopen("contact.csv", "r");
    char chaine[TAILLE];
    char ligne[TAILLE] = "";
    char *s1, *s2, *s3, *s4;
    printf("----------------------Chercher un Num de Tel-----------------------\n");
    printf("Entrer votre Nom : \n");
    scanf("%s", &chaine);
    if (f != NULL)
    {
        while (fgets(ligne, TAILLE, f))
        {
            s1 = strtok(ligne, ";");
            s2 = strtok(NULL, ";");
            s3 = strtok(NULL, ";");
            s4 = strtok(NULL, ";");
            if (strcmp(s1, chaine) == 0)
            {
                printf("Le num de %s est %s \n", s1, s3);
            }
        }
        fclose(f);
    }
}
void modifier_Num()
{
    FILE *f = fopen("contact.csv", "r");
    FILE *temp = fopen("temp.csv", "w");
    char ligne[TAILLE];
    char nom[TAILLE], prenm[TAILLE], tel[TAILLE], genre[TAILLE];
    char nom_chercher[50], tel_nouveau[50];
    int n;

    if (f == NULL || temp == NULL)
    {
        printf("Erreur ouverture fichier \n");
        exit(1);
    }
    else
    {
        printf("------------------------Modifier un num de Tel---------------------------\n");
        printf("Entrer votre nom: \n");
        fgets(nom_chercher, sizeof(nom_chercher), stdin);
        printf("Entrer le nouveau num : \n");
        fgets(tel_nouveau, sizeof(tel_nouveau), stdin);
        while (fgets(ligne, sizeof(ligne), f))
        {
            if (strstr(ligne, "Nom") != NULL)
            {
                fputs(ligne, temp); // On copie la ligne SANS MODIFICATION
                continue;
            }
            sscanf(ligne, "%[^;];%[^;];%[^;];%[^\n]", nom, prenm, tel, genre); // lire  sans lire au clavier
            // la chaine sur ligne stock sur nom,prenom,..
            if (strcmp(nom_chercher, nom) == 0)
            {
                fprintf(temp, "%s;%s;%s;%s\n", nom, prenm, tel_nouveau, genre);
            }
            else
            {
                fprintf(temp, "%s;%s;%s;%s\n", nom, prenm, tel, genre);
            }
        }
        fclose(f);
        fclose(temp);
        remove("contact.csv");             // Supprimer un fichier
        rename("temp.csv", "contact.csv"); // rename(Nouveau,Ancien)
        printf("--------------------------Modification terminer.------------------------------\n");
    }
}
