#include "diccPorNombres.h"
#include "mini_test.h"

void test_nuevo() {
	DiccPorNombres<int> diccEnteros;
	DiccPorNombres< DiccPorNombres<String> > diccDiccPorNombres;
	ASSERT_EQ(diccEnteros.tamanio(), 0);
	ASSERT_EQ(diccDiccPorNombres.tamanio(), 0);
}

void definir_test() {
	DiccPorNombres<int> diccEnteros;
	DiccPorNombres< DiccPorNombres<String> > diccDiccPorNombres;
	diccEnteros.definir("cero",0);
	diccEnteros.definir("uno",1);
	diccEnteros.definir("dos",2);
	std::cout << diccEnteros.toString() << std::endl;
	ASSERT_EQ(diccEnteros.tamanio(),3);
	ASSERT_EQ(diccEnteros.toString(), "[(cero,0),(uno,1),(dos,2)]");

}


void obtener_test() {
	DiccPorNombres<int> diccEnteros;
	DiccPorNombres< DiccPorNombres<String> > diccDiccPorNombres;
	diccEnteros.definir("cero",0);
	diccEnteros.definir("uno",1);
	diccEnteros.definir("dos",2);
	diccEnteros.definir("tres",3);
	ASSERT_EQ(diccEnteros.tamanio(),4);
	ASSERT_EQ(diccEnteros.toString(), "[(cero,0),(uno,1),(dos,2),(tres,3)]");

	// Obtener
	ASSERT_EQ(diccEnteros.obtener("cero"),0);
	ASSERT_EQ(diccEnteros.obtener("uno"),1);
	ASSERT_EQ(diccEnteros.obtener("dos"),2);
	ASSERT_EQ(diccEnteros.obtener("tres"),3);
}

void definido_test() {
	DiccPorNombres<int> diccEnteros;
	DiccPorNombres< DiccPorNombres<String> > diccDiccPorNombres;
	// No hay nada definido
	ASSERT(!diccEnteros.definido("cero"));
	ASSERT(!diccEnteros.definido("uno"));
	ASSERT(!diccEnteros.definido("dos"));
	ASSERT(!diccEnteros.definido("tres"));

	diccEnteros.definir("cero",0);
	diccEnteros.definir("uno",1);
	diccEnteros.definir("dos",2);
	diccEnteros.definir("tres",3);
	ASSERT_EQ(diccEnteros.tamanio(),4);
	ASSERT_EQ(diccEnteros.toString(), "[(cero,0),(uno,1),(dos,2),(tres,3)]");

	// Obtener
	ASSERT_EQ(diccEnteros.obtener("cero"),0);
	ASSERT_EQ(diccEnteros.obtener("uno"),1);
	ASSERT_EQ(diccEnteros.obtener("dos"),2);
	ASSERT_EQ(diccEnteros.obtener("tres"),3);	

	// Todos definidos
	ASSERT(diccEnteros.definido("cero"));
	ASSERT(diccEnteros.definido("uno"));
	ASSERT(diccEnteros.definido("dos"));
	ASSERT(diccEnteros.definido("tres"));
}

void eliminar_test() {
	DiccPorNombres<int> diccEnteros;
	DiccPorNombres< DiccPorNombres<String> > diccDiccPorNombres;
	// No hay nada definido
	ASSERT(!diccEnteros.definido("cero"));
	ASSERT(!diccEnteros.definido("uno"));
	ASSERT(!diccEnteros.definido("dos"));
	ASSERT(!diccEnteros.definido("tres"));

	diccEnteros.definir("cero",0);
	diccEnteros.definir("uno",1);
	diccEnteros.definir("dos",2);
	diccEnteros.definir("tres",3);
	ASSERT_EQ(diccEnteros.tamanio(),4);
	ASSERT_EQ(diccEnteros.toString(), "[(cero,0),(uno,1),(dos,2),(tres,3)]");

	// Obtener
	ASSERT_EQ(diccEnteros.obtener("cero"),0);
	ASSERT_EQ(diccEnteros.obtener("uno"),1);
	ASSERT_EQ(diccEnteros.obtener("dos"),2);
	ASSERT_EQ(diccEnteros.obtener("tres"),3);	

	// Todos definidos
	ASSERT(diccEnteros.definido("cero"));
	ASSERT(diccEnteros.definido("uno"));
	ASSERT(diccEnteros.definido("dos"));
	ASSERT(diccEnteros.definido("tres"));

	// Eliminar
	diccEnteros.eliminar("cero");
	diccEnteros.eliminar("uno");
	
	// Definidos
	ASSERT(!diccEnteros.definido("cero"));
	ASSERT(!diccEnteros.definido("uno"));
	ASSERT(diccEnteros.definido("dos"));
	ASSERT(diccEnteros.definido("tres"));

}


int main() {
	test_nuevo();
	definir_test();
	obtener_test();
	definido_test();
	eliminar_test();
}