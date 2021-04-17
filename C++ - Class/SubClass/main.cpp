#include <iostream>

class poligono {
protected:
    int x,y;
public:
    poligono() {
        printf("Inserire base del poligono: ");
        scanf("%d",&x);
        printf("Inserire altezza del poligono: ");
        scanf("%d",&y);
    }


};

class rect : public poligono {
public:
    int getArea() {
        return x*y;
    }
    int getPer() {
        return (x*2)+(y*2);
    }
};

int main()
{
    rect a;
    printf("Area: %d\n\nPerimetro: %d\n\n",a.getArea(),a.getPer());
    system("PAUSE");
    return 0;
}
