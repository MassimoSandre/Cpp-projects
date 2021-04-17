class Rettangolo {
private:
    float altezza;
    float larghezza;
public:
    Rettangolo();
    ~Rettangolo();
    void setAltezza(float);
    void setLarghezza(float);
    float getAltezza();
    float getLarghezza();
    void modifica(float,float);
    void stampa();
    float getArea();
    float getPerimetro();
};

Rettangolo::Rettangolo() {}

Rettangolo::~Rettangolo() {}

void Rettangolo::setAltezza(float altezza) {
    this->altezza = altezza;
}
void Rettangolo::setLarghezza(float larghezza) {
    this->larghezza = larghezza;
}

float Rettangolo::getAltezza() {
    return this->altezza;
}

float Rettangolo::getLarghezza() {
    return this->larghezza;
}

void Rettangolo::modifica(float altezza,float larghezza){
    this->altezza = altezza;
    this->larghezza = larghezza;
}

void Rettangolo::stampa() {
    printf("Altezza: %f, Larghezza: %f",this->altezza,this->larghezza);
}

float Rettangolo::getArea() {
    return this->altezza*this->larghezza;
}

float Rettangolo::getPerimetro() {
    return 2*(this->altezza+this->larghezza);
}
