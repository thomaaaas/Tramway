#ifndef TRAMWAY_TRAMWAY_H
#define TRAMWAY_TRAMWAY_H
class Tramway{
public:
    Tramway();
    Tramway(double vitesse, double distanceMin, double positionX, double positionY, bool sens);
    double getVitesse() const;
    double getDistanceMin() const;
    double getX() const;
    double getY() const;
    bool getSens() const;
    bool getonMarche () const;
    double getTempsArret() const;
    void setVitesse(double valeur);
    void setTempsArret( double temps);
    void setDistanceMin(double valeur);
    void setPosition(double x, double y);
    void setSens(bool sens);
    void setonMarche (bool marche);
    void affiche();
    void efface();
private:
    double d_vitesse, d_distanceMin;
    double d_X, d_Y;
    bool d_sens;
    double tempsArret;
    bool onMarche;
};
#endif //TRAMWAY_TRAMWAY_H
