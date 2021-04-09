#ifndef DTPUERTO
#define DTPUERTO
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
    string getId();
    string getNombre();
    DtFecha getFechaCreacion();
    int getCantArribos();
    ~DtPuerto();
};

#endif // DTARRIBO
