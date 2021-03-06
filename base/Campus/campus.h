#include "../aed2/aed2.h"
#include "../Tipos.h"

namespace aed2{

class Campus
{
	private:
	     Nat _ancho;
	     Nat _alto;
		Arreglo<Arreglo<bool> > _grilla;
	public:
		Campus(Nat, Nat);
		void agregarObs(Posicion);
		Nat alto();
		Nat ancho();
		bool ocupada(Posicion);
		bool posValida(Posicion);
		bool esIngreso(Posicion);
		bool ingresoSup(Posicion);
		bool ingresoInf(Posicion);
		Nat distancia(Posicion, Posicion);
		Conj<Posicion> vecinos(Posicion);
		Posicion aPosMasCercana(Posicion, Conj<Posicion>);
		std::string showtime();
		bool operator ==(Campus);
};

bool Campus::operator ==(Campus otro){
	bool proas=(this->ancho()==otro.ancho())&&(this->alto()==otro.alto());
	int an=otro.ancho();
	int al=otro.alto();
	int i=0;
	while (proas && i<an){
		int j = 0;
		while (proas && j<al){
			Posicion p; p.x=i, p.y=j;
			proas=(this->ocupada(p)==otro.ocupada(p));
			j++;
		}
		i++;
	}
	return proas;
}
std::string Campus::showtime(){
	std::string os;
	int i=0;
	while (i<(this->_ancho)){
		os.append("[");
		int j=0;
		while (j<(this->_alto)){
			if (this->_grilla[i][j]) os.append("X"); else os.append("O");
			if(j<((this->_alto)-1)) os.append(",");
			j++;
		}
		os.append("]");
		os.append("\n");
		i++;
	}
	return os;
}

Campus::Campus (Nat an, Nat al){
	this->_ancho=an;
	this->_alto=al;
	this->_grilla=Arreglo<Arreglo<bool> >(an);
	int i=0;
	while(i<an){
		this->_grilla.Definir(i,Arreglo<bool>(al));
		int j=0;
		while (j<al) this->_grilla[i].Definir(j, false), j++;
		i++;
		}
};
void Campus::agregarObs(Posicion obst){
	this->_grilla[obst.x].Definir(obst.y, true);
};

Nat Campus::alto(){
	return this->_alto;
};

Nat Campus::ancho(){
	return this->_ancho;
};

bool Campus::ocupada(Posicion p){
	return this->_grilla[p.x][p.y];
};

bool Campus::posValida(Posicion p){
	return (p.x<this->_ancho)&&(p.y<this->_alto);
};

bool Campus::esIngreso(Posicion p){
	return (p.y==0)||(p.y==(this->_alto -1));
};

bool Campus::ingresoSup(Posicion p){
	return p.y==0;
};

bool Campus::ingresoInf(Posicion p){
	return p.y==this->_alto -1;
};

Nat Campus::distancia(Posicion p1, Posicion p2){
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
};
Conj<Posicion> Campus::vecinos(Posicion p){
	  Conj<Posicion> veci;
	  Posicion cand;
	  cand.x=p.x-1;
	  cand.y=p.y;
	  if(this->posValida(cand)) veci.AgregarRapido(cand);
	  cand.x+=2;
	  if(this->posValida(cand)) veci.AgregarRapido(cand);
	  cand.x-=1;
	  cand.y-=1;
	  if(this->posValida(cand)) veci.AgregarRapido(cand);
	  cand.y+=2;
	  if(this->posValida(cand)) veci.AgregarRapido(cand);
	  return veci;
};
Posicion Campus::aPosMasCercana(Posicion p, Conj<Posicion> posi){
	Conj<Posicion>::Iterador it=posi.CrearIt();
	Posicion cand=it.Siguiente();// Que haya una pos esta segurado por el pre?
	while (it.HaySiguiente()){
		if (this->distancia(cand,p)>this->distancia(it.Siguiente(),p)){
			cand=it.Siguiente();
			while (it.HayAnterior()) it.EliminarAnterior();
			it.Avanzar();
		}else{
			if (this->distancia(cand,p)<this->distancia(it.Siguiente(),p)){
				it.EliminarSiguiente();
				cand=it.Siguiente(); //Como aseguras q E siguiente para asignar?
			}else it.Avanzar();
		} // Si la distancia es = no tiene que avanzar?
	}
	it=posi.CrearIt();
	cand=it.Siguiente();
	Posicion ceero;
	ceero.x=0;
	ceero.y=0;
	while (it.HaySiguiente()){
		if (this->distancia(ceero,p)>this->distancia(it.Siguiente(),ceero)){
			cand=it.Siguiente();
			while (it.HayAnterior()) it.EliminarAnterior();
			it.Avanzar();
		}else{
			if (this->distancia(ceero,p)<this->distancia(it.Siguiente(),ceero)){
				it.EliminarSiguiente();
				cand=it.Siguiente();
			}else it.Avanzar();
		}
	}
	it=posi.CrearIt();
	cand=it.Siguiente();
	while (it.HaySiguiente()){
		it=posi.CrearIt();
		cand=it.Siguiente();
		if (cand.y<it.Siguiente().y){
			cand=it.Siguiente();
			while (it.HayAnterior()) it.EliminarAnterior();
			it.Avanzar();
		}else{
			if (cand.y>it.Siguiente().y){
				it.EliminarSiguiente();
				cand=it.Siguiente();
			}else it.Avanzar();
		}
	}
	return cand;
};

}
