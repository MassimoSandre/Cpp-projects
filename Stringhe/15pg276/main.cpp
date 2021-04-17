#include <iostream>
#include <string.h>

#define MAX 50

int main()
{
    char par[MAX],far[MAX*3],vocali[]={'a','e','i','o','u'};
    int i,j,p=0;
    bool voc;

    printf("Inserire una stringa: ");
    gets(par);

    for(i=0;i<strlen(par);i++,p++) {
        par[i]=tolower(par[i]);
        voc=false;
        for(j=0;j<5;j++) {
            if(par[i]==vocali[j]) {
                voc=true;
            }
        }
        far[p]=par[i];
        if(voc) {
            far[p+1]='f';
            far[p+2]=par[i];
            p+=2;
        }
    }
    far[p]='\0';

    printf("Frase risultante: %s\n\n",far);
    system("PAUSE");
    return 0;
}
