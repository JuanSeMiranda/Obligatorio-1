#ifndef CLASEA
#define CLASEA
#include <iostream>

using namespace std;

#include "B.h"

class B;
class C;

class A{
    private:
        int a;
        B* miB;
        C* miC;
    public:
        A();
        A(int a);
        void setA(int a, B* miB, C* miC);
        int getA();
        void setB(B* miB);
        B* getB();
        void setC(C* miC);
        C* getC();
        void imprimir();
        ~A();
};


#endif // A