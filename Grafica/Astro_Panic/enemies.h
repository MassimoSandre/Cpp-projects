#define LIM_LEFT 10             // distanza minima raggiungibile dalle navicelle dal bordo di sinistra
#define LIM_TOP 10              // distanza minima raggiungibile dalle navicelle dal bordo superiore
#define LIM_RIGHT 10            // distanza minima raggiungibile dalle navicelle dal bordo di destra
#define LIM_BOTTOM 200          // distanza minima dal bordo inferiore in cui le navicelle possono essere generate
#define LIM_BOTTOM_MOVEMENT 80  // distanza minima raggiungibile dalle navicelle dal bordo inferiore
#define MAXENEMY 100            // numero massimo di nemici gestibili contemporaneamente (all'ondata 20 vengono generati 94 nemici)
#define MAXSCOSTA 8             // massimo cambiamento di velocità
#define MAXANIMATIONIMAGES 3    // numero massimo di frame per l'animazione dell'esplosione
#define FRAMEPERIMAGE 4         // numero di fps per ogni frame dell'animazione

#include "player.h"

// definisco la struttura che identifica le navicelle
typedef struct sEnemy {
    int x; // posizione sull'asse x
    int y; // posizione sull'asse y
    int dir; // direzione in gradi
    int speed; // velocità
    int tle; // (time to live) essenzialmente il numero di frame dell'animazione che devono essere eseguiti (se la nave non sta esplodendo questa variabile vale -1)
    int animationFrameLeft; // fps rimasti al frame attuale dell'animazione
} enemy;

class Enemies {
private:
    // Il vettore en conterrà tutte le navicelle finché queste non verranno distrutte
    vector<enemy> en;
    // il vettore expAnimation di è un vettore di puntatori void. Conterrà tutti i frame dell'animazione di esplosione
    void** expAnimation;
    // la variabile nImagesAnimation contiene il numero di frame dell'animazione di esplosione
    int nImagesAnimation;
    int altezza,   // altezza dell'immagine della navicella
        larghezza, // larghezza dell'immagine della navicella
        num;       // numero di nemici attualmente esistenti
    // il puntatore void sprite punterà all'immagine della navicella
    void *sprite;
    int maxSpeed, // velocità massima della navicella
        minSpeed; // velocità minima della navicella
public:
    // Costruttore della classe Enemies
    Enemies();
    // Distruttore della classe Enemies
    ~Enemies();

    // la funzione update si occupa di aggiornare le posizioni, le direzioni e le velocità delle navicelle nemiche
    void update();
    // la funzione render si occupa di renderizzare le navicelle
    void render();
    // la funzione generateEnemies genera le navicelle
    // necessita del numero di navicelle da generare, la velocità minima e la velocità massima raggiungibili dalle navicelle
    void generateEnemies(int hm, int min_speed, int max_speed);
    // la funzine setImage imposta l'immagine della navicella
    // necessita di un puntatore all'immagine, la larghezza e l'altezza dell'immagine
    void setImage(void *image,int larg, int alte);
    // la funzione addExpImage aggiunge un nuovo frame per l'animazione
    // necessita del puntatore al frame da aggiungere
    void addExpImage(void* image);
    // la funzione getNumber ritorna il numero di nemici attualmente esistenti (compresi quelli che stanno esplodendo, in modo che l'animazione possa sempre terminare)
    int getNumber();
    // la funzione collide verifica se date le coordinate di 2 punti, una delle navicelle collide con il rettangolo formato
    // necessita delle coordinate del punto in alto a sinistra, delle coordinate del punto di basso a destra, la variabile booleana rem che indica se bisogna eliminare la navicella e assegnare punti al giocatore oppure no, un oggetto player per, eventualmente, assegnarli dei punti, e la wave attuale, per il calcolo del punteggio
    bool collide(int left,int top, int right, int bottom, bool rem, Player& pl, int wave);
};

Enemies::Enemies() {
    // riazzero il contatore delle navicelle
    num = 0;
    // imposto la dimensione del vettore delle navicelle a MAXENEMY
    en.resize(MAXENEMY);
    // riazzero il contatore di frame di animazione
    nImagesAnimation = 0;
    // alloco il vettore di puntatori void expAnimation
    expAnimation = (void**)malloc(sizeof(void*)*MAXANIMATIONIMAGES);
}

Enemies::~Enemies() {
    // libero la memoria occupata dal vettore di puntatori void expAnimation
    free(expAnimation);
    // libero la memoria occupata dall'immagine delle navicelle
    free(sprite);
}

void Enemies::update() {
    int scoX, // scostamento sulla x
        scoY; // scostamento sulla y

    // scorro tutte le navicelle
    for(int i = 0; i < num;i++) {
        // se la navicella sta esplodendo
        if(en[i].tle!=-1) {
            // se l'animazione di esplosione è finita
            if(en[i].tle==0) {
                // elimino la navicella
                num-=1;
                for(int j = i; j < num;j++) {
                    en[j] = en[j+1];
                }
                i--;
                continue;
            }
            // (il fatto che la navicella continui a muoversi anche mentre sta esplodendo è voluto)
        }
        bool rimbalzo = false;
        // se la navicella si è scontrata con il limite sinistro
        if(en[i].x<LIM_LEFT&&(en[i].dir>90||en[i].dir<270)) {
            rimbalzo = true;
            // ruoto l'angolo in modo che il rimbazo sia verosimile
            if(en[i].dir<=180)en[i].dir = 180-en[i].dir;
            else en[i].dir = 540-en[i].dir;
        }
        // se la navicella si è scontrata con il limite destro
        if(en[i].x+larghezza>getmaxx()-LIM_RIGHT&&(en[i].dir<90||en[i].dir>270)) {
            rimbalzo = true;
            // ruoto l'angolo in modo che il rimbazo sia verosimile
            if(en[i].dir<=180)en[i].dir = 180-en[i].dir;
            else en[i].dir = 540-en[i].dir;
        }
        // se la navicella si è scontrata con il limite superiore
        if(en[i].y<LIM_TOP&&(en[i].dir>0||en[i].dir<180)) {
            rimbalzo = true;
            // ruoto l'angolo in modo che il rimbazo sia verosimile
            en[i].dir=360-en[i].dir;
        }
        // se la navicella si è scontrata con il limite inferiore
        if(en[i].y+altezza>getmaxy()-LIM_BOTTOM_MOVEMENT&&(en[i].dir>180)) {
            rimbalzo = true;
            // ruoto l'angolo in modo che il rimbazo sia verosimile
            en[i].dir=360-en[i].dir;
        }

        // converto il valore della direzione della navicella da gradi a radianti
        double ang = (double)en[i].dir/180*3.1415;
        // calcolo lo spostamento sull'asse x
        scoX = en[i].speed*cos(ang);
        // calcolo lo spostamento sull'asse y
        scoY = en[i].speed*sin(ang);

        // applico le trasformazioni
        en[i].x+=scoX;
        en[i].y-=scoY;

        // se la navicella ha rimbalzato
        if(rimbalzo) {
            // inizializzo il seme
            srand(time(NULL));
            // cambio la velocità di un valore random compreso tra -MAXSCOSTA e +MAXSCOSTA
            en[i].speed += rand()%(2*MAXSCOSTA+1)-MAXSCOSTA;
            // mi assicuro che la velocità non superi i limiti imposti
            en[i].speed = max(min(en[i].speed,maxSpeed),minSpeed);
        }
    }
}

void Enemies::render() {
    // scorro tutte le navicelle
    for(int i = 0; i < num;i++) {
        // se la navicella non sta esplodento
        if(en[i].tle == -1) {
            // stampo l'immagine standard della navicella
            putimage(en[i].x,en[i].y,sprite,0);
        }
        else { // altrimenti
            // se ci sono ancora dei frame da mostrare
            if(en[i].tle > 0){
                // stampo l'immagine del frame attuale dell'animazione
                putimage(en[i].x,en[i].y,expAnimation[nImagesAnimation-(en[i].tle)],0);
                // decremento il contatore dei fps per il frame attuale
                en[i].animationFrameLeft--;
                // se il numero di fps rimasti per il frame attuale arriva a 0
                if(en[i].animationFrameLeft==0) {
                    // passo al frame successivo, decrementando il tle della navicella
                    en[i].tle--;
                    // reimposto il numero di fps per il frame attuale
                    en[i].animationFrameLeft = FRAMEPERIMAGE;
                }
            }
        }
    }
}

void Enemies::generateEnemies(int hm, int min_speed, int max_speed) {
    // imposto la velocità minima
    minSpeed = min_speed;
    // imposto la velocità massima
    maxSpeed = max_speed;
    // inizializzo il seme
    srand(time(NULL));
    // imposto il numero di navicelle da generare (se supera il massimo accettabile, lo riporto a MAXENEMY)
    num = min(hm,MAXENEMY);
    // genero le navicelle
    for(int i = 0; i < min(hm,MAXENEMY);i++) {
        enemy new_en;
        int temp_max1=getmaxx()-LIM_RIGHT-larghezza,temp_max2=getmaxy()-LIM_BOTTOM;
        // genero la posizione x della nuova navicella
        new_en.x = rand()%(temp_max1-LIM_LEFT+1)+LIM_LEFT;
        // genero la posizione y della nuova navicella
        new_en.y = rand()%(temp_max2-LIM_TOP+1)+LIM_TOP;
        // genero l'angolo in gradi della nuova navicella
        new_en.dir = rand()%360;
        // genero la velocità della nuova navicella
        new_en.speed = rand()%(maxSpeed-minSpeed+1)+minSpeed;
        // imposto il tle a -1 dato che la navicella appena generata non sta esplodendo
        new_en.tle = -1;
        // inserisco nel vettore delle navicelle la nuova navicella appena generato
        en[i]=(new_en);
    }
}

void Enemies::setImage(void *image,int larg, int alte) {
    // assegno l'immagine per le navicelle
    sprite = image;
    // assegno la larghezza dell'immagine delle navicelle
    larghezza = larg;
    // assegno la altezza dell'immagine delle navicelle
    altezza = alte;
}

void Enemies::addExpImage(void* image) {
    // aggiungo il frame appena inserito in posizione nImagesAnimation, poi incremento il contatore nImagesAnimation
    expAnimation[nImagesAnimation++] = image;
}

int Enemies::getNumber() {
    // ritorno il numero di navicelle rimaste
    return num;
}

bool Enemies::collide(int left,int top, int right, int bottom, bool rem, Player& pl, int wave) {
    int col = false;
    // scorro tutte le navicelle
    for(int i = 0; i < num;i++) {
        // se la navicella sta esplodendo non serve verificare che collida, infatti non può danneggiare il giocatore e non deve essere eliminata di nuovo da un proiettile
        if(en[i].tle!=-1) continue;
        // verifico se la navicella collide con il rettangolo descritto
        col = (left>en[i].x&&left<en[i].x+larghezza&&top>en[i].y&&top<en[i].y+altezza);
        col = col || (right>en[i].x&&right<en[i].x+larghezza&&top>en[i].y&&top<en[i].y+altezza);
        col = col || (left>en[i].x&&left<en[i].x+larghezza&&bottom>en[i].y&&bottom<en[i].y+altezza);
        col = col || (right>en[i].x&&right<en[i].x+larghezza&&bottom>en[i].y&&bottom<en[i].y+altezza);

        // se la navicella collide
        if(col) {
            // se la nave va eliminata e il punteggio assegnato al giocatore
            if(rem) {
                // avvio l'animazione di esplosione
                en[i].tle = nImagesAnimation;
                // imposto il numero di fps per il frame attuale
                en[i].animationFrameLeft = FRAMEPERIMAGE;
                // riproduco il suono di esplosione della navicella
                PlaySound(TEXT("sounds/exp.wav"),NULL,SND_FILENAME | SND_ASYNC);

                // assegno al giocatore un punteggio in funzione dell'altezza della navicella e moltiplicato per l'ondata attuale
                pl.addScore((pl.getPlayerY()-en[i].y)/30*wave);
            }
            // dato che è impossibile che un proiettile colpisca 2 navicelle (idealmente) e che non è importante il giocatore viene colpito da 2 navicelle contemporaneamnete, non serve cercare altre collisioni
            break;
        }
    }
    return col;
}
