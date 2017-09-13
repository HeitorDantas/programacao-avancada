#include "matriz.h"
#include <iostream>

using namespace std;

Matriz::Matriz(int _nl, int _nc) : nc(_nc), nl(_nl){
    cout << "build'in" <<endl;
    x = nullptr;

    if(_nl <=0 || _nc <= 0){
        nl = nc = 0;
        return;
    }

    x = new float*[_nl];
    if(x = nullptr){
        nl = nc =0;
        return;
    }
    *x = new float[_nl * _nc]();
    if(*x == nullptr){
        nl = nc = 0;
        delete[] x;
        return;
    }

    for(int i=1;i<_nl;i++){
        x[i] = x[i-1] + _nc;
    }

}

Matriz::~Matriz(){
    cout <<"destroy'in" << endl;
    if(x != nullptr){
        delete[] *x;
        delete[] x;
    }

}

int Matriz::getNC(){
    return nc;
}

int Matriz::getNL(){
    return nl;
}

void Matriz::print(){
    //cout<<"[";
    for(int i=0;i<nl;i++){
        cout << "[";
        for(int j=0;j<nc;j++){
            cout<< x[i][j]<<" ";
        }
        cout << "\b]" << endl;
    }
    //cout<<" ]\n";
}

float& Matriz::operator()(int i, int j){
    return x[i][j];
}
