/* 
 * File:   Pieza.h
 * Author: Josue_Fernandez
 *
 * Created on 04 de diciembre de 2020
 */

#ifndef PIEZA_H
#define PIEZA_H

#include <string>
using std::string;

class Tablero;

class Pieza {
public:
    //Constructor
    Pieza(bool,int,int);
    //Constructor de copia
    Pieza(const Pieza& orig);
    //Destructor
    virtual ~Pieza();
    
    //Método para validar el movimiento de las piezas
    virtual bool validarMovimiento(string,Tablero);
    
protected:
    int filaActual;
    int columnaActual;
    bool esBlanca;
    char caracter;
    
    friend class Tablero;
    
};

#endif /* PIEZA_H */

