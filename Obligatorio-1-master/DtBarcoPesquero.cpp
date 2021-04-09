#include "DtBarcoPesquero.h"

    DtBarcoPesquero::DtBarcoPesquero(){}
    
    DtBarcoPesquero::DtBarcoPesquero(string nombre, string id,int capacidad, int carga): DtBarco(nombre, id){
        this->capacidad = capacidad;
        this->carga = carga;
    }

    int DtBarcoPesquero::getCapacidad(){
        return this->capacidad;
    }

    int DtBarcoPesquero::getCarga(){
        return this->carga;
    }

    DtBarcoPesquero::~DtBarcoPesquero(){}

    ostream& operator <<(ostream& salida, DtBarcoPesquero& pesquero){
        cout << (DtBarco) pesquero << "Capacidad del barco: " << pesquero.capacidad << endl;
        cout << "Carga del barco: " << pesquero.carga << endl;
        return salida;
    }