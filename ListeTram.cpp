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

void ListeTram::Trajectoire (ChainonArret *Arret, ChainonTram *tram, vector<double> &Coord)
{
    double dt, d, a, b, x, y;
    cout << tram->getTramway()->getSens()<<endl;
    if(!Arret->getSuiv())
    {
        tram->getTramway()->setSens(false);
    }
    if(!Arret->getPrec())
    {
        tram->getTramway()->setSens(true);
    }
    if(tram->getTramway()->getSens())
    {
        //aller
        dt = sqrt(pow(tram->getTramway()->getX() - Arret->getArret()->getX(),2) + pow(tram->getTramway()->getY()-Arret->getArret()->getY(),2));
        d = sqrt(pow(Arret->getSuiv()->getArret()->getX()-Arret->getArret()->getX(),2) + pow(Arret->getSuiv()->getArret()->getY()-Arret->getArret()->getY(),2));
        dt+= tram->getTramway()->getVitesse();
        a = dt/d;
        b = 1-a;
        x = a*Arret->getSuiv()->getArret()->getX() + b*Arret->getArret()->getX();
        y = a*Arret->getSuiv()->getArret()->getY() + b*Arret->getArret()->getY();
    }
    else
    {
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

bool ListeTram::distance( ChainonTram *tram)
{
    ChainonTram *c;
    if(tram->suiv == nullptr)
    {
        return true;
    }
    else
    {
        c = tram->suiv;
    }
    double d = sqrt(pow(tram->getTramway()->getX() - c->getTramway()->getX(),2) + pow(tram->getTramway()->getY()-c->getTramway()->getY(),2));
    if(tram->getTramway()->getSens() == c->getTramway()->getSens())
    {
        if (d < tram->getTramway()->getDistanceMin())
        {
            cout<<"nique"<<endl;
            return false;
        }
    }
    return true;
}

void ListeTram::avancer(Ligne *ligne){
    ChainonTram *c = t;
    double x,y;
    double vitesse;
    vector<double> coord;
    while(c){
        if (c->getTramway()->getonMarche())
        {
            x = c->getTramway()->getX();
            y = c->getTramway()->getY();
            cout << "Tramway : " << x << " " << y << endl;
            if(distance(c))
            {
                cout<<"okay"<<endl;
                if(ligne->arretTram(x,y,c))
            {
                c->actuelArret = ligne->arretTram(x,y,c);
                c->getTramway()->setonMarche(false);
                c->getTramway()->setTempsArret(10);
            }
            Trajectoire(c->actuelArret, c,coord);
            c->getTramway()->setPosition(coord[0], coord[1]);
            coord.clear();
            }
        }
        else
        {
            if(c->getTramway()->getTempsArret() > 0)
            {
                double tmps = c->getTramway()->getTempsArret();
                cout << tmps << endl;
                c->getTramway()->setTempsArret(--tmps);
                cout << c->getTramway()->getTempsArret() <<endl;
            }
            else
            {
                c->getTramway()->setonMarche(true);
            }
        }

        c = c->suiv;
        cout << "Tramway suivant " << endl;
    }

}



/*
vérifier distance tram suivant stop si trop infd
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
