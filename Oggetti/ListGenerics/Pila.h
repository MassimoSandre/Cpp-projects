template <typename T> class Pila {
protected:
    typedef struct sNodo{
        T info;
        sNodo *pun;
    }tNodo;
    typedef tNodo* tPun;

    tPun p0,sup;
    T r;

public:
    Pila() {
        p0 = NULL;
    }
    ~Pila() {
        while(p0!=NULL) {
            sup = p0;
            p0 = p0->pun;
            free(sup);
        }
    }

    void push(T ele) {
        sup = p0;
        p0 = (tPun)malloc(sizeof(tNodo));
        p0->info = ele;
        p0->pun = sup;
    }

    T pop() {
        r = p0->info;
        sup = p0;
        p0 = p0->pun;
        free(sup);
        return r;
    }

    bool vuota() {
        return p0 == NULL;
    }

    bool piena() {
        sup = (tPun)malloc(sizeof(tNodo));
        if(sup == NULL) return true;
        free(sup);
        return false;
    }
};
