#include <iostream>
#include <string.h>


using namespace std;

void menu(){

    cout<<"Bienvenido. Elija la opción." << endl<< endl;
    cout<<"1) Agregar Puerto." << endl;
    cout<<"2) Agregar Barco" << endl;
    cout<<"3) " << endl;
    cout<<"4)" << endl;
    cout<<"5)" << endl;
    cout<<"6)" << endl;
    cout<<"7) Salir." << endl;

}


int main(){

    int opcion;
    while(opcion != 7){
        menu();
        cin>>opcion;
    }

}
