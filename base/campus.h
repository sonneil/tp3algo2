class Campus
{
	private:
		Nat _ancho;
		Nat _alto;
		Arreglo<Arreglo<bool> > _grilla;
	public:
		Campus(Nat, Nat);
		void agregarObs(posicion);
		Nat alto();
		Nat ancho();
		bool ocupada(posicion);
		bool posValida(posicion);
		bool esIngreso(posicion);
		bool ingresoSup(posicion);
		bool ingresoInf(posicion);
		Nat distancia(posicion, posicion);
		Conj<posicion> vecinos();
		posicion aPosMasCercana(posicion, const Conj<posicion>&);
};

Campus::Campus (Nat an, Nat al){
	this->_ancho=an;
	this->_alto=al;
	this->_grilla=Arreglo<Arreglo<bool> >(an);
	for(int i=0;i++;i<an){
		this->_grilla.Definir(i,Arreglo<bool>(al));
		}
};
void Campus::agregarObs(posicion obst){
	this->_grilla[obst.x].Definir(obst.y, true);
};

Nat alto(){
	return this->_alto;
};

Nat ancho(){
	return this->_ancho;
};

bool ocupada(posicion p){
	return this->_grilla[p.x][p.y];
};

bool posValida(posicion p){
	return (p.x<this->_ancho)&&(p.y<this->_alto);
};

bool esIngreso(posicion p){
	return (p.y==0)||(p.y==(this->_alto -1));
};

bool ingresoSup(posicion p){
	return p.y==0
}

bool ingresoInf(posicion p){
	return p.y==this->_alto -1;
}

Nat distancia(posicion p1,p2){
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
Conj<posicion> vecinos(posicion p){
	  Conj<posicion> veci;
	  posicion cand;
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
posicion aPosMasCercana(posicion p, const Conj<posicion>& posi){
	Conj<posicion>::Iterador it=posi.CrearIt();
	posicion cand=it.siguiente();
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
