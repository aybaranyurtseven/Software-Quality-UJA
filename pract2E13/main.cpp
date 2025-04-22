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
       //ERR62-CPP
       if(cin.fail()){
        cin.clear;
        cin.ignore(numeric_limits<streamsize>::max(), ' ');
       }
   }while(tamv<=0);

   //MEM51-CPP
   Vehiculo *v=new Vehiculo[tamv];

   //STR50-CPP
   try{
       rellenarVector (v,tamv);
   }catch(const string &e){
       cerr<<e<<endl;
   }

   //ERR50-CPP
    try{
        cout<<" los vehiculos introducidos de 5 en 5 son :"<<endl;
      mostrarEnPantalla( v, tamv );
    }catch(const string e){
        cerr<<e;
    }

    mayor=MaxPrecio(v,tamv);
    cout<<" el vehiculo cuyo precio es mayor es : "<<endl;
    muestraEnPantalla(v[mayor]);
    //ERR52-CPP
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
