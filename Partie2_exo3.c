#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions_TP3.h"


int OrdreLex(const char * s1, const char *s2)
{
    int resultat = strcmp(s1,s2);


    if(resultat < 0)
    {
        printf("\t%s < %s\t\n",s1,s2);
    }
    else if(resultat == 0)
    {
        printf("\t%s = %s\n",s1,s2);
    }
    else
    {
        printf("\t\t%s > %s\n",s1,s2);
    }
    return resultat;
}

int main()
{
    char * s1="Prem";
    char *s2 ="Deux";

    printf("\t%d",OrdreLex(s1,s2));
    printf("\t%d",OrdreLex(s2,s1));

    s1 = s2;
    printf("\t%d",OrdreLex(s1,s2));

    return 0;

}
