#include <iostream>
#include <math.h>
using namespace std;

int main(int argc, char** argv) {
	int a,
		b,
		c;
	float r;
	cout << "Inserire i lati di un triangolo scaleno:\n";
	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);
	int sp = (a+b+c)/2;
	r = sqrt(sp*(sp-a)*(sp-b)*(sp-c));
	printf("L\'area del Triangolo con lati a = %d, b = %d e c = %d e\' %f\n",a,b,c,r);
	system("PAUSE");
	return 0;
}
