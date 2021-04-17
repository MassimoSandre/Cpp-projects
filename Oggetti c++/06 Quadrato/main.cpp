#include <iostream>
#include <math.h>
#include "tQuadrato.h"
   
int main(int argc, char** argv) {
	double lato,diag;	// Dati del quadrato
	tQuadrato Q1;		// Oggetto quadrato
	char ch;

	printf("\n\nOGGETTO QUADRATO.\n");
	do {
		printf("Inserire lato o diagonale (l-d)? ");
		fflush(stdin);
		ch=getchar();
		if(ch!='l'&&ch!='L'&&ch!='d'&&ch!='D') printf("\nInserire l oppure d.\n");
	} while (ch!='l'&&ch!='L'&&ch!='d'&&ch!='D');
	if(ch=='l'||ch=='L') {	// Lato
		printf("\nLato quadrato? ");
		scanf("%lf",&lato);
		Q1.SetLato(lato);
	} 
	else {					// Diagonale
		printf("\nDiagonale quadrato? ");
		scanf("%lf",&diag);
		Q1.SetDiagonale(diag);
	}
	printf("\n\nDati del quadrato:\n");
	printf("\nLato: %lf",Q1.GetLato());
	printf("\nDiagonale: %lf",Q1.GetDiagonale());
	printf("\nPerimetro: %lf",Q1.Perimetro());
	printf("\nArea: %lf",Q1.Area());
		
	return 0;
}

