#define MAX_BULLETS 100
#define SPEED_BULLET 12
#define TLE_BULLET 50

class Bullets {
private:
    typedef struct {
        int x;
        int y;
        int tle;
        double angle;
    } bullet;
    vector<bullet> bu;
    int num;

public:
    Bullets();
    ~Bullets();

    void add(int x, int y, double a);
    void update(Asteroids &a);
    void render();
};

Bullets::Bullets() {
    bu.resize(MAX_BULLETS);
    num = 0;
}

Bullets::~Bullets() {}

void Bullets::add(int x, int y, double a) {
    bu[num].x = x;
    bu[num].y = y;
    bu[num].angle = a;
    bu[num].tle = TLE_BULLET;
    num++;
}

void Bullets::update(Asteroids &a) {
    for(int i = 0; i < num;i++) {
        if(bu[i].tle == 0  || a.collide(bu[i].x,bu[i].y,1,true)) {
            for(int j = i; j < num-1;j++) {
                bu[j] = bu[j+1];
            }
            num--;
        }
        else {
            bu[i].tle--;
            bu[i].x+=SPEED_BULLET*cos(bu[i].angle);
            bu[i].y-=SPEED_BULLET*sin(bu[i].angle);
            if(bu[i].x < 0) bu[i].x = getmaxx();
            if(bu[i].x > getmaxx()) bu[i].x = 0;
            if(bu[i].y < 0) bu[i].y = getmaxy();
            if(bu[i].y > getmaxy()) bu[i].y = 0;
        }
    }
}

void Bullets::render() {
    for(int i = 0; i < num;i++) {
        putpixel(bu[i].x,bu[i].y,WHITE);
    }
}
