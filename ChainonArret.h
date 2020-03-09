#ifndef CHAINONARRET_H
#define CHAINONARRET_H

#include "Station.h"

using namespace std;

class ChainonArret
{
    friend class ListeArret;
    friend class Ligne;
    public:
        Station getStation() const;
    private:
        ChainonArret(Station &station);
        Station d_station;
        ChainonArret *suiv;
        ChainonArret *prec;
};

#endif // CHAINONARRET_H
