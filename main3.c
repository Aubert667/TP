#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct
{
    char auteur[32];
    char titre[32];
} Livre;

void print_livre(Livre * livre);
void print_livres(Livre ** livres, int index_libre);
Livre *alloue_book(char *titre, char *auteur);
void free_book(Livre **livre);
void free_books(Livre **livres, int * index_libre);
int init_tab_livres(Livre **livres, int n);
int add_book(Livre *livre, Livre **livres, int * index_libre, int n);
Livre *search_book (Livre *livre, Livre **livres, int index_libre);
Livre *pop_book(Livre **livres, int * index_libre);

int main()
{
    Livre * livre1 = alloue_book("titre1", "auteur1");
    Livre * livre2 = alloue_book("titre2", "auteur2");
    Livre * livre3 = alloue_book("titre3", "auteur3");
    Livre * livre4 = alloue_book("titre4", "auteur4");
    Livre * livre5 = alloue_book("titre5", "auteur5");

    free_book(&livre2); // livre2 n'existe plus!

    Livre * livres[4];
    int n = sizeof(livres)/sizeof(livres[0]); // nombre de livres
    int status = init_tab_livres(livres, n);
    if (status == 0)
    {
        printf("Echec allocation \n");
        return 1;
    }

    int index_libre = 0;
    add_book(livre1, livres, &index_libre, n);
    add_book(livre2, livres, &index_libre, n);
    add_book(livre3, livres, &index_libre, n);
    add_book(livre4, livres, &index_libre, n);
    add_book(livre5, livres, &index_libre, n);

    printf("les livres : \n");
    print_livres(livres, index_libre);

    Livre * livre = NULL;

    printf("le livre recherché n'existe plus!\n");
    livre = search_book(livre2, livres, index_libre);
    if (NULL == livre)
        printf("pas trouvé!\n");
    else
        printf("trouvé!\n");


    printf("livre recherché : ");
    print_livre(livre3);
    livre = search_book(livre3, livres, index_libre);
    if (NULL == livre)
        printf("pas trouvé!\n");
    else
        printf("trouvé!\n");


    Livre * livre6 = alloue_book("titre6", "auteur6");
    printf("livre recherché : ");
    print_livre(livre6);
    livre = search_book(livre6, livres, index_libre);
    if (NULL == livre)
        printf("pas trouvé!\n");
    else
        printf("trouvé!\n");

    livre = pop_book(livres, &index_libre);
    printf("livre dépilé : ");
    print_livre(livre);

    printf("les livres : \n");
    print_livres(livres, index_libre);

    printf("On va remplir la boîte de livres au-delà de sa capacité égale à %d \n", n);
    Livre * livre7 = alloue_book("titre7", "auteur7");
    Livre * livre8 = alloue_book("titre8", "auteur8");
    Livre * livre9 = alloue_book("titre9", "auteur9");
    Livre * livre10 = alloue_book("titre10", "auteur10");
    Livre * livre11 = alloue_book("titre11", "auteur11");

    add_book(livre7, livres, &index_libre, n);
    add_book(livre8, livres, &index_libre, n);
    add_book(livre9, livres, &index_libre, n);
    add_book(livre10, livres, &index_libre,n);
    add_book(livre11, livres, &index_libre,n);

    printf("les livres : \n");
    print_livres(livres, index_libre);
    free_books(livres, &index_libre);

    printf("les livres : \n");
    print_livres(livres, index_libre);

    return 0;
}

void print_livre(Livre * livre)
{
    printf("(%s %s)\n", livre->auteur, livre->titre);
}

void print_livres(Livre ** livres, int  index_libre)
{
    int i;
    for (i = 0; i < index_libre; i++)
    {
        print_livre(livres[i]);
    }
}

Livre *alloue_book(char *titre, char *auteur)
{
    Livre *livre = NULL;
    livre = (Livre *)malloc(sizeof(Livre));
    if (NULL == livre)
        return NULL;
    strncpy(livre->auteur, auteur, 32);
    strncpy(livre->titre, titre, 32);
    return livre;
}

void free_book(Livre **livre)
{
    free(*livre);
    *livre = NULL;
}

void free_books(Livre **livres, int * index_libre)
{
    int i;
    for (i = 0; i < *index_libre; i++)
        free_book(&livres[i]);
    *index_libre = 0;
}

int init_tab_livres(Livre **livres, int n)
{
    if (NULL == livres)
        return 0;
    int i;
    for (i = 0; i < n; i++)
    {
        livres[i] = NULL;
    }
    return 1;
}

int add_book(Livre *livre, Livre **livres, int * index_libre, int n)
{
    if (NULL == livre)
    {
        return 0;
    }

    if (*index_libre == n)
    {
        printf("plus de place!\n");
        return 0;
    }

    livres[*index_libre] = livre;
    (*index_libre)++;

    return 1;
}

Livre *search_book (Livre *livre, Livre **livres, int index_libre)
{
    if (livre == NULL)
    {
        return NULL;
    }

    int i;
    for (i = 0; i < index_libre; i++)
    {
        if (livres[i] == livre)
        {
            return livres[i];
        }
    }
    return NULL;
}

Livre *pop_book(Livre **livres, int * index_libre)
{
    Livre * res = NULL;
    Livre * dernier = livres[*index_libre - 1];

    res = alloue_book(dernier->auteur, dernier->titre);
    free_book(&livres[*index_libre - 1]);
    (*index_libre)--;

    return res;
}

