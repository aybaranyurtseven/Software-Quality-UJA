//
// Created by Lydia on 17/02/2022.
//
/**
 * @file vehiculo.cpp
 * @brief Functions for vehicle management.
 */
#include "vehiculo.h"

/**
 * @brief Prompts the user for a vehicle's data and stores it in the provided structure.
 *
 * @param[in] p Reference to a Vehicle object where the entered data will be saved.
 *
 * @post The `p` object will contain the data entered by the user, as long as it is valid.
 *
 * @throws string If the flag is less than 3 or more than 20 characters.
 * @throws string If the model is less than 1 or more than 30 characters.
 * @throws string If the license plate does not have exactly 6 characters.
 * @throws string If the price is negative.
 * */
void vehiculos::LeePorTeclado (Vehiculo &p ){
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
//OOP53-CPP
vehiculo::vehiculo(string modelo,string matricula, int afabricacion,float precio,float peso);
/**
 *@brief fills a vector
 * @param [in] v Reference to a Vehicle object where the entered data will be saved.
 * @param [in] tamv Size of the vector that we are going to fill
 * @post fills the vector by calling the ReadByKeyboard function
 */
void vehiculos:: rellenarVector (Vehiculo v[], int tamv){
    for(int i=0; i<tamv; i++) {
        LeePorTeclado(v[i]);
    }
}
/**
 *@brief shown on screen
 * @param [in]  v Reference to a Vehicle object where the entered data will be saved.
 * @post shows all the cars entered on the screen
 */
void vehiculos:: muestraEnPantalla(const Vehiculo  &p ){
        cout << "la marca del vehiculo es : " << p.marca << endl;
        cout << "el modelo del vehiculo es : " << p.modelo << endl;
        cout << "la matricula del vehiculo es : " << p.matricula << endl;
        cout << "el anio de fabricacion del vehiculo es : " << p.afabricacion << endl;
        cout << "el precio del vehiculo es : " << p.precio << endl;

}
/**
 *@brief shown on screen
 * @param [in] v Reference to a Vehicle object where the entered data will be saved.
 * @param [in] tamv Size of the vector that we are going to fill
 * @post shows the cars on the screen 5 by 5
 */

//DCL52-CPP
void vehiculos:: mostrarEnPantalla(const Vehiculo *v, int tamv ){
    char c;
    for(int i=0; i<tamv; i++){
        muestraEnPantalla(v[i]);
        if((i+1)%5==0){
            cout<<"pulsa enter para los 5siguientes : ";
            cin.ignore(); //DCL50-CPP Instead of using `char c; cin >> c;`
        }

    }
}
/**
 * @brief shows the highest priced car
 * @param [in] p Reference to a Vehicle object where the entered data will be saved.
 * @param [in] tamv Size of the vector that we are going to fill
 * @post shows the highest priced car
 * @return pos , is the position where it is the car with the highest price
 */

//INT30-C (NEW)
int vehiculos::MaxPrecio(Vehiculo p[], int tamv) {
    if (tamv <= 0) return -1;  // Prevents out-of-bounds access
    long long aux = 0;  // Use a larger type to prevent wrapping
    int pos = 0;

    for (int i = 0; i < tamv; i++) {
        if (static_cast<long long>(p[i].precio) > aux) {  // Safe conversion
            aux = static_cast<long long>(p[i].precio);
            pos = i;
        }
    }
    return pos;
}

/**
 *@brief searches for a license plate
 * @param [in] matricula the license plate of the car we want to find
 * @param [in] v Reference to a Vehicle object where the entered data will be saved.
 * @param [in] tamv Size of the vector that we are going to fill
 * @post a license plate is entered and it searches for it among all the cars entered
 * @return i the position where is the car
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
 * @brief sum of weight
 * @param [in] v Reference to a Vehicle object where the entered data will be saved.
 * @param nVehicles number of vehicles we want to sum their wight
 * @post adds the weight of all the vehicles and if it exceeds 10,000kg it will throw an exception
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

