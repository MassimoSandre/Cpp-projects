#include <iostream>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int t,  // Numero di casi da analizzare
        a,  // Numero di amici per caso
        g,  // Grado di amicizia per il songolo amico
        s,  // Somma dei gradi di amicizia positivi
        i,  // Contatore casi
        j;  // Contatore amici
    FILE *pfi,*pfo;
    pfi=fopen("input.txt","r");
    pfo=fopen("output.txt","w");

    fscanf(pfi,"%d",&t);

    for(i=0;i<t;i++) {
        s=0;
        fprintf(pfo,"Case #%d: ",i+1);
        fscanf(pfi,"%d",&a);
        for(j=0;j<a;j++) {
            fscanf(pfi,"%d",&g);
            if(g>0)
                s+=g;
        }
        fprintf(pfo,"%d\n",s);
    }

    fclose(pfi);
    fclose(pfo);
    return 0;
}
