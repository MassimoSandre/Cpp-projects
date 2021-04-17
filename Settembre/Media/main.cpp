#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define TIMES 4

using namespace std;

int main()
{
    int a,c,d,y;
    int v[TIMES];
    int media,
        somma = 0;
    float medec,b,e,t,u,risd;
    printf("Inserire 4 voti:\n");
    for(int j = 0; j < TIMES; j++) {
        printf("Inserire il voto numero %d:\n",j+1);
        scanf("%d", &v[j]);
    }
    for(int i = 0; i < TIMES; i++) {
        somma=somma+v[i];
    }
    medec = (float)somma/TIMES;                 // Calcolo la media con tutti i decimali

    e = (float)medec *10;
    d = (int)e;                                 // Calcolo la media con 1 decimale
    t = e-d;
    u=t*10;
    y=(int)u;
    if(y >= 5) {
        d++;
    }
    risd = (float)d/10;

    a = (int)medec;
    b =((float)medec-a)*10;
    c = (int)b;                     // Calcolo la media senza decimali
    if(b >= 5) {

        a++;
    }


    printf("\nMedia precisa: %d\n",a);
    printf("\nMedia arrotondata alla prima cifra decimale: %.1f\n\n",risd);
    system("PAUSE");
    return 0;
}
