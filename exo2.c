#include <stdio.h>
#include <stdlib.h>
#include "fonctions_TP3.h"





int Position(int tab[], int n, int x)
{
    int pos;
    int i;
    pos = -1;

    for(i = 0; i < n; i++)
    {
        if(tab[i] == x)
        {
            pos = i;
        }
    }
    return pos;
}



void Lecture(int tab[], int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        printf("tab[%d] : ",i);
        scanf("%d",&tab[i]);
    }

}



void Ecriture(int tab[], int n)
{
    int i;

    for(i = 0; i < n; i++)
    {
        printf("%d ",tab[i]);
    }
    printf("\n");
}



int main()
{


    int taille;
    int x;

    printf("Taille du tableau : ");
    scanf("%d",&taille);

    int tab[taille];

    Lecture(tab,taille);
    printf("Entrer entier ");
    scanf("%d", &x);
    printf("\n");
    printf(" Position =  %d",Position(tab,taille,x));




    return 0;

}
