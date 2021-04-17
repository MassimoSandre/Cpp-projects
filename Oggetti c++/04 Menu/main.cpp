#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio2.h>

using namespace std;

#include "Menu.h"

int main(int argc, char *argv[])
{
    tVetVoc V={"Apri",			 //Vettore contenente le voci del menu
			   "Ordina",
			   "Stampa Tutto",
			   "Cerca elemento",
			   "Chiudi"};
    int Sce;					// Scelta fatta
    tMenu Menu(35,5,5,V);		// Crea menu posizionando a (35,5) 4 voci in vettore V

	Menu.Show();				// Mostra menu
    Sce=Menu.Choice();			// Scelta
    gotoxy(35,15);
    cout<<"\n\n\n\nLa scelta e': "<<Sce<<"\n";
    Menu.Hide();
    system("PAUSE");

    return 0;
}

