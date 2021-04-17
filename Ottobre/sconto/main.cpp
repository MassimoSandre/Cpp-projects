#include <iostream>
#include <stdlib.h>
#include <stdio.h>
int main()
{

    int s,
        c;
    do {
        printf("Inserire la spesa: ");
        scanf("%d",&s);
        if(s<0) {
            printf("La spesa non può essere negativa!\n\n");
        }
    }while(s<0);

    printf("Lo sconto previsto e\' di ");

    if(s > 100) {
        c = s/10;
        s = s-c;
        printf("%d euro, quindi la spesa totale e\' di %d euro",c,s);
    }
    else {
        if(s > 80) {
            c = s/100;
            c = c*7;
            s = s-c;
            printf("%d euro, quindi la spesa totale e\' di %d euro",c,s);
        }
        else {
            if(s > 65) {
                c = s/100;
                c = c*6;
                s = s-c;
                printf("%d euro, quindi la spesa totale e\' di %d euro",c,s);
            }
            else {
                if(s > 50) {
                    c = s/100;
                    c = c*5;
                    s = s-c;
                    printf("%d euro, quindi la spesa totale e\' di %d euro",c,s);
                }
                else {
                    printf("0 euro, quindi la spesa totale e\' di %d euro",s);
                }
            }
        }
    }
    printf("\n\n");
    system("PAUSE");
    return 0;
}
