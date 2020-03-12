#include "Arret.h"
#include "graphics.h"

Arret::Arret(int x, int y):
    d_X{x},
    d_Y{y}
{}

Arret::getX() const{
    return d_X;
}

Arret::getY() const{
    return d_Y;
}

void Arret::setPosition(int x, int y){
    d_X = x;
    d_Y = y;
}

void Arret::affiche(){
    bar(d_X, d_Y, d_X +30, d_Y +30);
}
