#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i,j,n;
    float p[100],a[100],b[100],s[100];
    float x=0,c;
    printf ("Entrer la dimension n\n");
    scanf("%d",&n);
    printf("Entrer la 1er vecteur\n");
    for(i=0;i<n;i++)
    {
    scanf("%f",&a[i]);
    }
    printf("Entrer la 2er vecteur\n");
    for(j=0;j<n;j++)
      {
         scanf("%f",&b[j]);
      }
        for (i=0;i<n;i++)
        {
           c=a[i]*b[i];
           x=x+c;
        }
    printf("Produit scalaire de deux vecteur p= %f\n",x);
    printf("Somme de deux vecteur\n");
    for (i=0;i<n;i++)
    {
    s[i]=a[i]+b[i];
    printf("%f\n",s[i]);
    }
    return 0;
}