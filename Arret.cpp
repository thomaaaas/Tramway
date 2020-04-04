#include "Arret.h"
#include "graphics.h"

Arret::Arret(double x, double y):               // Constructeur avec les coordonnées
    d_X{x},
    d_Y{y}
{}

double Arret::getX() const{                     //Obtenir la composante x
    return d_X;
}

double Arret::getY() const{                     //Obtenir la composante y
    return d_Y;
}

void Arret::setPosition(double x, double y){    //Définir la position de l'arret
    d_X = x;
    d_Y = y;
}

void Arret::affiche(){                          //Afficher l'arrêt : ici carré de 30 sur 30
    bar(d_X-15, d_Y-15, d_X +15, d_Y +15);
}
