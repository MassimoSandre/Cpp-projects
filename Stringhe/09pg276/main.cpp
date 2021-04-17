#include <iostream>
#include <string.h>

#define MAX 80

int main()
{
    char f[MAX*2],p1[MAX/4],p2[MAX/4],l1[MAX],l2[MAX],l3[MAX];
    int pos1,pos2,i,j;

    bool tr=true;

    printf("Inserire una frase: ");
    gets(l1);

    /* Inserimento prima parola da scambiare */
    do {
        printf("Inserire la prima parola da scambiare: ");
        gets(p1);
        system("CLS");
        if(!strstr(l1,p1)) {
            printf("La parola inserita non e\' presente nella stringa\n\n");
        }
    } while(!strstr(l1,p1));

    /* Rilevazione prima parola da scambiare */
    for(i=0;i<strlen(l1)-strlen(p1)+1;i++) {
        tr=true;
        for(j=0;j<strlen(p1);j++) {
            if(l1[j+i]!=p1[j]) tr=false;
        }
        if(tr) {
            pos1=i;
            i=strlen(l1)-strlen(p1);
        }
    }

    /* Inserimento seconda parola da scambiare */
    do {
        printf("Inserire la seconda parola da scambiare: ");
        gets(p2);
        system("CLS");
        if(!strstr(l1,p2)) {
            printf("La parola inserita non e\' presente nella stringa\n\n");
        }
    } while(!strstr(l1,p2));

    /* Rilevazione seconda parola da scabiare */
    for(i=0;i<strlen(l1)-strlen(p2)+1;i++) {
        tr=true;
        for(j=0;j<strlen(p2);j++) {
            if(l1[j+i]!=p2[j]) tr=false;
        }
        if(tr) {
            pos2=i;
            i=strlen(l1)-strlen(p2);
        }
    }



    if(pos1<pos2) {
        for(i=pos1+strlen(p1),j=0;i<pos2;i++,j++) {
            l3[j]=l1[i];
        }
        l3[j]='\0';

        for(i=pos2+strlen(p2),j=0;i<strlen(l1);i++,j++) {
            l2[j]=l1[i];
        }
        l2[j]='\0';

        l1[pos1]='\0';
    }
    else {
        for(i=pos2+strlen(p2),j=0;i<pos1;i++,j++) {
            l3[j]=l1[i];

        }
        l3[j]='\0';


        for(i=pos1+strlen(p1),j=0;i<strlen(l1);i++,j++) {
            l2[j]=l1[i];
        }
        l2[j]='\0';

        l1[pos2]='\0';
    }

    strcpy(f,l1);
    strcat(f,(pos1<pos2?p2:p1));
    strcat(f,l3);
    strcat(f,(pos1<pos2?p1:p2));
    strcat(f,l2);

    printf("Frase risultante: %s\n\n",f);
    system("PAUSE");
    return 0;
}
