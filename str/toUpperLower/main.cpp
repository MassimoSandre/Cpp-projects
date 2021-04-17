#include <iostream>
#include <stdio.h>

#define MAX 80
#define ASCGAP 32

int main()
{
    char str[MAX];

    printf("Inserire una frase: ");
    gets(str);
    system("CLS");
    // Trasformo tutti i caratteri della stringa in minuscolo
    for(int i=0;str[i];i++)
        if(str[i]>=65&&str[i]<=90)
            str[i]+=ASCGAP;

    printf("Frase in minuscolo: %s\n\n",str);
    // Trasformo tutti i caratteri della stringa in maiuscolo
    for(int i=0;str[i];i++)
        if(str[i]>=97&&str[i]<=122)
            str[i]-=ASCGAP;

    printf("Frase in maiuscolo: %s\n\n",str);
    system("PAUSE");
    return 0;
}
