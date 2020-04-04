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
    donnees >> temporaire >> nbLignes >> temporaire;    // Lecture du nombre de lignes à créer
    dataListe.resize(nbLignes);

    for(int i = 0; i < nbLignes; ++i){
        ListeArret *listeArret = new ListeArret{};
        ListeTram *listeTramway = new ListeTram{};

        donnees >> nbArret >> temporaire;               //Lecture du nombre d'arrêts à créer

        for(int i = 0; i < nbArret; ++i){
            donnees >> c >> x >> c >> y >>  c;          //Lecture des coordonnées des arrêts
            Arret *arret = new Arret{x,y};              // Création des arrêts
            listeArret->insererArret(arret);            //Insertion des arrêts
        }


        donnees >> temporaire >> nbTram >> temporaire;  // Lecture et création des trams
        for(int i = 0; i < nbTram; ++i){
            donnees >> c >> vitesse >> c >> distanceMin >> c >> x >> c >> y >> c >> sens >> c;
            Tramway *tramway = new Tramway{vitesse,distanceMin,x,y,sens};
            listeTramway->insererTramway(tramway);
        }
        donnees >> temporaire;
        Ligne *ligne = new Ligne(listeArret);           // Création des lignes


        dataListe[i].arret = listeArret;                // On stock tout dans un tableau
        dataListe[i].tramway = listeTramway;
        dataListe[i].ligne = ligne;
    }
}

void affichage(vector<liste> &dataListe, int i){        // On affiche le tableau ci-dessus, donc toute notre structure
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
