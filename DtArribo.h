#ifndef DTARRIBO
#define DTARRIBO
#include <string>
#include "DtFecha.h"
#include "DtBarco.h"

class DtArribo{
private:
    DtFecha fecha;
    float carga;
    DtBarco barco;
public:
    DtArribo();
    DtArribo(DtFecha fecha, float carga, DtBarco barco);
    void setFecha(DtFecha fecha);
    DtFecha getFecha();
    void setCarga(float carga);
    float getCarga();
    void setBarco(DtBarco barco);
    DtBarco getBarco();
    ~DtArribo();
};

#endif // DTARRIBO
