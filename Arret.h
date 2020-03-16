#include<vector>
#ifndef TRAMWAY_ARRET_H
#define TRAMWAY_ARRET_H
class Arret{
public:
    Arret(double x, double y);
    double getX() const;
    double getY() const;
    void setPosition(double x, double y);
    void affiche();
private:
    double d_X, d_Y;
};
#endif //TRAMWAY_ARRET_H
