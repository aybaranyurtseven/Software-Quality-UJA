//
// Created by Lydia on 17/02/2022.
//

#ifndef A_VEHICULO_H
#define A_VEHICULO_H


#include <iostream>
#include <string>

using  namespace std;
namespace vehiculos {
    struct Vehiculo {
        string marca;
        string modelo;
        string matricula;
        int afabricacion;
        float precio;
        float peso;
    };
    void LeePorTeclado (Vehiculo &p);
    void rellenarVector (Vehiculo v[], int tamv);
    void muestraEnPantalla(const Vehiculo  &p);
    void  mostrarEnPantalla(const Vehiculo *v, int tamv );
    int MaxPrecio(Vehiculo p[], int tamv);
    int buscarPorMatricula(string matricula, Vehiculo v[], int tamv);
    void cargaEnTransporte(Vehiculo v[], int nVehiculos);
}


#endif //A_VEHICULO_H
