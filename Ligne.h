#include "ListeArret.h"
#include "ChainonTram.h"
#include "ChainonArret.h"
#include "graphics.h"

#ifndef TRAMWAY_LIGNE_H
#define TRAMWAY_LIGNE_H

class Ligne{
public:
    Ligne(ListeArret *arret);
    void affiche();
    ChainonArret *arretTram(ChainonTram *d);
private:
    ListeArret *d_arret;
};
#endif //TRAMWAY_LIGNE_H
