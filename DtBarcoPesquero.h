#ifndef DTBARCOPESQUERO
#define DTBARCOPESQUERO
#include "DtBarco.h"

class DtBarcoPesquero : public DtBarco{

private:
    int capacidad;
    int carga;
public:
    DtBarcoPesquero();
    DtBarcoPesquero(string nombre, string id, int capacidad, int carga);
    void setCapacidad(int capacidad);
    int getCapacidad();
    void setCarga(int carga);
    int getCarga();
    ~DtBarcoPesquero();
};

#endif
