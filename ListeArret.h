#ifndef LISTEARRET_H
#define LISTEARRET_H
#include "ChainonArret.h"
#include "Station.h"

using namespace std;

class ListeArret
{
    friend class ChainonArret;
    public:
        ListeArret();
        ~ListeArret();
        void insererArret(Station &station);
        void affiche();
        //ChainonArret *arretTram(double x, double y);
    private:
        ChainonArret *t;
};

#endif // LISTEARRET_H