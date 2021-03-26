#include "DtPuerto.h"

    DtPuerto::DtPuerto(){}

    DtPuerto::DtPuerto(string id, string nombre, DtFecha fechaCreacion, int cantArribos){
        this->id = id;
        this->nombre = nombre;
        this->fechaCreacion = fechaCreacion;
        this->cantArribos = cantArribos;
    }

    void DtPuerto::setId(string id){
        this->id = id;
    }

    string DtPuerto::getId(){
        return this->id;
    }

    void DtPuerto::setNombre(string nombre){
        this->nombre = nombre;
    }

    string DtPuerto::getNombre(){
        return this->nombre;
    }

    void DtPuerto::setFechaCreacion(DtFecha fechaCreacion){
        this->fechaCreacion = fechaCreacion;
    }

    DtFecha DtPuerto::getFechaCreacion(){
        return this->fechaCreacion;
    }

    void DtPuerto::setCantArribos(int cantArribos){
        this->cantArribos = cantArribos;
    }

    int DtPuerto::getCantArribos(){
        return this->cantArribos;
    }

    DtPuerto::~DtPuerto(){}
