#include<stdio.h>
#include<stdlib.h>

int main()
{
 char c[3],b[3];
     c[0]='M';
     c[1]='I';
     c[2]='T';
     c[3]='\0';
    printf(" %s \n " ,c);
    b[0]=c[2];
    b[1]=c[1];
    b[2]=c[0];
    b[3]=c[3];
    printf(" Devient %s ",b);
    return 0;
}