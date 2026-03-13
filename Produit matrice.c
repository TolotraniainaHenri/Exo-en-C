#include<stdio.h>
#include<stdlib.h>

int main()
{
int i,j,k,l1,c1,l2,c2;
printf("Entrer la nombre de ligne et col de Mat1 \n");
scanf("%d",&l1);
scanf("%d",&c1);
printf("Entrer la nombre de ligne et col de Mat2 \n");
scanf("%d",&l2);
scanf("%d",&c2);
int m1[l1][c1],m2[l2][c2],Somme=0,s[100][100];
if(c1==l2)
{
  printf("Entrer la valeur de la Mat1\n");
   for (i=0;i<l1;i++)
   {
     for (j=0;j<c1;j++)
       {
         printf("m1[%d][%d]=",i,j);
         scanf("%d",&m1[i][j]);
       }
    }
   for (i=0;i<l2;i++)
   {
      for (j=0;j<c2;j++)
      {
        printf("m2[%d][%d]=",i,j);
       scanf("%d",&m2[i][j]);
      }
    }
for (i=0;i<l1;i++)
{
 for (j=0;j<c1;j++)
    {  
      for (k=0;k<l2;j++)
        {
          Somme+=m1[i][k]*m2[k][j];
        }
  s[i][j]=Somme;
    }
 }
printf("Produit de deux Matrice \n");
for(i=0;i<l1;i++)
   {
    for (j=0;j<c2;j++)
    {
    printf(" %d\t",s[i][j]);
    }
    printf("\n");
   }
  }
  else
  {
  printf("Il faut que nbr de col m1 égal à ligne de m2");
  }
   return(0);
 }
   
   
    