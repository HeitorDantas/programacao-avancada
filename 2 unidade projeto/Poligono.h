#ifndef POLIGONO_H
#define POLIGONO_H

#include "Ponto.h"


class Poligono{
protected:
	Ponto *vertices;
	int N;
public:
	Poligono();
	~Poligono();
	void inserir(Ponto v);
	int getNumVertices();
	float area();
	void translada(float a,float b);
	void rotacionar(double tetha,Ponto p0);
	void print();
};

#endif