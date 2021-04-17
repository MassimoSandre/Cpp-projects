#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{
    int i,n,somma=0;

    srand(time(NULL));
    for(i=0;i<3;i++){
        do{
            n=(rand()%151)-70;
        }while(n<20 && n>-30);
        if(n<0)
            printf("\b\b- %d + ",n*-1);
        else
            printf("%d + ",n);
        somma+=n;
    }
    printf("\b\b= %d\n\n",somma);
    system("PAUSE");
    return 0;
}
