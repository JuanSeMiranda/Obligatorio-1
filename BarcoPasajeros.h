#ifndef BARCOPASAJEROS
#define BARCOPASAJEROS
#include "Barco.h"
#include "TipoTamanio.h"
#include "DtBarcoPasajeros.h"

class BarcoPasajeros: public Barco{
private:
    int cantPasajeros;
    TipoTamanio tamanio;
public:
    BarcoPasajeros();
    BarcoPasajeros(string nombre, string id, int cantPasajeros, TipoTamanio tamanio);
    void setCantPasajeros(int cantPasajeros);
    int getCantPasajeros();
    void setTamanio(TipoTamanio tamanio);
    TipoTamanio getTamanio();
    ~BarcoPasajeros();

    void arribar(float cargaDespacho);
    DtBarco* getDtBarco();
};

#endif
