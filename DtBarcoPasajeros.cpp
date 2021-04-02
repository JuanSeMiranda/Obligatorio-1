#include "DtBarcoPasajeros.h"

    DtBarcoPasajeros:: DtBarcoPasajeros(){}
    DtBarcoPasajeros:: DtBarcoPasajeros(string nombre, string id, int cantPasajeros, TipoTamanio tamanio):DtBarco(nombre, id){
        this->cantPasajeros = cantPasajeros;
        this->tamanio = tamanio;
    }
    void DtBarcoPasajeros:: setCantPasajeros(int cantPasajeros){
        this->cantPasajeros = cantPasajeros;
    }
    int DtBarcoPasajeros::getCantPasajeros(){
        return this->cantPasajeros;
    }
    void DtBarcoPasajeros::setTamanio(TipoTamanio tamanio){
        this->tamanio = tamanio;
    }
    TipoTamanio DtBarcoPasajeros:: getTamanio(){
        return this->tamanio;
    }
    DtBarcoPasajeros::~DtBarcoPasajeros(){}

    ostream& operator << (ostream& salida, DtBarcoPasajeros*& pasajero){
        string tipo[4]={"BOTE","CRUCERO","GALEON","TRASATLANTICO"};
        cout << (DtBarco*) pasajero << " Cantidad de pasajeros: " << pasajero->cantPasajeros << "Tipo de Barco: " << tipo[pasajero->tamanio] << endl;
        return salida;
    }