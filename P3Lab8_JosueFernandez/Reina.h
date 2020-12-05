/* 
 * File:   Reina.h
 * Author: Josue_Fernandez
 *
 * Created on 04 de diciembre de 2020
 */

#ifndef REINA_H
#define REINA_H

#include "Pieza.h"

#include "Pieza.h"
#include "Tablero.h"
#include <string>
using std::string;

class Reina : public Pieza {
public:
    Reina();
    //Constructor
    Reina(bool);
    Reina(const Reina& orig);
    virtual ~Reina();
    
    //Método para validar el movimiento de la reina
    bool validarMovimiento(string, Tablero);
    
private:

};

#endif /* REINA_H */

