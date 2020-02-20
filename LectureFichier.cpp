#include <iostream>
#include <string>
#include <fstream>
using namespace std;



int nbTram(ifstream donnesTram){
    string temporaire;
    int nombre;
    donnesTram >> temporaire >> nombre;
    return nombre;
}


int main()
{
    int nombre;
    ifstream donnes;
    donnes.open("donnesTram.txt");
    string temporaire;
    cout << "Debut de lecture" << endl;
    if (!donnes.is_open()) return 1;

    cout << nbTram(donnes);
    cout << "Fin de lecture" << endl;
    donnes.close();
}
