/* 
 * File:   Caballo.h
 * Author: Josue_Fernandez
 *
 * Created on 04 de diciembre de 2020
 */

#ifndef CABALLO_H
#define CABALLO_H

#include "Pieza.h"
#include "Tablero.h"
#include <string>
using std::string;

class Caballo : public Pieza{
public:
    Caballo();
    Caballo(bool);
    Caballo(const Caballo& orig);
    virtual ~Caballo();
    
    //Método para validar el movimiento del caballo
    bool validarMovimiento(string, Tablero);
    
private:
    int absoluto(int);

};

#endif /* CABALLO_H */

