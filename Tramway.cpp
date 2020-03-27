#include "Tramway.h"
#include "graphics.h"

Tramway::Tramway():
    d_distanceMin{0.0},
    d_vitesse{0.0}
{}

Tramway::Tramway(double vitesse, double distanceMin, double x, double y, bool sens):
    d_vitesse{vitesse},
    d_distanceMin{distanceMin},
    d_X{x},
    d_Y{y},
    d_sens{sens},
    tempsArret{0.0},
    onMarche(true)
{}

double Tramway::getDistanceMin() const {
    return d_distanceMin;
}

double Tramway::getVitesse() const {
    return d_vitesse;
}

double Tramway::getX() const{
    return d_X;
}

double Tramway::getY() const{
    return d_Y;
}

bool Tramway::getSens() const{
    return d_sens;
}

double Tramway::getTempsArret() const{
    return tempsArret;
}

bool Tramway::getonMarche () const
{
    return onMarche;
}


void Tramway::setTempsArret( double temps){
    tempsArret = temps;
}

void Tramway::setVitesse(double valeur){
    d_vitesse = valeur;
}

void Tramway::setDistanceMin(double valeur) {
    d_distanceMin = valeur;
}

void Tramway::setPosition(double x, double y){
    d_X = x;
    d_Y = y;
}

void Tramway::setSens(bool sens){
    d_sens = sens;
}
void Tramway::setonMarche(bool marche)
{
    onMarche = marche;
}


void Tramway::affiche(){
    if (d_sens == 0)
    {
        setcolor(RED);
    }
    else
    {
        setcolor(GREEN);
    }
    bar(d_X-10, d_Y-10, d_X+10, d_Y+10);
    setcolor(BLUE);
}

void Tramway::efface(){
    setcolor(WHITE);
    bar(d_X-10, d_Y-10, d_X+10, d_Y+10);
    setcolor(BLUE);
}
