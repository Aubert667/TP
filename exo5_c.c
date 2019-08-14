#include<stdio.h>
#include "fonctions_TP3.h"


void Ecriture(int tab[], int n)
{
    int i;

    for(i = 0; i < n; i++)
    {
        printf("%d ", tab[i]);
    }
    printf("\n");
}

/** On se sert du tableau construit. On sait que 2 est premier.
    Puis pour chaque case, on part de la case precedente, et on regarde les entiers suivants.
*/

void nombres_premiers(int premiers[], int n)
{
    int i = 2;
    int j;
    int a;
    int k;

    for (j = 0; j < n; j++ )
    {
        a = 1;
        for (k = 0; k < j; k++)
        {
            if( i%premiers[k] == 0)
            {
                a = 0;s
            }
        }
        if(a)
        {
            premiers[j] = i;
            j++;

        }
        i++;
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
    Ecriture(premiers, n);

    return 0;
}
