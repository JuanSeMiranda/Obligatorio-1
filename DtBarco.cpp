#include "DtBarco.h"
#include "DtBarcoPasajeros.h"
#include "DtBarcoPesquero.h"


    DtBarco::DtBarco(){}
    DtBarco:: DtBarco(string nombre, string id){
        this->nombre = nombre;
        this->id = id;
    }
    void DtBarco:: setNombre(string nombre){
        this->nombre =  nombre;
    }
    string  DtBarco::getNombre(){
        return this->nombre;
    }
    void DtBarco:: setId(string id){
        this->id = id;
    }
    string DtBarco:: getId(){
        return this->id;
    }
    DtBarco::~DtBarco(){}

    ostream& operator <<(ostream& salida, const DtBarco& barco){
        cout << "Id del Barco: " << barco.id << endl;
        cout << "Nombre del Barco: " << barco.nombre << endl;
        return salida;
    }