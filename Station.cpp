#include "Station.h"

Station::Station(){}

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
