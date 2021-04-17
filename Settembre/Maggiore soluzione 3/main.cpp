#include <iostream>
using namespace std;

int main(int argc, char** argv) {
	int a,
		b,
		c,
		max;
		
 	printf("Inserire il primo numero:\n");
	scanf("%d", &a);
	printf("Inserire il secondo numero:\n");
	scanf("%d", &b);
	printf("Inserire terzo numero:\n");
	scanf("%d", &c);
	
	max = a;
	
	if(b > max) {
		max = b;
	}
	if(c > max) {
		max = c;
	}
	
	printf("Il numero maggiore tra quelli inseriti e\': %d\n",max);
	
	system("PAUSE");
	
	return 0;
}

	//	Soluzione alternativa simile

/*int main(int argc, char** argv) {
	int a,
		b,
		c,
		max;
	cout << "Inserire 3 numeri:\n";
	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);
	max = a;
	if(a > b) {
		max = a;
	}
	else {
		max = b;
	}
	if(c > max) {
		max = c;
	}
	printf("Il numero maggiore tra quelli inseriti e\': %d\n",max);
	system("PAUSE");
	return 0;
}*/
