#include "Ligne.h"
#include "graphics.h"
#include "ListeArret.h"
#include "ChainonArret.h"
#include <iostream>

using namespace std;

Ligne::Ligne(ListeArret &arret) : d_arret{arret}{

}

void Ligne::affiche(){
    setcolor(BLUE);
    ChainonArret *c = d_arret.t;
    while(c -> suiv){
        line(c->getArret()->getX(), c->getArret()->getY(), c->suiv->getArret()->getX(), c->suiv->getArret()->getY());
        c = c->suiv;
    }
}
