#ifndef MATRIZ_H
#define MATRIZ_H


class Matriz{

private:
    float **x;// para guardar a matriz
    int nlin;
    int ncol;

public:

    Matriz(int _nl=0, int _nc=0);
    ~Matriz();
    Matriz(Matriz&);
    int getNC();
    int getNL();
    void print();
    float &operator()(int i, int j);
    Matriz& operator=(Matriz& m);
    Matriz operator+(Matriz &m);

};

#endif // MATRIZ_H
