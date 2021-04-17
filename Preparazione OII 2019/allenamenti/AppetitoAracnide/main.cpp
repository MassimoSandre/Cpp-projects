#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int mn,bestp[30];

void calcolaPercorsi(int tela[30][2], int fil,int pos,bool isFirstTime, bool app,int sp,int v[], int old) {
    v[sp] = pos;
    printf("FF %d FF",pos);

   /* for(int i = 0; i < sp+1; i++) {
        printf("%4d", v[i]);
    }*/
    //system("PAUSE");
    //system("CLS");
    if(!isFirstTime && pos == 0) {


        //printf("APP: %d    SP: %d   MN: %d\n",app,sp,mn);
        if(app && sp < mn) {
            mn = sp;

            for(int i = 0; i < mn+1; i++) {
                bestp[i] = v[i];
            }
        }
        printf("TTT %d TTT",sp);
    }
    else {
        for(int i = 0; i < fil; i++) {
            if(tela[i][0] == pos && old != i) {
                calcolaPercorsi(tela, fil, tela[i][1],false,!app,sp+1,v,i);
            }
            else {
                if(tela[i][1] == pos && old != i) {
                    calcolaPercorsi(tela,fil,tela[i][0],false,!app,sp+1,v,i);
                }
            }
        }
    }
}

int main()
{
    FILE *pfi,*pfo;
    pfi = fopen("input.txt","r");
    pfo = fopen("output.txt","w");
    ///

    int t,n,f,tela[30][2],v[30]={0};

    mn = INT_MAX;
    fscanf(pfi,"%d",&n);
    fscanf(pfi,"%d",&f);
    for(int j = 0; j<f; j++) {
        fscanf(pfi,"%d",&tela[j][0]);
        fscanf(pfi,"%d",&tela[j][1]);
    }



    for(int i = 0; i<f; i++) {
        printf("%d  %d\n",tela[i][0],tela[i][1]);
    }

    system("PAUSE");
    calcolaPercorsi(tela,f,0,true,false,0,v,-1);
    fprintf(pfo,"%d\n",mn);
    for(int j = 0; j < mn+1;j++) {
        fprintf(pfo,"%d ",bestp[j]);
    }


    ///
    fclose(pfi);
    fclose(pfo);
    return 0;
}
