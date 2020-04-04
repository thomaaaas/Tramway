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

double Tramway::getDistanceMin() const {         //retourne la distance minimale du tramway
    return d_distanceMin;
}

double Tramway::getVitesse() const {             //retourne la vitesse du tramway
    return d_vitesse;
}

double Tramway::getX() const{                    //retourne la coordonnee x du tramway
    return d_X;
}

double Tramway::getY() const{                    //retourne la coordonnee y du tramway
    return d_Y;
}

bool Tramway::getSens() const{                   //  retourne le sens du tramway
    return d_sens;
}

double Tramway::getTempsArret() const{           //retourne le temps d'arrêt du tramway
    return tempsArret;
}

bool Tramway::getonMarche () const               //retourne true si le tramway doit avancer, sinon false
{
    return onMarche;
}


void Tramway::setTempsArret( double temps){      // Définit le temps d'arrêt
    tempsArret = temps;
}

void Tramway::setVitesse(double valeur){         // Définit la vitesse
    d_vitesse = valeur;
}

void Tramway::setDistanceMin(double valeur) {    //Définit la distance minimale
    d_distanceMin = valeur;
}

void Tramway::setPosition(double x, double y){   //Définit la position du tramway
    d_X = x;
    d_Y = y;
}

void Tramway::setSens(bool sens){                //Définit le sens
    d_sens = sens;
}
void Tramway::setonMarche(bool marche)           //Définit si le tramway doit se mettre en marche (true) ou non
{
    onMarche = marche;
}


void Tramway::affiche(){                         //Affiche le tramway, ici carré de 20 pixels, rouge si sens=0, vert sinon
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

void Tramway::efface(){                          //Efface le tramway
    setcolor(WHITE);
    bar(d_X-10, d_Y-10, d_X+10, d_Y+10);
    setcolor(BLUE);
}
