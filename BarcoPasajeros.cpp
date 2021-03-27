#include "BarcoPasajeros.h"

    BarcoPasajeros::BarcoPasajeros(){}

    BarcoPasajeros::BarcoPasajeros(string nombre, string id, int cantPasajeros, TipoTamanio tamanio): Barco(nombre, id){
        this->cantPasajeros = cantPasajeros;
        this->tamanio = tamanio;
    }

    void BarcoPasajeros::setCantPasajeros(int cantPasajeros){
        this->cantPasajeros = cantPasajeros;
    }

    int BarcoPasajeros::getCantPasajeros(){
        return this->cantPasajeros;
    }

    void BarcoPasajeros::setTamanio(TipoTamanio tamanio){
        this->tamanio = tamanio;
    }

    TipoTamanio BarcoPasajeros::getTamanio(){
        return this->tamanio;
    }

    BarcoPasajeros::~BarcoPasajeros(){}

    void BarcoPasajeros::arribar(float cargaDespacho){
        cout << "Los barcos de pasajeros no tienen carga" << endl;
    }
