#include "campus.h"
#include <iostream>
#include "../mini_test.h"


int main (){

	Campus c(12,12);
	std::cout<<c.showtime()<<"\n";
	Posicion p;
	p.x=3, p.y=5;
	c.agregarObs(p);
	std::cout<<c.showtime()<<"\n";
	p.x=4, p.y=6;
	c.agregarObs(p);
	std::cout<<c.showtime()<<"\n";
	std::cout<<c.ancho()<<"\n";
	std::cout<<c.alto()<<"\n";
	
	return 0;
}
