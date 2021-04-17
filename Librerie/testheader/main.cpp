#include <iostream>
#include <stdlib.h>
#include <limits.h>
#include "sandretti.h"

using namespace sandretti;

int main()
{
    int v[10];
    randArray(v,10,20,30);
    for(int i=0;i < 10;i++) {
        printf(" %d ",v[i]);
    }

    return 0;
}
