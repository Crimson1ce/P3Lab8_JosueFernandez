/* 
 * File:   Tablero.cpp
 * Author: Josue_Fernandez
 * 
 * Created on 04 de diciembre de 2020
 */

#include "Tablero.h" 
#include "Rey.h"
#include "Reina.h"
#include "Peon.h"
#include "Torre.h"
#include "Alfil.h"
#include "Caballo.h"
#include "PiezaNula.h"

#include <iostream>
using std::cout;
using std::endl;

Tablero::Tablero(int pieza) {
    
    //Torre
    //Caballo
    //Alfil
    //Reina
    //Peón
    
    size = 8;
    
    reyBlanco = new Rey(true);
    reyNegro = new Rey(false);
    
    tablero = crearTablero();
    
    switch(pieza){
        case 1: //Torre
            piezaBlanca = new Torre(true);
            piezaNegra = new Torre(false);
            break;
        case 2:
            piezaBlanca = new Caballo(true);
            piezaNegra = new Caballo(false);
            break;
        case 3:
            piezaBlanca = new Alfil(true);
            piezaNegra = new Alfil(false);
            break;
        case 4:
            piezaBlanca = new Reina(true);
            piezaNegra = new Reina(false);
            break;
        case 5:
            piezaBlanca = new Peon(true);
            piezaNegra = new Peon(false);
            break;
        default:
            piezaBlanca = new Peon(true);
            piezaNegra = new Peon(false);
            break;
    }
    
}

Tablero::Tablero(const Tablero& orig) {
    reyBlanco = orig.reyBlanco;
    reyNegro = orig.reyNegro;
    piezaBlanca = orig.piezaBlanca;
    piezaNegra = orig.piezaNegra;
    size = 8;
    crearTablero();
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            this->tablero[i][j] = orig.tablero[i][j];
        }
    }
}

Tablero::~Tablero() {
    liberarMemoria();
    delete reyBlanco;
    delete reyNegro;
    delete piezaBlanca;
    delete piezaNegra;
}

Pieza** Tablero::crearTablero() {
    
    if(tablero != NULL){
        liberarMemoria();
    }
    
    Pieza** tablero = new Pieza*[8];
    for (int i = 0; i < 8; i++) {
        tablero[i] = new Pieza[8];
        for (int j = 0; j < size; j++) {
            tablero[i][j] = PiezaNula();
        }
    }
    return tablero;
}

char Tablero::getCharCasilla(int fila, int columna) {
    if(fila > 0 && fila < 9 && columna > 0 && columna < 9){
        return tablero[fila][columna].caracter;
    }
    return '?';
}

void Tablero::imprimirTablero() {
    if(tablero != NULL){
        cout << "+---+---+---+---+---+---+---+---+\n";
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                cout << "| " <<  tablero[i][j].caracter << " "; 
            }
            cout <<"|\n";
            cout << "+---+---+---+---+---+---+---+---+\n";
        }
    }
}

void Tablero::liberarMemoria() {
    if(tablero != NULL){
        for (int i = 0; i < 8; i++) {
            if(tablero[i] != NULL){
                delete [] tablero[i];
                tablero[i] = NULL;
            }
        }
        delete [] tablero;
        tablero = NULL;
    }
}

bool Tablero::esAtacada(int fila, int columna, bool esBlanca) {
    
    string coordenadas = "[a1,__]";
    
    columna += 65;
    fila = (8 - fila) + 48;
    coordenadas[4] = (char) columna;
    coordenadas[5] = (char) fila;
    
    if(esBlanca){ //La pieza atacada es blanca
        
        //Vamos a verificar el movimiento para las piezas negras
        if (piezaNegra->validarMovimiento(coordenadas,(*this))){
            return true;
        } else if (reyNegro->validarMovimiento(coordenadas,(*this))) {
            return true;
        }
        
    } else { //La pieza atacada es negra
        
        //Vamos a verificar el movimiento para las piezas blancas
        if (piezaBlanca->validarMovimiento(coordenadas,(*this))){
            return true;
        } else if (reyBlanco->validarMovimiento(coordenadas,(*this))) {
            return true;
        }
        
    }
    return false;
}

Tablero::Tablero() {

}
