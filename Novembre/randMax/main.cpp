#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{
    int n,mx=INT_MIN,i;
    srand(time(NULL));
    for(i=0;i<10;i++) {
        n=(rand()%100)+1;
        if(n>mx)
            mx=n;
    }
    printf("Il numero maggiore generato e\' %d\n\n",mx);
    system("PAUSE");
    return 0;
}
