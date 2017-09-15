#include <iostream>
#include "matriz.h"


using namespace std;

int main(){
    Matriz m(3,3), n(3,3), o, p(4,5);
    /*o = m;
    o = m + n;
    m = p;

    cout << << endl;
    */
    m(1,2) = 4;


    o = p = m;
    m(0,0) = 5;
    p(0,0) = 52;
    o.print();
    m.print();
    p.print();
    return 0;
}
