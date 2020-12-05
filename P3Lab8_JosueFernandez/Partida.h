/* 
 * File:   Partida.h
 * Author: Josue_Fernandez
 *
 * Created on 04 de diciembre de 2020
 */

#ifndef PARTIDA_H
#define PARTIDA_H

#include <string>
using std::string;

#include <vector>
using std::vector;

#include "Tablero.h"

class Partida {
public:
    Partida();
    Partida(string, int);
    Partida(const Partida& orig);
    virtual ~Partida();
    
    void guardarPartida();
    
    vector<string> getMovimientos();
    
    void jugar();
    
private:
    string nombre;
    string tipoPieza;
    vector<string> movimientos;
    bool turnoBlancas;
    Tablero tablero;
    
    bool preguntarSeguir(bool);
    int* confirmar(string entrada);
    
};

#endif /* PARTIDA_H */

