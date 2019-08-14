#include <stdio.h>
#include <stdlib.h>
#include "fonctions_TP3.h"



void histogramme(int note[], int n, int histo[], int h)
{
    int i;
    int j;


    for(i = 0; i<h; i++)
    {
        histo[i] = 0;

        for(j = 0; j < n; j++)
        {
            histo[i] += 1;
        }

    }
}

void Ecriture(int tab[], int n)
{
    int i;

    for(i = 0; i < n; i++)
    {
        printf("%d",tab[i]);
    }
    printf("\n");
}



void Lecture(int tab[], int n, int limite)
{
    int i;

    for(i = 0; i < n; i++)
    {
        do
        {
            printf("histo[%d] : ",i);
            scanf("%d",&tab[i]);

        }while(tab[i] >= limite);

    }


}
void affiche(int tab[], int n)
{
    int i;
    int j;


    for(i = 0; i < n; i++)
    {
        printf("hist[%d]",i);
        for(j= 0; j <tab[i]; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}
int main()
{

    int c = 0;
    int n = 0;
    const int taille = 21;
    int histo[taille];

    printf("Entrer 'n' nombre de notes. \n");
    scanf("%d",&n);
    printf("\n");

    int note[n];

    printf("Entrer les notes \n");
    Lecture(note,n,taille);
    printf("\n");
    Ecriture(note,n);
    printf("\n");
    histogramme(note,n,histo,taille);
    affiche(histo,taille);


    return 0;

}
