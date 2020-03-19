#include <iostream>
#include <fstream>
#include "Ligne.h"
#include "graphics.h"
#include "Arret.h"
#include "Tramway.h"
#include <windows.h>
#include <stddef.h>
#include <stdio.h>
#include <math.h>
#include <vector>
#include "ChainonArret.h"
#include "ListeArret.h"
#include "ListeTram.h"
#include "ChainonTram.h"

using namespace std;

struct liste{
    ListeArret *arret;
    ListeTram *tramway;
    Ligne *ligne;
};

void lectureFichier(string const &nomFichier, vector <liste> &dataListe){
    string temporaire;
    char c;
    bool sens;
    double vitesse, distanceMin;
    int nbLignes, nbArret, nbTram;
    double  x, y;
    ifstream donnees;

    donnees.open(nomFichier);
    if(!donnees.is_open()){
        cout << "Le fichier n'a pas pu s'ouvrir." << endl;
        return;
    }
    donnees >> temporaire >> nbLignes >> temporaire;
    //cout << "nbLigne : " << nbLignes << endl;
    dataListe.resize(nbLignes);

    for(int i = 0; i < nbLignes; ++i){
        //cout << "----------------------------" << endl;
        ListeArret *listeArret = new ListeArret{};
        ListeTram *listeTramway = new ListeTram{};

        //Arrets
        donnees >> nbArret >> temporaire;
        //cout << nbArret << endl;
        for(int i = 0; i < nbArret; ++i){
            donnees >> c >> x >> c >> y >>  c;
            //cout << x << " " << y << endl;
            Arret *arret = new Arret{x,y};
            listeArret->insererArret(arret);
        }

        //Tram
        donnees >> temporaire >> nbTram >> temporaire;
       // cout << nbTram << endl;
        for(int i = 0; i < nbTram; ++i){
            donnees >> c >> vitesse >> c >> distanceMin >> c >> x >> c >> y >> c >> sens >> c;
            //cout << vitesse << " " << distanceMin << " " << x << " " << y << " " << sens << endl;
            Tramway *tramway = new Tramway{vitesse,distanceMin,x,y,sens};
            listeTramway->insererTramway(tramway);
        }
        donnees >> temporaire;
        Ligne *ligne = new Ligne(listeArret);

        dataListe[i].arret = listeArret;
        dataListe[i].tramway = listeTramway;
        dataListe[i].ligne = ligne;
    }
}

void affichage(vector<liste> &dataListe, int i){
        dataListe[i].arret -> affiche();
        dataListe[i].ligne -> affiche();
        dataListe[i].tramway -> affiche();
}

int main()
{
    vector<liste> dataListe;

    lectureFichier("donneesTram.txt", dataListe);

    opengraphsize(800,800);
    setbkcolor(WHITE);
    setcolor(BLUE);
    cleardevice();

    while(true){
        for(int i = 0; i < dataListe.size(); ++i){
            dataListe[i].tramway->effacer();
            dataListe[i].tramway->avancer(dataListe[i].ligne);
            affichage(dataListe,i);
        }
        Sleep(20);
    }

    getch();
    closegraph();
    return 0;
}
