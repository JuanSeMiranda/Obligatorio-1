#include "DtPuerto.h"

    DtPuerto::DtPuerto(){}

    DtPuerto::DtPuerto(string id, string nombre, DtFecha fechaCreacion, int cantArribos){
        this->id = id;
        this->nombre = nombre;
        this->fechaCreacion = fechaCreacion;
        this->cantArribos = cantArribos;
    }

    string DtPuerto::getId(){
        return this->id;
    }

    string DtPuerto::getNombre(){
        return this->nombre;
    }

    DtFecha DtPuerto::getFechaCreacion(){
        return this->fechaCreacion;
    }

    int DtPuerto::getCantArribos(){
        return this->cantArribos;
    }

    DtPuerto::~DtPuerto(){}
