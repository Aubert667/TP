#include <stdio.h>
#include <stdlib.h>

int nb_occurences_tab(int *tab, int n, int a);
int nb_occurencesRec_tab(int *tab, int n, int a);
int contient_doublons(int *tab, int n);
int test_doublons(int *tab, int n);

int main()
{
    int tab[] = {1,22,2,4,4,6};
    printf("4 est présent %d fois\n",nb_occurences_tab(tab, sizeof(tab)/sizeof(tab[0]), 4));
     printf("444 est présent %d fois\n",nb_occurences_tab(tab, sizeof(tab)/sizeof(tab[0]), 444));
    printf("%d\n",test_doublons(tab, sizeof(tab)/sizeof(tab[0])));

    return 0;
}


int nb_occurences_tab(int *tab, int n, int a) {
    int compteur = 0;
    int i;
    for (i = 0; i < n; i++) {
        if (tab[i] == a) {
            compteur++;
        }
    }
    return compteur;
}

int nb_occurencesRec_tab(int *tab, int n, int a)
{
    if (n == 0)
        return 0;
    if (*tab == a)
        return 1 + nb_occurencesRec_tab(tab + 1,n - 1, a);
    else
        return nb_occurencesRec_tab(tab + 1,n - 1, a);
}

int contient_doublons(int *tab, int n) {
    int i,j;
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (tab[i] == tab[j]) {
                return 1;
            }
        }
    }
    return 0;
}

int test_doublons(int *tab, int n) {
    return contient_doublons(tab, n);
}
