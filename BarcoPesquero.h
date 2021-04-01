#ifndef BARCOPESQUERO
#define BARCOPESQUERO
#include "Barco.h"
#include "DtBarcoPesquero.h"

class BarcoPesquero: public Barco{
private:
    int capacidad;
    int carga;
public:
    BarcoPesquero();
    BarcoPesquero(string nombre, string id, int capacidad, int carga);
    void setCapacidad(int capacidad);
    int getCapacidad();
    void setCarga(int carga);
    int getCarga();
    ~BarcoPesquero();

    void arribar(float cargaDespacho);
    DtBarco* getDtBarco();
};

#endif
