#include "Tramway.h"
#include "ChainonArret.h"

#ifndef CHAINONTRAM_H
#define CHAINONTRAM_H

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
