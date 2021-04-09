#ifndef CLASEB
#define CLASEB
#include <iostream>

using namespace std;

#include "C.h"

class C;
class A;

class B{
    private:
        int b;
        C* miC;
        A* miA;
    public:
        B();
        B(int b);
        void setB(int b, A* miA, C* miC);
        int getB();
        void setC(C* miC);
        C* getC();
        void setA(A* miA);
        A* getA();
        void imprimir();
        ~B();
};


#endif // B