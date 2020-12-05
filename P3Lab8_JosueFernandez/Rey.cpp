/* 
 * File:   Rey.cpp
 * Author: Josue_Fernandez
 * 
 * Created on 04 de diciembre de 2020
 */

#include "Rey.h"
#include "Pieza.h"
#include "Tablero.h"
#include <string>
using std::string;

Rey::Rey(bool esBlanco) : Pieza(esBlanco, (esBlanco ? 7 : 0), 4), estaEnJaque(false) {
    if (esBlanco) {
        caracter = 'K';
    } else {
        caracter = 'k';
    }
}

Rey::Rey(const Rey& orig) {
}

Rey::~Rey() {
}

bool Rey::validarMovimiento(string coordenadas, Tablero tablero) {

    if ( ! Pieza::validarMovimiento(coordenadas, tablero)){
        return false;
    }
    
    // El ingreso es de 1 a 8, pero la matriz está al revés de 0 a 7
    int fila = (int) coordenadas[5];
    //Columna se representa por un caracter
    int columna = (int) coordenadas[4];

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
    
    if(tablero.esAtacada(fila,columna,esBlanca)){
        return false;
    }
    

    setNextFila(fila);
    setNextColumna(columna);
    
    //Entonces sí se puede realizar e movimiento
    return true;
}

Rey::Rey() : Pieza() {

}
