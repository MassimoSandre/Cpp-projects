#include <Windows.h>
#include <iostream>
#include <conio.h>
#include "Menu.h"

#define LARGHEZZA 640
#define ALTEZZA 300

int main()
{


    tVetVoc v[] = {"Prova","Menu","Epico","Massimo"};
    Menu m1(10,10,4,v);

    return 0;
}
