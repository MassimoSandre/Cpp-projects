#include <iostream>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char** argv) {
	int n,
		r;

	printf("Inserire un numero:\n");
	scanf("%d", &n);

	r=n%2;

	if(r==0)
		n=n*2;
	else
		n=n*3;

	printf("\n%d\n\n", n);
	system("PAUSE");
	return 0;

}
