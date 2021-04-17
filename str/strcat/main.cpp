#include <iostream>
#include <stdio.h>

#define MAX 80

int main()
{
    char f1[MAX],f2[MAX],r[MAX*2];
    int i,k;
    printf("Inserire la prima parte della stringa: ");
    gets(f1);

    printf("Inserire la seconda parte della stringa: ");
    gets(f2);

    for(i=0;f1[i];i++)
        r[i]=f1[i];
    k=i;
    for(i=0;f2[i];i++,k++)
        r[k]=f2[i];

    r[k]=f2[i];
    printf("Stringa Risultante: %s\n\n",r);
    system("PAUSE");
    return 0;
}
