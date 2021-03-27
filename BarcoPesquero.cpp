#include "BarcoPesquero.h"

    BarcoPesquero::BarcoPesquero(){}

    BarcoPesquero::BarcoPesquero(string nombre, string id, int capacidad, int carga): Barco(nombre, id){
        this->capacidad = capacidad;
        this->carga = carga;
    }

    void BarcoPesquero::setCapacidad(int capacidad){
        this->capacidad = capacidad;
    }

    int BarcoPesquero::getCapacidad(){
        return this->capacidad;
    }

    void BarcoPesquero::setCarga(int carga){
        this->carga = carga;
    }

    int BarcoPesquero::getCarga(){
        return this->carga;
    }

    BarcoPesquero::~BarcoPesquero(){}

    void BarcoPesquero::arribar(float cargaDespacho){
        this->carga = (int) carga - cargaDespacho;
    }
