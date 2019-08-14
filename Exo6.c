#include <stdio.h>
#include <stdlib.h>



void Lecture(int tab[], int n);
void Ecriture(int tab[], int n);
void HeraTostene(int tab[], int Res[], int n)
int EstPremier(int n);


void HeraTostene(int tab[], int Res[], int n)
{
    int i;

    for(i=0; i<n; i++)
    {
        if((EstPremier(tab[i])) == 1)
           {
               Res[i] = 1;
           }
           else
            {
                Res[i] = 0;
            }

    }

}
int main()
{    return 0;

}
