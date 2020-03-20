#include "Arret.h"
#include "graphics.h"

Arret::Arret(double x, double y):
    d_X{x},
    d_Y{y}
{}

double Arret::getX() const{
    return d_X;
}

double Arret::getY() const{
    return d_Y;
}

void Arret::setPosition(double x, double y){
    d_X = x;
    d_Y = y;
}

void Arret::affiche(){
    bar(d_X-15, d_Y-15, d_X +15, d_Y +15);
}
