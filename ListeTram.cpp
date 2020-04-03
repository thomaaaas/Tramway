#include "ListeTram.h"
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

ListeTram::ListeTram() : t{nullptr}
{
    //ctor
}

ListeTram::~ListeTram()
{
    while(t){
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

void ListeTram::Trajectoire (ChainonArret *Arret, ChainonTram *tram, vector<double> &Coord)
{
    double dt, d, a, b, x, y;
    if(!Arret->getSuiv()){
        tram->getTramway()->setSens(false);
    }
    if(!Arret->getPrec()){
        tram->getTramway()->setSens(true);
    }
    if(tram->getTramway()->getSens()){
        //aller
        dt = sqrt(pow(tram->getTramway()->getX() - Arret->getArret()->getX(),2) + pow(tram->getTramway()->getY()-Arret->getArret()->getY(),2));
        d = sqrt(pow(Arret->getSuiv()->getArret()->getX()-Arret->getArret()->getX(),2) + pow(Arret->getSuiv()->getArret()->getY()-Arret->getArret()->getY(),2));
        dt+= tram->getTramway()->getVitesse();
        a = dt/d;
        b = 1-a;
        x = a*Arret->getSuiv()->getArret()->getX() + b*Arret->getArret()->getX();
        y = a*Arret->getSuiv()->getArret()->getY() + b*Arret->getArret()->getY();
    }
    else{
        //retour
        dt = sqrt(pow(tram->getTramway()->getX() - Arret->getArret()->getX(),2) + pow(tram->getTramway()->getY()-Arret->getArret()->getY(),2));
        d = sqrt(pow(Arret->getPrec()->getArret()->getX()-Arret->getArret()->getX(),2) + pow(Arret->getPrec()->getArret()->getY()-Arret->getArret()->getY(),2));
        dt+= tram->getTramway()->getVitesse();
        a = dt/d;
        b = 1-a;
        x = a*Arret->getPrec()->getArret()->getX() + b*Arret->getArret()->getX();
        y = a*Arret->getPrec()->getArret()->getY() + b*Arret->getArret()->getY();
    }
    Coord.push_back(x);
    Coord.push_back(y);
}

int ListeTram::taille (Ligne *ligne)
{
    ChainonTram *c = t;
    int i = 0;
    while(c)
    {
        i++;
        c=c->suiv;
    }
    return i;
}


bool ListeTram::distance(ChainonTram *tram,Ligne *ligne )
{
    ChainonTram *c;
    ChainonTram *precC;
    if(taille(ligne) == 1 )
    {
        return true;
    }
    if(tram->suiv == nullptr)
    {
        precC = tram;
        c = t;
    }
    else
    {
        precC = tram;
        c = tram->suiv;
    }
    double d = sqrt(pow(tram->getTramway()->getX() - c->getTramway()->getX(),2) + pow(tram->getTramway()->getY()-c->getTramway()->getY(),2));

            if(taille(ligne) == 2)
            {
                if(tram->getTramway()->getSens() == c->getTramway()->getSens())
                {
                    if(tram->getTramway()->getVitesse() > c->getTramway()->getVitesse() && d < tram->getTramway()->getDistanceMin() )
                    {
                        return false;
                    }
                    else
                    {
                        return true;
                    }
                }
            }
            else
            {
                    double d = sqrt(pow(tram->getTramway()->getX() - c->getTramway()->getX(),2) + pow(tram->getTramway()->getY()-c->getTramway()->getY(),2));
                    if(tram->getTramway()->getSens() == c->getTramway()->getSens())
                    {
                        if (d < tram->getTramway()->getDistanceMin())
                        {
                            return false;
                        }
                    }

            }
    return true;
}

void ListeTram::avancer(Ligne *ligne){
    ChainonTram *c = t;
    vector<double> coord;
    while(c){
        if (c->getTramway()->getonMarche()){
            if(distance(c,ligne)){
                if(ligne->arretTram(c) ){
                    c->actuelArret = ligne->arretTram(c);
                    c->getTramway()->setonMarche(false);
                    c->getTramway()->setTempsArret(10);
                }
            Trajectoire(c->actuelArret, c,coord);
            c->getTramway()->setPosition(coord[0], coord[1]);
            coord.clear();
            }
        }
        else{
            if(c->getTramway()->getTempsArret() > 0){
                double tmps = c->getTramway()->getTempsArret();
                c->getTramway()->setTempsArret(--tmps);
            }
            else{
                c->getTramway()->setonMarche(true);
            }
        }
        c = c->suiv;
    }
}

void ListeTram::insererTramway(Tramway *tramway)
{
	ChainonTram *nc=new ChainonTram(tramway);
	if (t==nullptr){
		t=nc;
		return;
	}
	ChainonTram *precC=nullptr,*c=t;
	while(c){
		precC=c;
		c=c->suiv;
	}
	precC->suiv=nc;
	nc->suiv=c;
}
