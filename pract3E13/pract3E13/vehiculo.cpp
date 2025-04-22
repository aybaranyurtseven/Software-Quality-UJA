//
// Created by Lydia on 17/02/2022.
//

#include "vehiculo.h"
/**
 * @brief lee por teclado
 * @param p
 * @param n
 * @post lee los datos que le introduce el ususario pos teclado
 */
void vehiculos::LeePorTeclado (vehiculos::Vehiculo &p ){
    cout << "introduce la marca";
    getline(cin >> ws, p.marca);
    if (p.marca.length() < 3 || p.marca.length() > 20){
        throw string("vehiculos:: LeePorTeclado: has introducido mal la marca");
    }

    cout << "introduce el modelo";
    getline(cin >> ws, p.modelo);
    if  (p.modelo.length() < 1 || p.modelo.length() > 30){
        throw string("vehiculos::LeePorTeclado: has introducido mal el modelo");
    }
    cout << "introduce la matricula";
    getline(cin >> ws, p.matricula);
    if (p.matricula.length() != 6){
        throw string("vehiculos:: LeePorTeclado: has introducido mal la matricula");
    }
    cout << "introduce el anio de fabricacion :";
    cin >> p.afabricacion;

    cout << "introduce el precio";
    cin >> p.precio;
    if (p.precio < 0){
        throw string("vehiculos::LeePorTeclado: has introducido mal el precio");
    }

    cout<<"introduce el peso del vehiculo";
    cin>>p.peso;

}
/**
 *@brief rellena un vector
 * @param v
 * @param tamv
 * @post rellena el vector llamando a la funcion LeePorTeclado
 */
void vehiculos:: rellenarVector (Vehiculo v[], int tamv){
    for(int i=0; i<tamv; i++) {
        LeePorTeclado(v[i]);
    }
}
/**
 *@brief muestra en pantalla
 * @param v
 * @param tamv
 * @post muestra en pantalla todos los coches introducidos
 */
void vehiculos:: muestraEnPantalla(const Vehiculo  &p ){
        cout << "la marca del vehiculo es : " << p.marca << endl;
        cout << "el modelo del vehiculo es : " << p.modelo << endl;
        cout << "la matricula del vehiculo es : " << p.matricula << endl;
        cout << "el anio de fabricacion del vehiculo es : " << p.afabricacion << endl;
        cout << "el precio del vehiculo es : " << p.precio << endl;

}
/**
 *@brief muestra en pantalla
 * @param v
 * @param tamv
 *  @post muestra en pantalla los coches de 5 en 5
 */
void vehiculos:: mostrarEnPantalla(const Vehiculo *v, int tamv ){
    char c;
    for(int i=0; i<tamv; i++){
        muestraEnPantalla(v[i]);
        if((i+1)%5==0){
            cout<<"pulsa enter para los 5siguientes : ";
            cin>>c;
        }

    }
}
/**
 * @brief muestra el coche de mayor precio
 * @param p
 * @param tamv
 * @post muestra el coche de mayor precio
 * @return
 */

int vehiculos:: MaxPrecio(Vehiculo p[], int tamv){
    int aux=0;
    int pos=0;
    for(int i=0; i<tamv; i++){
        if(p[i].precio>aux){
            aux=p[i].precio;
            pos=i;
        }
    }
    return pos;
}
/**
 *@brief busca una matricula
 * @param matricula
 * @param v
 * @param tamv
 * @post se le introduce una matricula y la busca entre todos los coches introducidos
 * @return
 */
int vehiculos::buscarPorMatricula(string matricula, Vehiculo *v, int tamv) {
    for(int i=0; i<tamv; i++){
        if(matricula==v[i].matricula){
            return i;
        }
    }
    throw string("vehiculos:: buscarPorMatriculao:matricula no esta en el vecotr");
}
/**
 * @brief suma del peso
 * @param v
 * @param nVehiculos
 * @post suma el peso de todos los vehiculos y si pasa de 10000kg lanzara una excepcion
 */
void vehiculos:: cargaEnTransporte(Vehiculo v[], int nVehiculos){
    float suma=0;
    for(int i=0; i<nVehiculos; i++){
        suma=suma+v[i].peso;
    }
    if(suma>10000){
        throw string("vehiculos::cargaEnTransporte: el peso supera los 10000kg ");
    }
}

