#include <iostream>
#include <string.h>

#define MAX 100

int main()
{
    char str[MAX],temp;
    int lung,i;

    printf("Inserire una frase: ");
    gets(str);

    lung = strlen(str);

    for(i=0;i<lung/2;i++) {
        temp=str[i];
        str[i]=str[lung-i-1];
        str[lung-i-1]=temp;
    }
    printf("\nFrase invertita: %s\n\n",str);
    system("PAUSE");
    return 0;
}
