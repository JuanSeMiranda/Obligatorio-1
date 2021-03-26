#include "DtBarcoPasajeros.h"

    DtBarcoPasajeros:: DtBarcoPasajeros(){}
    DtBarcoPasajeros:: DtBarcoPasajeros(string nombre, string id, int cantPasajeros, TipoTamanio tamanio):DtBarco(nombre, id){
        this->cantPasajeros = cantPasajeros;
        this->tamanio = tamanio;
    }
    void DtBarcoPasajeros:: setCantPasajeros(){
        this->cantPasajeros = cantPasajeros;
    }
    int DtBarcoPasajeros::getCantPasajeros(){
        return this->cantPasajeros;
    }
    void DtBarcoPasajeros::setTamanio(){
        this->tamanio = tamanio;
    }
    TipoTamanio DtBarcoPasajeros:: getTamanio(){
        return this->tamanio;
    }
    DtBarcoPasajeros::~DtBarcoPasajeros(){}