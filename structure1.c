#include "structure1.h"
#include "structure2.h"




void afficheVoiture1(const Voitures voitures)
{
    printf("Nom du Constructeur......%s........\n",voitures.constructeur);
    printf("Nom du Modele............%s.........\n",voitures.modele);
    printf("Nombre de Kilometrage....%u........Km\n",voitures.nbre_kilometrage);
    printf("Montant de la Prime......%.2f......euros\n",voitures.Prime_assurance);
}


void afficheVoiture2(const Voitures *voitures)
{
    printf("Nom du Constructeur......%s........\n",voitures->constructeur);
    printf("Nom du Modele............%s.........\n",voitures->modele);
    printf("Nombre de Kilometrage....%u........Km\n",voitures->nbre_kilometrage);
    printf("Montant de la Prime......%.2f......euros\n",voitures->Prime_assurance);
}


void SaisirVoiture1(Voitures * voitures)
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
}




int main()
{
    Voitures voiture;

    printf("_____________________________________________________\n\n");
    printf("SAISIE DES INFORMATIONS SUR LA VOITURE\n");
    printf("______________________________________________________\n\n");

    SaisirVoiture1(&voiture);

    printf("_____________________________________________________\n\n");
    printf("AFIICHAGE DES INFORMATIONS SUR LA VOITURE\n");
    printf("______________________________________________________\n\n");
    afficheVoiture1(voiture);
    afficheVoiture2(&voiture);
    printf("\n\n");


    return 0;

}
