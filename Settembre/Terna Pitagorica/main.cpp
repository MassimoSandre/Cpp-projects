#include <iostream>
#include <math.h>

using namespace std;

int main(int argc, char** argv) {
	
	int a,
		b,
		c,
		c1,
		c2,
		c3,
		sa,
		sb,
		sc;
	
	
	bool check = false;
	cout << "Inserire 3 numeri:\n";
	scanf("%d",&a);
	scanf("%d",&b);
	scanf("%d",&c);
	
	
	sa = pow(a,2);
	sb = pow(b,2);
	sc = pow(c,2);
	
	c1 = sa + sb;
	c2 = sa + sc;
	c3 = sb + sc;
	
	if(c1 == sc) {
		check = true;
	}
	if(c2 == sb) {
		check = true;
	}
	if(c3 == sa) {
		check = true;
	}
	
	
	if(check == true) {
		printf("I numeri %d,%d e %d sono una terna pitagorica\n", a,b,c);
	}
	else{
	
		printf("I numeri %d,%d e %d non sono una terna pitagorica\n", a ,b,c);
	}
	system("PAUSE");
	return 0;
}
