#include "B.h"

B::B(){}
B::B(int b){
    this->b = b;
}

void B::setB(int b, A* miA, C* miC){
    this->b = b;
    this->miA = miA;
    this->miC = miC;
}

int B::getB(){
    return this->b;
}

void B::imprimir(){
    cout << "Clase B" << endl;
    cout << "Su atributo es: " << this->b << endl;
}

void B::setC(C* miC){
    this->miC = miC;
}

C* B::getC(){
    return this->miC;
}

void B::setA(A* miA){
    this->miA = miA;
}

A* B::getA(){
    return this->miA;
}

B::~B(){}