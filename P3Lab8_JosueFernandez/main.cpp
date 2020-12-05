/* 
 * Laboratorio 8, Programación 3
 * 
 * File:   main.cpp
 * Author: Josue_Fernandez
 *
 * Created on 04 de diciembre de 2020
 */

#include <cstdlib>

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <fstream>
using std::ifstream;

#include <vector>
using std::vector;

//#include "Alfil.h"
//#include "Caballo.h"
//#include "Reina.h"
//#include "Rey.h"
//#include "Peon.h"
//#include "Torre.h"
#include "Partida.h"
#include "Pieza.h"
#include "PiezaNula.h"
#include "Tablero.h"


vector<Partida*> partidas;

//Prototipos

/* Muestra el menú */
int menu(); 
/* Carga las partidas */
void cargarPartidas();
/* Libera la memoria del vector de partidas */
void liberarMemoriaPartidas();

/*
 * 
 */
int main(int argc, char** argv) {
    
    int opcion = 1;
    
    int tipoPieza = 0;
    string nombrePartida = "";
    
    while (opcion) {

        switch (opcion = menu()) {
            case 0:
            {
                cout << "Nos vemos!\n";
                break;
            }
            case 1: // Jugar partida
            {
                cout << "JUGAR PARTIDA\n\n";
                
                cout << "Ingrese un nombre para la partida: ";
                cin >> nombrePartida;
                cout << endl;
                
                cout << "Piezas a elegir:\n";
                cout << "\t1. Torre\n";
                cout << "\t2. Caballo\n";
                cout << "\t3. Alfil\n";
                cout << "\t4. Reina\n";
                cout << "\t5. Peon\n";
                cout << "Ingrese la pieza con la que quiere jugar: ";
                cin >> tipoPieza;
                while(tipoPieza < 1 || tipoPieza > 5){
                    cout << "Ingrese una pieza valida: ";
                    cin >> tipoPieza;
                }
                cout << endl;
                
                cout << "Hace esto\n";
                Partida* partida = new Partida(nombrePartida,tipoPieza);
                cout << "Y esto\n";
                partida->jugar();
                cout << "Esto no\n";
                partida->guardarPartida();
                partidas.push_back(partida);
                partida = NULL;
            }
            case 2: // Recrear partida
            {
                
            }
        }
        cout << endl;
    }
    
    liberarMemoriaPartidas();
    return 0;
}

/* Muestra el menú */
int menu() {
    int opcion = 0;
    cout << "\n\tApunta Chess - Aprende Ajedrez!" << endl << endl
            << "1. Jugar partida" << endl
            << "2. Recrear partida" << endl
            << "0. Salir" << endl;

    cout << "Ingrese una opcion: ";
    cin >> opcion;
    while (opcion < 0 || opcion > 2) {
        cout << "Ingrese una opcion valida: ";
        cin >> opcion;
    }
    cout << endl;
    return opcion;
}

/* Carga las partidas */
void cargarPartidas(){
    ifstream archivo("bitacoraPartidas.txt");
    
    if(archivo.is_open()){
        
        liberarMemoriaPartidas();
        
        string nombrePartida;
        string pieza;
        string todosMovimientos;
        while(archivo >> nombrePartida){
            archivo >> pieza;
            archivo >> todosMovimientos;
            int tipo;
            if(pieza.compare("Torre") == 0){
                tipo = 1;
            } else if (pieza.compare("Caballo") == 0){
                tipo = 2;
            } else if (pieza.compare("Alfil") == 0){
                tipo = 3;
            } else if (pieza.compare("Reina") == 0){
                tipo = 4;
            } else if (pieza.compare("Peon") == 0){
                tipo = 5;
            }
            
            Partida* partida = new Partida(nombrePartida,tipo);
            string movimiento = "_______";
            for (int i = 0; i < todosMovimientos.size(); i++) {
                movimiento[(i+1)%8 - 1] = todosMovimientos[i]; i++;
                movimiento[(i+1)%8 - 1] = todosMovimientos[i]; i++;
                movimiento[(i+1)%8 - 1] = todosMovimientos[i]; i++;
                movimiento[(i+1)%8 - 1] = todosMovimientos[i]; i++;
                movimiento[(i+1)%8 - 1] = todosMovimientos[i]; i++;
                movimiento[(i+1)%8 - 1] = todosMovimientos[i]; i++;
                movimiento[(i+1)%8 - 1] = todosMovimientos[i]; i++;
                
                partida->getMovimientos().push_back(movimiento);
                
            }
            partidas.push_back(partida);
        }
    }
    
    archivo.close();
}

void liberarMemoriaPartidas(){
    for (int i = 0; i < partidas.size(); i++) {
        delete partidas[i];
    }
    partidas.clear();
}