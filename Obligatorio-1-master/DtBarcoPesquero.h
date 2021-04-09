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
    int getCapacidad();
    int getCarga();
    ~DtBarcoPesquero();

    friend ostream& operator <<(ostream&, DtBarcoPesquero&);
};

#endif
