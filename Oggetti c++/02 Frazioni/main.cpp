#include <iostream>
#include <stdio.h>
#include <windows.h>
#include "tFrazioni.h"

using namespace std;

int main(int argc, char** argv) {
	tFrazione f1,f2,		// Frazioni da sommare
			  fsomma;		// Frazione somma
	int num,den;			// Numeratore Denominatore generici

	system("CLS");
	cout<<"\n\nSOMMA TRA FRAZIONI (con oggetti)\n";
	cout<<"\n\nFrazione 1.\n";
	cout<<"   Numeratore? ";
	cin>>num;
	cout<<"   Denominatore? ";
	cin>>den;
	f1.setNum(num);			// Metodo setNum
	f1.setDen(den);
	cout<<"\n\nFrazione 2.\n";
	cout<<"   Numeratore? ";
	cin>>num;
	cout<<"   Denominatore? ";
	cin>>den;
	f2.setFract(num,den);	// Metodo setFract
	fsomma.setDen(f1.getDen()*f2.getDen());
	fsomma.setNum(f1.getNum()*f2.getDen()+f1.getDen()*f2.getNum());
	cout<<"\n\nFrazione somma = ";
	fsomma.stampaFract();	// Metodo stampaFract

	return 0;
}
