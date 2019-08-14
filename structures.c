#include "fonctions_structures.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



void SaisirVoiture(Voitures * voitures)
{
    printf("Constructeur................");
    fflush(stdin);
    scanf("%s",&voitures->constructeur[0]);
    fflush(stdin);
    printf("Modele......................");
    scanf("%s",&voitures->modele[0]);
    printf("Kilometrage.................");
    scanf("%u",&voitures->nbre_kilometrage);
    printf("Prime d'assurance............");
    scanf("%lf",&voitures->Prime_assurance);
    printf("Veuillez renseignez la date de mise en circulation du vehicule : \n");
    saisirDate(&voitures->mise_en_circulation);
}


void saisirDate(Dates *dates)
{
    do
    {
        printf("entrer le jour.......");
        fflush(stdin);
        scanf("%u",&dates->jour);

    }while(dates->jour <= 1 && dates->jour <=31);

    do
    {

        printf("entrer le mois..........");
        fflush(stdin);
        scanf("%u",&dates->mois);

    }while(dates->mois <= 1  && dates->mois <= 12);

    do
    {
        printf("entrer une annee positive.........");
        fflush(stdin);
        scanf("%u",&dates->annee);

    }while(dates->annee <1);


}

double KilometrageAnnuel(const Voitures voitures)
{
    double KiloMoyen = 0;
    int diff_Mois = 0;

    time_t secondes;

    struct tm initial;
    time(&secondes);

    initial = *localtime(&secondes); // formatage du nombre de seconde en Annee et Mois

    diff_Mois = (initial.tm_year + 1899)*12 + initial.tm_mon -(voitures.mise_en_circulation.annee -1)*12 - voitures.mise_en_circulation.mois +1;

    printf("%d\n",diff_Mois);

    KiloMoyen = (voitures.nbre_kilometrage/(double)diff_Mois)*12.0;

    return KiloMoyen;


}

void afficherDate(const Dates dates)
{
    printf("date de mise en circulation %u / %u / %u",dates.jour,dates.mois,dates.annee);
}

void afficheVoiture(const Voitures voitures)
{
    printf("Nom du Constructeur......%s........\n",voitures.constructeur);
    printf("Nom du Modele............%s.........\n",voitures.modele);
    printf("Nombre de Kilometrage....%u........Km\n",voitures.nbre_kilometrage);
    printf("Montant de la Prime......%.2f......euros\n",voitures.Prime_assurance);
    afficherDate(voitures.mise_en_circulation);
}



int main()
{
    Voitures voiture;

    printf("_____________________________________________________\n\n");
    printf("SAISIE DES INFORMATIONS SUR LA VOITURE\n");
    printf("______________________________________________________\n\n");

    SaisirVoiture(&voiture);

    printf("_____________________________________________________\n\n");
    printf("AFIICHAGE DES INFORMATIONS SUR LA VOITURE\n");
    printf("______________________________________________________\n\n");
    afficheVoiture(voiture);
    printf("\n\n");

    printf("%.2f kms",KilometrageAnnuel(voiture));




    return 0;

}
