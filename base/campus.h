class Campus
{
	private:
		Nat _ancho;
		Nat _alto;
		Arreglo<Arreglo<bool> > _grilla;
	public:
		Campus(Nat, Nat);
		void agregarObs(posición);
		Nat alto();
		Nat ancho();
		bool ocupada(posición);
		bool posValida(posición);
		bool esIngreso(posición);
		bool ingresoSup(posición);
		bool ingresoInf(posición);
		Nat distancia(posición, posición);
		Conj<posición> vecinos();
		posición aPosMasCercana(posición, const Conj<posición>&);
};

Campus::Campus (Nat an, Nat al){
	this->_ancho=an;
	this->_alto=al;
	this->_grilla=Arreglo<Arreglo<bool> >(an);
	for(int i=0;i++;i<an){
		this->_grilla.Definir(i,Arreglo<bool>(al));
		}
};
void Campus::agregarObs(posición obst){
	this->_grilla[obst.x].Definir(obst.y, true);
};

Nat alto(){
	return this->_alto;
};

Nat ancho(){
	return this->_ancho;
};

bool ocupada(posición p){
	return this->_grilla[p.x][p.y];
};

bool posValida(posición p){
	return (p.x<this->_ancho)&&(p.y<this->_alto);
};

bool esIngreso(posición p){
	return (p.y==0)||(p.y==(this->_alto -1));
};

bool ingresoSup(posición p){
	return p.y==0
}

bool ingresoInf(posición p){
	return p.y==this->_alto -1;
}

Nat distancia(posición p1,p2){
	Nat resX;
	Nat resY;
	if(p1.x>p2.x){
		resX=p1.x-p2.x;
	}else{
		resX=p2.x-p1.x;
	}
	if(p1.y>p2.y){
		resY=p1.y-p2.y;
	}else{
		resY=p2.y-p1.y;
	}
	return resX+resY;
}
Conj<posición> vecinos(posición p){
	  Conj<posición> veci;
	  posición cand;
	  cand.x=p.x-1;
	  cand.y=p.y;
	  if(this->posValida(cand)) veci.agregarRapido(cand);
	  cand.x+=2;
	  if(this->posValida(cand)) veci.agregarRapido(cand);
	  cand.x-=1;
	  camd.y-=1;
	  if(this->posValida(cand)) veci.agregarRapido(cand);
	  cand.y+=2;
	  if(this->posValida(cand)) veci.agregarRapido(cand);
	  return veci;
}
posición aPosMasCercana(posición p, const Conj<posición>& posi){
	Conj<posición>::Iterador it=posi.CrearIt();
	posición cand=it.siguiente();
	while (it.HaySiguiente()){
		if (this->distancia(cand,p)>this->distancia(it.siguiente(),p){
			cand=it.siguiente();
			while (it.HayAnterior()) it.EliminarAnterior();
			it.Avanzar();
		}else{
			if (this->distancia(cand,p)<this->distancia(it.siguiente(),p){
				it.EliminarSiguiente();
				cand=it.siguiente();
			}else it.Avanzar();
		}
	}
	it=posi.CrearIt();
	cand=it.siguiente;
	posicion ceero;
	ceero.x=0;
	ceero.y=0;
	while (it.HaySiguiente()){
		if (this->distancia(ceero,p)>this->distancia(it.siguiente(),ceero){
			cand=it.siguiente();
			while (it.HayAnterior()) it.EliminarAnterior();
			it.Avanzar();
		}else{
			if (this->distancia(ceero,p)<this->distancia(it.siguiente(),ceero){
				it.EliminarSiguiente();
				cand=it.siguiente();
			}else it.Avanzar();
		}
	}
	it=posi.CrearIt();
	cand=it.siguiente;
	while (it.HaySiguiente()){
		it=posi.CrearIt();
		cand=it.siguiente;
		if (cand.y<it.siguiente.y){
			cand=it.siguiente();
			while (it.HayAnterior()) it.EliminarAnterior();
			it.Avanzar();
		}else{
			if (cand.y>it.siguiente.y){
				it.EliminarSiguiente();
				cand=it.siguiente();
			}else it.Avanzar();
		}
	}
	return cand;
}