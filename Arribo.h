#ifndef ARRIBO
#define ARRIBO
#include <iostream>
#include <string>
#include "DtFecha.h"
#include "Barco.h"

using namespace std;

class Arribo{
private:
    DtFecha arribo;
    float carga;
	Barco* barco;
public:
	Arribo();
	Arribo(DtFecha arribo, float carga);
	void setArribo(DtFecha arribo);
	DtFecha getArribo();
	void setCarga(float carga);
	float setCarga();
	void setBarco(Barco* Barco);
	Barco* getBarco();
	~Arribo();
};

#endif // BARCO
