#include "ChainonArret.h"
#include "Arret.h"
#include "ListeArret.h"
#include <iostream>

using namespace std;

ChainonArret::ChainonArret(Arret *arret) : d_arret{arret}, suiv{nullptr}, prec{nullptr}
{
    //ctor
}

Arret* ChainonArret::getArret(){
    return d_arret;
}

ChainonArret* ChainonArret::getSuiv() const
{
    return suiv;
}

ChainonArret* ChainonArret::getPrec() const
{
    return prec;
}

