#include "Arret.h"

#ifndef CHAINONARRET_H
#define CHAINONARRET_H

class ChainonArret
{
    friend class ListeArret;
    friend class Ligne;
    public:
        Arret* getArret();
        ChainonArret *getSuiv() const;
        ChainonArret *getPrec() const;
    private:
        ChainonArret(Arret *arret);
        Arret *d_arret;
        ChainonArret *suiv;
        ChainonArret *prec;
};

#endif // CHAINONARRET_H
