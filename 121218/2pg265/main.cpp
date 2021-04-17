#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXMAT 10

#define MAXGEN 50
#define MINGEN 1

int main()
{
    int a[MAXMAT][MAXMAT],b[MAXMAT][MAXMAT],m[MAXMAT][MAXMAT],s[MAXMAT][MAXMAT],n,i,j;
    srand(time(NULL));
    do {
        printf("Inserire il lato di una matrice: ");
        scanf("%d",&n);
        system("CLS");
        if(n<1||n>MAXMAT)
            printf("Si prega di inserire un valore positivo non maggiore di %d",MAXMAT);
    }while(n<1||n>MAXMAT);

    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            a[i][j]=rand()%(MAXGEN-MINGEN+1)+MINGEN;
        }
    }

    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            b[i][j]=rand()%(MAXGEN-MINGEN+1)+MINGEN;
        }
    }
    printf("Matrice 1:\n");
    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            printf("%d\t",a[i][j]);
        }
        printf("\b\n");
    }
    printf("\nMatrice 2:\n");
    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            printf("%d\t",b[i][j]);
        }
        printf("\b\n");
    }

    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            m[i][j]=a[i][j]*b[i][j];
            s[i][j]=a[i][j]+b[i][j];
        }
    }

    printf("Matrice Somma:\n");
    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            printf("%d\t",s[i][j]);
        }
        printf("\b\n");
    }
    printf("\nMatrice Prodotto:\n");
    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            printf("%d\t",m[i][j]);
        }
        printf("\b\n");
    }
    printf("\n\n");
    system("PAUSE");

    return 0;
}
