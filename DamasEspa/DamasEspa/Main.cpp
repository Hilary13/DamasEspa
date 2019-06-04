#include "Controladora.h"

int main() {
	setlocale(LC_CTYPE, "Spanish");
	Controladora* c = new Controladora();
	c->inicio();
	system("pause");
	return 0;
}