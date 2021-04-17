// ciao
class Frazione {
protected:
    int numeratore;
    int denominatore;
    int MCD(int a, int b) {
        if(a < 0) {
            a *= -1;
        }
        if(b < 0) {
            b *= -1;
        }

        while(a!=b) {
            if(a > b) {
                a = a-b;
            }
            else {
                b = b-a;
            }
        }
        return a;
    }
    // la funzione void semplifica() effettua la semplificazione della frazione
    void semplifica() {
        if(this->numeratore == 0 || this->denominatore == 0) return;
        // Se il numeratore e il denominatore sono entrambi negativi i segni si semplificano
        if(this->numeratore < 0 && this->denominatore < 0) {
            this->numeratore *= -1;
            this->denominatore *= -1;
        }

        int divisore = MCD(this->numeratore, this->denominatore);

        this->numeratore /= divisore;
        this->denominatore /= divisore;
    }
public:
    Frazione() {
        this->numeratore = 1;
        this->denominatore = 1;
    }
    Frazione(int num, int denom) {
        this->numeratore = num;
        if(denom == 0) {
            this->denominatore = 1;
        }
        else {
            this->denominatore = denom;
        }
        semplifica();
    }


    void aggiungiFrazione(Frazione f) {
        this->denominatore *= f.denominatore;
        this->numeratore *= f.denominatore;
        this->numeratore += f.numeratore*(this->denominatore/f.denominatore);

        semplifica();
    }

    void sottraiFrazione(Frazione f) {
        this->denominatore *= f.denominatore;
        this->numeratore *= f.denominatore;
        this->numeratore -= f.numeratore*(this->denominatore/f.denominatore);

        semplifica();
    }

    void stampaFrazione() {
        if(this->numeratore == 0) printf("0");
        else if(this->denominatore == 1) printf("%d",this->numeratore);
        else printf("%d/%d",this->numeratore,this->denominatore);
    }

    void setNumeratore(int num) {
        this->numeratore = num;

        semplifica();
    }

    void setDenominatore(int denom) {
        if(denom == 0) {
            this->denominatore = 1;
        }
        else {
            this->denominatore = denom;
        }

        semplifica();
    }

    int getNumeratore() {
        return this->numeratore;
    }

    int getDenominatore() {
        return this->denominatore;
    }

    Frazione copiaFrazione() {
        return Frazione(this->numeratore,this->denominatore);
    }

    Frazione getReciproco() {
        return Frazione(this->denominatore,this->numeratore);
    }

    void moltiplicaFrazione(Frazione f) {
        this->numeratore *= f.numeratore;
        this->denominatore *= f.denominatore;

        semplifica();
    }

    void dividiFrazione(Frazione f) {
        moltiplicaFrazione(f.getReciproco());
    }
};
