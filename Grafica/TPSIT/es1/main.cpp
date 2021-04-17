#include <bits/stdc++.h>
#include <unistd.h>
#include <stdio.h>

using namespace std;

int main() {
    int a=2,b=4;
    int pid = fork();
    if(pid==0) {
        printf("Sono il processo figlio, il mio pid e':%dd\n\tn%d - %d = %d",getpid(),a,b,a-b);
    }
    else {
        printf("Sono il processo padre, il mio pid e':%dd\n\tn%d + %d = %d",getpid(),a,b,a+b);
    }
    return 0;
}
