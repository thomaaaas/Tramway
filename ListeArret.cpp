#include "ListeArret.h"
#include "Arret.h"
#include <iostream>

using namespace std;

ListeArret::ListeArret() : t{nullptr}
{
    //ctor
}

ListeArret::~ListeArret()       // destructeur
{
    while(t)
	{
		ChainonArret *tmp=t->suiv;
		delete t;
		t=tmp;
	}
}



void ListeArret::affiche(){      //Utilise "affiche()" sur la liste, qui affiche les arr�ts
    ChainonArret *c = t;
    while(c){
        c->getArret()->affiche();
        c = c->suiv;
    }
}

void ListeArret::insererArret(Arret *arret)     // Ins�re un arr�t dans la liste cha�n�e
{
	ChainonArret *nc=new ChainonArret(arret);
	if(t==nullptr)
    {
        t=nc;
    }
    else
    {
        ChainonArret *precC=nullptr, *c=t;
        while(c!=nullptr)
        {
            precC=c;
            c=c->suiv;
        }
        precC->suiv=nc;
        nc->prec = precC;
        nc->suiv = c;
    }
}

