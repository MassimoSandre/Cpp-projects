#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#define MAXLENGHT 1000

int main()
{
    int t,
        c,
        r[MAXLENGHT],
        nr=0;

    bool finish=0;

    int i,j,s,f,l;

    FILE *pfi,*pfo;
    pfi=fopen("input.txt","r");
    pfo=fopen("output.txt","w");

    fscanf(pfi,"%d",&t);

    for(i=0;i<t;i++) {
        fscanf(pfi,"%d",&c);
        for(j=0;j<c;j++) {
            fscanf(pfi,"%d",&r[j]);
        }
        finish=false;
        nr=0;
        while(!finish) {
            printf(" %d %d %d %d\n",r[0],r[1],r[2],r[3]);

            if(r[0]>0){
                s=0;
                j=1;
                while(r[j] != 0 && j<c) {
                    j++;
                }
                f=j;
                for(;s<f;s++) {
                    r[s]--;
                }
                nr++;
            }
            else {
                j=1;
                while(r[j] == 0 && j<c) {
                    j++;
                }
                if(j<c) {
                    s=j;
                    j++;

                while(r[j] != 0 && j<c) {
                    j++;
                }
                f=j;
                for(;s<f;s++) {
                    r[s]--;
                }
                nr++;
                }
                else{
                    finish=true;
                }

            }
        }
        fprintf(pfo,"Case #%d: %d\n",i+1,nr);
    }

    fclose(pfi);
    fclose(pfo);
    return 0;
}
