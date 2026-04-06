#include<stdio.h>
#include<stdlib.h>
int main()
{
    int nombreDAmis=0,i=0;
    int *ageAmis=NULL;
    printf(" Entrer le nombre d'amis\n");
    scanf("%d",&nombreDAmis);
    if (nombreDAmis>0)
    {
        ageAmis=malloc(sizeof(int)); // on alloue de memoire pour le tableau 
        if (ageAmis==NULL)
        {
            exit (0);      // si la memoir n'exite pas on arret tout!
        }
        for( i=0;i<nombreDAmis;i++)
        {
            printf(" amis num %d \n", i+1);
            scanf("%d",&ageAmis[i]);
        }
         for( i=0;i<nombreDAmis;i++)
        {
            printf(" amis num %d Age= %d \n",i,ageAmis[i]);
        }
        free(ageAmis);
    }
}