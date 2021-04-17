#define PLAYER_RADIUS 20

class Player {
private:
    double posX, posY;
    double angle;
    double speedX, speedY;
    //double speed;
    double acc = 0.08;
public:
    Player(int x, int y, double a);
    ~Player();

    void setPosition(int x, int y);
    void setAngle(int a);
    void render();
    void update(Bullets &b, bool &canShoot);
    pair<int,int> getPosition();
    double getAngle();
};


Player::Player(int x, int y, double a) {
    posX = x;
    posY = y;
    angle = a;
    speedX = 0;
    speedY = 0;
}

Player::~Player() {}

void Player::setPosition(int x, int y) {
    posX = x;
    posY = y;
}

void Player::setAngle(int a) {
    angle = a;
}

void Player::render() {
    pair<int,int> nord, est, ovest;

    nord.first = posX + (PLAYER_RADIUS*cos(angle));
    nord.second = posY - (PLAYER_RADIUS*sin(angle));

    est.first = posX + (PLAYER_RADIUS*cos(angle-2.62));
    est.second = posY - (PLAYER_RADIUS*sin(angle-2.62));

    ovest.first = posX + (PLAYER_RADIUS*cos(angle+2.62));
    ovest.second = posY - (PLAYER_RADIUS*sin(angle+2.62));

    line(nord.first,nord.second,est.first,est.second);
    line(nord.first,nord.second,ovest.first,ovest.second);
    line(est.first,est.second,ovest.first,ovest.second);
}

void Player::update(Bullets &b, bool &canShoot) {
    if(GetKeyState(VK_LEFT)& 0x8000) {
        angle += 0.07;
    }
    if(GetKeyState(VK_RIGHT)& 0x8000) {
        angle -= 0.07;
    }
    if(GetKeyState(VK_UP)& 0x8000) {
        speedX+=(acc*cos(angle));
        speedX = min(7.0,abs(speedX))*(speedX/abs(speedX));

        speedY+=(acc*sin(angle));
        speedY = min(7.0,abs(speedY))*(speedY/abs(speedY));
    }

    if(GetKeyState(VK_SPACE)& 0x8000&&canShoot) {
        b.add(posX,posY,angle);
        canShoot = false;
    }
    //cout << speedX << " " << speedY << endl;

    angle = fmod(angle+((double)10*3.14),(double)2*3.14);

    posX+=speedX;
    posY-=speedY;
    if(posX > getmaxx()) posX = 0;
    if(posX < 0) posX = getmaxx();
    if(posY > getmaxy()) posY = 0;
    if(posY < 0) posY = getmaxy();
}

pair<int,int> Player::getPosition() {
    return make_pair(posX,posY);
}

double Player::getAngle() {
    return angle;
}
