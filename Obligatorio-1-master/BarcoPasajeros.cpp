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
        if(cargaDespacho < 0 || cargaDespacho > 0)
            throw invalid_argument("Los barcos de pasajeros no tienen carga.\n");
    }

    DtBarco* BarcoPasajeros::getDtBarco(){
        DtBarcoPasajeros* dtbPasajeros = new DtBarcoPasajeros(this->getNombre(),
                                                              this->getId(),
                                                              this->cantPasajeros,
                                                              this->tamanio);
        return dtbPasajeros;
    }