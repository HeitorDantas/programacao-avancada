#include "matriz.h"
#include <iostream>

using namespace std;

Matriz::Matriz(int _nl, int _nc) : ncol(_nc), nlin(_nl){
    cout << "build'in" <<endl;
    x = nullptr;

    if(_nl <=0 || _nc <= 0){
        nlin = ncol = 0;
        return;
    }

    x = new float*[_nl];
    if(x == nullptr){
        nlin = ncol =0;
        return;
    }
    *x = new float[_nl * _nc]();
    if(*x == nullptr){
        nlin = ncol = 0;
        delete[] x;
        return;
    }

    for(int i=1;i<_nl;i++){
        x[i] = x[i-1] + _nc;
    }

}

Matriz::~Matriz(){
    cout <<"destroyed" << endl;
    if(x != nullptr){
        delete[] *x;
        delete[] x;
    }

}

Matriz::Matriz(Matriz&){
    nlin = m.nlin;
    ncol = m.ncol;
    if(nlin ==0 || ncol == 0){
        x = nullptr;
        return;
    }
    x = new float*[_nl];
    *x = new float[_nl * _nc]();

    for(int i=1;i<_nl;i++){
        x[i] = x[i-1] + _nc;
    }
    memcpy(x[0],m.x[0],nlin*ncol*sizeof(float));
}

int Matriz::getNC(){
    return ncol;
}

int Matriz::getNL(){
    return nlin;
}

void Matriz::print(){
    //cout<<"[";
    for(int i=0;i<nlin;i++){
        cout << "[";
        for(int j=0;j<ncol;j++){
            cout<< x[i][j]<<" ";
        }
        cout << "\b]" << endl;
    }
    cout<<"\n";
}

float& Matriz::operator()(int i, int j){
    return x[i][j];
}

Matriz& Matriz::operator=(Matriz &m){
    if(&m == this)
        return *this;
    if(m.nlin != nlin || m.ncol != ncol){
        if(nlin != 0 && ncol != 0){
            delete[] *x;
            delete[] x;
            x = nullptr;
            nlin = ncol = 0;
        }

    }
    if(x == nullptr){
        if(m.nlin == 0 || m.ncol ==0){
            return *this;
        }
        nlin = m.nlin;
        ncol = m.ncol;
        x = new float*[nlin];
        *x = new float[nlin * ncol];
        for(int i= 1;i<nlin;i++){
            x[i] = x[i-1] + ncol;
        }
    }

    //for(int i = 0;i<ncol*nlin;i++){
      //  x[0][i] = m.x[0][i];
    //}
    memcpy(x[0],m.x[0],nlin*ncol*sizeof(float));
    return *this;
}



Matriz::Matriz operator+(Matriz &m){
    if(nlin != m.nlin || ncol != m.ncol){

    }

}
