#include <iostream>
#include <stdlib.h>
#include <stdio.h>



int main()
{
    int n1,
        n2,
        d1,
        d2,
        nt,
        dt,
        dv,
        a,
        b;
    char sl;
    printf("Inserire la prima frazione (a/b): ");
    scanf("%d%c%d",&n1,&sl,&d1);
    printf("Inserire la seconda frazione (c/d): ");
    scanf("%d%c%d",&n2,&sl,&d2);
    nt=n1*n2;
    dt=d1*d2;
    a=nt;
    b=dt;
    while(a!=b) {
        if(a>b)
            a-=b;
        else
            b-=a;
    }
    nt/=a;
    dt/=a;
    system("CLS");
    printf("%d/%d * %d/%d = %d/%d\n\n",n1,d1,n2,d2,nt,dt);
    system("PAUSE");
    return 0;
}
