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
