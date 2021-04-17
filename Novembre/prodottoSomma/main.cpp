#include <iostream>
#include <stdlib.h>
#include <stdio.h>


int main()
{
    int a,b,i,prod=0;
    printf("Inserire 2 numeri: ");
    scanf("%d %d",&a,&b);
    system("CLS");
    printf("%d * %d =",a,b);
    if(b<0){
        a*=-1;
        b*=-1;
    }
    for(i=0;i<b;i++) {
        prod+=a;
    }
    printf(" %d\n\n",prod);
    system("PAUSE");
    return 0;
}
