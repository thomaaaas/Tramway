#include "Ligne.h"
#include "graphics.h"

Ligne::Ligne(int Xdebut, int YDebut, int XFin, int YFin){
    d_XDebut = Xdebut;
    d_YDebut = YDebut;
    d_XFin = XFin;
    d_YFin = YFin;
}

int Ligne::getXdebut() const{
    return d_XDebut;
}

int Ligne::getYdebut() const{
    return d_YDebut;
}

int Ligne::getXfin() const{
    return d_XFin;
}

int Ligne::getYfin() const{
    return d_YFin;
}

void Ligne::affiche(){
    line(d_XDebut, d_YDebut, d_XFin, d_YFin);
}
