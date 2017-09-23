#include <iostream>

#include "Poligono.h"
#include "Retangulo.h"
#include <stdlib.h>

using namespace std;
#define PI  3.1415926535897932384626433832795028841971693993751058209



int main(){
	
	Retangulo ret = Retangulo(0,0,4,3);
	Ponto CM = ret.getCM();
	ret.print();
	cout << "Area:" <<ret.area() << endl;
	ret.translada(-3,4);
	
	
	ret.print();
	cout << "Area:" <<ret.area() << endl;
	ret.rotacionar(PI/6,CM);
	ret.print();
	cout << "Area:" <<ret.area() << endl;

cout << "num de vertices ret:" <<ret.getNumVertices() << endl;

	return 0;
}