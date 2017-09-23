#include "Retangulo.h"




Retangulo::Retangulo(float x, float y, float largura, float altura){
	Ponto aux;
	this->altura = altura;
	this->largura = largura;
	this->x = x;
	this->y = y;

	this->CM.setX(x + largura/2);
	this->CM.setY(y - altura/2);


	aux = Ponto(x,y);
	this->inserir(aux);
	aux.translada(largura,0);
	this->inserir(aux);
	aux.translada(0,-altura);
	this->inserir(aux);
	aux.translada(-largura,0);
	this->inserir(aux);

}

void Retangulo::translada(float a,float b){
	//adiciona a cada Ponto do array de vertices a em x e b em y
	int i;
	for(i=0;i<N;i++){
		vertices[i].translada(a, b);
	}
	this->CM.translada(a,b);
}

Ponto Retangulo::getCM(){
	
	return CM;
}