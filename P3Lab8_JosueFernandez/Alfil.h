/* 
 * File:   Alfil.h
 * Author: Josue_Fernandez
 *
 * Created on 04 de diciembre de 2020
 */

#ifndef ALFIL_H
#define ALFIL_H

#include "Pieza.h"
#include "Tablero.h"
#include <string>
using std::string;

class Alfil : public Pieza {
public:
    Alfil();
    //Constructor
    Alfil(bool);
    //Constructor de copia
    Alfil(const Alfil& orig);
    //Destructor
    virtual ~Alfil();

    //Método para validar el movimiento del alfil
    bool validarMovimiento(string, Tablero);

private:

};

#endif /* ALFIL_H */

