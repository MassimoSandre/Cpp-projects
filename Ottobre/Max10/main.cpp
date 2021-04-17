#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{
    int v[10], m = INT_MIN;
    printf("Inserire 10 numeri: \n");
    for(int k = 0; k < 10; k++) {
        cin >> v[k];
    }
    int i = 0;

    while(i < 10){
        if(v[i] > m) {
            m = v[i];
        }
        i++;
    }
    printf("\nIl maggiore tra i numeri inseriti e\': %d\n\n", m);
    system("PAUSE");
    return 0;
}
