#include <iostream>
#include <stdlib.h>
#include <string.h>

int main()
{
    char in[15],g[5],m[5],a[5];
    int i,j;

    printf("Inserire una data nel formato gg/mm/aaaa: ");
    gets(in);

    i=0;
    while(in[i]!='/') {
        g[i]=in[i];
        i++;
    }
    g[i]='\0';

    i++;
    j=i;
    while(in[i]!='/') {
        m[i-j]=in[i];
        i++;
    }
    m[i-j]='\0';

    i++;
    j=i;
    while(in[i]!='\0') {
        a[i-j]=in[i];
        i++;
    }
    a[i-j]='\0';

    printf("%s ",g);

    switch(atoi(m)) {
    case 1:
        printf("gennaio");
        break;
    case 2:
        printf("febbraio");
        break;
    case 3:
        printf("marzo");
        break;
    case 4:
        printf("aprile");
        break;
    case 5:
        printf("maggio");
        break;
    case 6:
        printf("giugno");
        break;
    case 7:
        printf("luglio");
        break;
    case 8:
        printf("agosto");
        break;
    case 9:
        printf("settembre");
        break;
    case 10:
        printf("ottobre");
        break;
    case 11:
        printf("novembre");
        break;
    case 12:
        printf("dicembre");
        break;
    default:
        system("CLS");
        printf("ERRORE DI ELABORAZIONE\n\n");
        system("PAUSE");
        exit(1);
        break;
    }
    printf(" %s",a);
    return 0;
}
