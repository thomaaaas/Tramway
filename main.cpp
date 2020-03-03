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
        //Fonction de Louis pour creer une Ligne
    }
    //Stations
    donnes >> temporaire >> nbStation;
    cout << nbStation << endl;
    donnes >> temporaire;
    for(int i = 0; i < nbStation; ++i){
        donnes >> c >> x >> c >> y >>  c;
        cout << '(' << x << ';' << y << ')' << endl;
        tabStation.push_back(Station(x,y));
        //Fonction de Louis pour creer une Station
    }
    //Tram
    donnes >> temporaire >> nbTram;
    cout << nbTram << endl;
    donnes >> temporaire;
    for(int i = 0; i < nbTram; ++i){
        donnes >> c >> x >> c >> y >>  c;
        cout << '(' << x << ';' << y << ')' << endl;
        tabTramway.push_back(Tramway(0,0,x,y));
        //Fonction de Louis pour creer un Tram
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
/*    Tramway tram{2.0,12.0,0,0};
    Station station1{0,0};
    Station station2{400,400};
    Station station3{700,700};

    Ligne ligne{station1.getX(),station1.getY(),station3.getX(),station3.getY()};

    opengraphsize(800,800);
    setbkcolor(WHITE);
    setcolor(BLUE);
    cleardevice();

    ligne.affiche();
    station1.affiche();
    station2.affiche();
    station3.affiche();

    while(true){
        while(tram.getX() <= station3.getX() && tram.getY() <= station3.getY()){

            tram.efface();
            tram.setPosition(tram.getX()+tram.getVitesse(), tram.getY()+tram.getVitesse());
            tram.affiche();

            ligne.affiche();
            station1.affiche();
            station2.affiche();
            station3.affiche();

            Sleep(10);
        }
        while(tram.getX() >= station1.getX() && tram.getY() >= station1.getY()){

            tram.efface();
            tram.setPosition(tram.getX()-tram.getVitesse(), tram.getY()-tram.getVitesse());
            tram.affiche();

            ligne.affiche();
            station1.affiche();
            station2.affiche();
            station3.affiche();

            Sleep(10);
        }
    }

    getch();
    closegraph();*/
    return 0;
}
