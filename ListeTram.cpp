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
    double coeff, b, x, y;
    cout << tram->getTramway()->getSens()<<endl;
    if(!Arret->getSuiv())
    {
        tram->getTramway()->setSens(false);
    }
    if(tram->getTramway()->getSens())
    {
           if(Arret->getSuiv()->getArret()->getX() - Arret->getArret()->getX() == 0)
        {
            y = tram->getTramway()->getY() + tram->getTramway()->getVitesse();
            x = tram->getTramway()->getX();
        }
        else if(Arret->getSuiv()->getArret()->getY() - Arret->getArret()->getY() == 0)
        {
            x = tram->getTramway()->getX() + tram->getTramway()->getVitesse();
            y = tram->getTramway()->getY();
        }
        else
        {
            coeff = (Arret->getSuiv()->getArret()->getY() - Arret->getArret()->getY()) / (Arret->getSuiv()->getArret()->getX() - Arret->getArret()->getX());
            b = Arret->getArret()->getY() - Arret->getArret()->getX()*coeff;
            y = coeff*(tram->getTramway()->getX()+tram->getTramway()->getVitesse()) + b;
            x = (y-b)/coeff;
        }
    }
    else
    {
        cout<< "ici"<<endl;
        if(Arret->getPrec()->getArret()->getX() - Arret->getArret()->getX() == 0)
        {
            y = tram->getTramway()->getY() - tram->getTramway()->getVitesse();
            x = tram->getTramway()->getX();
        }
        else if(Arret->getPrec()->getArret()->getY() - Arret->getArret()->getY() == 0)
        {
            x = tram->getTramway()->getX() - tram->getTramway()->getVitesse();
            y = tram->getTramway()->getY();
        }
        else
        {
            coeff = (Arret->getPrec()->getArret()->getY() - Arret->getArret()->getY()) / (Arret->getPrec()->getArret()->getX() - Arret->getArret()->getX());
            b = Arret->getArret()->getY() - Arret->getArret()->getX()*coeff;
            y = coeff*(tram->getTramway()->getX()-tram->getTramway()->getVitesse()) + b;
            x = (y-b)/coeff;
        }
    }
        cout<< x << " "<< y <<endl;
        Coord.push_back(x);
        Coord.push_back(y);
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
            if(ligne->arretTram(x,y))
            {
                c->actuelArret = ligne->arretTram(x,y);
                c->getTramway()->setonMarche(false);
                c->getTramway()->setTempsArret(10);
            }
            Trajectoire(c->actuelArret, c,coord);
            c->getTramway()->setPosition(coord[0], coord[1]);
            coord.clear();
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
