#include <iostream>
#include <string.h>
#include <ctype.h>

#define MAX 80

int main()
{
    char str[MAX],t;
    int i,j,le;


    printf("Inserisci una frase: ");
    gets(str);

    printf("Inserire un separatore per le parole: ");
    scanf("%c",&t);

    le=strlen(str);

    /* sostituzione spazi */
    for(i=0;i<le;i++) {
        if(isspace(str[i])) {
            str[i]=t;
        }
    }

    printf("Frase risultante: %s\n\n",str);
    system("PAUSE");
    return 0;
}
