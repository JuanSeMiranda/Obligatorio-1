#ifndef DTARRIBO
#define DTARRIBO
#include <string>
#include "DtFecha.h"
#include "DtBarco.h"

class DtArribo{
private:
    DtFecha fecha;
    float carga;
    DtBarco* barco;
public:
    DtArribo();
    DtArribo(DtFecha fecha, float carga, DtBarco* barco);
    void setFecha(DtFecha fecha);
    DtFecha getFecha();
    void setCarga(float carga);
    float getCarga();
    void setDtBarco(DtBarco* barco);
    DtBarco* getDtBarco();
    ~DtArribo();

    friend ostream& operator <<(ostream&, DtArribo&);
};

#endif // DTARRIBO
