/* 
 * File:   Tablero.h
 * Author: Josue_Fernandez
 *
 * Created on 04 de diciembre de 2020
 */

#ifndef TABLERO_H
#define TABLERO_H

class Tablero {
public:
    //Constructor
    Tablero();
    //Constructor de copia
    Tablero(const Tablero& orig);
    //Destructor
    virtual ~Tablero();
    
    //Libera memoria
    void liberarMemoria;
    //Crea un nuevo tablero
    char** crearTablero();
    
private:
    char** tablero;
};

#endif /* TABLERO_H */

