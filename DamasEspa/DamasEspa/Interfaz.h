#ifndef INTERFAZ_H
#define INTERFAZ_H
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <Windows.h>
#include "Archivos.h"
#include "Ficha.h"
#include "Jugador.h"
#include "Tablero.h"
#include "Controladora.h"
#include "Estrategia.h"
#include "Lista.h"
#include "Partida.h"
using namespace std;

class Archivos;

class Interfaz {
public:
	static void pruebas();
	static void inicio();

	static void inicializarTablero();
	static void imprimirTablero();
	static void lecturaArchivos();
	static void asignarNumPartida();
	static void eliminarTodo();
	static void crearPartida();
	static void elegirEstrategia();
	static void jugada();

	static void cargarPartida();
	static void guardarPartida();
	static string leerString();
	static void color(int);
	static bool comprobarNumPartida(int);
	static void moverFicha(int, int, int, int);

	static void Juego();
	static void confirmarSalir();
	static void crearJugador();
	static void bienvenido();
};
#endif 