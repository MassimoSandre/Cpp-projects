#define MAX_MOVING_ASTEROIDS 50
#define MAX_GENERABLE_ASTEROIDS 12
#define SMALL_RADIUS 20
#define MEDIUM_RADIUS 40
#define BIG_RADIUS 80
#define MIN_ASTEROID_SPEED 2
#define MAX_ASTEROID_SPEED 5

class Asteroids {
private:
    typedef struct {
        int x;
        int y;
        double angle;
        int speed;
        int astSize;
        int imageNum;
    } ast;
    vector<ast> movingAsteroids;
    int num;
    vector<void*> smallAsteroidsImages;
    vector<void*> mediumAsteroidsImages;
    vector<void*> bigAsteroidsImages;
public:
    Asteroids();
    ~Asteroids();

    void render();
    void update();
    void generateAsteroids(int n);
    void explode(int a);
    void addAsteroidsImage(void *image, int asteroidSize);
    bool collide(int x, int y, int r, bool exp);
};

Asteroids::Asteroids() {
    movingAsteroids.resize(MAX_MOVING_ASTEROIDS);
    num = 0;
}
Asteroids::~Asteroids() {
    for(int i = 0 ; i < smallAsteroidsImages.size();i++) {
        free(smallAsteroidsImages[i]);
    }
    for(int i = 0 ; i < mediumAsteroidsImages.size();i++) {
        free(mediumAsteroidsImages[i]);
    }
    for(int i = 0 ; i < bigAsteroidsImages.size();i++) {
        free(bigAsteroidsImages[i]);
    }
}

void Asteroids::render() {
    for(int i = 0; i < num;i++) {
        switch(movingAsteroids[i].astSize) {
            case 0:
                //cout << "ciao0\n";
                putimage(movingAsteroids[i].x-SMALL_RADIUS,movingAsteroids[i].y-SMALL_RADIUS,smallAsteroidsImages[movingAsteroids[i].imageNum],0);
                break;
            case 1:
                //cout << "ciao1\n";
                putimage(movingAsteroids[i].x-MEDIUM_RADIUS,movingAsteroids[i].y-MEDIUM_RADIUS,mediumAsteroidsImages[movingAsteroids[i].imageNum],0);
                break;
            case 2:
                //cout << "ciao2\n";
                putimage(movingAsteroids[i].x-BIG_RADIUS,movingAsteroids[i].y-BIG_RADIUS,bigAsteroidsImages[movingAsteroids[i].imageNum],0);
                break;
            default:
                break;
        }
    }
}

void Asteroids::update() {
    for(int i = 0; i < num;i++) {
        movingAsteroids[i].x += movingAsteroids[i].speed*cos(movingAsteroids[i].angle);
        movingAsteroids[i].y -= movingAsteroids[i].speed*sin(movingAsteroids[i].angle);
        if(movingAsteroids[i].x < 0) movingAsteroids[i].x = getmaxx();
        if(movingAsteroids[i].x > getmaxx()) movingAsteroids[i].x = 0;
        if(movingAsteroids[i].y < 0) movingAsteroids[i].y = getmaxy();
        if(movingAsteroids[i].y > getmaxy()) movingAsteroids[i].y = 0;
    }
}

void Asteroids::generateAsteroids(int n) {
    n = min(n,MAX_GENERABLE_ASTEROIDS);
    srand(time(NULL));
    for(int i = 0; i < n;i++) {
        ast tempAst;
        tempAst.astSize = 2;

        tempAst.imageNum = rand()%bigAsteroidsImages.size();

        do {
            tempAst.angle = (double)(rand()%360)/(double)180*3.1415;
        } while(cos(tempAst.angle)==1||sin(tempAst.angle)==1);
        int zeroX = rand()%2;
        if(zeroX) {
            tempAst.x = 0;
            tempAst.y = rand()%getmaxy();
        }
        else {
            tempAst.x = rand()%getmaxx();
            tempAst.y = 0;
        }
        tempAst.speed = rand()%(MAX_ASTEROID_SPEED-MIN_ASTEROID_SPEED+1)+MIN_ASTEROID_SPEED;

        movingAsteroids[num++] = tempAst;
    }
}


void Asteroids::explode(int a) {
    if(movingAsteroids[a].astSize==0) {
        for(int i = a; i < num-1;i++) {
            movingAsteroids[i] = movingAsteroids[i+1];
        }
        num--;
    }
    else {
        srand(time(NULL));
        movingAsteroids[a].astSize--;

        movingAsteroids[num]=movingAsteroids[a];

        movingAsteroids[a].angle += (double)(10+rand()%20)/180*3.1415;
        movingAsteroids[num].angle -= (double)(10+rand()%20)/180*3.1415;

        num++;
    }
}

void Asteroids::addAsteroidsImage(void *image, int asteroidSize) {
    switch(asteroidSize) {
        case 0:
            smallAsteroidsImages.push_back(image);
            break;
        case 1:
            mediumAsteroidsImages.push_back(image);
            break;
        case 2:
            bigAsteroidsImages.push_back(image);
            break;
        default:
            break;
    }
}

bool Asteroids::collide(int x, int y, int r, bool exp) {
    for(int i = 0; i < num;i++) {
        int dist = sqrt((double)pow(movingAsteroids[i].x-x,2)+(double)pow(movingAsteroids[i].y-y,2));

        dist -= r;
        switch(movingAsteroids[i].astSize) {
            case 0:
                dist-=SMALL_RADIUS;
                break;
            case 1:
                dist-=MEDIUM_RADIUS;
                break;
            case 2:
                dist-=BIG_RADIUS;
                break;
            default:
                break;
        }
        if(dist<0) {
            if(exp) {
                explode(i);
            }
            return true;
        }
    }
    return false;
}
