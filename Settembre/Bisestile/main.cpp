#include <iostream>


int main(int argc, char** argv) {
	int a;
	bool bis = false;
	printf("Inserire un anno: ");
	scanf("%d", &a);
	if(a >= 1582) {
		if(a%100== 0) {
			if(a%400 == 0) {
				bis = true;
			}	
		}
		else if(a%4 == 0) {
			bis = true;
		}
		if(bis) {
			printf("\nL\'anno inserito e\' bisestile\n");
		}
		else {
			printf("\nL'anno inserito non e\' bisestile\n");
		}
	
	}
	else {
		printf("Prima dell'anno 1582, non si usava il Calendario Gregoriano\n");
	}
	system("PAUSE");
	return 0;
}
