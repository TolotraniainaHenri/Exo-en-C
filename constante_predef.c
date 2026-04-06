#include <stdio.h>
int main()
{
    printf("Erreur de la linge %d du fichier %s \n ", __LINE__, __FILE__);
    printf("Ce fichier a ete compile le %s a %s \n", __DATE__, __TIME__);
    return 0;
}