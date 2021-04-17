#include <bits/stdc++.h>
#include <graphics.h>
#include <chrono>

using namespace std;

#include "asteroids.h"
#include "bullets.h"
#include "player.h"


#define LARG 1024
#define ALTE 720
#define TIME_TO_SHOOT 150

void loadAsteroidsImages(Asteroids &a);

int main() {
    initwindow(LARG,ALTE);
    clearviewport();

    Asteroids as;
    loadAsteroidsImages(as);
    as.generateAsteroids(10);

    Player pl(getmaxx()/2,getmaxy()/2,1.57);

    Bullets bu;

    bool running = true, canRender = false, canShoot = true, wasAbleToShoot;
    double target = 120.0;
    double nsPerTick = 1000000000.0 / target;
    auto lastTime = chrono::steady_clock::now();
    auto lastShoot = chrono::steady_clock::now();
    double unprocessed = 0.0;

    while(running) {
        auto now = chrono::steady_clock::now();
        unprocessed += (double)chrono::duration_cast<chrono::nanoseconds>(now - lastTime).count() / nsPerTick;
        lastTime = chrono::steady_clock::now();

        if(unprocessed >= 1.0) {

            if(chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - lastShoot).count()>=TIME_TO_SHOOT) {
                canShoot = true;
            }
            wasAbleToShoot = canShoot;
            pl.update(bu, canShoot);
            if(wasAbleToShoot!=canShoot) {
                lastShoot = chrono::steady_clock::now();
            }
            as.update();
            bu.update(as);

            unprocessed--;
            canRender = true;
        }
        else canRender = false;

        delay(1);

        if(canRender) {
            clearviewport();

            as.render();
            pl.render();
            bu.render();
        }
    }

    //POINT cursorPosition;
    //GetCursorPos(&cursorPosition);


    return 0;
}

void loadAsteroidsImages(Asteroids &a) {
    void *p;

    setcolor(WHITE);

    // small N1
    setcolor(BLUE);
    //circle(100,100,MEDIUM_RADIUS);
    setcolor(WHITE);
    line(80,100,85,87);
    line(85,87,100,80);
    line(100,80,112,84);
    line(112,84,107,95);
    line(107,95,120,100);
    line(120,100,115,112);
    line(115,112,105,112);
    line(105,112,100,120);
    line(100,120,86,114);
    line(86,114,80,100);

    p = malloc(imagesize(80,80,120,120));
    getimage(80,80,120,120,p);
    clearviewport();

    a.addAsteroidsImage(p,0);

    // medium N1
    setcolor(BLUE);
    //scircle(100,100,BIG_RADIUS);
    setcolor(WHITE);
    line(60,100,70,74);
    line(70,74,100,60);
    line(100,60,124,68);
    line(124,68,114,86);
    line(114,86,140,100);
    line(140,100,130,124);
    line(130,124,110,124);
    line(110,124,100,140);
    line(100,140,72,128);
    line(72,128,60,100);

    p = malloc(imagesize(60,60,140,140));
    getimage(60,60,140,140,p);
    clearviewport();
    a.addAsteroidsImage(p,1);

    // big N1
    setcolor(BLUE);
    //circle(100,100,SMALL_RADIUS);
    setcolor(WHITE);
    line(20,100,40,48);
    line(40,48,100,20);
    line(100,20,148,36);
    line(148,36,128,72);
    line(128,72,180,100);
    line(180,100,160,148);
    line(160,148,120,148);
    line(120,148,100,180);
    line(100,180,44,156);
    line(44,156,20,100);

    p = malloc(imagesize(20,20,180,180));
    getimage(20,20,180,180,p);
    clearviewport();

    a.addAsteroidsImage(p,2);
}
