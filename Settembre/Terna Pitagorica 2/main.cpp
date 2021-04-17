// Massimo Albino Sandretti
// 26/09/2018
// Riconoscere se i numeri inseriti formano una terna pitagorica
#include <iostream>
#include <math.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	bool check = false;
	int a,
		b,
		c;	
	printf("Inserire il primo numero: ");
	scanf("%d",&a);
	printf("Inserire il secondo numero: ");
	scanf("%d", &b);
	printf("Inserire il terzo numero: ");
	scanf("%d", &c);
	system("CLS");
	if(a == b && a == c) {
	
	}
	else{
		if(a>b) {
			if(a >c) {
				if(pow(b,2) + pow(c,2) == pow(a,2)) {
					check = true;
				}
			}
			else {
				if(pow(b,2) + pow(a,2) == pow(c,2)) {
					check = true;
				}
			}
		}
		else {
			if(b > c) {
				if(pow(a,2) + pow(c,2) == pow(b,2)) {
					check = true;
				}
			}
			else {
				if(pow(b,2) + pow(a,2) == pow(c,2)) {
					check = true;
				}
			}
		}
	}
	if(!check) {
		printf("I numeri inseriti non sono una terna pitagorica\n");
	}
	else {
		printf("I numeri inseriti sono una terna pitagorica\n");
	}
	system("PAUSE");
	return 0;
}
