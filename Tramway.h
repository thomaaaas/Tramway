#ifndef TRAMWAY_TRAMWAY_H
#define TRAMWAY_TRAMWAY_H
class Tramway{
public:
    Tramway();
    Tramway(double vitesse, double distanceMin, int positionX, int positionY);
    double getVitesse() const;
    double getDistanceMin() const;
    int getX() const;
    int getY() const;
    void setVitesse(double valeur);
    void setDistanceMin(double valeur);
    void setPosition(int x, int y);
    void affiche();
    void efface();
private:
    double d_vitesse, d_distanceMin;
    int d_X, d_Y;
};
#endif //TRAMWAY_TRAMWAY_H
