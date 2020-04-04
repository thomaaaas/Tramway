#include "ChainonTram.h"

ChainonTram::ChainonTram(Tramway *tram) : d_tramway{tram}, suiv{nullptr}{}

Tramway* ChainonTram::getTramway(){     //Retourne le pointeur du tramway concerné
    return d_tramway;
}


