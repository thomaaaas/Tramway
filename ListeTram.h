#include "Tramway.h"
#include "ChainonTram.h"
#include "Ligne.h"
#include <cmath>
#include <vector>

#ifndef LISTETRAM_H
#define LISTETRAM_H

class ListeTram
{
    friend class ChainonTram;
    public:
        ListeTram();
        ~ListeTram();
        void insererTramway(Tramway *tramway);
        void avancer(Ligne *ligne);
        void affiche();
        void effacer();
        void Trajectoire(ChainonArret *Arret, ChainonTram *tram, std::vector<double> &coord);
        bool distance(ChainonTram *tram, Ligne *ligne);
        int taille(Ligne *ligne);
    private:
        ChainonTram *t;
};

#endif // LISTETRAM_H
