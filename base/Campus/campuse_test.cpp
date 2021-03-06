#include "campus.h"
#include <iostream>
#include "../mini_test.h"
#include <stdlib.h> //incluir para rabdom
#include <time.h> //idem
using namespace aed2;
Campus randcreate(){
	//aqui comienza la creacion de una instancia random
	//srand(time(NULL)); comentada porque sòlo debe aparecer una vez por ejecuciòn
	int al= rand()%40+5;
	int an= rand()%40+5;
	Campus c(an, al);
	int max_obst=rand()%((an*al)/2)+20;
	int i=0;
	while (i<max_obst){
		Posicion p;
		p.x=rand()%an;
		p.y=rand()%al;
		c.agregarObs(p);
		i++;
	}
	//aqui termina la creaciòn random de instancia
	return c;
}
Campus randsinobs(){//crea un campus sin obstaculos
	int al= rand()%40+5;
	int an= rand()%40+5;
	Campus c(an, al);
	int max_obst=rand()%((an*al)/2)+20;
	int i=0;
	return c;
}

void test_igualdad() {
	Campus c =randsinobs();
	Campus d =c;
	bool proas= (c==d);
	ASSERT(proas);
	Posicion p;
	p.x=rand()%(c.ancho());
	p.y=rand()%(c.alto());
	c.agregarObs(p);
	proas= (c==d);
	ASSERT(!proas);
	d.agregarObs(p);
	proas= (c==d);
	ASSERT(proas);
}

void test_pos_valida() {
	Campus c =randsinobs();
	Campus d =c;
	bool proas= (c==d);
	Posicion p;
	p.x=rand()%(c.ancho())+(c.ancho())+1;
	p.y=rand()%(c.alto())+(c.alto())+1;
	proas=c.posValida(p);
	ASSERT(!proas);
	p.x=rand()%(c.ancho());
	p.y=rand()%(c.alto());
	proas=c.posValida(p);
	ASSERT(proas);
}

int main (){
	srand(time(NULL));
	int veces=0;
	while(veces<100000){
	RUN_TEST(test_igualdad);
	RUN_TEST(test_pos_valida);
	veces++;
	}
	return 0;
}
