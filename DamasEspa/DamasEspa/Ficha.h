#ifndef FICHA_H
#define FICHA_H

class Ficha
{
private:

	char caracter;

public:
	Ficha();
	Ficha(char);
	char getCaracter();
	void setCaracter(char);

	~Ficha();
};
#endif 
