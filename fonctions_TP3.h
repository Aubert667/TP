#ifndef FONCTIONS_TP3_H_INCLUDED
#define FONCTIONS_TP3_H_INCLUDED


# define N 128
typedef enum {TRUE,FALSE} BOOLEAN;

extern void RemplirEratos(BOOLEAN premier[], int n);
extern void AfficherEratos(BOOLEAN premier[], int n);
extern int OrdreLex(const char *s1,const char * s2);
extern int position(int tab[],int n, int x);
extern void Lecture(int tab[], int n);
extern void Ecriture(int tab[], int n);
extern void somme(int tab1[], int tab2[], int resultat[], int n);
extern void lecture(int tab[], int n);
extern void ecriture(int tab[], int n);
extern void copie(char s1[], const char s2[]);
extern void copie1(char s1[], const char s2[]);
void copie4(char * s1, const char *s2);
void copie3(char * s1, const char * s2);
void copie6(char *dst, const char *src);
void Remplace(const char * s1, char c, char d, char *s2);
void Occurence(const char * s1, char c);
int anagramme(char * s1, char *s2);
int rechercheMot(const char *s, const char *mot);


#endif // FONCTIONS_TP3_H_INCLUDED
