#include <iostream>
using namespace std;

int main(int argc, char** argv) {
	int num;
	printf("Inserire un numero:\n");
	scanf("%d", &num);
	if(num == 0) {
		printf("Il valore inserito e\' nullo\n");
	}
	else if(num < 0) {
		printf("Il valore inserito e\' negativo\n");
	}
	else if(num > 0) {
		printf("Il valore inserito e\' positivo\n");
	}
	printf("\n");
	system("PAUSE");
	return 0;
}
