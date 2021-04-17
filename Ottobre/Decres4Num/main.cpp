#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main()
{
    int a,
        b,
        c,
        d;
    int n1,
        n2,
        n3,
        n4;
    printf("Inserire 4 numeri:\n");
    scanf("%d %d %d %d",&a,&b,&c,&d);

    if(a == b && a == c && a == d) {
        n1 = a;
        n2 = a;
        n3 = a;
        n4 = a;
    }

    else {
        if(a >= b && a >= c && a >= d) {
            n1 = a;
            if(b <= a && b <= c && b <= d) {
                n4 = b;
                if(c >= d) {
                    n2 = c;
                    n3 = d;
                }
                else {
                    n2 = d;
                    n3 = c;
                }
            }
            if(c <= a && c <= b && c <= d) {
                n4 = c;
                if(b >= d) {
                    n2 = b;
                    n3 = d;
                }
                else {
                    n2 = d;
                    n3 = b;
                }
            }
            if(d <= a && d <= b && d <= c) {
                n4 = d;
                if(b >= c) {
                    n2 = b;
                    n3 = c;
                }
                else {
                    n2 = c;
                    n3 = b;
                }
            }
        }
        else {
            if(b >= a &&  b >= c && b >= d) {
                n1 = b;
                if(a <= b && a <= c && a <= d) {
                    n4 = a;
                    if(c >= d) {
                        n2 = c;
                        n3 = d;
                    }
                    else {
                        n2 = d;
                        n3 = c;
                    }

                }
                if(c <= a && c <= b && c <= d) {
                    n4 = c;
                    if(a >= d) {
                        n2 = a;
                        n3 = d;
                    }
                    else {
                        n2 = d;
                        n3 = a;
                    }
                }
                if(d <= a && d <= b && d <= c) {
                    n4 = d;
                    if(a >= c) {
                        n2 = a;
                        n3 = c;
                    }
                    else {
                        n2 = c;
                        n3 = a;
                    }
                }
            }
            else {
                if(c >= a && c >= b && c >= d) {
                    n1 = c;
                    if(a <= b && a <= c && a <= d) {
                        n4 = a;
                        if(b >= d) {
                            n2 = b;
                            n3 = d;
                        }
                        else {
                            n2 = d;
                            n3 = b;
                        }
                    }
                    if(b <= a && b <= c && b <= d) {
                        n4 = b;
                        if(a >= d) {
                            n2 = a;
                            n3 = d;
                        }
                        else {
                            n2 = d;
                            n3 = a;
                        }
                    }
                    if(d <= a && d <= b && d <= c) {
                        n4 = d;
                        if(a >= b) {
                            n2 = a;
                            n3 = b;
                        }
                        else {
                            n2 = b;
                            n3 = c;
                        }
                    }
                }
                else{
                    if(d >= a && d >= b && d >= c) {
                        n1 = d;
                        if(a <= b && a <= c && a <= d) {
                            n4 = a;
                            if(c >= b) {
                                n2 = c;
                                n3 = b;
                            }
                            else {
                                n2 = b;
                                n3 = c;
                            }
                        }
                        if(b <= a && b <= c && b <= d) {
                            n4 = b;
                            if(a >= c) {
                                n2 = a;
                                n3 = c;
                            }
                            else {
                                n2 = c;
                                n3 = a;
                            }
                        }
                        if(c <= a && c <= b && c <= d) {
                            n4 = c;
                            if(a >= b) {
                                n2 = a;
                                n3 = b;
                            }
                            else {
                                n2 = b;
                                n3 = a;
                            }
                        }

                    }
                    else {
                        exit(1);
                    }
                }
            }
        }
    }
    system("CLS");
    printf("Ordine descrescente: %d %d %d %d\n\n\n", n1,n2,n3,n4);
    printf("\nOrdine crescente: %d %d %d %d", n4,n3,n2,n1);
    system("PAUSE");
    return 0;
}
