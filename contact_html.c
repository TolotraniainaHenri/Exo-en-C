#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAILLE 1000
void lire();
void html();
int main()
{
    char buffer[20];
    int choix;

    while (1)
    {
        printf("\n===== MENU =====\n");
        printf("1. Lire\n");
        printf("2. Version HTML\n");
        printf("0. Quitter\n");
        printf("Votre Choix: ");

        fgets(buffer, sizeof(buffer), stdin);
        choix = atoi(buffer);

        switch (choix)
        {
        case 1:
            lire();
            break;
        case 2:
            html();
            break;
        case 0:
            printf("Fin du programme.\n");
            exit(0);
        default:
            printf("Choix invalide.\n");
        }
    }
    // pause avant retour menu
    printf("\n Appuyez sur Entree pour continuer.........");
    fgets(buffer, sizeof(buffer), stdin);
    return 0;
}
void lire()
{
    FILE *f = fopen("fichierINT.csv", "r");
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

void html()
{
    FILE *f = fopen("fichierINT.csv", "r");
    FILE *temp = fopen("temp.html", "w");
    char ligne[TAILLE];
    char nom[TAILLE], prenm[TAILLE], git[TAILLE], email[TAILLE];
    char nom_chercher[50], tel_nouveau[50];
    int compt = 0;
    int n;

    if (f == NULL || temp == NULL)
    {
        printf("Erreur ouverture fichier \n");
        exit(1);
    }
    else
    {
        printf("-------- Copie vers HTML--------\n");
        fprintf(temp, "<!DOCTYPE html>\n");
        fprintf(temp, "<html lang='en'>\n");
        fprintf(temp, "<head>\n");
        fprintf(temp, "<meta charset=' UTF - 8 '>\n");
        fprintf(temp, "<meta name= viewport ' content=' width = device - width, initial - scale = 1.0 '>\n");
        fprintf(temp, " <title>Document</title>\n");
        fprintf(temp, "<link rel='stylesheet' href='style.css'>");
        fprintf(temp, "</head><body>\n");
        fprintf(temp, "<div><p><strong>Liste des etudiants INT</strong></p>\n");
        fprintf(temp, "<table border='1' cellpadding='10' cellspacing ='1' style=' text-align: center'  >\n");
        while (fgets(ligne, sizeof(ligne), f))
        {
            sscanf(ligne, "%[^;];%[^;];%[^;];%[^\n]", nom, prenm, git, email); // lire  sans lire au clavier
            // la chaine sur ligne stock sur nom,prenom,..
            compt++;
            if (compt == 1)
            {
                fprintf(temp, "<thead>\n");
                fprintf(temp, " <tr><td>%s</td>;<td>%s</td>;<td>%s</td>;<td>%s</td></tr>\n", nom, prenm, git, email);
                fprintf(temp, " </thead>");
            }
            else
            {
                fprintf(temp, "<tbody>\n");
                fprintf(temp, " <tr><td>%s</td>;<td>%s</td>;<td>%s</td>;<td>%s</td></tr>\n", nom, prenm, git, email);
                fprintf(temp, " </tbody>");
            }
        }

        fprintf(temp, "</table></div></body></html>\n");

        fclose(f);
        fclose(temp);
        printf("--------------------------Copie terminer.------------------------------\n");
    }
}
