#include <iostream>
#include <stdio.h>
#include <stdlib.h>
// PROGRAMMA CREATO PER IL TEST DI BATTITURA DI MASSIMO SANDRETTI

// LO SCOPO DEL PROGRAMMA E' QUELLO DI GESTIRE LA MODIFICA DELLE PAROLE
// IN MODO CHE RISULTI FUNZIONALE E FACILE DA USARE

int main()
{
    FILE *pf1=fopen("words.txt","a"),*pf2 = fopen("input.txt","w");
    fclose(pf1),
    pf1=fopen("words.txt","r");

    int i=0,par;
    bool inizio=false;
    char in;
    do {
        in = fgetc(pf1);
        if(in!=EOF) {
            if(inizio && isspace(in)) {
                inizio=false;
                i++;
            }
            if(!inizio && !isspace(in)) {
                inizio = true;
            }
        }
    }while(in!=EOF);

    if(inizio) i++;
    fclose(pf1);
    pf1=fopen("words.txt","r");
    fprintf(pf2,"%d\n",i);
    inizio = false;
    do {
        in = fgetc(pf1);
        if(in!=EOF) {
            if(inizio && isspace(in)) {
                fprintf(pf2,"\n");
                inizio=false;
            }
            if(inizio && !isspace(in)) {
                fprintf(pf2,"%c",in);
            }
            if(!inizio && !isspace(in)) {
                fprintf(pf2,"%c",in);
                inizio=true;
            }
        }
    }while(in!=EOF);

    fclose(pf1);
    fclose(pf2);
    return 0;
}
