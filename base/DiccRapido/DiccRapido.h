#include <sstream>
#include "../aed2/aed2.h"

template<typename B>
class DiccRapido {
	public:

		// struct ClaveSignificado;

		
		struct ClaveSignificado {
			int clave;
			B significado;

			ClaveSignificado(const int& c, const B& s) : clave(c), significado(s) {}
		};

		class itDiccR {
			public:
				itDiccR();
				DiccRapido<B>::ClaveSignificado Siguiente() const;
				DiccRapido<B>::ClaveSignificado Anterior() const;
				int SiguienteClave() const;
				int AnteriorClave() const;
				B SiguienteSignificado() const;
				B AnteriorSignificado() const;
			private:
				typename Dicc<int,B>::Iterador itDicc;
		};


		// class itDiccR;
 		// Constructores
    	DiccRapido();
    	DiccRapido(const Dicc<int,B>);
    	std::string toString() const;
    	//DiccRapido(const DiccRapido otro);
    	//DiccRapido& operator=(const DiccRapido& otro);
    	
    	B obtener(int);
    	itDiccR DameIterador();
    	//void Definir( DiccRapido& a, const int clave, const B significado);
    	// bool Definido(const DiccRapido& a, const int clave);
    	// int CantClaves(const DiccRapido& a);

	private:
		Vector< Dicc< int,typename Dicc<int,B>::Iterador > > accesoRapido;
		Dicc<int,B> contenedor;

		//Operaciones privadas
		int fHash(int k) const {
			return (k%this->accesoRapido.Longitud());
		}
};

template<typename B>
DiccRapido<B>::DiccRapido() {}

template<typename B>
DiccRapido<B>::DiccRapido(const Dicc<int,B> diccADefinir) {
	// Inicializar vector de acceso rapido
	typename Dicc<int,B>::const_Iterador it = diccADefinir.CrearIt();
	while (it.HaySiguiente()) {
		Dicc< int,typename Dicc<int,B>::Iterador > diccionario;
		this->accesoRapido.AgregarAtras(diccionario);
		it.Avanzar();
	}
	// Definir los elementos en el hash
	typename Dicc<int,B>::const_Iterador it2 = diccADefinir.CrearIt();
	while (it2.HaySiguiente()) {
		int c = it2.SiguienteClave();
		this->accesoRapido[fHash(c)].Definir(c,this->contenedor.Definir(c,it2.SiguienteSignificado()));
		std::cout << "Definido: " << this->accesoRapido[fHash(it2.SiguienteClave())].Significado(c).SiguienteSignificado() << "  Tamanio: " << this->accesoRapido.Longitud() << std::endl;
		it2.Avanzar();
	}
}

template<typename B>
std::string DiccRapido<B>::toString() const {
	std::stringstream str;
	str << "[";
	typename Dicc<int,B>::const_Iterador it = this->contenedor.CrearIt();
	while (it.HaySiguiente()) {
		str << "(" << it.SiguienteClave() << "," << it.SiguienteSignificado() << ")";
		it.Avanzar();
	}
	str << "]";
	return str.str();

	/*std::stringstream str;
	for (int i=0;i<this->accesoRapido.Longitud();i++) {
		typename Dicc< int,typename Dicc<int,B>::Iterador >::const_Iterador it = this->accesoRapido[i].CrearIt();
		str << "[";
		while (it.HaySiguiente()) {
			str << it.SiguienteClave();
			it.Avanzar();
		}
		str << "]" << std::endl;
	}
	return str.str();*/
}

template<typename B>
B DiccRapido<B>::obtener(int c) {
	return this->accesoRapido[fHash(c)].Significado(c).SiguienteSignificado();
}