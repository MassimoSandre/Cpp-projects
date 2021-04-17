#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "Pila.h"

int main()
{
    typedef struct {
        int x,y;
    } prova;
    Pila<prova> p;

    prova k;
    k.x = 13;
    k.y = 25;

    p.push(k);
    std::cout << "\npop: " << p.pop().x;
    return 0;
}
