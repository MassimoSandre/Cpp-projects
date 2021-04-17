/* Non avento compreso lo scopo dell'esercizio, mi limiterò ad usare una funzione ricorsiva per ribaltare una stringa*/
#include <iostream>
#include <string.h>

#define MAX 100

void inverti(char str[],int i) {
    if(i<(strlen(str)/2)) {
        char temp=str[i];
        str[i]=str[strlen(str)-i-1];
        str[strlen(str)-i-1]=temp;
        inverti(str,i+1);
    }
}

int main()
{
    char str[MAX];
    printf("Inserire una frase: ");
    gets(str);

    inverti(str,0);

    printf("La frase invertita: %s\n\n",str);
    system("PAUSE");
    return 0;
}
