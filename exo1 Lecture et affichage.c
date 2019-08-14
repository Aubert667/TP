#include <stdio.h>

void lecture(int tab[], int n)
{
    int c;

    for (c = 0; c < n; c++)
    {
        printf("%d ", tab[c]);
    }
    printf("\n");
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
    int n;

    printf("Entrez 'n' taille du tableau.\n");
    scanf("%d", &n);

    int tab[n];

    ecriture(tab, n);
    lecture(tab, n);

    return 0;
}
