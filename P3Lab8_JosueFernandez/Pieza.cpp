/* 
 * File:   Pieza.cpp
 * Author: Josue_Fernandez
 * 
 * Created on 04 de diciembre de 2020
 */

#include "Pieza.h"
#include "Tablero.h"

Pieza::Pieza(bool esBlanca, int fila, int columna) : esBlanca(esBlanca), filaActual(fila), columnaActual(columna) {
    caracter = '_';
}

Pieza::Pieza(const Pieza& orig) {
}

Pieza::~Pieza() {
}

bool Pieza::validarMovimiento(string coordenadas, Tablero tablero) {
    
    //Validaciones
    
    if (coordenadas.length() != 7) return false;
    if (coordenadas[0] != '[' || coordenadas[3] != ',' || coordenadas[6] != ']') return false;
    // El ingreso es de 1 a 8, pero la matriz está al revés de 0 a 7
    int fila = (int) string[5];
    //Columna se representa por un caracter
    int columna = (int) string[4];

    //Validacion fila
    if(fila < 49 || fila > 56){ 
        //Debe ser un dígito
        return false;
    }
    
    fila = 8 - (fila - 48);
    
    //Validacion columna
    if (columna < 65 || columna > 104 || (columna > 72 && columna < 97)) {
        //Debe ser una letra, A-H o a-h
        return false;
    }
    
    if(columna < 73){
        columna -= 65;
    } else {
        columna -= 97;
    }
    
    int superior;
    int inferior;
    if (esBlanca) { 
        //Si nuestra pieza es blanca, verificamos que la casilla opcupada no sea
        //blanca. Si lo es, no se puede mover.
        superior = 90;
        inferior = 65;
    } else {
        superior = 97;
        inferior = 122;
    }
    
    //Si la casilla está ocupada
    char casilla = tablero.getCharCasilla(fila,columna);
    if( casilla != ' ' ){  //Si la casilla está ocupada
        if( (int)casilla >= inferior && (int)casilla <= superior ){
            return false; //Es de nuestro equipo, no la podemos comer
        }
    }
    
    //No se puede mover a la casilla en que ya se está
    if(fila == filaActual && columna == columnaActual){
        return false;
    }

    return true;
}
