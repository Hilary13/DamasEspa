
#include "Archivos.h"

Archivos::Archivos() {}
Archivos::~Archivos() {}

void Archivos::leerArchivoPartidas(Lista* lista) {
	ifstream lectura("../Partidas.txt", ios::app);
	lectura.exceptions(ifstream::failbit);
	Tablero* tablero;
	Jugador* jugador;
	Estrategia* estrategia;
	Ficha* ficha;
	Partida* partida;
	int numPartida = 1;
	try {
		string nombre, estAux, carAux, vacio;

		while (lectura.good()) {
			tablero = new Tablero();
			int numEstrategia = -1;
			char caracter;

			getline(lectura, nombre, '\t');
			getline(lectura, estAux, '\n');

			if (!estAux.empty()) {
				stringstream convertir(estAux);
				convertir >> numEstrategia;
			}
			getline(lectura, vacio, '\n');

			jugador = new Jugador(nombre);
			estrategia = new Estrategia(); // numEstrategia

			for (int i = 0; i < 8; i++) {
				for (int j = 0; j < 8; j++) {
					getline(lectura, carAux, ',');
					stringstream convertir(carAux);
					convertir >> caracter;
					if (caracter == '-') {
						ficha = NULL;
						tablero->agregar(ficha, i, j);
					}
					else {
						ficha = new Ficha(caracter);
						tablero->agregar(ficha, i, j);
					}
				}
			}
			getline(lectura, vacio, '\n');
			getline(lectura, vacio, '\n');

			partida = new Partida(numPartida, estrategia, jugador, tablero);
			lista->agregar(partida);
			numPartida++;
		}
	}
	catch (ifstream::failure) {} //cout << "Falla al abrir el archivo";
	lectura.close();
}

void Archivos::guardarPartidas(Lista* lista) {
	ofstream escritura;

	string nombreJugador;
	char caracter;
	int numEstrategia;

	Partida* partida;
	Jugador* jugador;
	Ficha* ficha;
	Tablero* tablero;
	Estrategia* estrategia;
	escritura.open("../Partidas.txt", ios::trunc);
	Nodo* actual = lista->getPrimero();
	while (actual != NULL) {
		partida = actual->getInfo();
		//planilla = (ContratoPlanilla*)oAux;
		jugador = partida->getJugador();
		tablero = partida->getTablero();
		//ficha = tablero->
		estrategia = partida->getEstrategia();

		nombreJugador = jugador->getNombre();
		numEstrategia = 0;

		escritura << nombreJugador << "\t";
		escritura << numEstrategia << "\n";

		for (int i = 0; i < 8; i++) {
			escritura << "\n";
			for (int j = 0; j < 8; j++) {
				if (tablero->getFicha(i, j) != NULL) {
					ficha = tablero->getFicha(i, j);
					caracter = ficha->getCaracter();
					escritura << caracter << ",";
				}
				else {
					caracter = '-';
					escritura << caracter << ",";
				}
			}
		}
		escritura << "\n";
		escritura << "/";
		escritura << "\n";

		actual = actual->getSig();
	}
	escritura.close();
}
//Python 