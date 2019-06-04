#ifndef JUGADOR_H
#define JUGADOR_H
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Jugador {

private:

	string nombre;

public:

	Jugador();
	Jugador(string);
	~Jugador();
	void setNombre(string);
	string getNombre();
	string toString();
};
#endif 
