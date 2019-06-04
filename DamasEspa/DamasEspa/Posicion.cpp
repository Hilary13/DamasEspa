#include "Posicion.h"



Posicion::Posicion(int i, int j, Ficha* ficha)
{
	this->i = i;
	this->j = j;
	this->ficha = ficha;
}

Ficha* Posicion::getFicha() { return ficha; }

void Posicion::setFicha(Ficha* ficha) { this->ficha = ficha; }

//void Posicion::restricciones(int i, int j)

	/*tablero->getFicha(i, j);
	if () {
		
	}else
*/

	/*	ficha = tablero->getFicha(i, j);
	tablero->getPosicion(i, j)->setFicha(NULL);
	tablero->agregar(ficha, n, m);
	ficha = NULL;*/


Posicion::~Posicion()
{
}
