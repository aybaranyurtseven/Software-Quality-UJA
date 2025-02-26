#include <iostream>
#include "vehiculo.h"
using namespace vehiculos;
/**
 * @file main.cpp
 * @brief Main program for vehicle management.
 *
 * This program allows the user to enter vehicle data, store it in a dynamic array,
 * show them on the screen, search for a vehicle by license plate, find the most expensive one and load vehicles on a transport.
 * Exceptions are handled in case of errors in data entry.
 *
 * @return Returns 0 if the execution is successful.
 */

int main() {
   int tamv; ///< Vehicle array size
   string matricula;  ///< Car license plate entered by the user
    int posicion,mayor;///< Auxiliary variables for search and comparison
    Vehiculo p; ///< Auxiliary vehicle
   do{
       cout<<"introduce el tamanio del vector";
       cin>>tamv;
   }while(tamv<=0);
   Vehiculo *v=new Vehiculo[tamv];

   try{
       rellenarVector (v,tamv);
   }catch(const string &e){
       cerr<<e<<endl;
   }

    try{
        cout<<" los vehiculos introducidos de 5 en 5 son :"<<endl;
      mostrarEnPantalla( v, tamv );
    }catch(const string e){
        cerr<<e;
    }

     mayor=MaxPrecio(v,tamv);
    cout<<" el vehiculo cuyo precio es mayor es : "<<endl;
    muestraEnPantalla(v[mayor]);
    try{
        cout<<"introduce la matricula ";
        cin>>matricula;
        posicion= buscarPorMatricula( matricula, v,tamv);
        cout<<" el vehiculo con matricula "<<matricula <<"ocupa la posicion"<<posicion<<endl;
        LeePorTeclado(v[posicion]);
    }catch(const string &e){
        cerr<<e<<endl;
    }
    try{
        cargaEnTransporte(v,tamv);
    }catch(const string &e){
     cerr<<e<<endl;
    }

    delete [] v;
    return 0;
}
