// programmatore: Massimo (26-09-2018)
// testo: trasformare secondi in hh:mm:ss
#include <iostream>
using namespace std;

#define SEC_ORE 3600	// Secondi in un'ora
#define SEC_MIN 60	// Secondi in un minuto

int main(int argc, char** argv) {
	int s, // Secondi
		o, // Ore
		m; // Minuti
	cout << "Inserire un numero di secondi:\n";
	scanf("%d", &s);
	o = s/SEC_ORE;
	s = s%SEC_ORE;
	m = s/SEC_MIN;
	s = s%SEC_MIN;
	printf("Il tempo inserito corrisponde a: %d:%d:%d\n",o,m,s);
	system("PAUSE");
	return 0;
}
