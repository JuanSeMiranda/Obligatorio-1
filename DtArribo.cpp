#include "DtArribo.h"

    DtArribo::DtArribo(){}

    DtArribo::DtArribo(DtFecha fecha, float carga, DtBarco* barco){
        this->fecha = fecha;
        this->carga = carga;
        this->barco = barco;
    }

    void DtArribo::setFecha(DtFecha fecha){
        this->fecha = fecha;
    }

    DtFecha DtArribo::getFecha(){
        return this->fecha;
    }

    void DtArribo::setCarga(float carga){
        this->carga = carga;
    }

    float DtArribo::getCarga(){
        return this->carga;
    }

    void DtArribo::setBarco(DtBarco* barco){
        this->barco = barco;
    }

    DtBarco* DtArribo::getBarco(){
        return this->barco;
    }

    DtArribo::~DtArribo(){}
