#include <iostream>
#include <string.h>
#include <ctype.h>

#define MAX 80

int main()
{
    char str[MAX];
    int i,j,le;

    printf("Inserisci una frase: ");
    gets(str);

    le=strlen(str);

    /* Rimozione spazi in eccesso */
    for(i=0;i<le;i++) {
        if(isspace(str[i]) && isspace(str[i+1])) {
            for(j=i;j<le-1;j++) {
                str[j]=str[j+1];
            }
            le--;
            str[le]='\0';
            i--;
        }
    }

    printf("Frase risultante: %s\n\n",str);
    system("PAUSE");
    return 0;
}
