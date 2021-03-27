#ifndef DTBARCO
#define DTBARCO
#include<iostream>
//#include <string.h>

using namespace std;   
//std::string;


class DtBarco{
private:
    string nombre;
    string id;
public:
    DtBarco();
    DtBarco(string nombre, string id);
    void setNombre(string nombre);
    string getNombre();
    void setId(string id);
    string getId();
    virtual ~DtBarco();
};

#endif
