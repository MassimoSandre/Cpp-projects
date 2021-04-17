#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) { 
	int a,
		b,
		c;
	int min,
		max,
		med;
	printf("Inserire 3 valori:\n");
	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);
	
	if(a == b && a==c) {
		min = a;
		max = a;
		med = a;
	}
	
	
	else {
		if(a > b && a > c) {
			max = a;
			if(b < c) {
				min = b;
				med = c;
			}
			else {
				min = c;
				med = b;
			}
		}
		else if(b > c && b > a) {
			max = b;
			if(c < a) {
				min = c;
				med = a;
			}
			else {
				min = a;
				med = c;
			}
		}
		else if(c > a && c > b) {
			max = c;
			if(a < b) {
				min = a;
				med = b;
			}
			else {
				min = b;
				med = a;
			}
		}
	}
	printf("\nOrdine crescente: %d %d %d", min, med,max);
	printf("\nOrdine decrescente: %d %d %d\n",max,med,min);
	system("PAUSE");
	return 0;
}
