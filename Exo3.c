#include <stdio.h>
#include <stdlib.h>
#include "fonctions_TP3.h"




void somme(int tab1[], int tab2[], int resultat[], int n)
{
    int i;

    for(i = 0; i < n; i++)
    {
        resultat[i] = tab1[i] + tab2[i];
    }

}
// Affichage des valeurs lues au clavier
void Ecriture(int tab[], int n)
{
    int i;

    for(i = 0; i < n; i++)
    {
        printf("%d ",tab[i]);
    }
    printf("\n");
}

// Lecture des valeurs lues au clavier
void Lecture(int tab[], int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        printf("tab[%d] : ", i);
        scanf("%d",&tab[i]);
    }


}


int main()
{

    int n;

    printf("Taille du tableau ");
    scanf("%d",&n);

    int tab1[n];
    int tab2[n];
    int resultat[n];



    printf("Valeurs de tableau 1 : \n");
    Lecture(tab1,n);
    printf("Valeurs de tableau 2 :\n ");
    Lecture(tab2,n);

    somme(tab1,tab2,resultat,n);
    printf("Affichage de la somme de deux tableaux\n\n\n");
    Ecriture(resultat,n);



    return EXIT_SUCCESS;
}
