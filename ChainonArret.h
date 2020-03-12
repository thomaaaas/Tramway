#ifndef CHAINONARRET_H
#define CHAINONARRET_H

#include "Arret.h"

using namespace std;

class ChainonArret
{
    friend class ListeArret;
    friend class Ligne;
    public:
        Arret* getArret();
    private:
        ChainonArret(Arret *arret);
        Arret *d_arret;
        ChainonArret *suiv;
        ChainonArret *prec;
};

#endif // CHAINONARRET_H
