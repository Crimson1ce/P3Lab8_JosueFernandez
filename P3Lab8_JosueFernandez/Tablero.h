/* 
 * File:   Tablero.h
 * Author: Josue_Fernandez
 *
 * Created on 04 de diciembre de 2020
 */

#ifndef TABLERO_H
#define TABLERO_H

#include "Pieza.h"
#include "Rey.h"


class Partida;

class Tablero {
public:
    Tablero();
    //Constructor
    Tablero(int);
    //Constructor de copia
    Tablero(const Tablero& orig);
    //Destructor
    virtual ~Tablero();
    
    //Libera memoria
    void liberarMemoria();
    //Crea un nuevo tablero
    Pieza** crearTablero();
    //Imprime el tablero actual
    void imprimirTablero();
    //Getter de la posicion del tablero
    char getCharCasilla(int,int);
    //Retorna si la casilla está siendo atacada por el contrario
    bool esAtacada(int,int,bool);
    
private:
    Pieza** tablero = NULL;
    int size;
    Pieza * reyBlanco = NULL; 
    Pieza * reyNegro = NULL; 
    Pieza * piezaBlanca = NULL;
    Pieza *  piezaNegra = NULL;
    
    friend class Partida;
    
};

#endif /* TABLERO_H */

