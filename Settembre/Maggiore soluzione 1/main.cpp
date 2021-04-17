#include <iostream>
using namespace std;

int main(int argc, char** argv) {
	int a,
		b,
		c;
	printf("Inserire il primo numero:\n");
	scanf("%d", &a);
	printf("Inserire il secondo numero:\n");
	scanf("%d", &b);
	printf("Inserire terzo numero:\n");
	scanf("%d", &c);
	
	if(a > b) {
		if(a > c){
			printf("\nIl numero maggiore e\': %d", a);
		}
		else {
			printf("\nIl numero maggiore e\': %d", c);
		}
	}
	else {
		if(b > c) {
			printf("\nIl numero maggiore e\': %d", b);
		}
		else {
			printf("\nIl numero maggiore e\': %d", c);
		}
	}
	printf("\n");
	system("PAUSE");	
	return 0;
}

