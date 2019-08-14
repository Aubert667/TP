#include <stdio.h>
#include <stdlib.h>


void Lecture(int tab[], int n)
{
    int c;

    for(c == 0; c < n; c++)
    {
        printf("%d",tab[c]);
    }
    printf("\n");
}

void ecriture(int tab[], int n)
{
    int c;

    for(c = 0; c<n; c++)
    {
        printf("tab[%d] : ", c+1);
        scanf("%d",&tab[c]);
    }
}
int main()
{

    int n;

    printf("Entrer 'n' taille du tableau : \n");
    scanf("%d",&n);


    int tab[n];

    ecriture(tab,n);
    Lecture(tab,n);

    return 0;
}
