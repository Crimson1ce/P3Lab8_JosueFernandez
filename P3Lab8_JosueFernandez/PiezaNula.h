/* 
 * File:   PosicionFueraDeRango.h
 * Author: Josue_Fernandez
 *
 * Created on 04 de diciembre de 2020
 */

#ifndef PIEZANULA_H
#define PIEZANULA_H

#include "Pieza.h"
#include "Tablero.h"
#include <string>
using std::string;

class PiezaNula : public Pieza {
public:
    PiezaNula();
    PiezaNula(const PiezaNula& orig);
    virtual ~PiezaNula();
    
    //Siempre retorna falso
    bool validarMovimiento(string,Tablero);
    
private:

};

#endif /* POSICIONFUERADERANGO_H */

