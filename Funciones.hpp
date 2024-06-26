#include <iostream>  //Es para la entrada y salida estandar
#include <vector>  // Se utiliza para el contenedor del vector
#include <string>  //Para manejar cadenas de texto 
#include <cstdlib> // Sirve para funciones generales de la maquina tales como rand() y srand() posiciones aleatorias
#include <ctime>   //Nos ayuda para obtener el tiempo actual
#include <fstream> //Nos sirive para manejar archivo.txt
using namespace std; 
//Declaración de la función
struct Participant { 
    string Name;
    int SCORE;
};

bool Tableroempate(char Tablero[][3]){   //Es para verificar si hay un empate sea de jugador vs jugador o Vsmaquina

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
// Imprime las lineas horizontales del tablero del juego
void ImpriTablero(char Tablero[][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << "| " << Tablero[i][j] << " ";
        }
        cout << "|\n";
        cout << "-------------\n";
    }
}

// Verifica el ganador en diferentes posiciones del tablero sea diagonal, horizontal o vertical

bool VerifiGANADOR(char Tablero[][3], char Jugador) {
    for (int i = 0; i < 3; ++i) {
        if (Tablero[i][0] == Jugador && Tablero[i][1] == Jugador && Tablero[i][2] == Jugador)
            return true;
        if (Tablero[0][i] == Jugador && Tablero[1][i] == Jugador && Tablero[2][i] == Jugador)
            return true;
    }
    if (Tablero[0][0] == Jugador && Tablero[1][1] == Jugador && Tablero[2][2] == Jugador)
        return true;
    if (Tablero[0][2] == Jugador && Tablero[1][1] == Jugador && Tablero[2][0] == Jugador)
        return true;
    
    return false;
}

