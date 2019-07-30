#include "Poligono.h"
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;


Poligono::Poligono(){

	//aloca 100 ponto para podemos usar
	N=0;
	vertices = new Ponto[100];


}
Poligono::~Poligono(){
	cout << "\nobject destroyed\n" ;
	delete[] vertices;
}
void Poligono::inserir(Ponto v){

	vertices[N++] = v;

}
int Poligono::getNumVertices(){
	//retorna o numero atual de vertices do poligono
	return N;
}
float Poligono::area(){
	//area do poligono
	float area=0;
	for(int i=0;i<N-1;i++){
		area += vertices[i].x * vertices[i+1].y;
		area += (vertices[i+1].x * vertices[i].y)*(-1);
	}
	area += vertices[N-1].getX() * vertices[0].getY();
	area += (vertices[0].getX() * vertices[N-1].getY())*(-1);
	area = abs(area/2.0);
	return area;
}
void Poligono::translada(float a,float b){
	//adiciona a cada Ponto do array de vertices a em x e b em y
	int i;
	for(i=0;i<N;i++){
		vertices[i].translada(a, b);
	}
}
void Poligono::rotacionar(double theta,Ponto p0){
	//rotaciona de theta graus o poligono, tendo o ponto p0 como eixo
	Ponto aux;
	float tx;
	for(int i=0;i<N;i++){
		aux = vertices[i].sub(p0);
		
		
		tx = aux.x;
		aux.setX(tx*cos(theta)  - aux.y*sin(theta));
		aux.setY(tx*sin(theta)  + aux.y*cos(theta));
		
		aux = aux.add(p0);
		
		this->vertices[i].setX(aux.x);
		this->vertices[i].setY(aux.y);
	}
}
void Poligono::print(){
	//imprime o poligono com formatacao definida
	int i;
	for(i = 0;i<N-1;i++){
		this->vertices[i].imprime();
		cout << "->";
	}
	this->vertices[i].imprime();
	cout << "->";
	this->vertices[0].imprime(); 
	cout << "\n";
}
