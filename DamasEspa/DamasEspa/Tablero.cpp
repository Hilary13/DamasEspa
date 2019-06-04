#include "Tablero.h"



Tablero::Tablero()
{
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			tablero[i][j] = new Posicion(i, j, NULL);
		}
	}
}

string Tablero::toStringTablero()
{

	int f = 1;
	int c = 1;
	stringstream s;
	s << "	    ";
	for (int k = 0; k < 8; k++) {
		s << "  " << c << "   ";
		c++;
	}
	s << "\n";
	s << "	   =================================================" << endl;
	for (int i = 0; i < 8; i++) {
		s << "       " << f << "   ";
		for (int j = 0; j < 8; j++) {
			if (tablero[i][j]->getFicha() == NULL) {
				s << "|     ";
			}
			else {
				s << "|  " << tablero[i][j]->getFicha()->getCaracter() << "  ";
			}
		}
		s << "|";
		s << endl;
		s << "	   =================================================";
		f++;
		s << endl;
	}
	s << endl;
	return s.str();
}

Ficha* Tablero::getFicha(int i, int j)
{
	return tablero[i][j]->getFicha();
}

Posicion* Tablero::getPosicion(int i, int j)
{
	return tablero[i][j];
}



void Tablero::color(int c)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void Tablero::agregar(Ficha* f, int i, int j){
	tablero[i][j]->setFicha(f);
}


Tablero::~Tablero()
{
}
