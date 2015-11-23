struct Pos{
	Nat X;
	Nat Y;
};
class Campus
{
	private:
		Nat _ancho;
		Nat _alto;
		Arreglo<Arreglo<bool> > _grilla;
	public:
		Campus(Nat, Nat);
		void agregarObs(Pos);
		Nat alto();
		Nat ancho();
		bool ocupada(Pos);
		bool posValida(Pos);
		bool esIngreso(Pos);
		bool ingresoSup(Pos);
		bool ingresoInf(Pos);
		Nat distancia(Pos, Pos);
		Conj<Pos> vecinos();
		Pos aPosMasCercana(Pos,Conj<Pos>);
};

Campus::Campus (Nat an, Nat al){
	this->_ancho=an;
	this->_alto=al;
	this->_grilla=Arreglo<Arreglo<bool> >(an);
	for(int i=0;i++;i<an){
		this->_grilla.Definir(i,Arreglo<bool>(al));
		}
};
void Campus::agregarObs(Pos obst){
	this->_grilla[obst.X].Definir(obst.Y, true);
};

Nat alto(){
	return this->_alto;
};

Nat ancho(){
	return this->_ancho;
};

bool ocupada(Pos p){
	return this->_grilla[p.X][p.Y];
};

bool posValida(Pos p){
	return (p.X<this->_ancho)&&(p.Y<this->_alto);
};

bool esIngreso(Pos p){
	return (p.X==0)||(p.X==(this->_ancho -1));
};

bool ingresoSup(Pos p){
	return p.X==0
}

bool ingresoInf(Pos p){
	return p.X==this->_ancho -1;
}

Nat distancia(Pos p1,p2){
	Nat resX;
	Nat resY;
	if(p1.X>p2.X){
		resX=p1.X-p2.X;
	}else{
		resX=p2.X-p1.X;
	}
	if(p1.Y>p2.Y){
		resY=p1.Y-p2.Y;
	}else{
		resY=p2.Y-p1.Y;
	}
	return resX+resY;
}
Conj<Pos> vecinos(Pos p){
	  Conj<Pos> veci;
	  Pos cand;
	  cand.X=p.X-1;
	  cand.Y=p.Y;
	  if(this->posValida(cand)) veci.agregarRapido(cand);
	  cand.X+=2;
	  if(this->posValida(cand)) veci.agregarRapido(cand);
	  cand.X-=1;
	  camd.Y-=1;
	  if(this->posValida(cand)) veci.agregarRapido(cand);
	  cand.Y+=2;
	  if(this->posValida(cand)) veci.agregarRapido(cand);
	  return veci;
}
Pos aPosMasCercana(Pos p, Conj<Pos> posi){
	Pos cand;
	Conj<Pos>::Iterador it=posi.CrearIt;
	return cand;
}