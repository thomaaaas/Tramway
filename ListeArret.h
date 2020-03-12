#ifndef LISTEARRET_H
#define LISTEARRET_H
#include "ChainonArret.h"
#include "Arret.h"

using namespace std;

class ListeArret
{
    friend class ChainonArret;
    friend class Ligne;
    public:
        ListeArret();
        ~ListeArret();
        ChainonArret* getTete() const;
        void insererArret(Arret *arret);
        void affiche();
        //ChainonArret *arretTram(double x, double y);
    private:
        ChainonArret *t;
};

#endif // LISTEARRET_H
