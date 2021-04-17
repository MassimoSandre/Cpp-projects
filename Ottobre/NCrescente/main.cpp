#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
using namespace std;

void ordine(int a, int b, int c) {
    if(a == b && b == c) {
        printf("\nOrdine decrescente: %d %d %d",a,b,c);
        printf("\nOrdine crescente: %d %d %d",c,b,a);
    }
    else {
        if(a >= b && b >= c) {
            printf("\nOrdine decrescente: %d %d %d",a,b,c);
            printf("\nOrdine crescente: %d %d %d",c,b,a);
        }
        else {
            if(a >= c && c >= b) {
                printf("\nOrdine decrescente: %d %d %d",a,c,b);
                printf("\nOrdine crescente: %d %d %d",b,c,a);
            }
            else {
                if(b >= a && a >= c) {
                    printf("\nOrdine decrescente: %d %d %d",b,a,c);
                    printf("\nOrdine crescente: %d %d %d",c,a,b);
                }
                else {
                    if(b >= c && c >= a) {
                        printf("\nOrdine decrescente: %d %d %d",b,c,a);
                        printf("\nOrdine crescente: %d %d %d",a,c,b);
                    }
                    else {
                        if(c >= a && a >= b) {
                            printf("\nOrdine decrescente: %d %d %d",c,a,b);
                            printf("\nOrdine crescente: %d %d %d",b,a,c);
                        }
                        else {
                            if(c >= b && b >= a) {
                                printf("\nOrdine decrescente: %d %d %d",c,b,a);
                                printf("\nOrdine crescente: %d %d %d",a,b,c);
                            }
                            else
                                exit(1);
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    int a,
        b,
        c;
    printf("Inserire 3 numeri\n");
    scanf("%d %d %d",&a,&b,&c);
    ordine(a,b,c);
    printf("\n");
    system("PAUSE");
    return 0;
}
