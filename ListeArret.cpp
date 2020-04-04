#include "ListeArret.h"

ListeArret::ListeArret() : t{nullptr}{}

ListeArret::~ListeArret()       // destructeur
{
    while(t){
		ChainonArret *tmp=t->suiv;
		delete t;
		t=tmp;
	}
}



void ListeArret::affiche(){      //Utilise "affiche()" sur la liste, qui affiche les arrêts
    ChainonArret *c = t;
    while(c){
        c->getArret()->affiche();
        c = c->suiv;
    }
}

void ListeArret::insererArret(Arret *arret)     // Insère un arrêt dans la liste chaînée
{
	ChainonArret *nc=new ChainonArret(arret);
	if(t==nullptr){
        t=nc;
    }
    else{
        ChainonArret *precC=nullptr, *c=t;
        while(c!=nullptr){
            precC=c;
            c=c->suiv;
        }
        precC->suiv=nc;
        nc->prec = precC;
        nc->suiv = c;
    }
}

