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
    Tablero(int);
    //Constructor de copia
    Tablero(const Tablero& orig);
    //Destructor
    virtual ~Tablero();
    
    //Libera memoria
    void liberarMemoria();
    //Crea un nuevo tablero
    char** crearTablero();
    //Imprime el tablero actual
    void imprimirTablero();
    //Getter de la posicion del tablero
    char getCharCasilla(int,int);
    //Retorna si la casilla está siendo atacada por el contrario
    bool esAtacada(int,int,bool);
    
private:
    Pieza** tablero;
    int size;
    
    Rey reyBlanco;
    Rey reyNegro;
    Pieza piezaBlanca;
    Pieza piezaNegra;
    
};

#endif /* TABLERO_H */

