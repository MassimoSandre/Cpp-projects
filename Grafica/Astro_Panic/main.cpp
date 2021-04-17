#include <bits/stdc++.h>
#include <graphics.h>
#include <chrono>
#include <windows.h>
#include <mmsystem.h>

using namespace std;
#include "enemies.h"
#include "bullets.h"

#define LARG 1024
#define ALTE 720
#define SPOST 10
#define STARTING_LIVES 3
#define IMMUNITY_TIME 1500
#define INV_FPS 10
#define ENEMY_MAXVEL 15
#define ENEMY_MINVEL 7
#define TIME_TO_SHOOT 300

// la funzione getPlayerImage() ritorna il puntatore all'immagine che identifica il giocatore
void* getPlayerImage();
// la funzione getEnemyImage() ritorna il puntatore all'immagine che identifica le navi nemici
void* getEnemyImage();
// la funzione getLivesIcon() ritorna il puntatore all'immagine che identifica l'icona delle vite
void* getLivesIcon();

// la funzione loadEnemyExplosionAnimationImages() carica in un oggetto di tipo Enemies tutte le immagini che formano l'animazione di esplosione delle navicelle nemiche
void loadEnemyExplosionAnimationImages(Enemies &e);

int main() {
    // inizializzo la finestra
    initwindow(LARG,ALTE);

    // inizializzo l'oggetto pl di tipo Player, che rappresenta il giocatore
    Player pl(10,getmaxy()-100);
    // imposto l'immagine al giocatore
    pl.setImage(getPlayerImage(),50,20);

    // inizializzo l'oggetto en di tipo Enemies, che rapprensenta le navi nemiche
    Enemies en;
    // imposto l'immagine alle nane nemiche
    en.setImage(getEnemyImage(),50,25);
    // carico le immagini che compongono l'animazione di esplosione delle navi nemiche
    loadEnemyExplosionAnimationImages(en);

    // il puntatore void livesIcon punta all'immagine che identifica l'icona delle vite
    void* livesIcon = getLivesIcon();

    // inizializzo l'oggetto bu di tipo Bullets, che rappresenta i proiettili sparati dall'utente
    Bullets bu;
    // all'inizio l'high score sarà impostato a 0
    int highScore = 0;
    int tas;
    do {
        // stampo il titolo
        settextstyle(4,0,7);
        setcolor(WHITE);
        outtextxy(25,150,"A S T R O - P A N I C");
        settextstyle(4,0,5);
        setcolor(GREEN);
        outtextxy(105,400,"PRESS ENTER TO START");
        setcolor(BLUE);
        char highScoreText[20]="HIGH SCORE: ",tempText[10];
        itoa(highScore,tempText,10);
        for(int i = 0; i < 5-strlen(tempText);i++) {
            strcat(highScoreText,"0");
        }
        strcat(highScoreText,tempText);
        outtextxy(185,500,highScoreText);

        // attendo che l'utente prema invio per iniziare a giocare, o esc per uscire
        do {
            if(GetKeyState(VK_ESCAPE)& 0x8000) {
                tas = 27;
                break;
            }
            if(GetKeyState(VK_RETURN)& 0x8000) break;
            delay(10);
        }while(true);

        // se l'utente ha premuto esc, termino l'esecuzione
        if(tas == 27) continue;

        // la variabile wave identifica l'ondata di nemici attuale
        int wave = 1;
        // genero i nemici con la seguente formula 1.17^(9+wave)
        en.generateEnemies(pow(1.17,9+wave),ENEMY_MINVEL,ENEMY_MAXVEL);
        // resetto il punteggio del giocatore
        pl.resetScore();
        // reimposto le vite del giocatore
        pl.setLives(STARTING_LIVES);
        // elimino tutti i proiettili rimasti nel buffer
        bu.clearBullets();

        // la variabile running sarà a true finché la partita non sarà finita
        bool running = true;
        // la variabile target indica il numero di FPS e TPS che si intende raggiungere
        double target = 60.0;
        // la variabile nsPerTick indica il numero di nanosecondi che trascorrono tra un TPS e l'altro
        double nsPerTick = 1000000000.0 / target;
        // la variabile lastTime viene usata per calcolare quanto è passato dall'ultima iterazione
        auto lastTime = chrono::steady_clock::now();
        // la variabile lastShot viene usata per calcolare quanto è passato dall'ultimo sparo
        auto lastShot = chrono::steady_clock::now();
        // la variabile immunity viene usata per gestire l'immunità del giocatore dopo essere stato colpito
        auto immunity = chrono::steady_clock::now();

        bool canShot=true,      // la variabile canShot indica se è possibile sparare
            collided=false,     // la variabile collided indica se il giocatore è stato colpito di recente
            timeToDisplay=false;// la variabile timeToDisplay indica se è il momento di stampare a video il giocatore o no

        // la variabile unprocessed serve per verificare la necessità di un update
        double unprocessed = 0.0;

        // la bariabile fps conta degli fps
        int fps = 0;
        // la variabile canRender serve per dire se c'è la necessità di renderizzare
        bool canRender = false;

        while(running) {
            // calcolo quanto tempo e passato dall'ultima iterazione, e aggiungo questo intervallo al tempo non processato
            auto now = chrono::steady_clock::now();
            unprocessed += (double)chrono::duration_cast<chrono::nanoseconds>(now - lastTime).count() / nsPerTick;
            lastTime = chrono::steady_clock::now();

            // se per raggiungere il target è necessario processare, aggiorno
            if(unprocessed >= 1.0) {
                // aggiorno le navi nemiche
                en.update();
                // aggiorno i proiettili
                bu.update(en,pl,wave);

                // se il giocatore è stato colpito di recente, verifico se sono già passati IMMUNITY_TIME millisecondi, se è così, imposto collided a false
                if(collided && chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - immunity).count()>IMMUNITY_TIME) {
                    collided = false;
                }
                // se il giocatore è stato colpito in questo momento e non era stato colpito di recente
                if(en.collide(pl.getPosition(),pl.getPlayerY(),pl.getPosition()+50,pl.getPlayerY()+20,false,pl,0)&&!collided) {
                    // riproduco il suono dell'impatto
                    PlaySound(TEXT("sounds/impact.wav"),NULL,SND_FILENAME | SND_ASYNC);
                    // decremento le vite del giocatore
                    pl.setLives(pl.getLives()-1);
                    // il giocatore è stato colpito di recente
                    collided = true;
                    // imposto la conta degli fps a 0
                    fps = 0;
                    // imposto come ora l'inizio del timer dell'immunità
                    immunity = chrono::steady_clock::now();
                }
                // se le vite sono 0
                if(pl.getLives() == 0) {
                    // la partita è finita
                    running = false;
                }

                // se i nemici sono 0, significa che l'ondata è stata completata
                if(en.getNumber()==0){
                    // passo all'ondata successiva
                    wave++;
                    // genero i nemici dell'ondata
                    en.generateEnemies(pow(1.17,9+wave),7,11);
                }

                // se il giocatore ha sparato di recente
                if(!canShot) {
                    // se sono passati TIME_TO_SHOOT millisecondi, il giocatore può sparare ancora
                    if(chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - lastShot).count()>TIME_TO_SHOOT) {
                        // l'utente può sparare di nuovo
                        canShot = true;
                    }
                }
                // se la freccia destra è premuta
                if(GetKeyState(VK_RIGHT)& 0x8000) {
                    // sposto il giocatore a destra
                    pl.setPosition(pl.getPosition()+SPOST, true);
                }
                // se la freccia sinistra è premuta
                if(GetKeyState(VK_LEFT)& 0x8000) {
                    // sposto il giocatore a sinistra
                    pl.setPosition(pl.getPosition()-SPOST, true);
                }
                // se la barra spaziatrice è premuta e il giocatore può sparare
                if(GetKeyState(VK_SPACE)& 0x8000 && canShot) {
                    // riproduco il suono dello sparo
                    PlaySound(TEXT("sounds/shoot.wav"),NULL,SND_FILENAME | SND_ASYNC);
                    // aggiungo un proiettile che parte dalla posizione del giocatore
                    bu.add(pl.getPosition()+25,getmaxy()-100);
                    // imposto come ora l'inizio del timer per il prossimo sparo
                    lastShot = chrono::steady_clock::now();
                    // il giocatore non potrà più sparare finché non gli verrà riassegnato il consenso
                    canShot = false;
                }

                // ho processato, quindi posso decrementare il contatore di tempo non processato
                unprocessed--;
                // ora che ho aggiornato, posso renderizzare
                canRender = true;
            } else canRender = false;

            // attendo 10 millisecondi
            delay(10);

            // se posso renderizzare
            if(canRender) {
                // pulisco lo schermo
                clearviewport();
                // stampo il numero di ondata
                settextstyle(2,0,10);
                char waveText[] = "WAVE=00";
                waveText[5]=wave/10+48;
                waveText[6]=wave%10+48;
                // stampo il punteggio
                setcolor(WHITE);
                outtextxy(500,getmaxy()-50,waveText);
                char score[10],scoreText[20]="SCORE=";
                itoa(pl.getScore(),score,10);
                for(int i = 0; i < 5-strlen(score);i++) {
                    strcat(scoreText,"0");
                }
                strcat(scoreText,score);
                outtextxy(50,getmaxy()-50,scoreText);
                // stampo il numero di vite
                putimage(810,getmaxy()-35,livesIcon,0);
                char livesText[5];
                itoa(pl.getLives(),livesText,10);
                outtextxy(850,getmaxy()-50,livesText);

                // se il giocatore si è scontrato con una nave nemica
                if(collided) {
                    // se dall'ultimo azzeramento di fps sono passati INV_FPS fps
                    if(fps>=INV_FPS) {
                        // riazzero fps
                        fps = 0;
                        // inverto la variabile timeToDisplay
                        timeToDisplay = !timeToDisplay;
                    }
                    // se la variabile timeToDisplay è true
                    if(timeToDisplay) {
                        // stampo il giocatore
                        pl.render();
                    }
                    // incremento il contatore di fps
                    fps++;
                }
                else {
                    // altrimenti renderizzo sempre
                    pl.render();
                }
                // renderizzo i nemici
                en.render();
                // renderizzo i proiettili
                bu.render();
            }
        }
        // se, una volta finita la partita, il giocatore ha superato l'high score, lo aggiorno
        if(pl.getScore()>highScore) highScore = pl.getScore();
    } while(tas!=27); // Se l'utente preme esc esco dal gioco

    // libero la memoria occupata dall'immagine dell'icona delle vite
    free(livesIcon);
    // chiudo la finestra
    closegraph();
    return 0;
}

void* getPlayerImage() {
    // il puntatore void p conterrà il puntatore dell'immagine del giocatore
    void *p;

    // disegno l'immagine
    setfillstyle(SOLID_FILL,YELLOW);
    setcolor(YELLOW);
    rectangle(100,100,110,110);
    floodfill(105,105,YELLOW);
    rectangle(110,95,120,102);
    floodfill(115,100,YELLOW);
    rectangle(120,90,130,98);
    floodfill(125,95,YELLOW);
    rectangle(140,100,150,110);
    floodfill(145,105,YELLOW);
    rectangle(130,95,140,102);
    floodfill(135,100,YELLOW);
    setcolor(BLUE);
    setfillstyle(SOLID_FILL,BLUE);
    rectangle(110,102,120,106);
    floodfill(115,104,BLUE);
    rectangle(130,102,140,106);
    floodfill(135,104,BLUE);
    setcolor(MAGENTA);
    setfillstyle(SOLID_FILL,MAGENTA);
    rectangle(120,98,130,108);
    floodfill(125,100,MAGENTA);

    // alloco lo spazio necessario per memorizzarla e la memorizzo
    long dim = imagesize(100,90,150,110);
    p = malloc(dim);
    getimage(100,90,150,110,p);

    // pulisco lo schermo
    clearviewport();

    // ritorno il puntatore all'immagine
    return p;
}

void* getEnemyImage() {
    // il puntatore void p conterrà il puntatore dell'immagine delle navi nemiche
    void *p;

    // disegno l'immagine
    setfillstyle(SOLID_FILL,MAGENTA);
    setcolor(MAGENTA);
    rectangle(100,100,110,110);
    floodfill(105,105,MAGENTA);
    rectangle(120,100,130,110);
    floodfill(125,105,MAGENTA);
    rectangle(140,100,150,110);
    floodfill(145,105,MAGENTA);

    setfillstyle(SOLID_FILL,BLUE);
    setcolor(BLUE);
    rectangle(100,97,150,100);
    floodfill(110,98,BLUE);
    rectangle(100,110,150,113);
    floodfill(110,112,BLUE);

    setfillstyle(SOLID_FILL, YELLOW);
    setcolor(YELLOW);
    rectangle(110,94,140,97);
    floodfill(120,95,YELLOW);
    rectangle(110,113,140,116);
    floodfill(120,115,YELLOW);
    rectangle(120,90,130,97);
    floodfill(125,92,YELLOW);
    rectangle(120,113,130,120);
    floodfill(125,118,YELLOW);

    // alloco lo spazio necessario per memorizzarla e la memorizzo
    long dim = imagesize(100,90,150,120);
    p = malloc(dim);
    getimage(100,90,150,120,p);

    // pulisco lo schermo
    clearviewport();

    // ritorno il puntatore all'immagine
    return p;
}

void* getLivesIcon() {
    // il puntatore void p conterrà il puntatore dell'immagine dell'icona delle vite
    void* p;

    // disegno l'immagine
    setfillstyle(SOLID_FILL,YELLOW);
    setcolor(YELLOW);
    rectangle(100,100,105,107);
    floodfill(102,104,YELLOW);
    rectangle(105,97,110,102);
    floodfill(107,100,YELLOW);
    rectangle(110,94,115,107);
    floodfill(112,100,YELLOW);
    rectangle(120,100,125,107);
    floodfill(121,104,YELLOW);
    rectangle(115,97,120,102);
    floodfill(116,100,YELLOW);

    // alloco lo spazio necessario per memorizzarla e la memorizzo
    long dim = imagesize(100,94,125,107);
    p = malloc(dim);
    getimage(100,94,125,107,p);

    // pulisco lo schermo
    clearviewport();

    // ritorno il puntatore all'immagine
    return p;
}

void loadEnemyExplosionAnimationImages(Enemies &e) {
    // il puntatore void temp conterrà temporaneamente i vari frame dell'animazione
    void *temp;

    // disegno il frame N1
    setfillstyle(SOLID_FILL, MAGENTA);
    setcolor(MAGENTA);
    rectangle(100,100,140,125);
    floodfill(120,120,MAGENTA);
    rectangle(140,103,150,118);
    floodfill(145,110,MAGENTA);
    rectangle(125,95,140,100);
    floodfill(130,97,MAGENTA);
    rectangle(90,95,110,100);
    floodfill(100,97, MAGENTA);
    rectangle(90,107,100,112);
    floodfill(96,110,MAGENTA);
    rectangle(90,118,100,122);
    floodfill(96,120,MAGENTA);
    rectangle(110,125,120,130);
    floodfill(115,127,MAGENTA);
    rectangle(130,125,140,130);
    floodfill(135,127,MAGENTA);
    rectangle(150,107,160,110);
    floodfill(155,108,MAGENTA);
    rectangle(140,122,150,125);
    floodfill(145,123,MAGENTA);

    setfillstyle(SOLID_FILL, YELLOW);
    setcolor(YELLOW);
    rectangle(110,110,117,114);
    floodfill(115,112,YELLOW);
    rectangle(117,107,132,117);
    floodfill(120,110,YELLOW);
    rectangle(132,110,139,114);
    floodfill(135,112,YELLOW);

    // alloco lo spazio necessario per memorizzarlo e la memorizzo
    long dim = imagesize(90,95,160,130);
    temp = malloc(dim);
    getimage(90,95,160,130,temp);

    // aggiungo il frame all'oggetto e di tipo Enemies
    e.addExpImage(temp);
    // pulisco lo schermo
    clearviewport();

    // disegno il frame N2
    setfillstyle(SOLID_FILL, MAGENTA);
    setcolor(MAGENTA);
    rectangle(100,100,138,115);
    floodfill(110,110,MAGENTA);
    rectangle(92,97,100,107);
    floodfill(97,100,MAGENTA);
    rectangle(84,94,92,97);
    floodfill(90,95,MAGENTA);
    rectangle(84,101,92,104);
    floodfill(90,103,MAGENTA);
    rectangle(92,112,100,115);
    floodfill(95,114,MAGENTA);
    rectangle(84,115,92,118);
    floodfill(90,117,MAGENTA);
    rectangle(100,115,110,120);
    floodfill(105,118,MAGENTA);
    rectangle(128,115,138,120);
    floodfill(130,118,MAGENTA);
    rectangle(108,94,116,100);
    floodfill(110,95,MAGENTA);
    rectangle(116,97,124,100);
    floodfill(120,98,MAGENTA);
    rectangle(138,97,146,100);
    floodfill(140,98,MAGENTA);
    rectangle(146,94,154,97);
    floodfill(150,95,MAGENTA);
    rectangle(138,105,146,113);
    floodfill(140,110,MAGENTA);
    rectangle(146,113,154,116);
    floodfill(150,115,MAGENTA);
    rectangle(146,107,154,110);
    floodfill(150,109,MAGENTA);

    setfillstyle(SOLID_FILL, YELLOW);
    setcolor(YELLOW);
    rectangle(103,102,116,105);
    floodfill(110,103,YELLOW);
    rectangle(108,105,124,108);
    floodfill(110,106,YELLOW);

    // alloco lo spazio necessario per memorizzarlo e la memorizzo
    dim = imagesize(84,94,154,120);
    temp = malloc(dim);
    getimage(84,94,154,120,temp);

    // aggiungo il frame all'oggetto e di tipo Enemies
    e.addExpImage(temp);
    // pulisco lo schermo
    clearviewport();

    // disegno il frame N3
    setfillstyle(SOLID_FILL, MAGENTA);
    setcolor(MAGENTA);
    rectangle(100,100,107,104);
    floodfill(104,102,MAGENTA);
    rectangle(107,104,115,108);
    floodfill(110,106,MAGENTA);
    rectangle(100,108,107,112);
    floodfill(105,110,MAGENTA);
    rectangle(107,112,115,116);
    floodfill(110,115,MAGENTA);
    rectangle(100,116,107,120);
    floodfill(105,118,MAGENTA);
    rectangle(107,120,115,124);
    floodfill(110,122,MAGENTA);
    rectangle(107,94,115,97);
    floodfill(110,96,MAGENTA);
    rectangle(115,100,122,106);
    floodfill(120,102,MAGENTA);
    rectangle(122,97,130,100);
    floodfill(125,98,MAGENTA);
    rectangle(130,94,137,97);
    floodfill(135,96,MAGENTA);
    rectangle(130,100,137,112);
    floodfill(135,110,MAGENTA);
    rectangle(122,110,130,116);
    floodfill(125,114,MAGENTA);
    rectangle(122,120,130,124);
    floodfill(124,123,MAGENTA);
    rectangle(137,112,145,117);
    floodfill(140,115,MAGENTA);
    rectangle(145,96,152,104);
    floodfill(150,100,MAGENTA);
    rectangle(152,94,160,97);
    floodfill(156,96,MAGENTA);
    rectangle(152,108,160,112);
    floodfill(155,110,MAGENTA);
    rectangle(152,120,160,124);
    floodfill(155,122,MAGENTA);

    setfillstyle(SOLID_FILL, YELLOW);
    setcolor(YELLOW);
    rectangle(115,108,122,112);
    floodfill(120,110,YELLOW);
    rectangle(122,104,130,108);
    floodfill(125,106,YELLOW);
    rectangle(138,104,145,108);
    floodfill(140,106,YELLOW);
    rectangle(145,113,153,117);
    floodfill(150,115,YELLOW);

    // alloco lo spazio necessario per memorizzarlo e la memorizzo
    dim = imagesize(100,94,160,120);
    temp = malloc(dim);
    getimage(100,94,160,120,temp);

    // aggiungo il frame all'oggetto e di tipo Enemies
    e.addExpImage(temp);
    // pulisco lo schermo
    clearviewport();
}
