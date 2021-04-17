#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    char n[100];
    int lung;

    printf("Inserire una frase: ");
    gets(n);

    lung=strlen(n);
    printf("La frase inserita e\' composta da %d caratteri\n\n",strlen(n));
    system("PAUSE");
    return 0;
}
