/* 
 * File:   Peon.cpp
 * Author: Josue_Fernandez
 * 
 * Created on 04 de diciembre de 2020
 */

#include "Peon.h"
#include "Pieza.h"
#include "Tablero.h"
#include <string>
using std::string;

Peon::Peon(bool esBlanco) : Pieza(esBlanco, (esBlanco ? 6 : 1), 4) {
    if (esBlanco) {
        caracter = 'P';
    } else {
        caracter = 'p';
    }
}

Peon::Peon(const Peon& orig) {
}

Peon::~Peon() {
}

bool Peon::validarMovimiento(string coordenadas, Tablero tablero) {

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

    if (fila != filaActual - (esBlanca ? 1 : -1)) {
        return false;
    }


    if (columna - columnaActual >= -1 && columna - columnaActual <= 1) {
        if (columna != columnaActual) {
            int valor = (int) tablero.getCharCasilla(fila, columna);
            if (valor == ' ') { //Si una casilla diagonal
                return false;
            }
        }
    }
    
    setNextFila(fila);
    setNextColumna(columna);

    return true;
}

Peon::Peon() : Pieza() {

}
