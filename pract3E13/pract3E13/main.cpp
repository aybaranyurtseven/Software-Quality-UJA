#include <iostream>
#include "vehiculo.h"
using namespace vehiculos;


int main() {
   // Vehiculo p;

    int tamv;
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
    }catch(const string &e){
        cerr<<e;
    }
    int mayor;
     mayor=vehiculos::MaxPrecio(v,tamv);
    cout<<" el vehiculo cuyo precio es mayor es : "<<endl;
    muestraEnPantalla(v[mayor]);
    int posicion
    try{
        string matricula;
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
