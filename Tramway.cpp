#include "Tramway.h"
#include "graphics.h"

Tramway::Tramway():
    d_distanceMin{0.0},
    d_vitesseActuelle{0.0},
    d_vitesseMax{0.0}
{}

Tramway::Tramway(double vitesseMax, double vitesseActuelle, double distanceMin, int x, int y):
    d_vitesseMax{vitesseMax},
    d_vitesseActuelle{vitesseActuelle},
    d_distanceMin{distanceMin},
    d_X{x},
    d_Y{y}
{}

double Tramway::getDistanceMin() const {
    return d_distanceMin;
}

double Tramway::getVitesseMax() const {
    return d_vitesseMax;
}

double Tramway::getVitesseActuelle() const {
    return d_vitesseActuelle;
}

int Tramway::getX() const{
    return d_X;
}

int Tramway::getY() const{
    return d_Y;
}

void Tramway::setVitesseMax(double valeur){
    d_vitesseMax = valeur;
}

void Tramway::setDistanceMin(double valeur) {
    d_distanceMin = valeur;
}

void Tramway::setVitesseActuelle(double valeur){
    d_vitesseActuelle = valeur;
}

void Tramway::setPosition(int x, int y){
    d_X = x;
    d_Y = y;
}

void Tramway::affiche(){
    bar(d_X, d_Y, d_X+20, d_Y+20);
}
