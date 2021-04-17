#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;


int main(int argc, char** argv) {
	int h1,
		h2,
		m1,
		m2,
		s1,
		s2,
		r;
	printf("Inserire un orario in formato hh mm\n");
	scanf("%d",&h1);
	scanf("%d",&m1);
	printf("Inserire un orario in formato hh mm\n");
	scanf("%d",&h2);
	scanf("%d",&m2);
	r = (h2*3600+m2*60)-(h1*3600+m1*60);
	if(r<0) {
		r=r*-1;
	}
	s1= r/3600;
	r=r%3600;
	s2 = r/60;
	printf("L\'intervallo tra i due orari specificati e\' uguale a %d:%d\n",s1,s2);
	system("pause");
	return 0;
}
