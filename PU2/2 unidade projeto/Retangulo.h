#ifndef RETANGULO_H
#define RETANGULO_H

#include "Poligono.h"

class Retangulo: public Poligono{
private:
	float altura,largura,x,y;
	Ponto CM;

public:
	
	Retangulo(float x, float y, float largura, float altura);
	void translada(float a,float b);
	Ponto getCM();

};



#endif