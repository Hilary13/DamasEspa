#include "Ficha.h"



Ficha::Ficha()
{
}

Ficha::Ficha(char caracter)
{
	this->caracter = caracter;
}

char Ficha::getCaracter() { return caracter; }

void Ficha::setCaracter(char caracter) { this->caracter = caracter; }


Ficha::~Ficha()
{
}
