#include <stdio.h>
#include <stdlib.h>
#include "fonctions_TP3.h"



void ecriture(int tab[], int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        printf("%d ", tab[i]);
    }
    printf("\n");
}

int est_premier(int n)
{
    int c;

    if ((n == 0) || (n == 1))
        return 0;
    if (n == 2)
        return 1;
    for (c = 2; c < n; c = c + 1)
    {
        if (n%c == 0)
            return 0;
    }

    return 1;
}

void nombres_premiers(int premiers[], int n)
{
    int m, i, test;
    m = 0;

    for(i = 2; m < n; i++)
    {
        test = est_premier(i);
        if(test == 1)
        {
            premiers[m] = i;
            m = m + 1;
        }
    }
}
int main()
{

    int n;

    printf("Entrez 'n' un entier superieur ou egal a 1.\n");
    do
    {
        scanf("%d", &n);
    }
    while(n < 1);

    int premiers[n];
    nombres_premiers(premiers, n);

    if(n == 1)
        printf("Le premier nombre premier est :\n");
    else
        printf("Les %d premiers nombres premiers sont :\n", n);
    ecriture(premiers, n);


    return 0;
}
