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

void ListeTram::affiche(){       //affiche le tramway point� sur l'interface graphique
    ChainonTram *c = t;
    while(c){
        c->getTramway()->affiche();
        c = c->suiv;
    }
}

void ListeTram::effacer(){      //efface le tramway point� de l'interface graphique
    ChainonTram *c = t;
    while(c){
        c->getTramway()->efface();
        c = c->suiv;
    }
}

void ListeTram::Trajectoire (ChainonArret *Arret, ChainonTram *tram, vector<double> &Coord)            //efface le tramway point� de l'interface graphique
{
    double dt, d, a, b, x, y;
    if(!Arret->getSuiv()){
        tram->getTramway()->setSens(false);     //efface le tramway point� de l'interface graphique
    }
    if(!Arret->getPrec()){
        tram->getTramway()->setSens(true);      //S'il n'y a pas d'arr�t avant, change le sens
    }
    if(tram->getTramway()->getSens()){      //Si le sens est "true", donc pour l'aller
        //aller
        dt = sqrt(pow(tram->getTramway()->getX() - Arret->getArret()->getX(),2) + pow(tram->getTramway()->getY()-Arret->getArret()->getY(),2));
        d = sqrt(pow(Arret->getSuiv()->getArret()->getX()-Arret->getArret()->getX(),2) + pow(Arret->getSuiv()->getArret()->getY()-Arret->getArret()->getY(),2));
        dt+= tram->getTramway()->getVitesse();      // On ajoute la vitesse � la distance pour le faire avancer d'un pas
        a = dt/d;
        b = 1-a;
        x = a*Arret->getSuiv()->getArret()->getX() + b*Arret->getArret()->getX();       //calcul des nouvelles coordonn�es
        y = a*Arret->getSuiv()->getArret()->getY() + b*Arret->getArret()->getY();
    }
    else{
        //retour
        dt = sqrt(pow(tram->getTramway()->getX() - Arret->getArret()->getX(),2) + pow(tram->getTramway()->getY()-Arret->getArret()->getY(),2));
        d = sqrt(pow(Arret->getPrec()->getArret()->getX()-Arret->getArret()->getX(),2) + pow(Arret->getPrec()->getArret()->getY()-Arret->getArret()->getY(),2));
        dt+= tram->getTramway()->getVitesse();       // On ajoute la vitesse � la distance pour le faire avancer d'un pas
        a = dt/d;
        b = 1-a;
        x = a*Arret->getPrec()->getArret()->getX() + b*Arret->getArret()->getX();       //calcul des nouvelles coordonn�es
        y = a*Arret->getPrec()->getArret()->getY() + b*Arret->getArret()->getY();
    }
    Coord.push_back(x);     //ajout des coordonn�es dans le tableau
    Coord.push_back(y);
}

int ListeTram::taille (Ligne *ligne)        //retourne la taille de la liste cha�n�e
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
    if(taille(ligne) == 1 )         //S'il n'y a qu'un tram sur la ligne, pas besoin de se soucier de la distance entre les trams
    {
        return true;
    }
    if(tram->suiv == nullptr)       //S'il n'y a plus de tram devant, le tramway devient la t�te
    {
        c = t;
    }
    else
    {
        c = tram->suiv;
    }
    double d = sqrt(pow(tram->getTramway()->getX() - c->getTramway()->getX(),2) + pow(tram->getTramway()->getY()-c->getTramway()->getY(),2));

            if(taille(ligne) == 2)          // S'il n'y a que 2 trams sur la ligne
            {
                if(tram->getTramway()->getSens() == c->getTramway()->getSens())     // S'il sont dans le m�me sens
                {
                    if(tram->getTramway()->getVitesse() > c->getTramway()->getVitesse() && d < tram->getTramway()->getDistanceMin() )
                    {
                        return false;       // renvoie false
                    }
                    else
                    {
                        return true;        // Sinon renvoie true
                    }
                }
            }
            else       // S'il y a plus que 2 trams sur la ligne
            {
                    if(tram->getTramway()->getSens() == c->getTramway()->getSens())     // Dans le m�me sens
                    {
                        if (d < tram->getTramway()->getDistanceMin())       // Si deux trams ne respectent pas la distance minimale
                        {
                            return false;       //renvoie false
                        }
                    }

            }
    return true;            // Sinon renvoie true
}

void ListeTram::avancer(Ligne *ligne){              // Fait avancer les trams
    ChainonTram *c = t;
    vector<double> coord;
    while(c){
        if (c->getTramway()->getonMarche()){        // Si le tramway est en marche
            if(distance(c,ligne)){                  // S'il respecte la distance
                if(ligne->arretTram(c) ){           // S'il arrive � un arr�t
                    c->actuelArret = ligne->arretTram(c);       // On change l'arr�t actuel dans ses variables
                    c->getTramway()->setonMarche(false);        // L'arr�te durant un certain temps
                    c->getTramway()->setTempsArret(10);
                }
            Trajectoire(c->actuelArret, c,coord);
            c->getTramway()->setPosition(coord[0], coord[1]);
            coord.clear();
            }
        }
        else{       // Si le tramway est arr�t�
            if(c->getTramway()->getTempsArret() > 0){
                double tmps = c->getTramway()->getTempsArret();     // On d�cr�mente le temps d'arr�t jusqu'� 0
                c->getTramway()->setTempsArret(--tmps);
            }
            else{
                c->getTramway()->setonMarche(true);     // Lorsque le temps d'arr�t arrive � 0, le remet en marche
            }
        }
        c = c->suiv;
    }
}


void ListeTram::insererTramway(Tramway *tramway)         //Ins�re un tramway dans la liste
{
	ChainonTram *nc=new ChainonTram(tramway);
	if (t==nullptr){    // S'il n'y a pas de t�te, il devient la t�te.
		t=nc;
		return;
	}
	ChainonTram *precC=nullptr,*c=t;
	while(c){
		precC=c;
		c=c->suiv;
	}
	precC->suiv=nc;         // S'il n'y a pas de t�te, il devient la t�te.
	nc->suiv=c;
}
