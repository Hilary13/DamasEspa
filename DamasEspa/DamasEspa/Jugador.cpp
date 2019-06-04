#include"Jugador.h"



Jugador::Jugador() {}

Jugador::Jugador(string n) {
	nombre = n;
}

Jugador::~Jugador() {}

string Jugador::toString() {
	stringstream s;
	s << "                Jugador: " << nombre << endl;
	return s.str();
}


string Jugador::getNombre() {
	return nombre;
}


void Jugador::setNombre(string n) {
	nombre = n;
}