class Player {
private:
    int posX,  // posizione sull'asse x del giocatore
        posY,  // posizione sull'asse y del giocatore
        lives, // numero di vite del giocatore
        alt,   // altezza dell'immagine del giocatore
        lar,   // larghezza dell'immagine del giocaotre
        score; // punteggio del giocatore
    // il puntatore void sprite punterà all'immagine del giocatore
    void *sprite;

public:
    // Costruttore della classe Player
    // necessita delle coordinate iniziali del giocatore
    Player(int x, int y);
    // Distruttore della classe Player
    ~Player();

    // la funzione setImage imposta l'immagine del giocatore
    // necessita del puntatore all'immagine, la larghezza e l'altezza dell'immagine
    void setImage(void *p, int larghezza, int altezza);
    // la funzione render renderizza il giocatore
    void render();
    // la funzione getPosition ritorna la posizione sull'asse X del giocatore
    int getPosition();
    // la funzione getPlayerY ritorna la posizione sull'asse Y del giocatore
    int getPlayerY();
    // la funzione setPosition imposta la posizione del giocatore
    // necessita della nuova posizione del giocatore e di un valore booleano che indica se la posizione va aggiustata in modo che non esca dai bordi
    void setPosition(int pos, bool adjust);
    // la funzione setLives imposta il numero di vite al giocatore
    // necessita del nuovo numero di vite del giocatore
    void setLives(int l);
    // la funzione getLives ritorna il numero di vite del giocatore
    int getLives();
    // la funzione resettaScore posta a 0 il punteggio del giocatore
    void resetScore();
    // la funzione addScore aggiunge un punteggio all'utente
    // necessita del punteggio da aggiungere
    void addScore(int sc);
    // la funzione getScore ritorna il numero di punti dell'utente
    int getScore();
};

Player::Player(int x,int y) {
    // imposto la pozizione del giocaotre
    posX = x;
    posY = y;
}

Player::~Player() {
    // libero la memoria occupata dall'immagine del giocatore
    free(sprite);
}

void Player::setImage(void *p, int larghezza, int altezza) {
    // imposto l'immagine corrispondente al giocatore
    sprite = p;

    // imposto l'altezza del giocatore
    alt = altezza;
    // imposto la larghezza del giocaore
    lar = larghezza;
}

void Player::render() {
    // stampo l'immagine del giocatore
    putimage(posX,posY,sprite,0);
}

int Player::getPosition() {
    // ritorno la posizione sull'asse X del giocatore
    return posX;
}

int Player::getPlayerY() {
    // ritorno la posizione sull'asse Y del giocatore
    return posY;
}

void Player::setPosition(int pos, bool adjust) {
    // aggiorno la posizione
    posX = pos;
    // se il valore va aggiustato
    if(adjust) {
        // si fa in modo che il valore rispetti i limiti
        posX = max(min(posX,getmaxx()-lar),0);
    }
}

int Player::getLives() {
    // ritorno il numero di vite del giocatore
    return lives;
}

void Player::setLives(int l) {
    // aggiorno il numero di vite del giocatore
    lives = l;
}

void Player::resetScore() {
    // azzero il punteggio
    score = 0;
}

void Player::addScore(int sc) {
    // aggiungo il punteggio
    score+=sc;
}

int Player::getScore() {
    // ritorno il punteggio
    return score;
}
