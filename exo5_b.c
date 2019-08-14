#include <stdio.h>
#include <stdlib.h>
#include "fonctions_TP3.h"



void lecture(int tab[], int n)
{
    int c;

    for(c = 0; c < n; c++)
    {
        printf("%d ", tab[c]);
    }
    printf("\n");
}

/** Pour chaque nombre, on regarde si il est premier.
    Si oui, on l'ajoute au tableau, et on change de case.
    Quand le tableau est plein on s'arrete.
*/
void nombres_premiers(int premiers[], int n)
{
    int i, i1, m, test;
    m = 0;

    for(i = 2; m < n; i++)
    {
        test = 0;
        for(i1 = 2; i1 < i; i1++)
        {
            if(i % i1 == 0)
                test = 1;
        }
        if(test == 0)
        {
            premiers[m] = i;
            m = m + 1;
        }
    }
}

int main()
{
    int n;

    printf("Entrez un entier supérieur ou egal a 1.\n");
    do
    {
        scanf("%d", &n);
    }
    while(n < 1);

    int premiers[n];
    nombres_premiers(premiers, n);
    lecture(premiers, n);



    return 0;
}
