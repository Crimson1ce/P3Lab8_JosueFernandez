/* 
 * File:   Partida.cpp
 * Author: Josue_Fernandez
 * 
 * Created on 04 de diciembre de 2020
 */

#include "Partida.h"

#include <string>
using std::string;

#include <vector>
using std::vector;

#include "Tablero.h"
#include "Pieza.h"
#include "PiezaNula.h"

#include <fstream>
using std::ifstream;
using std::ofstream;

#include <iostream>
using std::ios;
using std::cout;
using std::cin;
using std::endl;

Partida::Partida(string nombrePartida, int opcionPieza) {
    nombre = nombrePartida;
    turnoBlancas = true;
    switch (opcionPieza) {
        case 1: //Torre
            tipoPieza = "Torre";
            break;
        case 2:
            tipoPieza = "Caballo";
            break;
        case 3:
            tipoPieza = "Alfil";
            break;
        case 4:
            tipoPieza = "Reina";
            break;
        case 5:
            tipoPieza = "Peon";
            break;
        default:
            tipoPieza = "Peon";
            break;
    }
    tablero = Tablero(opcionPieza);
}

Partida::Partida(const Partida& orig) {
}

Partida::~Partida() {
    guardarPartida();
}

void Partida::guardarPartida() {
    ofstream archivo;
    archivo.open("bitacoraPartidas.txt", ios::app | ios::out);
    if (archivo.is_open()) {
        archivo << nombre << "\n";
        archivo << tipoPieza << "\n";
        for (int i = 0; i < movimientos.size(); i++) {
            archivo << movimientos[i] << ";";
        }
        archivo << '\n';
    }
    archivo.close();
}

Partida::Partida() {

}

vector<string> Partida::getMovimientos() {
    return movimientos;
}

void Partida::jugar() {
    // (turnoBlancas ? "blancas" : "negras" );
    string ingreso;
    do {

        tablero.imprimirTablero();
        cout << "\nEs el turno de las " << (turnoBlancas ? "blancas" : "negras") << endl;
        cout << "Ingresa la pieza que deseas mover. ( Ejemplo: [e1,e2] ): ";
        cin >> ingreso;
        
        int* coordinates = confirmar(ingreso);
        while(coordinates == NULL
                || tablero.tablero[coordinates[0]][coordinates[1]].getCaracter() == ' '
                || tablero.tablero[coordinates[0]][coordinates[1]].isBlanca() != turnoBlancas 
                || tablero.tablero[coordinates[0]][coordinates[1]].validarMovimiento(ingreso,tablero)
                ){
            
            cout << "Ingreso no valido. Ingresa la pieza que deseas mover. ( Ejemplo: [e1,e2] ): ";
            cin >> ingreso;
            coordinates = confirmar(ingreso);
        }
        
        //Movemos la pieza
        Pieza pieza  = tablero.tablero[coordinates[0]][coordinates[1]];
        tablero.tablero[coordinates[0]][coordinates[1]] = PiezaNula();
        tablero.tablero[ pieza.getNextFila() ][ pieza.getNextColumna() ] = pieza;
        pieza.setNextColumna(-1);
        pieza.setNextFila(-1);
        
        delete [] coordinates;
        coordinates = NULL;
        
        this->movimientos.push_back(ingreso);
        
        turnoBlancas = !turnoBlancas;
    } while (preguntarSeguir(turnoBlancas));
}

bool Partida::preguntarSeguir(bool blancas) {
    if (blancas == false) {
        return true;
    }

    char opcion = '?';
    do {
        cout << "\nDesea seguir jugando? (S/N): ";
    } while (opcion != 's' && opcion != 'S' && opcion != 'n' && opcion != 'N');

    if (opcion == 's' || opcion == 'S') {
        return true;
    }
    return false;
}

int* Partida::confirmar(string entrada){
    int * coordenadas = new int[2];
    
    if (entrada.length() != 7) NULL;
    if (entrada[0] != '[' || entrada[3] != ',' || entrada[6] != ']') return NULL;
    // El ingreso es de 1 a 8, pero la matriz está al revés de 0 a 7
    int fila = (int) entrada[2];
    //Columna se representa por un caracter
    int columna = (int) entrada[1];

    //Validacion fila
    if(fila < 49 || fila > 56){ 
        //Debe ser un dígito
        return NULL;
    }
    
    fila = 8 - (fila - 48);
    
    //Validacion columna
    if (columna < 65 || columna > 104 || (columna > 72 && columna < 97)) {
        //Debe ser una letra, A-H o a-h
        return NULL;
    }
    
    if(columna < 73){
        columna -= 65;
    } else {
        columna -= 97;
    }
    
    coordenadas[0] = fila;
    coordenadas[1] = columna;
    
    return coordenadas;
}