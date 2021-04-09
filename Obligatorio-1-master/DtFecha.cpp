#include "DtFecha.h"

    DtFecha::DtFecha(){}

    DtFecha::DtFecha(int dia, int mes, int anio){
        if(dia > 31 || dia < 1 || mes < 1 || mes > 12 || anio < 1900)
            throw invalid_argument("Fecha no valida!\n");
        else{
            this->dia = dia;
            this->mes = mes;
            this->anio = anio;
        }
    }

    int DtFecha::getDia(){
        return this->dia;
    }

    int DtFecha::getMes(){
        return this->mes;
    }

    int DtFecha::getAnio(){
        return this->anio;
    }

    DtFecha::~DtFecha(){}

    ostream& operator <<(ostream& salida, DtFecha& fecha){
        cout << fecha.dia << "-" << fecha.mes << "-" << fecha.anio << endl;
        return salida;
    }

    bool operator ==(const DtFecha& fecha1, const DtFecha& fecha2){
        return fecha1.dia == fecha2.dia && fecha1.mes == fecha2.mes && fecha1.anio == fecha2.anio; 
    }