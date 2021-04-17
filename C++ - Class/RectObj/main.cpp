#include <iostream>
#include <math.h>

class rect {
private:
    int x,y;
public:
    char unit[10];
    rect() {
        printf("Inserire base del rettangolo: ");
        scanf("%d",&x);
        printf("Inserire altezza del rettangolo: ");
        scanf("%d",&y);
        printf("Inserire l\'unita\' di misura: ");
        scanf("%s",unit);
    }

    int getArea() {
        return x*y;
    }
    int getPer() {
        return (x*2)+(y*2);
    }
    float getDiag() {
        return sqrt((pow(x,2)+pow(y,2)));
    }
};

int main()
{
    rect a;

    system("CLS");
    printf("Area del rettangolo: %d %s^2\n\nPerimetro del rettangolo: %d %s\n\nDiagonale del rettangolo: %.3f %s\n\n",a.getArea(),a.unit,a.getPer(),a.unit,a.getDiag(),a.unit);
    system("PAUSE");
    return 0;
}
