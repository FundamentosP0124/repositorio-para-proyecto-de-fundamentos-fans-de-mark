#include <iostream>  //Es para la entrada y salida estandar
#include <vector>  // Se utiliza para el contenedor del vector
#include <string>  //Para manejar cadenas de texto 
#include <cstdlib> // Sirve para funciones generales de la maquina tales como rand() y srand() posiciones aleatorias
#include <ctime>   //Nos ayuda para obtener el tiempo actual

using namespace std; 

struct Participant {
    string Name;
    int SCORE;
};

bool Tableroempate(char Tablero[][3]){

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(Tablero[i][j] == ' ')
            {
                return false;
            }
                    
        }   
    }
    return true;
}

void ImpriTablero(char Tablero[][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << "| " << Tablero[i][j] << " ";
        }
        cout << "|\n";
        cout << "-------------\n";
    }
}
