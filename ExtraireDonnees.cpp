#include <iostream>
#include <fstream>
#include "Ligne.h"
#include "graphics.h"
#include "Station.h"
#include "Tramway.h"
#include <windows.h>
#include <stddef.h>
#include <stdio.h>
#include <math.h>
#include "graphics.h"

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
    Ligne *tabLigne[nbLignes];
    //Lignes
    for(int i = 0; i < nbLignes; ++i){
        donnes >> c >> xDebut >> c >> yDebut >>  c;
        cout << '(' << xDebut << ';' << yDebut << ')' << endl;
        donnes >> c >> xFin >> c >> yFin >>  c;
        cout << '(' << xFin << ';' << yFin << ')' << endl;
        tabLigne[i]= new Ligne(xDebut,yDebut,xFin,yFin);
        //Fonction de Louis pour créer une Ligne
    }
    //Stations
    donnes >> temporaire >> nbStation;
    cout << nbStation << endl;
    donnes >> temporaire;
    Station *tabStation[nbStation];
    for(int i = 0; i < nbStation; ++i){
        donnes >> c >> x >> c >> y >>  c;
        cout << '(' << x << ';' << y << ')' << endl;
        tabStation[i] = new Station(x,y);
        //Fonction de Louis pour créer une Station
    }
    //Tram
    donnes >> temporaire >> nbTram;
    cout << nbTram << endl;
    donnes >> temporaire;
    Tramway *tabTramway[nbTram];
    for(int i = 0; i < nbTram; ++i){
        donnes >> c >> x >> c >> y >>  c;
        cout << '(' << x << ';' << y << ')' << endl;
        tabTramway[i] = new Tramway(0,0,x,y);
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
