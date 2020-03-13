#include "Tramway.h"
#include "graphics.h"

Tramway::Tramway():
    d_distanceMin{0.0},
    d_vitesse{0.0}
{}

Tramway::Tramway(double vitesse, double distanceMin, int x, int y, bool sens):
    d_vitesse{vitesse},
    d_distanceMin{distanceMin},
    d_X{x},
    d_Y{y},
    d_sens{sens}
{}

double Tramway::getDistanceMin() const {
    return d_distanceMin;
}

double Tramway::getVitesse() const {
    return d_vitesse;
}

int Tramway::getX() const{
    return d_X;
}

int Tramway::getY() const{
    return d_Y;
}

bool Tramway::getSens() const{
    return d_sens;
}

void Tramway::setVitesse(double valeur){
    d_vitesse = valeur;
}

void Tramway::setDistanceMin(double valeur) {
    d_distanceMin = valeur;
}

void Tramway::setPosition(int x, int y){
    d_X = x;
    d_Y = y;
}

void Tramway::setSens(bool sens){
    d_sens = sens;
}

void Tramway::affiche(){
    setcolor(RED);
    bar(d_X, d_Y, d_X+20, d_Y+20);
    setcolor(BLUE);
}

void Tramway::efface(){
    setcolor(WHITE);
    bar(d_X, d_Y, d_X+20, d_Y+20);
    setcolor(BLUE);
}
