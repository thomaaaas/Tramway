#ifndef LISTETRAM_H
#define LISTETRAM_H
#include "Tramway.h"
#include "ChainonTram.h"

class ListeTram
{
    friend class ChainonTram;
    public:
        ListeTram();
        ~ListeTram();
        void insererTramway(Tramway &tramway);
        void avancer();
        void affiche();
    private:
        ChainonTram *t;
};

#endif // LISTETRAM_H
