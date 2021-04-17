#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int l,	
		a;
	printf("Inserire il lato di un quadrato:\n");
	scanf("%d", &l);
	a=l*l;
	printf("\nl\'area del quadrato e\' %d\n", a);
	system("PAUSE");
	return 0;
}
