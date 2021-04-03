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

    void DtArribo::setDtBarco(DtBarco* barco){
        this->barco = barco;
    }

    DtBarco* DtArribo::getDtBarco(){
        return this->barco;
    }

    DtArribo::~DtArribo(){}

	ostream& operator <<(ostream& salida, DtArribo& dtArribo){
		salida << "Fecha: " << dtArribo.fecha << endl;
        cout << "Carga: " << dtArribo.carga << endl;
        cout << *(dtArribo.barco) << endl;
		return salida;
	}