#include "C.h"

C::C(){}
C::C(int c){
    this->c = c;
}

void C::setC(int c, A* miA, B* miB){
    this->c = c;
    this->miA = miA;
    this->miB = miB;
}

int C::getC(){
    return this->c;
}

void C::imprimir(){
    cout << "Clase C" << endl;
    cout << "Su atributo es: " << this->c << endl;
}

void C::setB(B* miB){
    this->miB = miB;
}

B* C::getB(){
    return this->miB;
}

void C::setA(A* miA){
    this->miA = miA;
}

A* C::getA(){
    return this->miA;
}

C::~C(){}