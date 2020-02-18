#include <iostream>
#include "Tramway.h"
#include "Ligne.h"
#include "Station.h"
#include "graphics.h"
#include <Windows.h>

using namespace std;

void lectureFichier(const string &nomFichier){

};

int main()
{
    Tramway tram{1.0,5.0,12.0,0,0};
    //Tramway tram2{1.0,5.0,12.0,400,400};
    Station station1{0,0};
    Station station2{400,400};
    Station station3{800,800};

    Ligne ligne{station1.getX(),station1.getY(),station3.getX(),station3.getY()};

    opengraphsize(900,900);
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
            tram.setPosition(tram.getX()+tram.getVitesseMax(), tram.getY()+tram.getVitesseMax());
            tram.affiche();

            ligne.affiche();
            station1.affiche();
            station2.affiche();
            station3.affiche();

            Sleep(05);
        }
        while(tram.getX() >= station1.getX() && tram.getY() >= station1.getY()){

            tram.efface();
            tram.setPosition(tram.getX()-tram.getVitesseMax(), tram.getY()-tram.getVitesseMax());
            tram.affiche();

            ligne.affiche();
            station1.affiche();
            station2.affiche();
            station3.affiche();
            Sleep(05);
        }
    }

    getch();
    closegraph();
    return 0;
}
