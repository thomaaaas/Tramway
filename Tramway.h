#ifndef TRAMWAY_TRAMWAY_H
#define TRAMWAY_TRAMWAY_H
class Tramway{
public:
    Tramway();
    Tramway(double vitesseMax, double vitesseActuelle, double distanceMin, int positionX, int positionY);
    double getVitesseMax() const;
    double getVitesseActuelle() const;
    double getDistanceMin() const;
    int getX() const;
    int getY() const;
    void setVitesseMax(double valeur);
    void setVitesseActuelle(double valeur);
    void setDistanceMin(double valeur);
    void setPosition(int x, int y);
private:
    double d_vitesseMax, d_vitesseActuelle, d_distanceMin;
    int d_X, d_Y;
};
#endif //TRAMWAY_TRAMWAY_H
