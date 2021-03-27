#include <iostream>
#include <string.h>
#include "TipoTamanio.h"
#include "DtBarco.h"
#include "DtBarcoPasajeros.h"
#include "DtBarcoPesquero.h"
#include "DtFecha.h"
#include "DtPuerto.h"
#include "Barco.h"
#include "BarcoPasajeros.h"
#include "BarcoPesquero.h"
#include "Arribo.h"
#include "Puerto.h"


using namespace std;

void menu(){

    cout<<"Bienvenido. Elija la opción." << endl<< endl;
    cout<<"1) Agregar Puerto." << endl;
    cout<<"2) Agregar Barco." << endl;
    cout<<"3) Listar Puertos." << endl;
    cout<<"4) Agregar Arribo." << endl;
    cout<<"5) Obtener informacion de Arribos en Puerto." << endl;
    cout<<"6) Eliminar Arribos." << endl;
    cout<<"7) Salir." << endl;

}


int main(){

    int opcion;
    while(opcion != 7){
        menu();
        cin>>opcion;
    }

}
