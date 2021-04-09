#include "DtBarcoPasajeros.h"

    DtBarcoPasajeros:: DtBarcoPasajeros(){}
    
    DtBarcoPasajeros:: DtBarcoPasajeros(string nombre, string id, int cantPasajeros, TipoTamanio tamanio):DtBarco(nombre, id){
        this->cantPasajeros = cantPasajeros;
        this->tamanio = tamanio;
    }

    int DtBarcoPasajeros::getCantPasajeros(){
        return this->cantPasajeros;
    }

    TipoTamanio DtBarcoPasajeros:: getTamanio(){
        return this->tamanio;
    }

    DtBarcoPasajeros::~DtBarcoPasajeros(){}

    ostream& operator <<(ostream& salida, DtBarcoPasajeros& pasajero){
        string tipo[4]={"BOTE","CRUCERO","GALEON","TRASATLANTICO"};
        cout << (DtBarco) pasajero << "Cantidad de pasajeros: " << pasajero.cantPasajeros << endl;
        cout << "Tipo de Barco: " << tipo[pasajero.tamanio] << endl;
        return salida;
    }