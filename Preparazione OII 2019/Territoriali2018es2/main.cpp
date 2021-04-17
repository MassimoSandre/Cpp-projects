#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#define MAXLENGHT 100

int main()
{
    int t,
        lv,
        s1,
        s2,
        s3,
        s4,
        p1=0,
        p2=0,
        p3=0,
        p4=0,
        trov=1;
    // STRINGHE
    char v1[MAXLENGHT],
        v2[MAXLENGHT],
        v3[MAXLENGHT],
        v4[MAXLENGHT];
    // CONTATORI
    int i,j,k,m,n,l;

    FILE *pfi,*pfo;
    pfi=fopen("input.txt","r");
    pfo=fopen("output.txt","w");

    fscanf(pfi,"%d",&t);

    for(i=0;i<t;i++) {
        fscanf(pfi,"%d",&s1);
        fscanf(pfi,"%d",&s2);
        fscanf(pfi,"%d",&s3);
        fscanf(pfi,"%d",&s4);

        fscanf(pfi,"%d",&lv);

        fscanf(pfi,"\n%c",&v1[0]);
        for(j=1;j<s1;j++) {
            fscanf(pfi,"%c",&v1[j]);
        }

        fscanf(pfi,"\n%c",&v2[0]);
        for(j=1;j<s2;j++) {
            fscanf(pfi,"%c",&v2[j]);
        }

        fscanf(pfi,"\n%c",&v3[0]);
        for(j=1;j<s3;j++) {
            fscanf(pfi,"%c",&v3[j]);
        }

        fscanf(pfi,"\n%c",&v4[0]);
        for(j=1;j<s4;j++) {
            fscanf(pfi,"%c",&v4[j]);
        }

        for(j=0;j<s1-lv+1;j++) {
            for(k=0;k<s2-lv+1;k++) {
                for(m=0;m<s3-lv+1;m++) {
                    for(n=0;n<s4-lv+1;n++) {
                        trov=1;
                        for(l=0;l<lv;l++) {
                            if(v1[j+l]!=v2[k+l] || v1[j+l]!=v3[m+l] || v1[j+l]!=v4[n+l]) {
                                trov=0;
                            }
                        }
                        if(trov) {
                            p1 = j;
                            p2 = k;
                            p3 = m;
                            p4 = n;
                        }
                    }
                }
            }
        }

        fprintf(pfo,"Case #%d: %d %d %d %d\n",i+1,p1,p2,p3,p4);

    }

    fclose(pfi);
    fclose(pfo);
    return 0;
}
