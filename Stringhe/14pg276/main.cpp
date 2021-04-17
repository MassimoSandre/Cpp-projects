#include <iostream>
#include <string.h>
#include <ctype.h>

#define MAX 80

int main()
{
    char str[MAX];
    int i,j,le;
    bool pali=true;

    printf("Inserisci una frase: ");
    gets(str);

    le=strlen(str);

    for(i=0;i<le;i++) str[i]=tolower(str[i]); /* Rendo tutte le lettere minuscole */

    /* Rimozione spazi */
    for(i=0;i<le;i++) {
        if(isspace(str[i])) {
            for(j=i;j<le-1;j++) {
                str[j]=str[j+1];
            }
            le--;
            str[le]='\0';
        }
    }

    for(i=0;i<strlen(str)/2;i++) {
        if(str[i]!=str[strlen(str)-i-1]) {
            pali=false;
        }
    }

    if(pali) {
        printf("La frase inserita e\' palindroma\n\n");
    }
    else {
        printf("La frase inserita non e\' palindroma\n\n");
    }
    system("PAUSE");
    return 0;
}
