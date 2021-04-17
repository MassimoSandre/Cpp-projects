#include <iostream>
#include <string.h>

int main()
{
    bool par=true;
    int i,p=0;
    char b[10];

    printf("Inserire un valore binario: ");
    gets(b);
    if(strlen(b)==8) {
        for(i=0;i<8;i++) {
            if(b[i]!= '1' && b[i] != '0') {
                par=false;
            }
            if(b[i]=='1')
                p++;
        }
    }
    else {
        par=false;
    }
    if(par) {
        if(p%2==1) {
            printf("Questa codifica binaria non e\' corretta\n\n");
        }
        else{
            printf("Questa codifica binaria e\' corretta\n\n");
        }
    }
    else {
        printf("Il valore inserito non e\' una codifica binaria\n\n");
    }
    system("PAUSE");
    return 0;
}
