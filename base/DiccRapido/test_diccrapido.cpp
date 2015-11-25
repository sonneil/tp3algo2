#include "DiccRapido.h"
#include "../mini_test.h"


void test() {
	DiccRapido<int> diccRapido;
}

void test_nuevo() {
	Dicc<int,std::string> diccACopiar;
	diccACopiar.Definir(0,"Cero");
	diccACopiar.Definir(5,"Cinco");
	diccACopiar.Definir(8,"Ocho");
	diccACopiar.Definir(11,"Once");
	diccACopiar.Definir(90,"Noventa");
	//
	DiccRapido<std::string> diccRapido(diccACopiar);
	//
	//ASSERT_EQ(diccRapido.toString(),"[(0,Cero)(5,Cinco)(8,Ocho)(11,Once)(90,Noventa)]");
	std::cout << diccRapido.toString() << std::endl;
}

void test_obtener() {
	Dicc<int,std::string> diccACopiar;
	diccACopiar.Definir(0,"Cero");
	diccACopiar.Definir(5,"Cinco");
	diccACopiar.Definir(8,"Ocho");
	diccACopiar.Definir(11,"Once");
	diccACopiar.Definir(90,"Noventa");
	//
	DiccRapido<std::string> diccRapido(diccACopiar);
	//
	ASSERT_EQ(diccRapido.obtener(0),"Cero");
	ASSERT_EQ(diccRapido.obtener(5),"Cinco");
	ASSERT_EQ(diccRapido.obtener(8),"Ocho");
	ASSERT_EQ(diccRapido.obtener(11),"Once");
	ASSERT_EQ(diccRapido.obtener(90),"Noventa");
}

int main() {
	test();
	test_nuevo();
	test_obtener();
	return 0;
}