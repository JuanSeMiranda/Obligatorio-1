#ifndef DTBARCOPASAJEROS
#define DTBARCOPASAJEROS
#include "TipoTamanio.h"
#include "DtBarco.h"

class DtBarcoPasajeros : public DtBarco{
private:
    int cantPasajeros;
    TipoTamanio tamanio;
public:
    DtBarcoPasajeros();
    DtBarcoPasajeros(string nombre, string id, int cantPasajeros, TipoTamanio tamanio);
    void setCantPasajeros(int cantPasajeros);
    int getCantPasajeros();
    void setTamanio(TipoTamanio tamanio);
    TipoTamanio getTamanio();
    ~DtBarcoPasajeros();
};

#endif

