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
#include "ListeTram.h"
#include "ChainonTram.h"

using namespace std;

void lectureFichier(string const &nomFichier, vector<Ligne> &tabLigne, ListeTram &listeTramway, ListeArret &listeArret){
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
    //cout << nbLignes << endl;
    donnees >> temporaire;
    //Lignes
    for(int i = 0; i < nbLignes; ++i){
        donnees >> c >> xDebut >> c >> yDebut >>  c;
        //cout << '(' << xDebut << ';' << yDebut << ')' << endl;
        donnees >> c >> xFin >> c >> yFin >>  c;
        //cout << '(' << xFin << ';' << yFin << ')' << endl;
        //tabLigne.push_back(Ligne(xDebut,yDebut,xFin,yFin));
    }
    //Stations
    donnees >> temporaire >> nbStation;
    //cout << nbStation << endl;
    donnees >> temporaire;
    for(int i = 0; i < nbStation; ++i){
        donnees >> c >> x >> c >> y >>  c;
        //cout << '(' << x << ';' << y << ')' << endl;
        Station station{x,y};
        listeArret.insererArret(station);
    }
    //Tram
    donnees >> temporaire >> nbTram;
    //cout << nbTram << endl;
    donnees >> temporaire;
    for(int i = 0; i < nbTram; ++i){
        donnees >> c >> x >> c >> y >>  c;
        //cout << '(' << x << ';' << y << ')' << endl;
        Tramway tramway{1,1,x,y};
        listeTramway.insererTramway(tramway);
    }
    donnees >> temporaire;
    for(int i = 0; i < nbTram; ++i){
        donnees >> temporaire;
        sens = temporaire == "Aller";
        //cout << sens << endl;
    }
}

void affichage(Ligne &ligne,ListeTram &listeTramway, ListeArret &listeArret){
    ligne.affiche();
    listeArret.affiche();
    listeTramway.affiche();
}

int main()
{
    vector<Ligne> tabLigne;

    ListeArret listeArret{};
    ListeTram listeTramway{};

    lectureFichier("donneesTram.txt", tabLigne, listeTramway, listeArret);
    Ligne ligne{listeArret};

    opengraphsize(800,800);
    setbkcolor(WHITE);
    setcolor(BLUE);
    cleardevice();

    affichage(ligne, listeTramway, listeArret);
    //petit soucis ici
    //listeTramway.avancer();
    /*
    while(true){
        listeTramway.avancer();
        affichage(ligne, listeTramway, listeArret);
        Sleep(10);
    }
    */
    getch();
    closegraph();

    return 0;
}
