//
// Created by Lydia on 17/02/2022.
//
/**
 * @file vehiculo.h
 * @brief Definitions and functions for vehicle management.
 */
// DCL51-CPP 
#ifndef A_VEHICULO_H 
#define A_VEHICULO_H


#include <iostream>
#include <string>

using  namespace std;

namespace vehiculos {
/**
     * @struct Vehicle
     * @brief Represents a vehicle with its main characteristics.
     * **/

    //OOP53-CPP
    struct Vehiculo {
        string marca;
        string modelo;
        string matricula;
        int afabricacion;
        float precio;
        float peso;
    };
    //ERR56-CPP
    Vehiculo& operator=( const Vehiculo &v){
        int *a=nullptr;
        if (v){
            a= new Vehiculo;
            a=v;
        }
        delete[] v;
        v=a;
        return *this;
    }
    void LeePorTeclado (Vehiculo &p);
    void rellenarVector (Vehiculo v[], int tamv);
    void muestraEnPantalla(const Vehiculo  &p);
    void  mostrarEnPantalla(const Vehiculo *v, int tamv );
    int MaxPrecio(Vehiculo p[], int tamv);
    int buscarPorMatricula(string matricula, Vehiculo v[], int tamv);
    void cargaEnTransporte(Vehiculo v[], int nVehiculos);
}


#endif //A_VEHICULO_H
