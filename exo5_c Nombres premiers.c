#include<stdio.h>

void lecture(int tab[], int n)
{
    int c;

    for(c = 0; c < n; c++)
    {
        printf("%d ", tab[c]);
    }
    printf("\n");
}


/** On se sert du tableau construit. On sait que 2 est premier.
    Puis pour chaque case, on part de la case precedente, et on regarde les entiers suivants.
     Tant qu'un entier du tableau le divise, on regarde le suivant.
     Des qu'on trouve un entier qui n'est pas divisible par ceux du tableau, il est premier :
     dans le tableau, il y a les premiers entiers, donc il ne peut pas etre divisible par un autre entier.
*/
void nombres_premiers(int premiers[], int n)
{
    int i = 2, j, a, k;

    for (j = 0; j < n; )
    {
        a = 1;
        for (k = 0; k < j; k++)
        {
            if(i%premiers[k] == 0)
                a = 0;
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
    lecture(premiers, n);

    return 0;
}
