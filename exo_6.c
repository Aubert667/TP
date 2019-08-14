// FILE: eratos.c
/* ROLE:
Remplissage du tableau des n premiers nombres

*/

#include <stdio.h>
#include <stdlib.h>
#include "fonctions_TP3.h"


void RemplirEratos(BOOLEAN premier[], int n)
{
    int i;
    int j;

    // 0 et 1 ne sont pas premiers
    premier[0] = premier[1] = FALSE;

    // definir toutes les autres positions à TRUE

    for(i = 2; i<n; i++)
        premier[i] = TRUE;
    for(i = 2; i*i < n; i++)
    {
        for(j=2; i*j < n; j++)
        {
            premier[i*j] = FALSE;
        }
    }
}


void AfficherEratos(BOOLEAN premier[], int n)
{
    int i;
    int j;

    for(i = 0; i < n; i++)
    {
        printf("\t %d",i);

        if(!(++j % 5))
        {
            printf("\n");
            j = 0;
        }
    }
}



int main(void)
{

    const int MAX_SIZE = 100;
    int n;
    BOOLEAN premier[MAX_SIZE];

    printf("Entrer un nombre premier inferieur a 100 \n");
    scanf("%d",&n);

    if(n > MAX_SIZE)
    {
        printf("Desole la valeur entree depasse la capacite qui vaut %d ", MAX_SIZE);
        return(EXIT_FAILURE);
    }
    RemplirEratos(premier,MAX_SIZE);
    AfficherEratos(premier,n);


    return EXIT_SUCCESS;
}
