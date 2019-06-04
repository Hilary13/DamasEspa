#include "Interfaz.h"

//------------------------------------------------VARIABLES GLOBALES---------------------------------------------
int contAux = 0;
int numPartida = 0;
Tablero* tablero = new Tablero();
Lista* lista = new Lista();
Ficha* ficha;
Nodo* actual;
Jugador* jugador;
Estrategia* estrategia;
Partida* partida;
Archivos* archivos;
//--------------------------------------------------------------------------------------------------------------

//---------------------------------------UTILIDADES-------------------------------------------------------------
void Interfaz::color(int c) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void Interfaz::moverFicha(int i, int j, int n, int m){
	ficha = tablero->getFicha(i, j);
	tablero->getPosicion(i, j)->setFicha(NULL);
	tablero->agregar(ficha, n, m);
	ficha = NULL;
}

void Interfaz::pruebas() {
	//empresa->calculoSalariosPlanilla(listContPlan);
}

void Interfaz::inicio() {
	Interfaz::inicializarTablero();
	Interfaz::lecturaArchivos();
	Interfaz::asignarNumPartida();
	estrategia = new Estrategia();
	bienvenido();
}

void Interfaz::inicializarTablero() {
	Ficha* x = new Ficha('x');
	Ficha* o = new Ficha('o');

	tablero->agregar(o, 0, 0);
	tablero->agregar(o, 0, 2);
	tablero->agregar(o, 0, 4);
	tablero->agregar(o, 0, 6);
	tablero->agregar(o, 1, 1);
	tablero->agregar(o, 1, 3);
	tablero->agregar(o, 1, 5);
	tablero->agregar(o, 1, 7);
	tablero->agregar(o, 2, 0);
	tablero->agregar(o, 2, 2);
	tablero->agregar(o, 2, 4);
	tablero->agregar(o, 2, 6);

	tablero->agregar(x, 5, 0);
	tablero->agregar(x, 5, 2);
	tablero->agregar(x, 5, 4);
	tablero->agregar(x, 5, 6);
	tablero->agregar(x, 6, 1);
	tablero->agregar(x, 6, 3);
	tablero->agregar(x, 6, 5);
	tablero->agregar(x, 6, 7);
	tablero->agregar(x, 7, 0);
	tablero->agregar(x, 7, 2);
	tablero->agregar(x, 7, 4);
	tablero->agregar(x, 7, 6);
}

void Interfaz::imprimirTablero() {
	cout << "\n\n\n";
	cout << "\n\n\n";
	cout << "\n\n\n";
	cout << "\n\n\n";
	cout << tablero->toStringTablero();
	cout << "\n\n\n";
}

void Interfaz::lecturaArchivos() {
	archivos->leerArchivoPartidas(lista);
}

void Interfaz::asignarNumPartida() {
	numPartida = lista->numElementos();
	numPartida++;
}

void Interfaz::eliminarTodo() {
	delete partida;
	delete archivos;
	delete lista;
}

void Interfaz::crearPartida() {
	partida = new Partida(numPartida, estrategia, jugador, tablero);
}
//-----------------------------------------------------------------------------------------------------------


//-------------------------------------------------JUEGO---------------------------------------------------------
void Interfaz::cargarPartida() {
	system("cls");
	int num;
	cout << " \n";
	cout << "				Partidas Guardadas";
	cout << " \n";
	cout << lista->toStringLista();
	cout << "	Ingrese el número de la partida que desea cargar: ";
	cin >> num;
	if (comprobarNumPartida(num)) {
		Partida* pAux;
		partida = actual->getInfo();
		jugador = partida->getJugador();
		tablero = partida->getTablero();
		estrategia = partida->getEstrategia();

		//partida->setJugador(jugador);
		//partida->setTablero(tablero);
		//partida->setEstrategia(estrategia);

		actual = lista->getPrimero();
		cout << " \n";
		cout << "\n\n\t\t\t\t\t\tCargando la partida, un momento...\n" << endl;
		cout << "\t\t\t";
		for (int i = 0; i < 60; i++) {
			color(255);
			cout << " ";
			Sleep(20);
		}
		color(15);
		cout << " \n\n";
		cout << "	          La partida se ha cargado con exito. \n";
		cout << " \n";
		system("pause");
		system("cls");
		Interfaz::Juego();
	}
	else {
		cout << " \n";
		cout << " \n";
		cout << "	          El número de partida ingresado no coincide con nunguno de la lista. \n";
		cout << "	          Por favor vuelva a intentarlo. \n";
		cout << " \n";
		system("pause");
		system("cls");
		cargarPartida();
	}
}

void Interfaz::guardarPartida() {

	if (comprobarNumPartida(numPartida)) {
		system("cls");
		Partida* pAux;
		pAux = actual->getInfo();
		pAux->setJugador(jugador);
		pAux->setTablero(tablero);
		pAux->setEstrategia(estrategia);
		actual = lista->getPrimero();
		archivos->guardarPartidas(lista);
		Interfaz::imprimirTablero();
		cout << "	     Partida #" << partida->getNumPartida() << endl;
		cout << "        Jugador: " << jugador->getNombre() << endl;
		cout << " \n";
		cout << "       +------------------------------------+         " << endl;
		cout << "       |                                              " << endl;
		cout << "	    | 1. Realizar Jugada                           " << endl;
		cout << "	    | 2. Cambiar Dificultad                        " << endl;
		cout << "	    | 3. Guardar Partida                           " << endl;
		cout << "       | 4. Salir                                     " << endl;
		cout << "       |                                              " << endl;
		cout << "       +------------------------------------+         " << endl;
		cout << " \n";
		cout << "	       Opcion: ";
		cout << " \n";
		cout << "\n\n\t\t\t\t\t\tGuardando, no apagues la consola...\n" << endl;
		cout << "\t\t\t";
		for (int i = 0; i < 60; i++) {
			color(255);
			cout << " ";
			Sleep(20);
		}
		color(15);
		cout << " \n\n";
		cout << "	          La partida que quiere guardar ya se encontraba registrada.\n";
		cout << "	          La partida se ha sobre-escrito con exito. \n";
		cout << " \n";
	}
	else {
		lista->agregar(partida);
		archivos->guardarPartidas(lista);
		Interfaz::imprimirTablero();
		cout << "	     Partida #" << partida->getNumPartida() << endl;
		cout << "        Jugador: " << jugador->getNombre() << endl;
		cout << " \n";
		cout << "       +------------------------------------+         " << endl;
		cout << "       |                                              " << endl;
		cout << "	    | 1. Realizar Jugada                           " << endl;
		cout << "	    | 2. Cambiar Dificultad                        " << endl;
		cout << "	    | 3. Guardar Partida                           " << endl;
		cout << "       | 4. Salir                                     " << endl;
		cout << "       |                                              " << endl;
		cout << "       +------------------------------------+         " << endl;
		cout << " \n";
		cout << "	       Opcion: ";
		cout << " \n";
		cout << "\n\n\t\t\t\t\t\tGuardando, no apagues la consola...\n" << endl;
		cout << "\t\t\t";
		for (int i = 0; i < 60; i++) {
			color(255);
			cout << " ";
			Sleep(20);
		}
		color(15);
		cout << " \n";
		cout << " \n";
		cout << "	          Partida guardada con exito. \n";
		cout << " \n";
	}
}

string Interfaz::leerString() {

	char chain[100];
	cin.getline(chain, 99);
	stringstream s;
	s << chain;
	int size = s.str().length();

	if (size == 0 || s.str()[0] == 32) {
		if (contAux > 0) {
			cout << "Texto incorrecto, por favor ingreselo nuevamente: ";
		}
		contAux++;
		return leerString();
	}
	contAux = 0;
	return s.str();
}


bool Interfaz::comprobarNumPartida(int codAux) {
	int codAux2;
	actual = lista->getPrimero();
	Partida* pAux;
	while (actual != NULL) {
		pAux = actual->getInfo();
		codAux2 = pAux->getNumPartida();
		if (codAux == codAux2) {
			return true;
		}
		actual = actual->getSig();
	}
	return false;
}

//-----------------------------------------------------------------------------------------------------------


//----------------------------------------------MENUS-------------------------------------------------------------
void Interfaz::Juego() {
	char entrar;
	do {
		Interfaz::imprimirTablero();
		cout << "	        Partida #" << partida->getNumPartida()<<endl;
		cout << jugador->toString();
		cout << " \n";
		cout << "       +------------------------------------+         " << endl;
		cout << "       |                                    |         " << endl;
		cout << "       | 1. Realizar Jugada                 |         " << endl;
		cout << "       | 2. Cambiar Dificultad              |         " << endl;
		cout << "       | 3. Guardar Partida                 |         " << endl;
		cout << "       | 4. Salir                           |         " << endl;
		cout << "       |                                    |         " << endl;
		cout << "       +------------------------------------+         " << endl;
		cout << " \n";
		cout << "	       Opción: ";
		cin >> entrar;
		switch (entrar) {

		case '1':
			system("cls");
			//Controladora::menuEmpresa();
			Interfaz::jugada();
			system("pause");
			system("cls");
			break;

		case '2':
			system("cls");
			//Controladora::menuEmpleado();
			system("pause");
			system("cls");
			break;

		case '3':
			system("cls");
			Interfaz::guardarPartida();
			system("pause");
			system("cls");
			break;

		case '4':
			//----salir-----
			cout << " \n";
			Interfaz::confirmarSalir();
			cout << "       Cargando menú principal \n";
			for (int i = 0; i < 60; i++) {
				color(255);
				cout << " ";
				Sleep(20);
			}
			cout << " \n";
			system("pause");
			system("cls");
			Controladora::menuprincipal();

			break;
		default:
			cout << " \n";
			cout << "       La opción digitada es incoreccta: " << endl;
			cout << " \n";
			system("pause");
			system("cls");
			break;

		}
	} while (entrar > 4);

}

void Interfaz::confirmarSalir() {
	cout << " \n";
	cout << "	          Si sale en este momento no se guardarán los cambios   " << endl; //imprimir el ombre del jugador
	cout << "	          ¿Desea guardar la partida antes de salir?:    " << endl; //imprimir el ombre del jugador
	char entrar;
	do {
		cout << " \n";
		cout << "	          1. Volver                           " << endl;
		cout << "	          2. Guardar Partida                        " << endl;
		cout << "	          3. Salir sin guardar                                     " << endl;
		cout << " \n";
		cout << "	       Opcion: ";
		cin >> entrar;
		switch (entrar) {

		case '1':
			//--------estudiantes-------
			system("cls");
			Interfaz::Juego();
			system("pause");
			system("cls");
			break;

		case '2':
			//--------carreras---
			system("cls");
			//Controladora::menuEmpleado();
			system("pause");
			system("cls");
			break;

		case '3':
			//--------carreras---
			cout << " \n";
			cout << "       Cargando menú principal \n";
			cout << " \n";
			system("pause");
			system("cls");
			tablero = new Tablero();
			inicializarTablero();
			Controladora::menuprincipal();

			break;
		default:
			cout << " \n";
			cout << "       La opción digitada es incoreccta: " << endl;
			cout << " \n";
			system("pause");
			system("cls");
			break;

		}
	} while (entrar > 3);








}

void Interfaz::crearJugador() {
	string nombre;
	cout << " \n";
	cout << "       +-----------------------------------------------+" << endl;
	cout << "       |                     INICIO                    |" << endl;
	cout << "       +-----------------------------------------------+" << endl;
	cout << "       |                                               |" << endl;
	cout << "       |  Por favor, ingrese los datos del jugador     |" << endl;
	cout << "       |                                               |" << endl;
	cout << "       +-----------------------------------------------+" << endl;
	cout << "       | Nombre del jugador: "; nombre = Interfaz::leerString();
	jugador = new Jugador(nombre);
	cout<<"\n";
	cout << "       +-----------------------------------------------+" << endl;
	//nombre = Interfaz::leerString();
	//jugador = new Jugador(nombre);
	system("cls");
	cout << " \n";
	cout << "       +-----------------------------------------------+" << endl;
	cout << "       |                     INICIO                    |" << endl;
	cout << "       +-----------------------------------------------+" << endl;
	cout << "       |                                               |" << endl;
	cout << "       |  Jugador ingresado, disfrute de la partida!   |" << endl;
	cout << "       |                                               |" << endl;
	cout << "       +-----------------------------------------------+" << endl;
	system("cls");
	Interfaz::elegirEstrategia();
}

void Interfaz::elegirEstrategia() {
	//hacemos un menu para elegir la estrategia y llamamos al de crear partida para que la cree y con esto el juego esta listo;
	Interfaz::crearPartida();
	Interfaz::Juego();
}

void Interfaz::jugada(){
	int i;
	int j;
	int n;
	int m;
	Interfaz::imprimirTablero();
	cout << "Numero de fila que desea mover: "; cin >> i;
	cout << "Numero de columna que desea mover: "; cin >> j;
	cout << "Posición de fila a la que desea mover: "; cin >> n;
	cout << "Posicion de columna a la que desea mover: "; cin >> m;
	i--;
	j--;
	n--;
	m--;
	moverFicha(i, j, n, m);

}

void Interfaz::bienvenido() {
	for (int i = 0; i < 3; i++) { cout << "\n"; }
	for (int i = 0; i < 5; i++) { cout << "\t"; }
	color(11);
	cout << "¡ B i e n v e n i d o s ! \n";
	for (int i = 0; i < 1; i++) { cout << "\n"; }
	for (int i = 0; i < 5; i++) { cout << "\t"; }
	color(14);
	cout << "     Damas Españolas: \n";
	for (int i = 0; i < 2; i++) { cout << "\n"; }
	color(9);
	for (int i = 0; i < 5; i++) { cout << "\t"; }
	cout << " ________      __     __      \n";
	for (int i = 0; i < 5; i++) { cout << "\t"; }
	cout << "|   _____|    |  |   |  |     \n";
	for (int i = 0; i < 5; i++) { cout << "\t"; }
	cout << "|  |   __     |  |___|  |     \n";
	for (int i = 0; i < 5; i++) { cout << "\t"; } 
	cout << "|  |  |  |    |   ___   |     \n";
	for (int i = 0; i < 5; i++) { cout << "\t"; }
	cout << "|  |__|  |    |  |   |  |     \n";
	for (int i = 0; i < 5; i++) { cout << "\t"; }
	cout << "|________|    |__|   |__|     \n";
	color(15);
	cout << "\n\n\n";
	cout << "\t\t\t\t      [Pulse ";
	color(10);
	cout << " ENTER ";
	color(15);
	cout << " para continuar ] ";
	cin.clear();
	cin.get();
	cout << "\n\n\t\t\t\t\t\tCargando...\n" << endl;
	cout << "\t\t\t";
	for (int i = 0; i < 60; i++) {
		color(255);
		cout << " ";
		Sleep(7);
	}
	color(15);
}
//-----------------------------------------------------------------------------------------------------------