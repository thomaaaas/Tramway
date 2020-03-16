#ifndef CHAINONTRAM_H
#define CHAINONTRAM_H
#include "Tramway.h"
#include "Arret.h"
#include "ChainonArret.h"

class ChainonTram
{
    friend class ListeTram;
    public:
        Tramway* getTramway();

    private:
        ChainonArret *actuelArret;
        ChainonTram(Tramway *tramway);
        Tramway *d_tramway;
        ChainonTram *suiv;
};

#endif // CHAINONTRAM_H
