#ifndef ARRIBO
#define ARRIBO
#include <iostream>
#include <string>
#include "DtFecha.h"

using namespace std;

class Arribo{
private:
    DtFecha arribo;
    float carga;
public:
	Arribo();
	Arribo(DtFecha arribo, float carga);
	void setArribo(DtFecha arribo);
	DtFecha getArribo();
	void setCarga(float carga);
	float setCarga();
	~Arribo();
};

#endif // BARCO
