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
    DtFecha arribo;
    float carga;
	Barco* barco;
public:
	Arribo();
	Arribo(DtFecha arribo, float carga, Barco* barco);
	void setArribo(DtFecha arribo);
	DtFecha getArribo();
	void setCarga(float carga);
	float getCarga();
	void setBarco(Barco* Barco);
	Barco* getBarco();
	DtBarco* getDtBarco();
	~Arribo();

	//friend ostream& operator << (ostream&, DtArribo&);
};

#endif // BARCO
