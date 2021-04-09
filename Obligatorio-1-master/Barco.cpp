#include "Barco.h"

    Barco::Barco(){}

    Barco::Barco(string nombre, string id){
        this->nombre = nombre;
        this->id = id;
    }

    void Barco::setNombre(string nombre){
        this->nombre = nombre;
    }

    string Barco::getNombre(){
        return this->nombre;
    }

    void Barco::setId(string id){
        this->id = id;
    }

    string Barco::getId(){
        return this->id;
    }

    Barco::~Barco(){}
