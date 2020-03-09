#include "ChainonTram.h"
#include "Tramway.h"

ChainonTram::ChainonTram(Tramway &tram) : d_tramway{tram}, suiv{nullptr}
{
    //ctor
}

Tramway ChainonTram::getTramway() const{
    return d_tramway;
}
