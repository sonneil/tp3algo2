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

bool