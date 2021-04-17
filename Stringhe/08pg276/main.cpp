#include <iostream>
#include <string.h>


int main()
{
    char str[160],tos[80], l1[80],l2[80];
    int i,j,trov,l1l;

    bool tr=true;

    printf("Inserire una frase: ");
    gets(l1);
    l1l=strlen(l1);

    printf("Inserire una parola da rimpiazzare: ");
    gets(tos);

    if(strstr(l1,tos)) {
        for(i=0;i<strlen(l1)-strlen(tos)+1;i++) {
            tr=true;
            for(j=0;j<strlen(tos);j++) {
                if(l1[j+i]!=tos[j]) tr=false;
            }
            if(tr) {
                trov=i;
                i=strlen(l1)-strlen(tos);
            }
        }
        l1[trov]='\0';
        for(i=trov+strlen(tos),j=0;i<l1l;i++,j++) {
            l2[j]=l1[i];

        }
        l2[j]='\0';

        printf("Inserire una parola con cui sostituire: ");
        gets(tos);

        strcpy(str,l1);
        strcat(str,tos);
        strcat(str,l2);

        printf("Frase risulante: %s\n\n",str);

    }
    else {
        printf("La parola inserita non e\' presente nella frase!\n\n");
    }

    system("PAUSE");
    return 0;
}
