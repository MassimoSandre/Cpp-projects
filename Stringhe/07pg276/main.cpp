#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <limits.h>


int main()
{
    int x,p=0,i,j,temp;
    char str[15],fin[20];

    printf("Inserisci un numero: ");
    scanf("%d",&x);

    itoa(x,str,10);

    for(i=0,j=1;i<strlen(str);i++,j++) {
        fin[i+p]=str[strlen(str)-i-1];
        if(j!=0 && j%3==0) {
            fin[i+p+1]='.';
            p++;
        }
    }
    fin[i+p]='\0';

    for(int i=0;i<strlen(fin)/2;i++) {
        temp=fin[i];
        fin[i]=fin[strlen(fin)-1-i];
        fin[strlen(fin)-1-i]=temp;
    }

    printf("Numero inserito formattato: %s\n\n",fin);
    system("PAUSE");
    return 0;
}
