#ifndef LISTETRAM_H
#define LISTETRAM_H
#include "Tramway.h"
#include "ChainonTram.h"
#include "Ligne.h"

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
        void Trajectoire (ChainonArret *Arret, ChainonTram *tram, vector<double> &coord);
        bool distance (ChainonTram *tram);
    private:
        ChainonTram *t;
};

#endif // LISTETRAM_H
