#ifndef TRAMWAY_LIGNE_H
#define TRAMWAY_LIGNE_H
#include "ListeArret.h"

class Ligne{
public:
    Ligne(ListeArret &arret);
    void affiche();
private:
    ListeArret d_arret;
};
#endif //TRAMWAY_LIGNE_H
