class tQuadrato {
	
	private:
		double lato,
			   diagonale;
		
	public:
		tQuadrato();
		~tQuadrato();
		void SetLato(double l);
		double GetLato();
		void SetDiagonale(double d);
		double GetDiagonale();
		double Area();
		double Perimetro();
};

// Metodi

	tQuadrato::tQuadrato() {
		lato=-1;
		diagonale=-1;
	}
	
	tQuadrato::~tQuadrato() {
		
	}
	
	double tQuadrato::Perimetro() {
		if (lato==-1 && diagonale==-1) return -1;
		else if(lato==-1) lato=diagonale/sqrt(2);
		return lato*4;
	}
	
	double tQuadrato::Area() {
		if (lato==-1 && diagonale==-1) return -1;
		else if(lato==-1) lato=diagonale/sqrt(2);
		return pow(lato,2);
	}
	
	void tQuadrato::SetLato(double l) {
		lato=l; 
	}
	
	double tQuadrato::GetLato() {
		if (diagonale!=-1 && lato==-1) lato=diagonale/sqrt(2);
		return lato;
	}
	
	void tQuadrato::SetDiagonale(double d) {
		diagonale=d; 
	}
	
	double tQuadrato::GetDiagonale() {
		if (lato!=-1 && diagonale==-1) diagonale=lato*sqrt(2);
		return diagonale;
	}

