/* 
 * File:   Rey.h
 * Author: Josue_Fernandez
 *
 * Created on 04 de diciembre de 2020
 */

#ifndef REY_H
#define REY_H

#include "Pieza.h"
#include "Tablero.h"
#include <string>
using std::string;

class Rey : public Pieza {
public:
    //Constructor
    Rey(bool);
    //Constructor de copia
    Rey(const Rey& orig);
    //Destructor
    virtual ~Rey();
    
    //Método para validar el movimiento del rey
    bool validarMovimiento(string,Tablero);
    
private:
    bool estaEnJaque;
};

#endif /* REY_H */

