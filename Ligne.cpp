#include "Ligne.h"
#include "graphics.h"
#include "ListeArret.h"
#include "ChainonArret.h"
#include "ChainonTram.h"
#include <iostream>
#include <cmath>

using namespace std;

Ligne::Ligne(ListeArret *arret) : d_arret{arret}{

}

void Ligne::affiche(){        // Affiche les lignse en vert ici
    setcolor(GREEN);
    ChainonArret *c = d_arret->t;
    while(c -> suiv){
        line(c->getArret()->getX(), c->getArret()->getY(), c->suiv->getArret()->getX(), c->suiv->getArret()->getY());
        c = c->suiv;
    }
}

ChainonArret *Ligne::arretTram(ChainonTram *d)
{
    ChainonArret *c=d_arret->t;
    while(c!=nullptr)
    {
        if(c->getArret()->getX() > d->getTramway()->getX() - d->getTramway()->getVitesse() && c->getArret()->getX() < d->getTramway()->getX() + d->getTramway()->getVitesse() && c->getArret()->getY() > d->getTramway()->getY() - 1 && c->getArret()->getY() < d->getTramway()->getY() + d->getTramway()->getVitesse()){
            return c;
        }
        else
        {
            c=c->suiv;
        }
    }
    return nullptr;
}


