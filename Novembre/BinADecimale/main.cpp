#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#define SLOTS 31

int main()
{
    unsigned int n=0;
    int v[SLOTS],
        i=0;
    char b;
    printf("Inserire un numero binario(terminante con b): ");
    do{
        scanf("%c",&b);
        if(b != 'b'){
            for(int j = 0; j<i; j++) {
                v[j]*=2;
            }
            switch(b) {
                case '0':
                    v[i]=0;
                    i++;
                    break;
                case '1':
                    v[i]=1;
                    i++;
                    break;
                default:
                    printf("\n\nIl numero inserito non e\' binario\n\n");
                    system("PAUSE");
                    return 0;
                    break;
            }
        }
    }while(b != 'b');
    for(int j = 0; j<i;j++){
        n = n+v[j];
    }
    system("CLS");
    printf("Il numero binario inserito corrisponde al numero decimale: %d\n\n\n",n);
    system("PAUSE");
    return 0;
}
