#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int main(int argc, char** argv) {
	int n,
		e,
		p;
	printf("Inserire un numero da elevare a potenza\n");
	scanf("%d", &n);
	printf("Inserire l'espondente\n");
	scanf("%d", &e);
	p = pow(n,e);
	printf("Il risultato della potenza e\': %d\n\n", p);
	system("PAUSE");
	return 0;
}
