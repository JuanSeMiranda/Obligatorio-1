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

    void DtFecha::setDia(int dia){
        this->dia = dia;
    }

    int DtFecha::getDia(){
        return this->dia;
    }

    void DtFecha::setMes(int mes){
        this->mes = mes;
    }
    int DtFecha::getMes(){
        return this->mes;
    }

    void DtFecha::setAnio(int anio){
        this->anio = anio;
    }

    int DtFecha::getAnio(){
        return this->anio;
    }

    DtFecha::~DtFecha(){}

    ostream& operator <<(ostream& salida, DtFecha& fecha){
        cout << fecha.dia << "-" << fecha.mes << "-" << fecha.anio << endl;
        return salida;
    }