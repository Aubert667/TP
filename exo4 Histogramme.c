#include<stdio.h>

void histogramme(int note[], int n, int histo[], int h)
{
    int i, j;

    for(i = 0; i < h; i++)
    {
        histo[i] = 0;
        for(j = 0; j < n; j++)
        {
            if(note[j] == i)
            {
                histo[i] += 1;
            }
        }
    }
}

void lecture(int tab[], int n)
{
    int c;

    for(c = 0; c < n; c++)
    {
        printf("%d ", tab[c]);
    }
    printf("\n");
}

void ecriture(int tab[], int n, int seuil)
{
    int c;

    for(c = 0; c < n; c++)
    {
        do
        {
            printf(" element %d : ", c + 1);
            scanf("%d", &tab[c]);
        }
        while(tab[c] >= seuil);
    }
}

void affichage(int tab[], int n)
{
    int c, etoile;

    for(c = 0; c < n; c++)
    {
        printf("[%d] : ", c);
        for (etoile = 0; etoile < tab[c]; etoile++)
            printf("*");
        printf("\n");
    }
}

int main()
{
    int c, n;
    const int capacite = 21;
    int histo[capacite];

    printf("Entrez 'n' nombre de notes.\n");
    scanf("%d", &n);
    printf("\n");

    int note[n];

    printf("Entrez les notes\n");
    ecriture(note, n, capacite);
    printf("\n");
    lecture(note, n);
    printf("\n");

    histogramme(note, n, histo, capacite);

    affichage(histo, capacite);

    return 0;
}
