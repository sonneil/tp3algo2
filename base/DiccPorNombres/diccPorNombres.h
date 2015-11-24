#include <sstream>
#include "../aed2/aed2.h"

template<typename B>
class DiccPorNombres {
	public:
		struct ClaveSignificado {
			std::string clave;
			B significado;

			ClaveSignificado(const std::string& c, const B& s) : clave(c), significado(s) {}
		};

		/// Iterador
		class ItDPN {
			public:
				ItDPN();
				DiccPorNombres<B>::ClaveSignificado Siguiente() const;
				DiccPorNombres<B>::ClaveSignificado Anterior() const;
				std::string SiguienteClave() const;
				std::string AnteriorClave() const;
				B SiguienteSignificado() const;
				B AnteriorSignificado() const;
			private:
				typename Lista< DiccPorNombres<B>::ClaveSignificado >::Iterador itLista;
		};


		/// Estructura
		~DiccPorNombres();
		DiccPorNombres();
		const int tamanio() const;
		const std::string toString() const;
		typename Lista<typename DiccPorNombres<B>::ClaveSignificado>::Iterador definir(std::string, B);
		B obtener(std::string) const;
		bool definido(std::string) const;
		void eliminar(std::string);

	private:
		struct Nodo {
			bool hayS;
			B significado;
			DiccPorNombres* hijos;
			typename Lista<typename DiccPorNombres<B>::ClaveSignificado>::Iterador enLista;

			~Nodo() {
				if (hijos!=NULL) delete hijos;
			}

			Nodo() : hayS(false), hijos(new DiccPorNombres()) {}

			Nodo(bool haySignificado, B s, typename Lista<typename DiccPorNombres<B>::ClaveSignificado>::Iterador itALista) : hayS(haySignificado),  significado(s), hijos(new DiccPorNombres()), enLista(itALista) {}
		};

		Vector<Nodo*> buckets;
		Lista<typename DiccPorNombres<B>::ClaveSignificado>& enLista = *(new Lista<typename DiccPorNombres<B>::ClaveSignificado>());
		int tam;

		/// Op aux
		Vector<Nodo*> nuevosBuckets() const {
			Vector<Nodo*> buckets;
			for (int i=0; i < 128; i++) {
				buckets.AgregarAtras(NULL);
			}
			return buckets;
		}

		int cantDefinidos(Vector<Nodo*> vec) const {
			int cant = 0;
			for (int i=0; i < 128; i++) {
				cant += (vec[i]!=0)?1:0;
			}
			return cant;
		}

		void destruir(DiccPorNombres<B>* d) {
			if (d!=NULL) {
	 			for (int i=0; i<d->buckets.Longitud(); i++) {
					if (d->buckets[i]!=NULL){
						delete(d->buckets[i]);
					}
				}
				delete (d);
			}
		}

};


/// Implementacion de operaciones
template<class B>
DiccPorNombres<B>::DiccPorNombres() {
	this->buckets = this->nuevosBuckets();
	this->tam = 0;
}

template<class B>
DiccPorNombres<B>::~DiccPorNombres() {
	delete (&(this->enLista));
	for (int i=0; i<this->buckets.Longitud();i++){
		if (this->buckets[i] != NULL)
			delete (this->buckets[i]);
	}
}

template<class B>
const int DiccPorNombres<B>::tamanio() const {
	return this->tam;
}

template<class B>
const std::string DiccPorNombres<B>::toString() const {
	std::stringstream str;
	str << "[";
	typename Lista<typename DiccPorNombres<B>::ClaveSignificado>::Iterador it = this->enLista.CrearIt();
	while (it.HaySiguiente()) {
		str << "(" << it.Siguiente().clave << "," << it.Siguiente().significado << ")";
		it.Avanzar();
		if (it.HaySiguiente()) {
			str << ",";
		}
	}
	str << "]";
	return str.str();
}

template<class B>
typename Lista<typename DiccPorNombres<B>::ClaveSignificado>::Iterador DiccPorNombres<B>::definir(std::string c, B s) {
	// PRE: La clave no esta definida en el diccionario
	DiccPorNombres* d = this;
	int i=0;
	while (i < c.length()-1) {
 		if (d->buckets.EsVacio()) {
 			d->buckets = this->nuevosBuckets();
 		}
 		if (d->buckets[c[i]]==0) {
 			d->buckets[c[i]] = new Nodo();
 		}
		d = d->buckets[c[i]]->hijos;
		i++;
	}
	DiccPorNombres<B>::ClaveSignificado cs(c,s);
	if (d->buckets.EsVacio()) {
		d->buckets = nuevosBuckets();
	}
	d->buckets[c[i]] = new Nodo(true,s,this->enLista.AgregarAtras(cs));
	this->tam++;
	return d->buckets[c[i]]->enLista;
}

template<class B>
B DiccPorNombres<B>::obtener(std::string c) const {
	const DiccPorNombres* d = this;
	int i=0;
	while (i < c.length()-1) {
		d = d->buckets[c[i]]->hijos;
		i++;
	}
	return d->buckets[c[i]]->significado;
}

template<class B>
bool DiccPorNombres<B>::definido(std::string c) const {
	const DiccPorNombres* d = this;
	int i=0;
	while (i < c.length()-1) {
		if (d==0 || d->buckets.EsVacio() || d->buckets[c[i]]==0) {
			return false;
		}
		d = d->buckets[c[i]]->hijos;
		i++;
	}
	if (d==0 || d->buckets.EsVacio() || d->buckets[c[i]]==0) {
		return false;
	}
	return d->buckets[c[i]]->hayS;
}

template<class B>
void DiccPorNombres<B>::eliminar(std::string c) {
	DiccPorNombres* d = this;
	int i=0;
	bool ramaUnica = false;
	DiccPorNombres* aBorrarInicio = NULL;
	DiccPorNombres* hijoABorrar = NULL;
	int inicioRamaABorrar = 0;
	// Diccionario d; ramaUnica = false;
	// Mientras i menor que la longitud de la clave menos uno
	//		Si los buckets del dicc tienen un unico significado entre los caracteres y no ramaUnica -> ramaUnica = true; aBorrarInicio = d; inicioRamaABorrar = i;
	//		d igual a hijos de buckets[c[i]]
	//		i++
	//	Finalizar Ciclo
	//  Comenzar borrado de rama
	//		If (ramaUnica && d->buckets[c[i]]->hijos==NULL(0)) :
	//		  mientras (inicioRamaABorrar < longClaveMenosUno) : 
	//			hijoABorrar = aBorrarInicio->buckets[c[inicioRamaABorrar]]; 
	//			delete(aBorrarInicio->buckets[c[inicioRamaABorrar]]); 
	//			aBorrarInicio->buckets[c[inicioRamaABorrar]] = NULL
	//			aBorrarInicio = hijoABorrar
	//			inicioRamaABorrar++
	//		Fin mientras
	//		La rama quedo ubicada al final; i esta en la ultima posicion de la clave; d quedo en el ultimo bucket a borrar
	//			delete(d->buckets[c[i]])
	//			d->buckets[c[i]] = NULL

	// Busco primer posicion a borrar y posiciono el dicc en la ultima (la que tiene el significado)
	while (i < c.length()-1) {
		if (!ramaUnica && (cantDefinidos(d->buckets)==1)) {
				ramaUnica = true;
				aBorrarInicio = d;
				inicioRamaABorrar = i;
		}
		d = d->buckets[c[i]]->hijos;
		i++;
	}

	if (d->buckets[c[i]]->hijos==0) {
		while (ramaUnica && inicioRamaABorrar < c.length()-1) {
			hijoABorrar = aBorrarInicio->buckets[c[inicioRamaABorrar]]->hijos;
			delete (aBorrarInicio->buckets[c[inicioRamaABorrar]]);
			aBorrarInicio->buckets[c[inicioRamaABorrar]] = NULL;
			aBorrarInicio = hijoABorrar;
			inicioRamaABorrar++;
		}
		d->buckets[c[i]]->enLista.EliminarSiguiente();
		delete (d->buckets[c[i]]);
		d->buckets[c[i]] = NULL;
	} else {
		d->buckets[c[i]]->hayS = false;
		d->buckets[c[i]]->enLista.EliminarSiguiente();
	}
	this->tam--;
}

/// Implementacion del iterador
template<class B>
DiccPorNombres<B>::ItDPN::ItDPN() : itLista(this->enLista.CrearIt()) {}

template<class B>
typename DiccPorNombres<B>::ClaveSignificado DiccPorNombres<B>::ItDPN::Siguiente() const {
	return itLista.Siguiente();
}

template<class B>
typename DiccPorNombres<B>::ClaveSignificado DiccPorNombres<B>::ItDPN::Anterior() const {
	return itLista.Anterior();
}

template<class B>
std::string DiccPorNombres<B>::ItDPN::SiguienteClave() const {
	return itLista.Siguiente().clave;
}

template<class B>
std::string DiccPorNombres<B>::ItDPN::AnteriorClave() const {
	return itLista.Anterior().clave;
}

template<class B>
B DiccPorNombres<B>::ItDPN::SiguienteSignificado() const {
	return itLista.Siguiente().significado;
}

template<class B>
B DiccPorNombres<B>::ItDPN::AnteriorSignificado() const {
	return itLista.Anterior().significado;
}