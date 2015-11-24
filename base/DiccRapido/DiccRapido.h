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

		class itDiccR{
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

    	DiccRapido();
    	//DiccRapido(const DiccRapido otro);
    	DiccRapido& operator=(const DiccRapido& otro);

    	void Nuevo(const Dicc<int,B> diccACopiar);
    	B Obtener(const DiccRapido<B> a, const int clave);
    	itDiccR DameIterador();
    	//void Definir( DiccRapido& a, const int clave, const B significado);
    	// bool Definido(const DiccRapido& a, const int clave);
    	// int CantClaves(const DiccRapido& a);

	private:
		Vector< Dicc< int,typename Dicc<int,B>::Iterador > > accesoRapido;
		Dicc<int,B> contenedor;

		//Operaciones privadas
		int fHash() const;
};

template<typename B>
DiccRapido<B>::DiccRapido() {

}