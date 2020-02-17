#include <iostream>
#include "Tramway.cpp"
#include "Ligne.cpp"
#include "Station.cpp"
#include "graphics.h"

using namespace std;

int main() {
    Tramway tram{};
    cout << tram.getVitesseActuelle();
    return 0;
}
