#include <iostream>
#include <string.h>

#define MAX 100

int VocaliDispari(char s[]) {
    char voc[5]={'a','e','i','o','u'};
    int i,j,v=0;
    for(i=0;i<strlen(s);i++) {
        s[i]=tolower(s[i]);
        for(j=0;j<5;j++) {
            if(s[i]==voc[j]) {
                v++;
            }
        }
    }
    return v%2;
}


int main()
{
    char str[MAX];

    printf("Inserire una frase: ");
    gets(str);

    if(VocaliDispari(str))
        printf("Il numero di vocali e\' dispari\n\n");
    else
        printf("Il numero di vocali e\' pari\n\n");
    system("PAUSE");
    return 0;
}
