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
    int getCantPasajeros();
    TipoTamanio getTamanio();
    ~DtBarcoPasajeros();

    friend ostream& operator <<(ostream&, DtBarcoPasajeros&);
};

#endif

