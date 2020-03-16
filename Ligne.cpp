#include "Ligne.h"
#include "graphics.h"
#include "ListeArret.h"
#include "ChainonArret.h"
#include <iostream>

using namespace std;

Ligne::Ligne(ListeArret *arret) : d_arret{arret}{

}

void Ligne::affiche(){
    setcolor(BLUE);
    ChainonArret *c = d_arret->t;
    while(c -> suiv){
        line(c->getArret()->getX(), c->getArret()->getY(), c->suiv->getArret()->getX(), c->suiv->getArret()->getY());
        c = c->suiv;
    }
}

ChainonArret *Ligne::arretTram(double x, double y)
{
    ChainonArret *c=d_arret->t;
    while(c!=nullptr)
    {
        if(c->getArret()->getX()>x-1 && c->getArret()->getX()<x+1 && c->getArret()->getY()>y-1 && c->getArret()->getY()<y+1)
        {
            return c;
        }
        else
        {
            c=c->suiv;
        }
    }
    return nullptr;
}
