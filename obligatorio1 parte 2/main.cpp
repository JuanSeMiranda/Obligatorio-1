#include "A.h"
#include "B.h"
#include "C.h"

int main(){
    //clases base
    A* tipoA = new A(1);
    B* tipoB = new B(2);
    C* tipoC = new C(3);

    //imprime las clases base
    tipoA->imprimir();
    tipoB->imprimir();
    tipoC->imprimir();

    //imprime las clases B y C a partir de A
    tipoA->setB(tipoB);
    (tipoA->getB())->imprimir();

    tipoA->setC(tipoC);
    (tipoA->getC())->imprimir();

    //imprime las clases C y A a partir de B
    tipoB->setC(tipoC);
    (tipoB->getC())->imprimir();

    tipoB->setA(tipoA);
    (tipoB->getA())->imprimir();

    //imprime las clases B y A a partir de C
    tipoC->setB(tipoB);
    (tipoC->getB())->imprimir();

    tipoC->setA(tipoA);
    (tipoC->getA())->imprimir();

    //se libera la memoria
    delete tipoA;
    delete tipoB;
    delete tipoC;

    return 0;
}