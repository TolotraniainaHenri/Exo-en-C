#include<stdio.h>
#include<stdlib.h>

int main()
{ int n,i,j,u[100],s[100];
    printf("Entrer la valeur de n \n");
    scanf("%d",&n);
    u[0]=3 ;
    u[1]=-4;
    for(i=2;i<=n;i++)
    {
    u[i]= 2*u[i-1] + 3*u[i-2];
    }
    printf("Un= %d \n",u[n]);
    s[0]=u[0];
    for (j=1;j<=n;j++)
    {
    s[j]=u[j]+s[j-1];
    }
    printf("Somme de Un pour n=30 = %d",s[30]);
    return 0;
}