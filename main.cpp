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
    Tramway tram{10.0,5.0,12.0,450,450};
    x=tram.getX();
    y=tram.getY();

    opengraphsize(900,900);
    setbkcolor(WHITE);
    setcolor(BLUE);

    while(x<900 && y < 900){
        cleardevice();
        bar(x+5, y+5, x+25, y+25);
        x+=1;
        Sleep(10);
    }

    getch();
    closegraph();
    return 0;
}
