#include "ListeTram.h"
#include <iostream>

using namespace std;

ListeTram::ListeTram() : t{nullptr}
{
    //ctor
}

ListeTram::~ListeTram()
{
    while(t)
	{
		ChainonTram *tmp=t->suiv;
		delete t;
		t=tmp;
	}
}

void ListeTram::affiche(){
    ChainonTram *c = t;
    while(c){
        c->getTramway()->affiche();
        c = c->suiv;
    }
}

void ListeTram::effacer(){
    ChainonTram *c = t;
    while(c){
        c->getTramway()->efface();
        c = c->suiv;
    }
}

void ListeTram::avancer(){
    ChainonTram *c = t;
    double x,y;
    double vitesse;
    while(c){
        x = c->getTramway()->getX();
        y = c->getTramway()->getY();
        vitesse = c->getTramway()->getVitesse();
        c->getTramway()->setPosition(x+vitesse, y+vitesse);
        x = c->getTramway()->getX();
        y = c->getTramway()->getY();
        c = c->suiv;
    }
}
/*
vérifier distance tram suivant stop si trop inf
pointeur arret sur tram
si coord = alors stop quelque s
sinon avance de vitesse avec ligne tracer entre station (equation)
if sens = true -> station = suiv (+ vitesse)
if sens = false -> station = prec (-vitesse)
*/
void ListeTram::insererTramway(Tramway *tramway)
{
	ChainonTram *nc=new ChainonTram(tramway);
	if(t==nullptr)
    {
        t=nc;
    }
    else
    {
        ChainonTram *precC=nullptr, *c=t;
        while(c!=nullptr)
        {
            precC=c;
            c=c->suiv;
        }
        precC->suiv=nc;
        nc->suiv = c;
    }
}
