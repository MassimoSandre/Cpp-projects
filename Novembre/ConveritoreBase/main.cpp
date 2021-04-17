#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>

using namespace std;

int main()
{
    string str="";
    int n,
        r;
    printf("Inserire un numero in base decimale: ");
    scanf("%d",&n);

    while(n != 0) {
      r = n%2;
      n = n/2;
      switch(r) {
          case 0:
            str= "0"+str;
            break;
          case 1:
            str= "1"+str;
            break;
      }
    }
    system("CLS");
    printf("Il numero inserito corrisponde a: ");
    cout << str<<endl<<endl;
    system("PAUSE");
    return 0;
}
