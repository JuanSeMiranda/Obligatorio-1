#include "Puerto.h"

	Puerto::Puerto(){}

	Puerto::Puerto(string id, string nombre, DtFecha fechaCreacion){
	    this->id = id;
	    this->nombre = nombre;
	    this->fechaCreacion = fechaCreacion;
	}

	void Puerto::setId(string id){
	    this->id = id;
	}

	string Puerto::getId(){
	    return this->id;
	}

	void Puerto::setNombre(string nombre){
	    this->nombre = nombre;
	}

	string Puerto::getNombre(){
	    return this->nombre;
	}

	void Puerto::setFechaCreacion(DtFecha fechaCreacion){
	    this->fechaCreacion = fechaCreacion;
	}

	DtFecha Puerto::getFechaCreacion(){
	    return this->fechaCreacion;
	}

	Puerto::~Puerto(){}

	void Puerto::agregarArribo(Arribo* arribo){
		this->arribos[this->cantArribos]= arribo;
		this->cantArribos ++;
	}

	int Puerto::getCantArribos(){
        return this->cantArribos;
    }

	DtArribo** Puerto::getDtArribos(){
		DtArribo** dtArribos= new DtArribo*[this->cantArribos];
  		for(int i = 0; i < this->cantArribos; i++){
    		DtArribo* dtArribo = new DtArribo(this->arribos[i]->getFecha(),
            		                          this->arribos[i]->getCarga(),
                    		                  this->arribos[i]->getDtBarco());
    		dtArribos[i] = dtArribo;
  		}

  		return dtArribos;
	}

	void Puerto::eliminarArribos(DtFecha fecha){
  		for(int i = 0; i < this->cantArribos; i++){
    		while(i < this->cantArribos && this->arribos[i]->getFecha() == fecha){
      			this->arribos[i] = this->arribos[this->cantArribos-1];
      			this->arribos[this->cantArribos-1]=NULL;
      			delete this->arribos[this->cantArribos-1];
      			this->cantArribos--;
    		}
  		}
	}