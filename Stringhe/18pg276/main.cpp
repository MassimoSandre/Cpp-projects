#include <iostream>
#include <string.h>

#define MAX 80

void scambia(char s[]) {
    char temp=s[0];
    s[0]=s[strlen(s)-1];
    s[strlen(s)-1]=temp;
}

int main()
{
    char str[MAX];

    printf("Inserire una stringa: ");
    gets(str);

    scambia(str);

    printf("Stringa risultante: %s\n\n",str);
    system("PAUSE");
    return 0;
}
