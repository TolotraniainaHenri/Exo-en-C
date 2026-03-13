#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int testpremier(int nbr);
int main()
 {
 int j=2,i,compte=0,tab[100];
      while (j<=1000)
      {
       if (testpremier(j)!=0)
          {
           compte=compte+1;
           tab[compte]=j;
          }
           j++;
      }
      for(i=1;i<=25;i++)
        {
          printf(" %d... %d \n",i,tab[i]);
        }
    return 0;
}
int testpremier(int nbr)
{
int i=2,r=sqrt(nbr),b=1;
while (i<=r)
    {
      if (nbr%i==0)
    { 
    b=0;
  return b ;
    }
      i++;
    }
   return b ;
 }