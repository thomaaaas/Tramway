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
#include <vector>

using namespace std;



void lectureFichier(string const &nomFichier, vector<Ligne> &tabLigne, vector<Station> &tabStation, vector<Tramway> &tabTramway){
    string temporaire;
    char c;
    bool sens;
    int xDebut, yDebut, xFin, yFin, x, y;
    int nbLignes, nbStation, nbTram;
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
        tabLigne.push_back(Ligne(xDebut,yDebut,xFin,yFin));
    }
    //Stations
    donnes >> temporaire >> nbStation;
    cout << nbStation << endl;
    donnes >> temporaire;
    for(int i = 0; i < nbStation; ++i){
        donnes >> c >> x >> c >> y >>  c;
        cout << '(' << x << ';' << y << ')' << endl;
        tabStation.push_back(Station(x,y));
    }
    //Tram
    donnes >> temporaire >> nbTram;
    cout << nbTram << endl;
    donnes >> temporaire;
    for(int i = 0; i < nbTram; ++i){
        donnes >> c >> x >> c >> y >>  c;
        cout << '(' << x << ';' << y << ')' << endl;
        tabTramway.push_back(Tramway(0,0,x,y));
    }
    donnes >> temporaire;
    for(int i = 0; i < nbTram; ++i){
        donnes >> temporaire;
        sens = temporaire == "Aller";
        cout << sens << endl;
        //Fonction de Louis pour creer un Tram
    }
}

int main()
{
    vector<Ligne> tabLigne;
    vector<Station> tabStation;
    vector<Tramway> tabTramway;
    lectureFichier("donnesTram.txt", tabLigne, tabStation, tabTramway);

    opengraphsize(800,800);
    setbkcolor(WHITE);
    setcolor(BLUE);
    cleardevice();

    for(int i = 0; i < tabStation.size(); ++i){
        tabStation[i].affiche();
    }

    for(int i = 0; i < tabLigne.size(); ++i){
        tabLigne[i].affiche();
    }

    for(int i = 0; i < tabTramway.size(); ++i){
        tabTramway[i].affiche();
    }

    getch();
    closegraph();
    return 0;
}
