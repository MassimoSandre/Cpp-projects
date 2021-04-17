#include <iostream>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int n, mx=INT_MIN;
    do{
        printf("Inserire un numero (terminare con 0): ");
        scanf("%d",&n);
        system("CLS");
        if(n!=0){
            if(mx<n)
                mx=n;
        }
    }while(n!=0);
    printf("Il numero maggiore tra quelli inseriti e\' %d\n\n",mx);
    system("PAUSE");
    return 0;
}
