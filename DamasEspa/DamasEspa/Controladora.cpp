#include "Controladora.h"
#include "Tablero.h"
#include "Ficha.h"

Controladora::Controladora() {}
Controladora::~Controladora() {}

//-----------------------------------menu principal----------------------------------------------------
void Controladora::menuprincipal() {
	system("cls");
	char entrar;
	do {
		cout << " \n";
		cout << "       +-----------------------------------------------+" << endl;
		cout << "       |                      MENU                     |" << endl;
		cout << "       +-----------------------------------------------+" << endl;
		cout << "       |                                               |" << endl;
		cout << "       |  1. Comenzar Partida                          |" << endl;
		cout << "       |  2. Cargar Partida                            |" << endl;
		cout << "       |  3. Salir                                     |" << endl;
		cout << "       |                                               |" << endl;
		cout << "       +-----------------------------------------------+" << endl;
		cout << "       Opción: ";
		cin >> entrar;
		switch (entrar) {

		case '1':
			system("cls");
			Interfaz::crearJugador();
			system("pause");
			system("cls");
			break;

		case '2':
			system("cls");
			Interfaz::cargarPartida();
			system("pause");
			system("cls");
			break;

		case '3':
			cout << " \n";
			cout << "       ¡Gracias por jugar! \n";
			cout << " \n";
			system("pause");
			exit(1);

			break;
		default:
			cout << " \n";
			cout << "       La opción digitada es incoreccta, por favor digite una opción correcta: " << endl;
			cout << " \n";
			system("pause");
			system("cls");
			break;
		}
	} while (entrar > 3);
}

void Controladora::inicio() {
	Interfaz::inicio();
	Controladora::menuprincipal();
}