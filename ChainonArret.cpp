#include "ChainonArret.h"
#include "Station.h"
#include "ListeArret.h"

using namespace std;

ChainonArret::ChainonArret(Station &station) : d_station{station}, suiv{nullptr}, prec{nullptr}
{
    //ctor
}

Station ChainonArret::getStation() const{
    return d_station;
}
