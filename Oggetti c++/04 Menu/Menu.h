#include <string.h>

//******************************************************************************
// COSTANTI
//******************************************************************************
#define MAXVETVOC 50    	// Massimo numero delle voci del menù
#define MAXVOC 20           // Massima lunghezza delle voci
#define ARROW -32			// Primo ASCII carattere freccia cursore
#define FRESU 72			// ASCII freccia su
#define FREGIU 80			// ASCII freccia giu'
#define INVIO 13			// ASCII invio
#define ESC 27				// ASCII ESC
#define D 2					// Distanza righe tra voci menu
//******************************************************************************
// TIPI
//******************************************************************************
typedef char tVoce[MAXVOC];			// Tipo singola voce menu
typedef tVoce tVetVoc[MAXVETVOC];	// Tipo vettore menu

//******************************************************************************
class tMenu
//******************************************************************************
    {
    protected:
    int NumVoc,     //Numero voci  del Menu
        PosMenX,    //Colonna spigolo sx menu
        PosMenY;    //Colonna Spigolo dx menu
    tVetVoc VetVoc; //Voci del Menu
    public:
    tMenu(int IniPosX, int IniPosY, int IniNumVoc, tVetVoc IniVetVoc);
    ~tMenu();
    void Show();	// Mostra menu
    void Hide();	// Nascondi menu
    int Choice();	// Scelta voce menu
    };

//Implementazione dei metodi
tMenu::tMenu(int IniPosX, int IniPosY, int IniNumVoc, tVetVoc IniVetVoc)    //Costruttore
    {
    if(IniPosX<4)
        {
        IniPosX=4;
        }
    PosMenX=IniPosX;
    PosMenY=IniPosY;
    NumVoc=IniNumVoc;
    for (int i=0;i<NumVoc;i++)
        {
        strcpy(VetVoc[i],IniVetVoc[i]);
        }
    };
tMenu::~tMenu()         //Distruttore
    {
    };
void tMenu::Show()      //Visualizza il menu
    {
    for (int i=0;i<NumVoc;i++)			// Visualizza tutte le voci del menu
        {
        textcolor(WHITE);				// Colore standard voci menu
        gotoxy(PosMenX,PosMenY+(i*D));	// Posiziona singola voce
        cout<<VetVoc[i]<<"\n";
        }
    };
void tMenu::Hide()      //Nasconde il menu
    {
        for (int i=0;i<NumVoc;i++)
        {
        gotoxy(PosMenX,PosMenY+(i*D));			// Posiziona cancellazione voce menu
        for(int j=0;j<strlen(VetVoc[i]);j++)	// Cancella voci menu stampate
            {
            cout<<" ";
            }
        }
        cout<<"\n\n";
    };
int tMenu::Choice()     //Gestisce i tasti freccia e restituisce il numero della scelta effettuata alla pressione del tasto  INVIO. Se viene premuto ESC restituisce 0.
    {
    char Fre=16, 		// ASCII carattere freccetta indicatore voce menu
		 Tas;			// Carattere acquisito
    int Con=1;			// Contatore voce menu
    do
        {
        gotoxy(PosMenX-2,PosMenY+(Con-1)*D);	// Posiziona freccetta scelta su voce menu (Con)
        textcolor(LIGHTRED);					// Colore freccetta indicatore
        cout<<Fre;								// Stampa freccetta indicatore
        textcolor(YELLOW);						// Colore voce menu selezionata
        gotoxy(PosMenX,PosMenY+((Con-1)*D));	// Posizione della voce menu selezionata
        cout<<VetVoc[Con-1]<<"\n";				// Colora voce menu selezionata
        gotoxy(80,25);
        Tas=getch();
        if(int(Tas)==ARROW)		// Intercetta freccia movimento cursore
                {
                //le freccette utilizzano un doppio input ed il primo ha valore -32
                Tas=getch();	// Secondo ASCII per freccetta movimento
                }
        gotoxy(PosMenX-2,PosMenY+(Con-1)*D);	// Rimuove freccetta indicatore da voce menu
        cout<<"  ";
        textcolor(WHITE);
        gotoxy(PosMenX,PosMenY+((Con-1)*D));	// Colora voce menu come standard
        cout<<VetVoc[Con-1]<<"\n";
        if(Tas==FREGIU)			// Freccia giu': aumenta scelta, portando a 1 se supera l'ultima
            {
            Con=Con+1;
            if(Con>NumVoc)
                {
                Con=1;
                }
            }
        else if (Tas==FRESU)	// Freccia su: diminuisce scelta, portando a 4 se supera la prima
            {
            Con=Con-1;
            if(Con<1)
                {
                Con=NumVoc;
                }
            }

        }
    while((Tas!=INVIO)&&(Tas!=ESC));	// Ripeti fino a che premuto INVIO oppure ESC
    textcolor(WHITE);
    if (Tas==INVIO)				// Se INVIO restituisce la scelta fatta
        {
        return Con;
        }
    else						// Se ESC esce senza restituire nessuna scelta
        {
        return (0);
        }
	};


