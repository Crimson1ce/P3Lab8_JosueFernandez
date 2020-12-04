/* 
 * File:   Caballo.cpp
 * Author: Josue_Fernandez
 * 
 * Created on 04 de diciembre de 2020
 */

#include "Caballo.h"
#include "Pieza.h"
#include "Tablero.h"
#include <string>
using std::string;

Caballo::Caballo(bool esBlanco) : Pieza(esBlanco, (esBlanco ? 7 : 1), (esBlanco ? 2 : 6)) {
    if (esBlanco) {
        caracter = 'C';
    } else {
        caracter = 'c';
    }
}

Caballo::Caballo(const Caballo& orig) {
}

Caballo::~Caballo() {
}

int Caballo::absoluto(int numero) {
    return (numero > 0 ? numero : -numero);
}

bool Caballo::validarMovimiento(string, Tablero) {
    if (!Pieza::validarMovimiento(coordenadas, tablero)) {
        return false;
    }

    // El ingreso es de 1 a 8, pero la matriz está al revés de 0 a 7
    int fila = (int) string[5];
    //Columna se representa por un caracter
    int columna = (int) string[4];

    //Validacion fila
    if (fila < 49 || fila > 56) {
        //Debe ser un dígito
        return false;
    }

    fila = 8 - (fila - 48);

    //Validacion columna
    if (columna < 65 || columna > 104 || (columna > 72 && columna < 97)) {
        //Debe ser una letra, A-H o a-h
        return false;
    }

    if (columna < 73) {
        columna -= 65;
    } else {
        columna -= 97;
    }

    //Movimiento tipo caballo
    int difHorizontal = absoluto(fila - filaActual);
    int difVertical = absoluto(columna - columnaActual);
    if ( !(difHorizontal == 1 && difVertical == 2)
            && !(difHorizontal == 2 && difVertical == 1) ) {
        return false;
    }

    return true;
}
