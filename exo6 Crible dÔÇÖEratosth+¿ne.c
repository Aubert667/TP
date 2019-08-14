#include<stdio.h>
#include <math.h>

void lecture(int tab[], int n)
{
    int c;

    for(c = 0; c < n; c++)
    {
        if (tab[c] == 1)
            printf("%d ", c);
    }
    printf("\n");
}

void crible_eratosthene(int tableau[], int n)
{
    int i, j;

    for (i = 0; i < n; i++)
        tableau[i] = 1;

    tableau[0]=0;
    tableau[1]=0;
    for (i = 2; i < sqrt(n); i++)
    {
        if(tableau[i] == 1)
        {
            for(j = i + i; j < n; j = j+i)
                tableau[j] = 0;
        }
    }
}

int main()
{
    int n;

    printf("Saisissez un entier supérieur a 1\n");
    do
    {
        scanf("%d", &n);
    }
    while(n < 1);

    int premier[n];

    crible_eratosthene(premier, n);
    lecture(premier, n);

    return 0;
}

