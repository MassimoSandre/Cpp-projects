#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

void scambia(char v[],int i, int j) {
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void anagramma(char str[],int p, int l) {
    int i;
    if(p == l)
        printf("%s\n",str);
    else {
        for(i = p; i<l+1;i++) {
            scambia(str,p,i);
            anagramma(str,p+1,l);
            scambia(str,p,i);
        }

    }
}

int main()
{
    char str[MAX];

    printf("Inserire una parola: ");
    gets(str);

    anagramma(str,0,strlen(str)-1);

    system("PAUSE");
    return 0;
}
