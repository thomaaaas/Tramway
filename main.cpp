#include <iostream>
#include "Tramway.cpp"
#include "Ligne.cpp"
#include "Station.cpp"
#include "graphics.h"

using namespace std;

int main() {
    Tramway tram{};
    cout << tram.getVitesseActuelle() << endl;
    tram.setVitesseMax(10.0);
    cout << tram.getVitesseMax();
    return 0;
}
