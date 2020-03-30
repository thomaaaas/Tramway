#include "ChainonTram.h"
#include "Tramway.h"
#include<iostream>
#include "ChainonArret.h"

using namespace std;

ChainonTram::ChainonTram(Tramway *tram) : d_tramway{tram}, suiv{nullptr}
{

}

Tramway* ChainonTram::getTramway(){
    return d_tramway;
}


