#include <stdio.h>
#include <stdlib.h>

int * init_tab(int n);
void delete_tab(int **tab);
void print_tab(const int *tab, int n);
int duplicate_tab(int *tab, int n);

int main()
{
    int n;
    printf("Veuillez saisir un entier : taille du tableau\n");
    scanf("%d",&n);

    int * tab = init_tab(n);
    if (NULL == tab)
    {
        printf("plus de place mémoire dans le tas!\n");
        return 1;
    }

    print_tab(tab, n);

    int status;
    status = duplicate_tab(tab, n);
    if (status == 0)
    {
        printf("plus de place mémoire dans le tas!\n");
        return 1;
    }

    print_tab(tab, 2 * n); // la taille a doublée

    delete_tab(&tab);
    print_tab(tab, 2 * n);

    return 0;
}

int *init_tab(int n) {
    int *tab = (int*)malloc(n * sizeof(int));
    if (NULL == tab) {
       return NULL;
    }
    int i;
    for (i = 0; i < n; i++) {
        tab[i] = i + 1;
    }

    return tab;
}

void delete_tab(int **tab) {
    free(*tab);
    *tab = NULL;
}

void print_tab(const int *tab, int n) {
    int i;
    if (NULL == tab)
        return;
    for (i = 0; i < n; i++) {
        printf("%d ",tab[i]);
    }
    printf("\n");
}

int duplicate_tab(int *tab, int n) {
    int * temp = NULL;
    temp = (int *)realloc(tab, 2 * n * sizeof(int));
     if (NULL == temp) {
       return 0;
    }
    int i;
    tab = temp;
    for (i = 0; i < n; i++) {
        tab[i + n] = i + 1;
    }
    return 1;
}







