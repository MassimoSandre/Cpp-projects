#include <stdio.h>
#include <stdlib.h>

bool eliminato(int g, int c) {
    return eliminato(g,c-2);
}

int main()
{
    FILE *pfi,*pfo;
    pfi = fopen("input.txt","r");
    pfo = fopen("output.txt","w");
    ///

    int t,g,r;
    fscanf(pfi,"%d",&t);
    for(int i = 0; i < t; i++) {
        fscanf(pfi,"%d",&g);
        for(i = 1; i<g; i+=2) {
            eliminato();
        }
    }

    ///
    fclose(pfi);
    fclose(pfo);
    return 0;
}
