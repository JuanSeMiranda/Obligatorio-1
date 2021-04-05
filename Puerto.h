#ifndef PUERTO
#define PUERTO
#define CANT_ARRIBOS 30

#include <iostream>
#include <string>
#include "DtFecha.h"
#include "Arribo.h"
#include "DtArribo.h"

using namespace std;

class Puerto{
private:
	string id;
	string nombre;
	DtFecha fechaCreacion;
	//pseudoatributos - A VERIFICAR
	Arribo* arribos[CANT_ARRIBOS];
	int cantArribos;// osea el tope
public:
	Puerto();
	Puerto(string id, string nombre, DtFecha fechaCreacion);
	void setId(string id);
	string getId();
	void setNombre(string nombre);
	string getNombre();
	void setFechaCreacion(DtFecha fechaCreacion);
	DtFecha getFechaCreacion();
	void agregarArribo(Arribo* arribo);
	~Puerto();
	//
	int getCantArribos();
	DtArribo** getDtArribos();
	void eliminarArribos(DtFecha fecha);
};

#endif
