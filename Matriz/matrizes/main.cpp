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
    m.print();

    return 0;


}
