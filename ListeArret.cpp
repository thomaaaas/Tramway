#include "ListeArret.h"
#include "Station.h"
#include <iostream>

using namespace std;

ListeArret::ListeArret() : t{nullptr}
{
    //ctor
}

ListeArret::~ListeArret()
{
    while(t)
	{
		ChainonArret *tmp=t->suiv;
		delete t;
		t=tmp;
	}
}

ChainonArret* ListeArret::getTete() const{
    return t;
}

void ListeArret::affiche(){
    ChainonArret *c = t;
    while(c){
        c->getStation().affiche();
        c = c->suiv;
    }
}

void ListeArret::insererArret(Station &station)
{
	ChainonArret *nc=new ChainonArret(station);
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

/*
ChainonArret *ListeArret::arretTram(double x, double y)
{
    ChainonArret *c=t;
    int i=1;
    while(c!=nullptr)
    {
        if(c->d_x==x && c->d_y==y)
        {
            return c;
        }
        else
        {
            c=c->suiv;
            i++;
        }
    }

}
*/
