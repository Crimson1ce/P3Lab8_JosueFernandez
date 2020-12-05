/* 
 * File:   Torre.cpp
 * Author: Josue_Fernandez
 * 
 * Created on 04 de diciembre de 2020
 */

#include "Torre.h"
#include "Pieza.h"
#include "Tablero.h"
#include <string>
using std::string;

Torre::Torre(bool esBlanca) : Pieza(esBlanca, (esBlanca ? 7 : 0), (esBlanca ? 0 : 7)) {
    if (esBlanca) {
        caracter = 'T';
    } else {
        caracter = 't';
    }
}

Torre::Torre(const Torre& orig) {
}

Torre::~Torre() {
}

bool Torre::validarMovimiento(string coordenadas, Tablero tablero) {
 
    if (!Pieza::validarMovimiento(coordenadas, tablero)) {
        return false;
    }

    // El ingreso es de 1 a 8, pero la matriz está al revés de 0 a 7
    int fila = (int) coordenadas[5];
    //Columna se representa por un caracter
    int columna = (int) coordenadas[4];

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

    //Movimiento torre
    int difHorizontal = fila - filaActual;
    int difVertical = columna - columnaActual;
    if (difHorizontal != 0 && difVertical != 0) {
        return false;
    }
    
    setNextFila(fila);
    setNextColumna(columna);
    
    return true;
    
}

Torre::Torre() : Pieza() {

}
