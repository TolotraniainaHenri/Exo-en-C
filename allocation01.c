#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *memoireAlloue=NULL;
    memoireAlloue=malloc(sizeof(int));
    if(memoireAlloue==NULL) // on verifie si la memoire a ete louee
    {
         exit(0);// on arret tout!
    }
    printf("Entrer une entier \n");
    scanf("%d",memoireAlloue);
    printf(" memoir alloue = %d ",*memoireAlloue);
// on peut utiliser ici la memoir
free(memoireAlloue);// on n'a plus besoin de memoire on la libere   
}
