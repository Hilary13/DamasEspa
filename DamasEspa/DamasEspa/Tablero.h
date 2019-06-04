#ifndef TABLERO_H
#define TABLERO_H

#include <iostream>
#include <sstream>
#include <conio.h>
#include <Windows.h>
#include "Posicion.h"
using namespace std;

class Tablero
{
private:

	Posicion* tablero[8][8];  
	Ficha* ficha;

public:
	Tablero();
	string toStringTablero();
	Ficha* getFicha(int, int);
	Posicion* getPosicion(int, int);
	void color(int);
	void agregar(Ficha*, int, int);

	~Tablero();
};
#endif 

