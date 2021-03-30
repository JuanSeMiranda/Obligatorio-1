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
        BarcoPasajeros* barcoPas = new BarcoPasajeros(dtBarcoPas.getId(),
                                                      dtBarcoPas.getNombre(),
                                                      dtBarcoPas.getCantPasajeros(),
                                                      dtBarcoPas.getTamanio());
        colBarcos.b[colBarcos.tope] = barcoPas;
        colBarcos.tope++;
    } catch(bad_cast){
        try{
            DtBarcoPesquero& dtBarcoPes = dynamic_cast<DtBarcoPesquero&>(barco);
            BarcoPesquero* barcoPes = new BarcoPesquero(dtBarcoPes.getId(),
                                                        dtBarcoPes.getNombre(),
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

    cout << "Ingrese ID: ";
    cin >> id;

    int i = 0;
    while(i < colBarcos.tope && colBarcos.b[i]->getId() != id)
        i++;


    if(i != colBarcos.tope)
        throw invalid_argument("Ya existe un barco con ese Id");


    cout << "Ingrese nombre: ";
    cin >> nombre;

    cout << "Elija tipo de barco (1 para pasajero, 2 para carga): ";
    cin >> opcion;

    switch(opcion){
        case 1: {
                    int cantPasajeros;
                    int tamanioNum;
                    TipoTamanio tamanio;
                    cout << "Ingrese cantidad de pasajeros: ";
                    cin >> cantPasajeros;

                    cout << "Ingrese tipo tamanio (0 para bote, 1 para crucero, 2 para galeon o 3 para transatlantico): ";
                    cin >> tamanioNum;

                    tamanio = (TipoTamanio) tamanioNum;

                    DtBarcoPasajeros barco(id, nombre, cantPasajeros, tamanio);
                    agregarBarco(barco);
                }
                break;
        case 2: {
                    int capacidad;
                    int carga;
                    cout << "Ingrese capacidad: ";
                    cin >> capacidad;

                    cout << "Ingrese carga: ";
                    cin >> carga;

                    DtBarcoPesquero barco(id, nombre, capacidad, carga);
                    agregarBarco(barco);
                }
                break;
        default:cout << "Opcion invalida, vuelva a intentarlo." << endl;
                break;
    }

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

void imprimirFecha(DtFecha fecha){
    cout << fecha.getDia() << "/" << fecha.getMes() << "/" << fecha.getAnio() << endl;
}

void menuListarPuertos(){
    DtPuerto** listado;
    listado = listarPuertos(colPuertos.tope);
    for(int i = 0; i < colPuertos.tope; i++){
        cout << "\n" << endl;
        cout << "Puerto numero " << i+1 << endl;
        cout << "----------------" << endl;
        cout << "Id del puerto: " << listado[i]->getId() << endl;
        cout << "Nombre del puerto: " << listado[i]->getNombre() << endl;
        cout << "Fecha de Creacion del puerto: ";
        imprimirFecha(listado[i]->getFechaCreacion());
        cout << "Cantidad de arribos del puerto: " << listado[i]->getCantArribos() << endl;
        cout << "\n" << endl;
    }
}

//CUARTA FUNCION

void agregarArribo(string idPuerto, string idBarco, DtFecha fecha, int cargaDespacho){
	int i = 0;
	while(colPuertos.p[i]->getId() != idPuerto && i != colPuertos.tope)
		i++;

    if(i == colPuertos.tope && colPuertos.p[i]->getId() != idPuerto)
        throw invalid_argument("No existe el puerto con ese Id.\n");

	int j = 0;
	while(colBarcos.b[j]->getId() != idBarco && j != colBarcos.tope)
		j++;

    if(j == colBarcos.tope && colBarcos.b[j]->getId() != idBarco)
        throw invalid_argument("No existe el barco con ese Id.\n");

	Arribo* arribo = new Arribo(fecha, cargaDespacho);

	colPuertos.p[i]->agregarArribo(arribo);
}

void menuAgregarArribo(){
    string idPuerto;
    string idBarco;
    int cargaDespacho;

    cout << "Ingrese el Id del Puerto" << endl;
    cin >> idPuerto;

    cout << "Ingrese el Id del Barco" << endl;
    cin >> idBarco;

    int dia, mes, anio;

    cout << "Ingrese el dia" << endl;
    cin >> dia;

    cout << "Ingrese el mes" << endl;
    cin >> mes;

    cout << "Ingrese el anio" << endl;
    cin >> anio;

    DtFecha fecha(dia, mes, anio);

    cout << "Ingrese la carga a despachar" << endl;
    cin >> cargaDespacho;

    agregarArribo(idPuerto, idBarco, fecha, cargaDespacho);

}

//SEPTIMA FUNCION

DtBarco** listarBarcos(int& cantBarcos){
  cantBarcos=colBarcos.tope;
  DtBarco** listado = new DtBarco*[cantBarcos];
  for(int i=0 ; i < colBarcos.tope ; i++){
    if(BarcoPasajeros* pas = dynamic_cast<BarcoPasajeros*>(colBarcos.b[i])){
        DtBarcoPasajeros* dtbpa = new DtBarcoPasajeros(pas->getId(), pas->getNombre(), pas->getCantPasajeros(), pas->getTamanio());
        listado[i]=dtbpa;

    } else if(BarcoPesquero* pes= dynamic_cast<BarcoPesquero*>(colBarcos.b[i])){
        DtBarcoPesquero* dtbpe = new DtBarcoPesquero(pes->getId(), pes->getNombre(), pes->getCapacidad(), pes->getCarga());

        listado[i]=dtbpe;
    }
  }
  return listado;
}

void imprimirTamanio(TipoTamanio num){
    switch(num){
        case BOTE: cout << "BOTE" << endl;
                break;
        case CRUCERO: cout << "CRUCERO" << endl;
                break;
        case GALEON: cout << "GALEON" << endl;
                break;
        case TRANSATLANTICO: cout << "TRANSATLANTICO" << endl;
                break;
    }
}

void menuListarBarcos(){
    DtBarco** listado;
    listado = listarBarcos(colBarcos.tope);
    for(int i = 0; i < colBarcos.tope; i++){
        cout << "\n" << endl;
        cout << "Barco numero " << i+1 << endl;
        cout << "----------------" << endl;
        if(BarcoPasajeros* pas = dynamic_cast<BarcoPasajeros*>(colBarcos.b[i])){
            cout << "Id del barco: " << pas->getId() << endl;
            cout << "Nombre del barco: " << pas->getNombre() << endl;
            cout << "Cantidad de pasajeros del barco: " << pas->getCantPasajeros() << endl;
            cout << "Tipo de barco: ";
            imprimirTamanio(pas->getTamanio());
        }else if(BarcoPesquero* pes= dynamic_cast<BarcoPesquero*>(colBarcos.b[i])){
            cout << "Id del barco: " << pes->getId() << endl;
            cout << "Nombre del barco: " << pes->getNombre() << endl;
            cout << "Capacidad del barco: " << pes->getCapacidad() << endl;
            cout << "Carga del barco: " << pes->getCarga() << endl;
        }
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
    while(opcion != 8){
        switch(opcion){
            case 1: try{
                        menuAgregarPuerto();
                        cout << "Puerto creado con exito" << endl;
                    }catch(invalid_argument& fecha){
                        cout << fecha.what() << endl;
                        cout << "Ya maneje la excepcion" << endl;
                    }
                    break;
            case 2: try{
                        menuAgregarBarco();
                    } catch(invalid_argument& fecha){
                        cout << fecha.what() << endl;
                    }
                    break;
            case 3: menuListarPuertos();
                    break;
            case 4: try{
                        menuAgregarArribo();
                    } catch(invalid_argument& fecha){
                        cout << fecha.what() << endl;
                    } catch (invalid_argument& BarcoPesquero){
                        cout << BarcoPesquero.what() << endl;
                    }
                    break;
            case 7: menuListarBarcos();
                    break;
            default: cout << "Opcion invalida, vuelva a intentarlo" << endl;
                    break;
        }
        menu();
        cin>>opcion;
    }

}
