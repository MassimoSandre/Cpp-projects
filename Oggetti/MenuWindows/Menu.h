#define INVIO 13
#define ESC 27
#define ARROW -32
#define FRECCIASU 72
#define FRECCIAGIU 80
#define FREC 16

typedef char* tVetVoc;

class Menu {
protected:
    HWND myConsole;
    HDC mdc;

    tVetVoc *voc;
    int numVoc,posX,posY;
public:
    Menu(int,int,int,tVetVoc*);
};

Menu::Menu(int posX,int posY, int numVoc, tVetVoc *voc) {
    this->posX = posX;
    this->posY = posY;
    this->numVoc = numVoc;
    this->voc = voc;

    this->myConsole = GetConsoleWindow();
    this->mdc = GetDC(this->myConsole);

    SetConsoleCursorPosition(mdc,{30,30});
    printf("vaffa");
}
