#ifndef CLASEC
#define CLASEC
#include <iostream>

using namespace std;

#include "A.h"

class A;
class B;

class C{
    private:
        int c;
        A* miA;
        B* miB;
    public:
        C();
        C(int c);
        void setC(int c, A* miA, B* miB);
        int getC();
        void setA(A* miA);
        A* getA();
        void setB(B* miB);
        B* getB();
        void imprimir();
        ~C();
};


#endif // C