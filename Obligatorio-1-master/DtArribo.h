#ifndef DTARRIBO
#define DTARRIBO
#include <string>
#include "DtFecha.h"
#include "DtBarco.h"
#include "DtBarcoPesquero.h"
#include "DtBarcoPasajeros.h"

class DtArribo{
private:
    DtFecha fecha;
    float carga;
    DtBarco* barco;
public:
    DtArribo();
    DtArribo(DtFecha fecha, float carga, DtBarco* barco);
    DtFecha getFecha();
    float getCarga();
    DtBarco* getDtBarco();
    ~DtArribo();

    friend ostream& operator <<(ostream&, DtArribo&);
};

#endif // DTARRIBO
