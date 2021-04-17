#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
    int pid = fork();
    if(pid == 0) printf("ciao");
    return 0;
}
