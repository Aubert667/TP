#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions_TP3.h"

void copie1(char dst[], const char src[])
{
    int i;
    for (i = 0; src[i] != '\0'; i++)
    {
        dst[i] = src[i];
    }
    dst[i] = '\0';
}



/** Vision pointeurs avec la Methode strcmp*/

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


/** En utilisant les pointeurs */
void Occurence(const char * s1, char c)
{
    int compteur = 0;
    while(*s1 != '\0')
    {
        if(*s1 == c)
        {
            compteur++;
            *s1++;
        }
        else
        {
            *s1++;
        }
    }

    printf(" %c apparait %d fois",c,compteur);

}




void copie2(char dst[], const char src[])
{
    for ( ; src[0] != '\0'; src++, dst++)
    {
        dst[0] = src[0];
    }
    dst[0] = '\0';
}

/** Vision pointeurs …
*/
void copie3(char * dst, const char * src)
{
    for ( ; *src != '\0'; src++, dst++)
    {
        *dst = *src;
    }
    *dst = '\0';
}

/** Ecritures compactes */
void copie4(char * dst, const char * src)
{
    while (*src != '\0')
    {
        *dst++ = *src++;
    }
    *dst = '\0';
}


void copie5(char * dst, const char * src)
{
    while ((*dst++ = *src++) != '\0')
    {
        ;
    }
}

void copie6(char *dst, const char *src)
{
    while((*dst++)=(*src++));
}






int concatene(const char * s1, const char * s2, char * concat)
{
    int i, j = 0;

    for (i = 0; s1[i] != '\0'; i++)
        concat[i] = s1[i];

    for (j = 0; (s2[j] !='\0') && (i + j < N); j++)
        concat[i+j] = s2[j];

    concat[i + j] ='\0';

    if (i + j >= N)
        return 0;

    return 1;
}



int ordreLex(const char * s1, const char * s2)
{
    int i;

    for (i = 0; s1[i] != '\0'; i++)
    {
        if (s1[i] < s2[i])
            return -1;
        if (s1[i] > s2[i])
            return 1;
    }
    return(0);
}


int occurence(const char * s, char caractere)
{
    int i, k;

    for (i = 0, k = 0; s[i] != '\0'; i++)
    {
        if (s[i] == caractere)
            k++;
    }
    return k;
}


void remplaceCaractere(char * s, char caractere, char remplace)
{
    int i;
    for(i = 0; s[i] != '\0'; i++)
    {
        if(s[i] == caractere)
            s[i] = remplace;
    }
}


void remplaceListe(char * s1, const char * s2, const char * s3)
{
    int i, j;

    for (i = 0; s1[i] != '\0'; i++)
    {
        for (j = 0; (s2[j]!= '\0') && (s3[j] != '\0'); j++)
        {
            if (s1[i] == s2[j])
            {
                s1[i] = s3[j];
            }
        }
    }
}

/** On initialise 2 tableaux de 256 entiers, qu'on initialise à 0.
Ca suffit pour capturer toutes les lettres.
Puis on lit les 2 chaines en ajoutant 1 dans la case correspondant a la lettre lue.
A la fin, on compare simplement si on a la meme valeur dans toutes les cases.
Si oui, c'est un anagramme.
*/
int anagramme (char * s1, char * s2)
{
    int i, index;
    int s1Occurences[256], s2Occurences[256];

    for (i = 0; i < 256; i++)
    {
        s1Occurences[i] = 0;
        s2Occurences[i] = 0;
    }

    for (i = 0; s1[i] != '\0'; i++)
    {
        index = s1[i];
        s1Occurences[index]++;
    }

    for (i = 0; s2[i] != '\0'; i++)
    {
        index = s2[i];
        s2Occurences[index]++;
    }

    for (i = 0; i < 256; i++)
    {
        if (s1Occurences[i] != s2Occurences[i])
            return 0;
    }

    return 1;
}


int recherche(const char * s, const char * mot)
{
    int i, j;

    for (i = 0; s[i] != '\0'; i++)
    {
        for(j = 0; s[i+j] == mot[j]; j++)
        {
            if(mot[j+1] == '\0')
                return i;
        }
    }

    return -1;
}

int main(void)
{
    int choix;
    char chaine1[N], chaine2[N], chaine3[N];
    char caractere, remplace;

    do
    {
           printf("____________MENU____________________\n\n");
           printf("     1  copie\n");
           printf("     2 concatene\n");
           printf("     3 ordreLex\n");
           printf("     4 occurence\n");
           printf("     5 remplaceCaractere\n");
           printf("     6 remplaceListe\n");
           printf("     7 anagramme\n");
           printf("     8 rechercheMot\n");
           printf("     9 Fin\n");
           printf("_____________________________________________\n\n");
           printf("entrer votre choix........");
           scanf("%d", &choix);
           printf("\n\n");

        switch(choix)
        {
        case 0:
            printf("Merci et A bientot \n");
            break;
        case 1:
            system("cls");
            printf("Entrez 1 chaine\n");
            printf("Chaine 1 : ");
            scanf("%s", chaine1);
            copie1(chaine2, chaine1); /** essayer les 6 autres versions */
            printf("copie: %s\n", chaine2);
            break;
        case 2:
            system("cls");
            printf("Entrez 2 chaines\n");
            printf("Chaine 1 : ");
            scanf("%s", chaine1);
            printf("Chaine 2 : ");
            scanf("%s", chaine2);
            concatene(chaine1, chaine2, chaine3);
            printf("concatenation : %s\n", chaine3);
            break;
        case 3:
            system("cls");
            printf("Entrez 2 chaines\n");
            printf("Chaine 1 : ");
            scanf("%s", chaine1);
            printf("Chaine 2 : ");
            scanf("%s", chaine2);
            printf("Ordre Lexicographique : %d\n", ordreLex(chaine1, chaine2));
            break;
        case 4:
            system("cls");
            printf("Entrez 1 chaine\n");
            printf("Chaine 1 : ");
            scanf("%s", chaine1);
            printf("Entrez un caractere\n");
            scanf(" %c",&caractere);
            printf("%c apparait %d fois\n", caractere, occurence(chaine1,caractere));
            break;
        case 5:
            system("cls");
            printf("Entrez 1 chaine\n");
            scanf("%s", chaine1);
            printf("Entrez un caractere a remplacer puis celui par lequel le remplacer\n");
            scanf(" %c %c", &caractere, &remplace);
            remplaceCaractere(chaine1, caractere, remplace);
            printf("resultat : %s\n", chaine1);
            break;
        case 6:
            system("cls");
            printf("Entrez 1 chaine, puis la chaine des caracteres a remplacer, \
                   puis la chaine des caracteres par lesquels on remplace les precedents à la même position\n");
            printf("Chaine 1 : ");
            scanf("%s", chaine1);
            printf("Chaine 2 : ");
            scanf("%s", chaine2);
            printf("Chaine 3 : ");
            scanf("%s", chaine3);
            remplaceListe(chaine1, chaine2, chaine3);
            printf("resultat : %s\n",chaine1);
            break;
        case 7:
            system("cls");
            printf("Entrez 2 chaines\n");
            printf("Chaine 1 : ");
            scanf("%s", chaine1);
            printf("Chaine 2 : ");
            scanf("%s", chaine2);
            if (anagramme(chaine1, chaine2) == 1)
                printf("Ce sont des anagrammes\n");
            else
                printf("Ce ne sont pas des anagrammes\n");
            break;
        case 8:
        {
            system("cls");
            int position;
            printf("Entrez 2 chaines\n");
            printf("Chaine 1 : ");
            scanf("%s", chaine1);
            printf("Chaine 2 : ");
            scanf("%s", chaine2);
            position =  recherche(chaine1, chaine2);
            if (position !=-1)
                printf("%s est dans %s a la position %d\n",chaine2, chaine1, position);
            else
                printf("%s n'est pas dans %s\n", chaine2, chaine1);
            break;
        }
        case 9:
            break;

        default:
            printf("cas non prévu\n");
            break;
        }
    }
    while(choix != 0);

    return 0;
}
