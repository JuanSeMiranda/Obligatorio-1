#include "A.h"

A::A(){}
A::A(int a){
    this->a = a;
}

void A::setA(int a, B* miB, C* miC){
    this->a = a;
    this->miB = miB;
    this->miC = miC;
}

int A::getA(){
    return this->a;
}

void A::imprimir(){
    cout << "Clase A" << endl;
    cout << "Su atributo es: " << this->a << endl;
}

void A::setB(B* miB){
    this->miB = miB;
}

B* A::getB(){
    return this->miB;
}

void A::setC(C* miC){
    this->miC = miC;
}

C* A::getC(){
    return this->miC;
}

A::~A(){}