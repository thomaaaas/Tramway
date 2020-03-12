#include<vector>
#ifndef TRAMWAY_ARRET_H
#define TRAMWAY_ARRET_H
class Arret{
public:
    Arret(int x, int y);
    int getX() const;
    int getY() const;
    void setPosition(int x, int y);
    void affiche();
private:
    int d_X, d_Y;
};
#endif //TRAMWAY_ARRET_H
