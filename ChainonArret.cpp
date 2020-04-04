#include "ChainonArret.h"
#include "Arret.h"
#include "ListeArret.h"
#include <iostream>

using namespace std;

ChainonArret::ChainonArret(Arret *arret) : d_arret{arret}, suiv{nullptr}, prec{nullptr}
{
    //ctor
}

Arret* ChainonArret::getArret(){                // Retourne l'arr�t point�
    return d_arret;
}

ChainonArret* ChainonArret::getSuiv() const     // retourne le cha�non suivant
{
    return suiv;
}

ChainonArret* ChainonArret::getPrec() const     // retourne le cha�non pr�c�dent
{
    return prec;
}

