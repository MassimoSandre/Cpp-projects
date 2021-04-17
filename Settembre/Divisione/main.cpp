#include <iostream>

using namespace std;

int main(int argc, char** argv) {
	int d;
	int e,c =0,l;
	cout << "Inserire il dividendo: ";
	scanf("%d", &d);
	cout << "Inserire il divisore: ";
	scanf("%d", &e);
	cout << "Quanti decimali?";
	scanf("%d", &l);
	system("cls");
	cout << d/e;
	d = d%e;
	if(d != 0) {
		printf(".");
	}
	while(d != 0 && c < l) {
		d = d*10;
		cout << d/e;
		d = d%e;
		c++;
	}
	system("PAUSE");
	return 0;
}
