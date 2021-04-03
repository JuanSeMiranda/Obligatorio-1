#ifndef DTBARCO
#define DTBARCO
#include<iostream>

using namespace std;   


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

    friend ostream& operator <<(ostream&, const DtBarco&);
};

#endif
