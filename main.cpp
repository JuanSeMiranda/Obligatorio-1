#include <iostream>
#include <string>
#include "TipoTamanio.h"
#include "DtBarco.h"
#include "DtBarcoPasajeros.h"
#include "DtBarcoPesquero.h"
#include "DtFecha.h"
#include "DtArribo.h"
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
	while(i < colPuertos.tope && colPuertos.p[i]->getId() != idPuerto)
		i++;

    if(i == colPuertos.tope)
        throw invalid_argument("No existe el puerto con ese Id.\n");

	int j = 0;
	while(j < colBarcos.tope && colBarcos.b[j]->getId() != idBarco)
		j++;

    if(j == colBarcos.tope)
        throw invalid_argument("No existe el barco con ese Id.\n");

	Arribo* arribo = new Arribo(fecha, cargaDespacho, colBarcos.b[j]);

    colBarcos.b[j]->arribar(cargaDespacho);
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

//QUINTA FUNCION

DtArribo** obtenerInfoArribosEnPuerto(string idPuerto, int& cantArribos){
    int i = 0;
	while(i < colPuertos.tope && colPuertos.p[i]->getId() != idPuerto)
		i++;

    cantArribos = colPuertos.p[i]->getCantArribos();
    DtArribo** arribos = colPuertos.p[i]->getDtArribos();
    
    return arribos;
}

void menuObtenerInfoArribosEnPuerto(){
    string idPuerto;

    cout << "Id de puerto: ";
    cin >> idPuerto;

    int i = 0;
	while(i < colPuertos.tope && colPuertos.p[i]->getId() != idPuerto)
		i++;

    if(i == colPuertos.tope)
        throw invalid_argument("No existe el puerto con ese Id.\n");

    int cantArribos = colPuertos.p[i]->getCantArribos();
    DtArribo** arribos = obtenerInfoArribosEnPuerto(idPuerto, cantArribos);
    
    cout << "Cantidad de arribos: " << cantArribos << "\n" << endl;

    for(int j = 0; j < colPuertos.p[i]->getCantArribos(); j++){
        cout << "Arribo " << j+1 << endl;
        cout << "------" << endl;
        //cout << *arribos[j] << endl; no va, los hijos acceden directamente al id y nombre del padre

        if(DtBarcoPasajeros* pas = dynamic_cast<DtBarcoPasajeros*>(arribos[j]->getDtBarco())){
            cout << *pas << endl;
        }else if(DtBarcoPesquero* pes= dynamic_cast<DtBarcoPesquero*>(arribos[j]->getDtBarco())){
            cout << *pes << endl;
        }
    }
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
    /////FECHAS
    DtFecha f1 = DtFecha(1,1,2021);
    DtFecha f2 = DtFecha(1,2,2021);
    DtFecha f3 = DtFecha(1,3,2021);
    /////PUERTOS
    agregarPuerto("1", "Puerto1", f1);
    agregarPuerto("2", "Puerto2", f2);
    agregarPuerto("3", "Puerto3", f2);
    agregarPuerto("4", "Puerto4", f2);
    /////BARCOS

    DtBarcoPasajeros Bpas1 = DtBarcoPasajeros("Pas1","1",50,CRUCERO);
    DtBarcoPasajeros Bpas2 = DtBarcoPasajeros("Pas2","2",50,CRUCERO);
    DtBarcoPesquero Bpes1 = DtBarcoPesquero("Pes1","3",50,10);
    DtBarcoPesquero Bpes2 = DtBarcoPesquero("Pes2","4",50,10);

    agregarBarco(Bpas1);
    agregarBarco(Bpas2);
    agregarBarco(Bpes1);
    agregarBarco(Bpes2);

    ///// ARRIBOS

    agregarArribo("1", "1", f1, 0);
    agregarArribo("1", "2", f2, 0);
    agregarArribo("2", "3", f3, 0);
    agregarArribo("2", "4", f2, 0);

    menu();
    int opcion;
    cin >> opcion;
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
                    }catch(invalid_argument& fecha){
                        cout << fecha.what() << endl;
                    }
                    break;
            case 3: menuListarPuertos();
                    break;
            case 4: try{
                        menuAgregarArribo();
                    }catch(invalid_argument& fecha){
                        cout << fecha.what() << endl;
                        try{
                            
                        }catch(invalid_argument& BarcoPesquero){
                            cout << BarcoPesquero.what() << endl;
                        }
                    }
                    break;
            case 5: try{
                        menuObtenerInfoArribosEnPuerto();
                    }catch(invalid_argument& idPuerto){
                        cout << idPuerto.what() << endl;
                        cout << "Ya maneje la exepcion" << endl;
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

    return 0;
}