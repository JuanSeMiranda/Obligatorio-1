#include "Arribo.h"

	Arribo::Arribo(){}

	Arribo::Arribo(DtFecha arribo, float carga){
	    this->arribo = arribo;
	    this->carga = carga;
	}

	void Arribo::setArribo(DtFecha arribo){
	    this->arribo = arribo;
	}

	DtFecha Arribo::getArribo(){
	    return this->arribo;
	}

	void Arribo::setCarga(float carga){
	    this->carga = carga;
	}

	float Arribo::getCarga(){
	    return this->carga;
	}

	void Arribo::setBarco(Barco* Barco){
		this->barco = barco;
	}

	Barco* Arribo::getBarco(){
		return this->barco;
	}

	DtBarco* Arribo::getDtBarco(){
 		return this->barco->getDtBarco();
	}

	Arribo::~Arribo(){}
