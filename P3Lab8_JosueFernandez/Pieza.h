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

class Pieza {
public:
    //Constructor
    Pieza();
    //Constructor de copia
    Pieza(const Pieza& orig);
    //Destructor
    virtual ~Pieza();
    
    //Método virtual puro para validar el movimiento de las piezas
    bool validarMovimiento(string) = 0;
    
private:

};

#endif /* PIEZA_H */

