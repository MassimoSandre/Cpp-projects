#include <Windows.h>
#include <iostream>
#include <cmath>
#include <math.h>
#include <conio.h>

#define LARGHEZZA 640
#define ALTEZZA 300

#define ZOOMX 20
#define ZOOMY 40
// larghezza 640
// altezza 300
using namespace std;

int main()
{
    HWND myConsole = GetConsoleWindow();
    HDC mdc = GetDC(myConsole);

    COLORREF BASE = RGB(255,255,255);
    COLORREF FUNZ = RGB(255,0,0);
    COLORREF BLAC = RGB(0,0,0);

    float x,y;
    // disegno l'asse x
    for(int i = 0; i < LARGHEZZA;i++) {
        SetPixel(mdc,i,ALTEZZA/2,BASE);
    }
    // disegno l'asse y
    for(int i = 0; i < ALTEZZA;i++) {
        SetPixel(mdc,LARGHEZZA/2,i,BASE);
    }

    // disegno la funzione y = 2^x
    bool secondo = false;
    while(true) {
        for(double i = 0; i < LARGHEZZA/ZOOMX;i+=0.0001) {
            x = (i-LARGHEZZA/(2*ZOOMX));
            /// DESCRIVERE LA FUNZIONE QUI:
                ///y = sin(x)*ZOOMY;
            y = sin(x)*ZOOMY;
            /// ---------------------------
            x*=ZOOMX;
            SetPixel(mdc,(x+LARGHEZZA/2),ALTEZZA/2-y,(secondo?BLAC:FUNZ));
        }
        secondo =!secondo;
    }

    char c = getch();

    ReleaseDC(myConsole,mdc);


    //cin.ignore();
    printf("%c",c);

    return 0;
}
