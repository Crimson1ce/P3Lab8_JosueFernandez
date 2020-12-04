/* 
 * File:   Torre.h
 * Author: Josue_Fernandez
 *
 * Created on 04 de diciembre de 2020
 */

#ifndef TORRE_H
#define TORRE_H

#include "Pieza.h"
#include "Tablero.h"
#include <string>
using std::string;


class Torre : public Pieza {
public:
    Torre(bool);
    Torre(const Torre& orig);
    virtual ~Torre();
    
    //Método para validar el movimiento de la torre
    bool validarMovimiento(string, Tablero);
    
private:

};

#endif /* TORRE_H */

