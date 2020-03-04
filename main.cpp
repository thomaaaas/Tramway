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
#include "ChainonArret.h"
#include "ListeArret.h"

using namespace std;

void lectureFichier(string const &nomFichier, vector<Ligne> &tabLigne, vector<Station> &tabStation, vector<Tramway> &tabTramway){
    string temporaire;
    char c;
    bool sens;
    int xDebut, yDebut, xFin, yFin, x, y;
    int nbLignes, nbStation, nbTram;
    ifstream donnees;
    donnees.open(nomFichier);
    if(!donnees.is_open()){
        cout << "Le fichier n'a pas pu s'ouvrir." << endl;
        return;
    }

    donnees >> temporaire >> nbLignes;
    cout << nbLignes << endl;
    donnees >> temporaire;
    //Lignes
    for(int i = 0; i < nbLignes; ++i){
        donnees >> c >> xDebut >> c >> yDebut >>  c;
        cout << '(' << xDebut << ';' << yDebut << ')' << endl;
        donnees >> c >> xFin >> c >> yFin >>  c;
        cout << '(' << xFin << ';' << yFin << ')' << endl;
        tabLigne.push_back(Ligne(xDebut,yDebut,xFin,yFin));
    }
    //Stations
    donnees >> temporaire >> nbStation;
    cout << nbStation << endl;
    donnees >> temporaire;
    for(int i = 0; i < nbStation; ++i){
        donnees >> c >> x >> c >> y >>  c;
        cout << '(' << x << ';' << y << ')' << endl;
        tabStation.push_back(Station(x,y));
    }
    //Tram
    donnees >> temporaire >> nbTram;
    cout << nbTram << endl;
    donnees >> temporaire;
    for(int i = 0; i < nbTram; ++i){
        donnees >> c >> x >> c >> y >>  c;
        cout << '(' << x << ';' << y << ')' << endl;
        tabTramway.push_back(Tramway(0,0,x,y));
    }
    donnees >> temporaire;
    for(int i = 0; i < nbTram; ++i){
        donnees >> temporaire;
        sens = temporaire == "Aller";
        cout << sens << endl;
    }
}

void affichage(vector<Ligne> &tabLigne, vector<Station> &tabStation, vector<Tramway> &tabTramway){
    for(int i = 0; i < tabStation.size(); ++i){
        tabStation[i].affiche();
    }


    for(int i = 0; i < tabLigne.size(); ++i){
        tabLigne[i].affiche();
    }

    for(int i = 0; i < tabTramway.size(); ++i){
        tabTramway[i].affiche();
    }
}

int main()
{
    vector<Ligne> tabLigne;
    vector<Station> tabStation;
    vector<Tramway> tabTramway;
    lectureFichier("donneesTram.txt", tabLigne, tabStation, tabTramway);
    ListeArret arret{};

    for(int i = 0; i < tabStation.size(); ++i){
        arret.insererArret(tabStation[i]);
    }
    arret.affiche();
    /*
    ca avance bien
    opengraphsize(800,800);
    setbkcolor(WHITE);
    setcolor(BLUE);
    cleardevice();
    affichage(tabLigne, tabStation, tabTramway);

    while(true){
        for(int i = 0; i < tabTramway.size(); ++i){
            tabTramway[i].efface();
            tabTramway[i].setPosition(tabTramway[i].getX(), tabTramway[i].getY()+1);
            affichage(tabLigne, tabStation, tabTramway);
        }
    Sleep(10);
    }

    getch();
    closegraph();
    */
    return 0;
}
