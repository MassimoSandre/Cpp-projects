#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main()
{
    srand(time(NULL));
    int m[10][10]={
        {1,1,1,1,1,1,1,1,1,1},
        {1,0,1,0,0,0,0,1,0,1},
        {1,1,0,1,1,1,1,0,1,1},
        {1,0,1,0,0,0,0,1,0,1},
        {1,0,1,0,1,1,0,1,0,1},
        {1,0,1,0,1,1,0,1,0,1},
        {1,0,1,0,0,0,0,1,0,1},
        {1,1,0,1,1,1,1,0,1,1},
        {1,0,1,0,0,0,0,1,0,1},
        {1,1,1,1,1,1,1,1,1,1}
    };
    for(int i = 0;i<10;i++) {
        for(int j=0;j<10;j++) {
            m[i][j]=rand()%(2);
        }
    }
    for(int i=0;i<10;i++) {
        for(int otto=0;otto<8;otto++) {
            for(int j=0;j<10;j++) {
                if(m[i][j]) {
                    for(int k=0;k<8;k++) {
                        printf("*");
                        usleep(rand()%6000);
                    }
                }
                else {
                    printf("\t");
                }
                usleep(rand()%6000);
            }
            usleep(rand()%60000);

        }
    }

    printf("\n\n");
    system("PAUSE");
    return 0;
}
