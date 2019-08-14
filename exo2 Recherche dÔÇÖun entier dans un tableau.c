#include<stdio.h>

int position(int tab[], int n, int x)
{
    int indice, c;
    indice = -1;

    for (c = 0; c < n; c++)
    {
        if (tab[c] == x)
            indice = c;
    }

    return indice;
}

void ecriture(int tab[], int n)
{
    int c;

    for (c = 0; c < n; c++)
    {
        printf(" element %d : ", c + 1);
        scanf("%d", &tab[c]);
    }
}

int main()
{
    int n, x;

    printf("Taille tableau: ");
    scanf("%d", &n);

    int tab[n];

    ecriture(tab, n);
    printf("Entrez entier: ");
    scanf("%d", &x);
    printf("%d\n", position(tab, n, x));

    return 0;
}
