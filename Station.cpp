#include "Station.h"
#include "graphics.h"

Station::Station(int x, int y):
    d_X{x},
    d_Y{y}
{}

Station::getX() const{
    return d_X;
}

Station::getY() const{
    return d_Y;
}

void Station::setPosition(int x, int y){
    d_X = x;
    d_Y = y;
}

void Station::affiche(){
    bar(d_X, d_Y, d_X +30, d_Y +30);
}
