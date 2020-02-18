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
    Ligne ligne{0,0,800,800};
    Station station{400,400};

    opengraphsize(900,900);
    setbkcolor(WHITE);
    setcolor(BLUE);

    while(tram.getX()<900 && tram.getY() < 900){
        cleardevice();
        setcolor(BLUE);

        tram.setPosition(tram.getX()+tram.getVitesseMax(), tram.getY()+tram.getVitesseMax());

        tram.affiche();
        ligne.affiche();
        station.affiche();

        if(tram.getX() == 400 && tram.getY() == 400){
            setcolor(RED);
            cleardevice();
            tram.affiche();
            ligne.affiche();
            station.affiche();
            Sleep(2000);
        }
        Sleep(10);
    }

    closegraph();
    return 0;
}
