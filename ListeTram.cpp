#include "ListeTram.h"
#include <iostream>

using namespace std;

ListeTram::ListeTram() : t{nullptr}
{
    //ctor
}

ListeTram::~ListeTram()
{
    while(t)
	{
		ChainonTram *tmp=t->suiv;
		delete t;
		t=tmp;
	}
}

void ListeTram::affiche(){
    ChainonTram *c = t;
    while(c){
        cout << c->getTramway().getX() << " " << c->getTramway().getY() << endl;
        c = c->suiv;
    }
}

void ListeTram::insererTramway(Tramway tramway)
{
	ChainonTram *nc=new ChainonTram(tramway);
	if(t==nullptr)
    {
        t=nc;
    }
    else
    {
        ChainonTram *precC=nullptr, *c=t;
        while(c!=nullptr)
        {
            precC=c;
            c=c->suiv;
        }
        precC->suiv=nc;
        nc->suiv = c;
    }
}
