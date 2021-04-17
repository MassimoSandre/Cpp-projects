#include <iostream>
#include <string.h>

#define MAX 20

void concat(char s1[],char s2[],char s3[]) {
    strcpy(s3,s1);
    strcat(s3,s2);
}


int main()
{
    char s1[MAX],s2[MAX],s3[MAX*2];
    printf("Inserire la prima meta\' della stringa: ");
    gets(s1);

    printf("Inserire la seconda meta\' della stringa: ");
    gets(s2);

    concat(s1,s2,s3);

    printf("Stringa risultante: %s\n\n",s3);
    system("PAUSE");
    return 0;
}
