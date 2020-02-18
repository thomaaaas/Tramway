//
// Created by norma on 29/01/2020.
//

#ifndef TRAMWAY_TRAMWAY_H
#define TRAMWAY_TRAMWAY_H
class Tramway{
public:
    Tramway();
    double getVitesseMax() const;
    double getVitesseActuelle() const;
    double getDistanceMin() const;
    void setVitesseMax(double valeur);
    void setVitesseActuelle(double valeur);
    void setDistanceMin(double valeur);
private:
    double d_vitesseMax, d_vitesseActuelle, d_distanceMin;
};
#endif //TRAMWAY_TRAMWAY_H
