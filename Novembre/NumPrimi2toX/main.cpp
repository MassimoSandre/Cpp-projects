#include <iostream>
#include <stdlib.h>
#include <stdio.h>


int main()
{
    int n,i,j;
    bool primo;
    do{
        printf("Inserire un numero positivo: ");
        scanf("%d",&n);
        system("CLS");
        if(n<0)
            printf("Il numero inserito non e\' positivo!\n\n");
    }while(n<0);
    printf("Numeri primi:\n");
    for(i=2;i<n+1;i++){
            primo=true;
        for(j=2;j<i;j++) {
            if(i%j==0 && i!=2)
                primo=false;
        }
        if(primo)   // if primo == true
            printf("%d\t",i);
    }
    printf("\n\n");
    system("PAUSE");
    return 0;
}
