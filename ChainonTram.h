#ifndef CHAINONTRAM_H
#define CHAINONTRAM_H
#include "Tramway.h"

class ChainonTram
{
    friend class ListeTram;
    public:
        Tramway getTramway() const;
    private:
        ChainonTram(Tramway &tramway);
        Tramway d_tramway;
        ChainonTram *suiv;
};

#endif // CHAINONTRAM_H
