#ifndef PUERTO
#define PUERTO
#include <iostream>
#include <string>
#include "DtFecha.h"

using namespace std;

class Puerto{
private:
	string id;
	string nombre;
	DtFecha fechaCreacion;
	//pseudoatributos - A VERIFICAR
	int cantArribos;
public:
	Puerto();
	Puerto(string id, string nombre, DtFecha fechaCreacion);
	void setId(string id);
	string getId();
	void setNombre(string nombre);
	string getNombre();
	void setFechaCreacion(DtFecha fechaCreacion);
	DtFecha getFechaCreacion();
	~Puerto();
	//
	int getCantArribos();
};

#endif
