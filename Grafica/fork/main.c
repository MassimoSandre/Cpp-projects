#include <stdio.h>
#include <stdlib.h>

int main()
{
    int pid = fork();
    if(pid == 0) printf("ciao");
    return 0;
}
