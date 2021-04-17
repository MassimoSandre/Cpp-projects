#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#define NMAX 100

int nmin,poss,posst;

bool esiste(int l1, int l2, int v[NMAX][3],int pos,int x,int y) {
    bool flag;
    if(x < 0 || x > l2-1 || y < 0 || y > l1-1) {
        return false;
    }
    else {
        flag =true;
        for(int i = 0; i < pos; i++) {
            if(x == v[i][0] && y == v[i][1]) {
                flag = false;
            }
        }
        return flag;
    }
}

void confronta(int v[NMAX][3],int p) {
    bool flag = true;
    int temp;

    for (int i = 0; i < p ; i++) {
        //printf("F %d F",v[i][2]);
    }

    int malt = -1;
    for (int i = 0; i < p-1; i++) {
        if((v[i][2] > v[i+1][2] ? v[i][2]-v[i+1][2] : v[i+1][2]-v[i][2])> malt) {
            malt = (v[i][2] > v[i+1][2] ? v[i][2]-v[i+1][2] : v[i+1][2]-v[i][2]);
        }

        //printf("K %d K", malt);
    }
    /*for (int i = 0; i < p; i++) {
        printf("F %d F",v[i][2]);
    }
    system("PAUSE");
    system("CLS");
    printf("K %d K", malt);*/
    //printf("GG %d GG", nmin);
    if(nmin>malt) {
        nmin = malt;
      //  printf("MI STO INCAZZANTO - %d - TANTO", nmin);
    }
}

void calcolapercorsoCOMB(int m[NMAX][NMAX],int l1, int l2, int v[NMAX][3], int pos, int x, int y) {

    /*for(int ii = 0; ii < pos; ii++) {
        printf("\tN = %d | X = %d | Y = %d | V = %d\n",ii,v[ii][0],v[ii][1],v[ii][2]);
    }*/
    if(x == l2-1 && y == l1-1) {
        v[pos][0] = x;
        v[pos][1] = y;
        v[pos][2] = m[y][x];

        poss++;
       /* printf("percorso: %d", poss);
        for(int kk = 0; kk<pos+1;kk++) {
            printf("%4d",v[kk][2]);
        }
        system("PAUSE");*/
    }
    else {
        v[pos][0] = x;
        v[pos][1] = y;
        v[pos][2] = m[y][x];
        if(esiste(l1,l2,v,pos,x-1,y))
            calcolapercorsoCOMB(m,l1,l2,v,pos+1,x-1,y);
        if(esiste(l1,l2,v,pos,x,y+1))
            calcolapercorsoCOMB(m,l1,l2,v,pos+1,x,y+1);
        if(esiste(l1,l2,v,pos,x+1,y))
            calcolapercorsoCOMB(m,l1,l2,v,pos+1,x+1,y);
        if(esiste(l1,l2,v,pos,x,y-1))
            calcolapercorsoCOMB(m,l1,l2,v,pos+1,x,y-1);
    }
}

void calcolapercorso(int m[NMAX][NMAX],int l1, int l2, int v[NMAX][3], int pos, int x, int y, int tr) {
    if(x == l2-1 && y == l1-1) {
        v[pos][0] = x;
        v[pos][1] = y;
        v[pos][2] = m[y][x];
        if(posst == tr) {
            confronta(v,pos+1);
        }
        posst++;
    }
    else {
        v[pos][0] = x;
        v[pos][1] = y;
        v[pos][2] = m[y][x];
        if(esiste(l1,l2,v,pos,x-1,y))
            calcolapercorso(m,l1,l2,v,pos+1,x-1,y,tr);
        if(esiste(l1,l2,v,pos,x,y+1))
            calcolapercorso(m,l1,l2,v,pos+1,x,y+1,tr);
        if(esiste(l1,l2,v,pos,x+1,y))
            calcolapercorso(m,l1,l2,v,pos+1,x+1,y,tr);
        if(esiste(l1,l2,v,pos,x,y-1))
            calcolapercorso(m,l1,l2,v,pos+1,x,y-1,tr);
    }
}

int main()
{
    int m[NMAX][NMAX],v[NMAX][3];

    int t,i,j,k,l1,l2,c;

    FILE *pfi,*pfo;
    pfi=fopen("input.txt","r");
    pfo=fopen("output.txt","w");

    fscanf(pfi,"%d",&t);

    for(i = 0; i < t; i++) {
        nmin = INT_MAX;
        fscanf(pfi,"%d",&l1);
        fscanf(pfi,"%d",&l2);
        for(j = 0; j < l1; j++) {
            for(k = 0; k < l2; k++) {
                fscanf(pfi,"%d",&m[j][k]);
            }
        }
        if(i == 2) {
            for(j = 0; j < l1; j++) {
                for(k = 0; k < l2; k++) {
                    //printf("JJJ %d JJJ",m[j][k]);
                }
            }
        }
        poss = 0;
        calcolapercorsoCOMB(m,l1,l2,v,0,0,0);
       // printf("COMB: %d\n",poss);
        for( j = 0; j < poss; j++) {
            posst = 0;
            calcolapercorso(m,l1,l2,v,0,0,0,j);
        }
        fprintf(pfo,"Case #%d: %d\n",i+1,nmin);
        //printf("Case #%d: %d\n",i+1,nmin);
    }

    fclose(pfi);
    fclose(pfo);
    return 0;
}
