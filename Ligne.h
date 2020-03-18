#ifndef TRAMWAY_LIGNE_H
#define TRAMWAY_LIGNE_H
#include "ListeArret.h"
#include "ChainonTram.h"

class Ligne{
public:
    Ligne(ListeArret *arret);
    void affiche();
    ChainonArret *arretTram(ChainonTram *d);
private:
    ListeArret *d_arret;
};
#endif //TRAMWAY_LIGNE_H
