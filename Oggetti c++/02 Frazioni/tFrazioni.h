class tFrazione
    {
    private:
    	int numeratore;		// num frazione
    	int denominatore;	// den frazione
    	    	
    public:
    	tFrazione();
    	tFrazione(int num,int den);
    	~tFrazione();
    	void Semplifica();
    	int MCD();
    	void setNum(int num);
    	void setDen(int den);
    	void setFract(int num,int den);
    	int getNum();
    	int getDen();
    	void getFract(int &num,int &den);
    	void stampaFract();
    };
//Implementazione dei metodi    
    tFrazione::tFrazione()					// Costruttore
        {
        	
		}
	
	tFrazione::tFrazione(int num,int den) { // Costruttore alternativo
		numeratore=num;
		denominatore=den;
		Semplifica();
	}

void tFrazione::Semplifica()
        {
        	int min;
        	
        	min=MCD();
        	numeratore/=min;
        	denominatore/=min;
		}

int tFrazione::MCD()
        {
        	int a,b;
        	
        	a=numeratore;
        	b=denominatore;
        	while(a!=b) 
        		if (a>b) a-=b;
        		else b-=a;
        	return a;
		}
		
void tFrazione::setNum(int num) {
			numeratore=num;
}

void tFrazione::setDen(int den) {
			denominatore=den;
}

void tFrazione::setFract(int num,int den) {
			numeratore=num;
			denominatore=den;
}

int tFrazione::getNum() {
	
	return numeratore;
}

int tFrazione::getDen() {
	
	return denominatore;
}

void tFrazione::getFract(int &num,int &den) {
	
	num=numeratore;
	den=denominatore;
}

void tFrazione::stampaFract() {
	
	Semplifica();
	printf("%d\/%d",numeratore,denominatore);
}

    tFrazione::~tFrazione()
        {
        	
        }

