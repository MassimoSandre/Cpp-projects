/* Massimo Albino Sandretti
*  3 Inf
*/
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int main() {
	int n;
	printf("Inserire un numero:\n");
	scanf("%d", &n);
	if(n%2==0)
		printf("Il numero inserito e\' pari\n\n");
	else
		printf("Il numero inserito e\' dispari\n\n");
	system("PAUSE");
	return 0;
}
