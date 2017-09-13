#ifndef MATRIZ_H
#define MATRIZ_H


class Matriz{

private:
    float **x;// para guardar a matriz
    int nl, nc;// numero de linhas e numero de colunas

public:

    Matriz(int _nl=0, int _nc=0);
    ~Matriz();
    int getNC();
    int getNL();
    void print();
    float &operator()(int i, int j);
};

#endif // MATRIZ_H
