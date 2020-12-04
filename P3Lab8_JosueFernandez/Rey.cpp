/* 
 * File:   Rey.cpp
 * Author: Josue_Fernandez
 * 
 * Created on 04 de diciembre de 2020
 */

#include "Rey.h"
#include "Pieza.h"

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
    
    if(tablero.esAtacada(fila,columna,esBlanca)){
        return false;
    }
    
    /*
    //Ya tenemos la fila y columna
    if( fila - filaActual >= -1 && fila - filaActual <= 1 
        && columna - columnaActual >= -1 && columna - columnaActual <= 1 ){
        
        filaActual = fila;
        columnaActual = columna;
    }
     */

    //Entonces sí se puede realizar e movimiento
    return true;
}
