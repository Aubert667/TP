#include <stdio.h>
#include <stdlib.h>

#include "fonctions_TP3.h"



void ecriture(int tab[], int n)
{
    int i;

    for(i == 0; i < n; i++)
    {
        printf("%d",tab[i]);
    }
    printf("\n");
}

void lecture(int tab[], int n)
{
    int c;

    for(i = 0; i<n; i++)
    {
        printf("tab[%d] : ", c+1);
        scanf("%d",&tab[c]);
    }
}
int main()
{

    int n;

    printf("Entrer 'n' taille du tableau : \n");
    scanf("%d",&n);


    int tab[n];

    lecture(tab,n);
    ecriture(tab,n);

    return 0;
}
