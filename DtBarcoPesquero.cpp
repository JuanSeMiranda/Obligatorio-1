#include "DtBarcoPesquero.h"

    DtBarcoPesquero::DtBarcoPesquero(){}
    DtBarcoPesquero::DtBarcoPesquero(string nombre, string id,int capacidad, int carga): DtBarco(nombre, id){
        this->capacidad = capacidad;
        this->carga = carga;
    }
    void DtBarcoPesquero:: setCapacidad(int capacidad){
        this->capacidad = capacidad;
    }
    int DtBarcoPesquero::getCapacidad(){
        return this->capacidad;
    }
    void DtBarcoPesquero::setCarga(int carga){
        this->carga = carga;
    }
    int DtBarcoPesquero::getCarga(){
        return this->carga;
    }
    DtBarcoPesquero::~DtBarcoPesquero(){}