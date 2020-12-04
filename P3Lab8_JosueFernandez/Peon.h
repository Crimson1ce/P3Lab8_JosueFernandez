/* 
 * File:   Peon.h
 * Author: Josue_Fernandez
 *
 * Created on 04 de diciembre de 2020
 */

#ifndef PEON_H
#define PEON_H

class Peon : public Pieza{
public:
    //Constructor
    Peon(bool);
    //Constructor de copia
    Peon(const Peon& orig);
    //Destructor
    virtual ~Peon();
    
    //Método para validar el movimiento del rey
    bool validarMovimiento(string,Tablero);
    
private:

};

#endif /* PEON_H */