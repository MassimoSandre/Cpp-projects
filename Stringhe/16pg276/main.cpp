#include <iostream>
#include <string.h>
#include <stdlib.h>

int main()
{
    char add[15];
    int somma=0,i;

    for(i = 0;i<4;i++){
        printf("Inserire l\'addendo %d: ",i+1);
        gets(add);

        somma+=atoi(add);
    }
    itoa(somma,add,10);
    printf("\n\tLa somma dei numeri inseriti e\' %s\n\n",add);
    system("PAUSE");
    return 0;
}
