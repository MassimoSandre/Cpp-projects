#define SPEED 20        // velocità di spostamento verso l'alto dei proiettili
#define COLCLASS 144    // dimensione delle classi di colore
#define MAXBULLET 20    // numero massimo di proiettili che possono essere gestiti contemporaneamnete

class Bullets {
private:
    // vettore di coppie che rappresentano le coordinate (x,y) dei vari proiettili
    vector<pair<int,int>> bu;
    // la variabile num conterrà il numero di proiettili da gestire
    int num;
public:
    // Costruttore della classe Bullets
    Bullets();
    // Distruttore della classe Bullets
    ~Bullets();

    // La funzione update si occupa di aggiornare la posizione dei proiettili e verificarne le collisioni
    // necessita di un oggetto Enemies per verificare le collisioni con i nemici, un oggetto Player per assegnare punti al giocatore e del numero di ondata attuale, che fa parte del calcolo del punteggio
    void update(Enemies &e, Player& pl, int wave);
    // La funzione render si occupa di renderizzare i proiettili
    void render();
    // la funzione creaBullets si occupa di svuotare il vettore dei proiettili
    void clearBullets();
    // La funzione add aggiunge un proiettile al vettore
    // necessita delle coordinate x e y del proiettile da aggiungere
    void add(int x, int y);
};

Bullets::Bullets() {
    // imposto la dimensione del vettore a MAXBULLET
    bu.resize(MAXBULLET);
    // azzero il contatore dei proiettili
    num = 0;
}
Bullets::~Bullets() {}

void Bullets::update(Enemies &e, Player& pl, int wave) {
    // scorro tutti i proiettili
    for(int i = 0; i < num;i++) {
        // sposto i proiettili di SPEED verso l'alto
        bu[i].second -=SPEED;
        // se il proiettile è uscito dallo schermo o se ha colliso con un nemico
        if(bu[i].second < 0 || e.collide(bu[i].first-5,bu[i].second-7,bu[i].first+5,bu[i].second+7, true, pl,wave)) {
            // elimino il proiettile
            for(int j = i; j < num-1;j++) {
                bu[j] = bu[j+1];
            }
            // decremento il contatore dei proiettili
            num--;
        }
    }
}

void Bullets::render() {
    // scorro tutti i proiettili
    for(int i = 0; i < num;i++) {
        // imposto il colore in base alla coordinata y
        setcolor(5-bu[i].second/COLCLASS);
        // disegno il rettangolo che forma il proiettile
        rectangle(bu[i].first-5,bu[i].second-7,bu[i].first+5,bu[i].second+7);
        // riempo il rettangolo che forma il proiettile
        setfillstyle(SOLID_FILL,5-bu[i].second/COLCLASS);
        floodfill(bu[i].first,bu[i].second,5-bu[i].second/COLCLASS);
    }
}

void Bullets::clearBullets() {
    // azzero il contatore dei proiettili
    num = 0;
}

void Bullets::add(int x, int y) {
    // inserisco (in posizione num) il nuovo proiettile nel vettore e, dopo, incremento il contatore dei proiettili
    bu[num++]=(make_pair(x,y));
}
