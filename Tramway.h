#ifndef TRAMWAY_TRAMWAY_H
#define TRAMWAY_TRAMWAY_H
class Tramway{
public:
    Tramway();
    Tramway(double vitesse, double distanceMin, int positionX, int positionY, bool sens);
    double getVitesse() const;
    double getDistanceMin() const;
    int getX() const;
    int getY() const;
    bool getSens() const;
    void setVitesse(double valeur);
    void setDistanceMin(double valeur);
    void setPosition(int x, int y);
    void setSens(bool sens);
    void affiche();
    void efface();
private:
    double d_vitesse, d_distanceMin;
    int d_X, d_Y;
    bool d_sens;
};
#endif //TRAMWAY_TRAMWAY_H
