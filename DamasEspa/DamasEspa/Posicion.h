#ifndef POSICION_H
#define POSICION_H
#include "Ficha.h"
//#include "Tablero.h"
using namespace std;

class Posicion
{
private:
	int i;
	int j;
	Ficha* ficha;
	//Tablero* tablero;
public:
	Posicion(int, int, Ficha*);
	Ficha* getFicha();
	void setFicha(Ficha*);
	//void restricciones(int, int);
	~Posicion();
};
#endif 
