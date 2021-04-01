#include "BarcoPesquero.h"

    BarcoPesquero::BarcoPesquero(){}

    BarcoPesquero::BarcoPesquero(string nombre, string id, int capacidad, int carga): Barco(nombre, id){
        if(carga > capacidad)
            throw invalid_argument("La carga es mayor a la capacidad del barco.\n");
        else{
            this->capacidad = capacidad;
            this->carga = carga;
        }
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
        if((cargaDespacho < 0) && ((-cargaDespacho + carga) > capacidad))
            throw invalid_argument("La carga excede la capacidad del barco.\n");
        else if((cargaDespacho > 0) && (carga < cargaDespacho))
            throw invalid_argument("El barco no cuenta con suficiente carga para hacer el arribo.\n");
        else
            this->carga = (int) (carga - cargaDespacho);
    }

    DtBarco* BarcoPesquero::getDtBarco(){
        DtBarcoPesquero* dtbPesquero = new DtBarcoPesquero(this->getNombre(),
                                                           this->getId(),
                                                           this->capacidad,
                                                           this->carga);
        return dtbPesquero;
    }