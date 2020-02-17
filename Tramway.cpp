#include "Tramway.h"

Tramway::Tramway():
    d_distanceMin{0.0},
    d_vitesseActuelle{0.0},
    d_vitesseMax{0.0}
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