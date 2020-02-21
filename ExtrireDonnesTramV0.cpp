#include <iostream>
#include <fstream>

using namespace std;

void lectureFichier(string nomFichier){
    string temporaire, nom = nomFichier;
    char c;
    bool sens;
    int xDebut, yDebut, xFin, yFin, x, y;
    int information, nbLignes, nbStation, nbTram;
    ifstream donnes;
    donnes.open(nomFichier);
    if(!donnes.is_open()){
        cout << "Le fichier n'a pas pu s'ouvrir." << endl;
        return;
    }

    donnes >> temporaire >> nbLignes;
    cout << nbLignes << endl;
    donnes >> temporaire;
    //Lignes
    for(int i = 0; i < nbLignes; ++i){
        donnes >> c >> xDebut >> c >> yDebut >>  c;
        cout << '(' << xDebut << ';' << yDebut << ')' << endl;
        donnes >> c >> xFin >> c >> yFin >>  c;
        cout << '(' << xFin << ';' << yFin << ')' << endl;
        //Fonction de Louis pour créer une Ligne
    }
    //Stations
    donnes >> temporaire >> nbStation;
    cout << nbStation << endl;
    donnes >> temporaire;
    for(int i = 0; i < nbStation; ++i){
        donnes >> c >> x >> c >> y >>  c;
        cout << '(' << x << ';' << y << ')' << endl;
        //Fonction de Louis pour créer une Station
    }
    //Tram
    donnes >> temporaire >> nbTram;
    cout << nbTram << endl;
    donnes >> temporaire;
    for(int i = 0; i < nbTram; ++i){
        donnes >> c >> x >> c >> y >>  c;
        cout << '(' << x << ';' << y << ')' << endl;
        //Fonction de Louis pour créer un Tram
    }
    donnes >> temporaire;
    for(int i = 0; i < nbTram; ++i){
        donnes >> temporaire;
        sens = temporaire == "Aller";
        cout << sens << endl;
        //Fonction de Louis pour créer un Tram
    }
}

int main(){
    lectureFichier("donnesTram.txt");
}
