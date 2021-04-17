#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <stdio.h>

main () {
	int a,
		b,
		c;
	double p1,p2,p3;
	printf("Inserire 3 lati di un triangolo:\n");
	scanf("%d %d %d", &a, &b, &c);
	p1 = pow(a,2);
	p2 = pow(b,2);
	p3 = pow(c,2);
	if(p1 > p2 && p1> p3) {
		if(p2 + p3 == p1)  {
			printf("\nIl triangolo inserito e\' rettangolo\n");
		}
		else {
			printf("\nIl triangolo inserito non e\' rettangolo\n");
		}
	}
	else {
		if(p2 > p1 && p2 > p3) {
			if(p1 + p3 == p2) {
				printf("\nIl triangolo inserito e\' rettangolo\n");
			}
			else {
				printf("\nIl triangolo inserito non e\' rettangolo\n");
			}
		}
		else {
			if(p1 + p2 == p3) {
				printf("\nIl triangolo inserito e\' rettangolo\n");
			}
			else {
				printf("\nIl triangolo inserito non e\' rettangolo\n");
			}
		}
	}
	system("PAUSE");
	return 0;
}
