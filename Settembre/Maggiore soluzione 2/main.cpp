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
	
	if(a>b && a>c) {
		printf("Il numero maggiore tra quelli inseriti e\': %d\n", a);
	}
	else if(b>a && b> c){
		printf("Il numero maggiore tra quelli inseriti e\': %d\n", b);
		
	}
	else {
		printf("Il numero maggiore tra quelli inseriti e\': %d\n", c);
	}
	system("PAUSE");
	return 0;
}
