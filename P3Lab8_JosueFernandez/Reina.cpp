/* 
 * File:   Reina.cpp
 * Author: Josue_Fernandez
 * 
 * Created on 04 de diciembre de 2020
 */

#include "Reina.h"
#include "Pieza.h"
#include "Tablero.h"
#include <string>
using std::string;

Reina::Reina(bool esBlanca) : Pieza(esBlanca, (esBlanca ? 7 : 0), 3) {
    if (esBlanca) {
        caracter = 'Q';
    } else {
        caracter = 'q';
    }
}

Reina::Reina(const Reina& orig) {
}

Reina::~Reina() {
}

bool Reina::validarMovimiento(string coordenadas, Tablero tablero) {
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

    //Movimiento tipo torre
    int difHorizontal = fila - filaActual;
    int difVertical = columna - columnaActual;
    if (difHorizontal != 0 && difVertical != 0) {
        //Movimiento alfil
        if (difHorizontal != difVertical && difHorizontal != -difVertical) {
            return false;
        }
    }
    
    setNextFila(fila);
    setNextColumna(columna);

    return true;
}

Reina::Reina() : Pieza() {

}
