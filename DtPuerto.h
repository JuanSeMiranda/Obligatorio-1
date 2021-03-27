#ifndef DTARRIBO
#define DTARRIBO
#include <string>
#include <iostream>

#include "DtFecha.h"

class DtPuerto{
private:
    string id;
    string nombre;
    DtFecha fechaCreacion;
    int cantArribos;
public:
    DtPuerto();
    DtPuerto(string id, string nombre, DtFecha fechaCreacion, int cantArribos);
    void setId(string id);
    string getId();
    void setNombre(string nombre);
    string getNombre();
    void setFechaCreacion(DtFecha fechaCreacion);
    DtFecha getFechaCreacion();
    void setCantArribos(int cantArribos);
    int getCantArribos();
    ~DtPuerto();
};

#endif // DTARRIBO
