#ifndef TRAMWAY_LIGNE_H
#define TRAMWAY_LIGNE_H
class Ligne{
public:
    Ligne(int Xdebut, int YDebut, int XFin, int YFin);
    int getXdebut() const;
    int getYdebut() const;
    int getXfin() const;
    int getYfin() const;
    void affiche();
private:
    int d_XDebut, d_YDebut, d_XFin, d_YFin;
};
#endif //TRAMWAY_LIGNE_H
