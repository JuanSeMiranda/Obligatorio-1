//#include <string>
#include "DtBarco.h"


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

    ostream& operator << (ostream& salida, const DtBarco*& barco){
        cout << "Nombre del Barco: " << barco->nombre << endl;
        cout << "Id del Barco: " << barco->id << endl;
        return salida;
    }