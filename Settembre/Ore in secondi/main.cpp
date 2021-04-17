#include <iostream>
using namespace std;

#define SEC_ORE 3600 // Secondi in un'ora
#define SEC_MIN 60	// Secondi in un minuto

int sec(int s,int m, int o) {
	return s+(m*SEC_MIN)+(o*SEC_ORE);
}

int main(int argc, char** argv) {
	int s,	// Secondi
		o,	// Ore
		m;	// Minuti
	cout << "Inserire un tempo in questo formato: hhh mm ss\n";
	{
		scanf("%d", &o);
		scanf("%d", &m);
		scanf("%d", &s);
	}
	printf("Il tempo inserito corrisponde a %d secondi\n", sec(s,m,o));
	system("PAUSE");
	return 0;
}


