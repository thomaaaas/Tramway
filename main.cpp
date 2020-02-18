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
    Station station1{0,0};
    Station station2{400,400};
    Station station3{800,800};

    Ligne ligne{station1.getX(),station1.getY(),station3.getX(),station3.getY()};


    opengraphsize(900,900);
    setbkcolor(WHITE);
    setcolor(BLUE);

    while(tram.getX()<800 && tram.getY() < 800){
        cleardevice();
        setcolor(BLUE);

        tram.setPosition(tram.getX()+tram.getVitesseMax(), tram.getY()+tram.getVitesseMax());

        tram.affiche();
        ligne.affiche();
        station1.affiche();
        station2.affiche();
        station3.affiche();

        if(tram.getX() == 400 && tram.getY() == 400){
            setcolor(RED);
            cleardevice();
            tram.affiche();
            ligne.affiche();
            station1.affiche();
            station2.affiche();
            station3.affiche();
            Sleep(2000);
        }
        Sleep(10);
    }
    getch();
    closegraph();
    return 0;
}
