#include <iostream>
#include <limits.h>
#include <string.h>
#define MAX 80

int main()
{
    char vocali[]={'a','e','i','o','u'};
    int cont[5]={0,0,0,0,0};
    int i,j,mx=INT_MIN,mn=INT_MAX,posMax,posMin;
    char str[MAX];
    printf("Inserire una frase: ");
    gets(str);

    for(i=0;i<strlen(str);i++) {
        str[i]=tolower(str[i]);
        for(j=0;j<5;j++) {
            if(vocali[j]==str[i]) {
                cont[j]++;
                j=5;
            }
        }
    }
    for(i=0;i<5;i++) {
        if(cont[i]>mx) {
            mx=cont[i];
            posMax=i;
        }
        if(cont[i]<mn) {
            mn=cont[i];
            posMin=i;
        }
    }
    printf("Frequenza delle vocali:\n\n");
    for(i=0;i<5;i++) {
        printf("La vocale %c appare %d volte nella stringa\n",vocali[i],cont[i]);
    }

    printf("\nVocale con maggiore presenza: %c",vocali[posMax]);
    printf("\nVocale con minore presenza: %c\n\n\n",vocali[posMin]);
    system("PAUSE");
    return 0;
}
