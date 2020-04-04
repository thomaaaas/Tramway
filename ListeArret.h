#include "ChainonArret.h"
#include "Arret.h"

#ifndef LISTEARRET_H
#define LISTEARRET_H

class ListeArret
{
    friend class ChainonArret;
    friend class Ligne;
    public:
        ListeArret();
        ~ListeArret();
        void insererArret(Arret *arret);
        void affiche();
    private:
        ChainonArret *t;
};

#endif // LISTEARRET_H
