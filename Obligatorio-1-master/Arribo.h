#ifndef ARRIBO
#define ARRIBO
#include <iostream>
#include <string>
#include "DtFecha.h"
#include "Barco.h"
#include "DtArribo.h"

using namespace std;

class Arribo{
private:
    DtFecha fecha;
    float carga;
	Barco* barco;
public:
	Arribo();
	Arribo(DtFecha arribo, float carga, Barco* barco);
	void setFecha(DtFecha fecha);
	DtFecha getFecha();
	void setCarga(float carga);
	float getCarga();
	void setBarco(Barco* Barco);
	Barco* getBarco();
	DtBarco* getDtBarco();
	~Arribo();
};

#endif // BARCO
