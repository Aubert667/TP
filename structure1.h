#ifndef STRUCTURE1_H_INCLUDED
#define STRUCTURE1_H_INCLUDED
#include "structure2.h"
typedef struct Voiture
{
    unsigned int nbre_kilometrage;
    unsigned int annee_fabrication;
    Dates mise_en_circulation;
    char constructeur[32];
    char modele[16] ;
    double Prime_assurance;


}Voitures;






#endif // STRUCTURE1_H_INCLUDED
