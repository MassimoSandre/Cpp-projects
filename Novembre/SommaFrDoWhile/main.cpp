#include <iostream>
#include <stdio.h>
#include <stdlib.h>


int main()
{
    int n1,
        n2,
        d1,
        d2,
        nt,
        dt,
        div,
        a,
        b;
    char sl;
    printf("Inserire la prima frazione (a/b): ");
    scanf("%d%c%d",&n1,&sl,&d1);
    printf("Inserire la seconda frazione (c/d): ");
    scanf("%d%c%d",&n2,&sl,&d2);
    dt = d1*d2;
    nt = ((dt/d1)*n1)+((dt/d2)*n2);
    a=nt;
    b=dt;
    if(a!=b) {
        do {
            if(a>b)
                a-=b;
            else
                b-=a;
        }while(a!=b);
    }
    div = a;
    dt/=div;
    nt/=div;
    system("CLS");
    printf("%d/%d + %d/%d = %d/%d\n\n", n1,d1,n2,d2,nt,dt);
    system("PAUSE");
    return 0;
}
