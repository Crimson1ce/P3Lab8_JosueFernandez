/* 
 * File:   PosicionFueraDeRango.cpp
 * Author: IT
 * 
 * Created on 04 de diciembre de 2020, 03:02 PM
 */

#include "PiezaNula.h"
#include "Pieza.h"
#include "Tablero.h"
#include <string>
using std::string;

PiezaNula::PiezaNula() : Pieza() {
    caracter = ' ';
    filaActual = -1;
    columnaActual = -1;
    esBlanca = false;
}

PiezaNula::PiezaNula(const PiezaNula& orig) {
}

PiezaNula::~PiezaNula() {
}

bool PiezaNula::validarMovimiento(string coordenadas, Tablero tablero) {
    return false;
}
