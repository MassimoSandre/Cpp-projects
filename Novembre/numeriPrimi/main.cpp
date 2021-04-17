#include <iostream>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int n,i;
    bool primo=true;
    do {
        printf("Inserire un numero positivo: ");
        scanf("%d",&n);
        system("CLS");
        if(n<0)
            printf("Il numero inserito non e\' positivo!\n\n");
    }while(n<0);
    for(i=2;i<n;i++) {
        if(n%i==0){
            primo=false;
            i=n;
        }
    }
    if(!primo)
        printf("Il numero inserito non e\' primo\n\n");
    else
        printf("Il numero inserito e\' primo\n\n");
    system("PAUSE");
    return 0;
}
