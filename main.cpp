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
    int x, y;

    Tramway tram{1.0,5.0,12.0,0,0};
    Ligne ligne{0,0,800,800};
    Station station{400,400};

    x=tram.getX();
    y=tram.getY();

    opengraphsize(900,900);
    setbkcolor(WHITE);
    setcolor(BLUE);

    while(x<900 && y < 900){
        cleardevice();
        setcolor(BLUE);
        line(ligne.getXdebut(), ligne.getYdebut(), ligne.getXfin(), ligne.getYfin());
        bar(x, y, x+20, y+20);
        bar(station.getX(), station.getY(), station.getX() +30, station.getY() +30);
        x+=tram.getVitesseMax();
        y+=tram.getVitesseMax();
        if(x == 400 && y == 400){
            setcolor(RED);
            cleardevice();
            line(ligne.getXdebut(), ligne.getYdebut(), ligne.getXfin(), ligne.getYfin());
            bar(x, y, x+20, y+20);
            bar(station.getX(), station.getY(), station.getX() +30, station.getY() +30);
            Sleep(2000);
        }
        Sleep(10);
    }

    closegraph();
    return 0;
}
