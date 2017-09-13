#include "Ponto.h"
#include <iostream>
#include <cmath>

Ponto::Ponto(){
	this->x = 0;
	this->y = 0;
}

Ponto::Ponto(float x, float y){
	//default constructor
	this->x = x;
	this->y = y;
}


void Ponto::setX(float _x){
		x = _x;
	}
void Ponto::setY(float _y){
		y = _y;
	}	
void Ponto::setXY(float _x,float _y){
		x = _x;
		y = _y;
	}			
float Ponto::getX(){
		return x;
	}
float Ponto::getY(){	
		return y;
	}
Ponto Ponto::add(Ponto p1){
	Ponto p3;
	//p3.setXY(x+p1.x,y+p1.y);
	p3.x = x + p1.x;
	p3.y = y + p1.y;
	return p3;
}
Ponto Ponto::sub(Ponto p1){
	Ponto p3;
	p3.setXY(x-p1.x,y-p1.y);
	return p3;
}
float Ponto::norma(){
	return sqrt(x*x + y*y);
}
void Ponto::translada(float a,float b){
	x +=a;
	y +=b;
}
void Ponto::imprime(){
	std::cout << "(" << x << ", " << y << ")";
}