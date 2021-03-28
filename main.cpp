#include <iostream>
#include <string>
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

#define MAX_PUERTOS 20
#define MAX_BARCOS 30

using namespace std;

//COLECCIONES GLOBALES

struct Puertos{
    Puerto* p[MAX_PUERTOS];
    int tope;
}colPuertos;

struct Barcos{
    Barco* b[MAX_BARCOS];
    int tope;
}colBarcos;

/////////////////////////////

//PRIMERA FUNCION

void agregarPuerto(string id, string nombre, DtFecha fechaCreacion){

    Puerto* p = new Puerto(id, nombre, fechaCreacion);
    colPuertos.p[colPuertos.tope] = p;
    colPuertos.tope++;
}

void menuAgregarPuerto(){
    if(colPuertos.tope < 20){
        string id;
        string nombre;
        DtFecha fechaCreacion;
        int dia, mes, anio;

        cout << "Id: ";
        cin >> id;

        int i = 0;
        while(i < colPuertos.tope && colPuertos.p[i]->getId() != id)
            i++;

        if(i != colPuertos.tope)
            throw invalid_argument("Ya hay un puerto con ese ID.\n");

        cout << "Nombre: ";
        cin >> nombre;

        cout << "\nFecha de Creacion:" << endl;
        cout << "Dia: ";
        cin >> dia;
        cout << "Mes: ";
        cin >> mes;
        cout << "Anio: ";
        cin >> anio;

        DtFecha fecha (dia, mes, anio);
        agregarPuerto(id, nombre, fecha);

    } else{
        cout << "No se admiten mas de 20 puertos." << endl;
    }

}

//SEGUNDA FUNCION

void agregarBarco(DtBarco& barco){
    try{
        DtBarcoPasajeros& dtBarcoPas = dynamic_cast<DtBarcoPasajeros&>(barco);
        BarcoPasajeros* barcoPas = new BarcoPasajeros(dtBarcoPas.getNombre(),
                                                      dtBarcoPas.getId(),
                                                      dtBarcoPas.getCantPasajeros(),
                                                      dtBarcoPas.getTamanio());
        colBarcos.b[colBarcos.tope] = barcoPas;
        colBarcos.tope++;
    } catch(bad_cast){
        try{
            DtBarcoPesquero& dtBarcoPes = dynamic_cast<DtBarcoPesquero&>(barco);
            BarcoPesquero* barcoPes = new BarcoPesquero(dtBarcoPes.getNombre(),
                                                        dtBarcoPes.getId(),
                                                        dtBarcoPes.getCapacidad(),
                                                        dtBarcoPes.getCarga());
            colBarcos.b[colBarcos.tope] = barcoPes;
            colBarcos.tope++;
        } catch(bad_cast){}
    }
}

void menuAgregarBarco(){
    string id;
    string nombre;
    int opcion;

    cout << "Ingrese ID:";
    cin >> id;

    cout << "Ingrese nombre:";
    cin >> nombre;

    cout << "Elija tipo de barco (1 para pasajero, 2 para carga)";
/*
    switch(opcion){
        case 1: int cantPasajeros;
                string tamanio;
                cout << "Ingrese cantidad de pasajeros:";
                cin >> cantPasajeros;

                cout << "Ingrese tipo tamanio:";
                cin >> tamanio;

                TipoTamanio& tam = dynamic_cast<TipoTamanio&>(tamanio);

                DtBarcoPasajeros barco(id, nombre, cantPasajeros, tamanio);
                agregarBarco(barco);
                break;

        case 2: int capacidad;
                int carga;
                cout << "Ingrese capacidad:";
                cin >> capacidad;

                cout << "Ingrese carga:";
                cin >> carga;

                DtBarcoPesquero barco(id, nombre, capacidad, carga);
                agregarBarco(barco);
                break;
    }
*/
}

//TERCERA FUNCION

DtPuerto** listarPuertos(int& cantPuertos){
	cantPuertos = colPuertos.tope;
	DtPuerto** listado = new DtPuerto*[cantPuertos];

	for(int i = 0; i < colPuertos.tope; i++){
        DtPuerto* dtp = new DtPuerto(colPuertos.p[i]->getId(), colPuertos.p[i]->getNombre(), colPuertos.p[i]->getFechaCreacion(), colPuertos.p[i]->getCantArribos());
        listado[i] = dtp;
    }
	return listado;
}

void menuListarPuertos(){
    DtPuerto** listado;
    listado = listarPuertos(colPuertos.tope);
    for(int i = 0; i < colPuertos.tope; i++){
        cout << "\n" << endl;
        cout << "Id del puerto: " << listado[i]->getId() << endl;
        cout << "Nombre del puerto: " << listado[i]->getNombre() << endl;
        //cout << "Fecha puerto: " << listado[i]->getFechaCreacion()->dia << "/" << listado[i]->getFechaCreacion()->mes << "/" << listado[i]->getFechaCreacion()->anio << endl;
        cout << "Cantidad de arribos del puerto: " << listado[i]->getCantArribos() << endl;
        cout << "\n" << endl;
    }
}

/////////////////////////

//Menu y main

void menu(){

    cout<<"Bienvenido. Elija una opcion." << endl<< endl;
    cout<<"1) Agregar Puerto." << endl;
    cout<<"2) Agregar Barco." << endl;
    cout<<"3) Listar Puertos." << endl;
    cout<<"4) Agregar Arribo." << endl;
    cout<<"5) Obtener informacion de Arribos en Puerto." << endl;
    cout<<"6) Eliminar Arribos." << endl;
    cout<<"7) Listar Barcos." << endl;
    cout<<"8) Salir." << endl;
    //system("cls");

}


int main(){

    colPuertos.tope = 0;
    colBarcos.tope = 0;

    int opcion;
    while(opcion != 7){
        switch(opcion){
            case 1: try{
                        menuAgregarPuerto();
                        cout << "Puerto creado con exito" << endl;
                    }catch(invalid_argument& fecha){
                        cout << fecha.what() << endl;
                        cout << "Ya maneje la excepcion" << endl;
                    }
                    break;
        }
        menu();
        cin>>opcion;
    }

}
