#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char** argv) {
	int n;
	float r;
	printf("Inserire un numero di cui fare la radice:\n");
	scanf("%d", &n);
	r = sqrt(n);
	printf("Il risultato della radice e\': %f\n\n",r);
	system("PAUSE");
	return 0;
}
