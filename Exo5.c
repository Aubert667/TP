#include <stdio.h>
#include <stdlib.h>




void Ecriture(int tab[], int n);
int EstPremier(int n);
void nombrePremier(int premier[], int n);


// Write
void Ecriture(int tab[], int n)
{
    int i;

    for(i = 0; i < n; i++)
    {
        printf("%d",tab[i]);
    }
    printf("\n\n");
}

int EstPremier(int n)
{
    int i;

    if((n==0) ||(n==1))
        return 0;
    if(n == 2)
        return 1;
    for(i = 2; i<n; i++)
    {
        if(n%i == 0)
           return 0;
    }

    return 1;

}

void nombrePremier(int premier[], int n)
{
    int deb;
    int i;
    int test;
    deb = 0;

    for(i = 2; deb < n; i++)
    {
        test = EstPremier(i);

        if(test == 1)
        {
            premier[deb] = i;
            deb = deb + 1;
        }
    }

}

int main()
{
    int n;
    printf("Entrer 'n' un entier superieur ou egal a 1.\n");

    do
    {
        scanf("%d",&n);

    }while(n<1);
    int premier[n];
    nombrePremier(premier,n);

    if(n==1)
        printf("Le premier nombre premier est \n");
    else
        printf("les %d premiers nombres sont : \n",n);
    Ecriture(premier,n);


    return 0;

}
