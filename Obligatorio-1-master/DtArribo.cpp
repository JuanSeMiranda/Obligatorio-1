#include "DtArribo.h"

    DtArribo::DtArribo(){}

    DtArribo::DtArribo(DtFecha fecha, float carga, DtBarco* barco){
        this->fecha = fecha;
        this->carga = carga;
        this->barco = barco;
    }

    DtFecha DtArribo::getFecha(){
        return this->fecha;
    }

    float DtArribo::getCarga(){
        return this->carga;
    }

    DtBarco* DtArribo::getDtBarco(){
        return this->barco;
    }

    DtArribo::~DtArribo(){}

	ostream& operator <<(ostream& salida, DtArribo& dtArribo){
        DtBarcoPesquero* pes;
        DtBarcoPasajeros* pas;
		salida << "Fecha: " << dtArribo.fecha << endl;
        cout << "Carga: " << dtArribo.carga << endl;
        pes = dynamic_cast<DtBarcoPesquero*>(dtArribo.getDtBarco());
        pas = dynamic_cast<DtBarcoPasajeros*>(dtArribo.getDtBarco());

        if(pas != NULL)
            cout << *pas << endl;
        else
            cout << *pes << endl;

		return salida;
	}