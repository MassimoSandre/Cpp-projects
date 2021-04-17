#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main()
{
    int f1,
        f2,
        ris,
        cont = 0;
    char op;
    printf("Inserire un operazione base:\n");
    scanf("%d",&f1);
    scanf("%c",&op);
    scanf("%d",&f2);

    switch(op) {
        case '*':
            ris = f1*f2;
            printf("%d%c%d = %d",f1,op,f2,ris);
            break;
        case '%':
            if(f2!= 0) {
                ris = f1%f2;
                printf("%d%c%d = %d",f1,op,f2,ris);
            }
            else
                printf("Non è possibile eseguire divisioni per 0");
            break;
        case '+':
            ris = f1+f2;
            printf("%d%c%d = %d",f1,op,f2,ris);
            break;
        case '-':
            ris = f1-f2;
            printf("%d%c%d = %d",f1,op,f2,ris);
            break;
        case '/':
            if(f2!= 0) {
                float div =(float)f1/f2;
                printf("%d%c%d = %f",f1,op,f2,div);
            }
            else
                printf("Non è possibile eseguire divisioni per 0");
            break;
        default:
            printf("L'operatore %c non è stato riconosciuto", op);
            break;
    }
    printf("\n\n");
    system("PAUSE");

    return 0;
}
