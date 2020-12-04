/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PosicionFueraDeRango.h
 * Author: IT
 *
 * Created on 04 de diciembre de 2020, 03:02 PM
 */

#ifndef PIEZANULA_H
#define PIEZANULA_H

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

