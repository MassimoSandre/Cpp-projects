#include <iostream>
#include <string.h>

#define MAX 15

int main()
{
    char nome[MAX],cognome[MAX],comp[MAX*2];
    int i;

    printf("Inserire il nome: ");
    gets(nome);

    nome[0]=toupper(nome[0]);
    for(i=1;i<MAX&&nome[i];i++) {
        nome[i]=tolower(nome[i]);
    }

    printf("Inserire il cognome: ");
    gets(cognome);

    cognome[0]=toupper(cognome[0]);
    for(i=1;i<MAX&&cognome[i];i++) {
        cognome[i]=tolower(cognome[i]);
    }

    strcpy(comp,nome);
    strcat(comp," ");
    strcat(comp,cognome);

    system("CLS");
    printf("Nome Completo:\n%s\n\n",comp);
    system("PAUSE");
    return 0;
}
