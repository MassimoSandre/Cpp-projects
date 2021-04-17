#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>

using namespace std;

int main()
{
    string str="";
    int n,
        b,
        r;
    printf("Inserire un numero in base decimale: ");
    scanf("%d",&n);
    printf("Inserire la base in cui convertire (da 2 a 16): ");
    scanf("%d",&b);
    while(n != 0) {
      r = n%b;
      n = n/b;
      switch(r) {
          case 0:
            str= "0"+str;
            break;
          case 1:
            str= "1"+str;
            break;
          case 2:
            str= "2"+str;
            break;
          case 3:
            str= "3"+str;
            break;
          case 4:
            str= "4"+str;
            break;
          case 5:
            str= "5"+str;
            break;
          case 6:
            str= "6"+str;
            break;
          case 7:
            str= "7"+str;
            break;
          case 8:
            str= "8"+str;
            break;
          case 9:
            str= "9"+str;
            break;
          case 10:
            str= "A"+str;
            break;
          case 11:
            str= "B"+str;
            break;
          case 12:
            str= "C"+str;
            break;
          case 13:
            str= "D"+str;
            break;
          case 14:
            str= "E"+str;
            break;
          case 15:
            str= "F"+str;
            break;
          default:
            exit(1);
            break;
        }
    }
    system("CLS");
    printf("Il numero inserito corrisponde a: ");
    cout << str;
    printf(" in base %d\n\n",b);
    system("PAUSE");
    return 0;
}
