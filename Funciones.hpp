#include <iostream>  //Es para la entrada y salida estandar
#include <vector>  // Se utiliza para almacenar datos que ingresamos dentro del vector pero se necesita la libreria iostream
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
void ImpriTablero(char Tablero[][3]) 
{   cout << "-------------\n";                      //Modificación del 'Tablero'
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

//Movimientos que realiza la maquina en el tablero al momento de jugar contra el jugador

void MovimientoMaquina(char Tablero[][3])
{
    srand(time(0));                       //Tiempo que toma la maquina al ingresar un dato al momento de jugar 
    int Fila, Columna;                    //El dato segun el tiempo(segundos) cambiando de posisiones aleatorias cada vez quen el programa se ejecute 
    do
    {
        Fila = rand() % 3;                     //Adentro del "do" esto se trabaja en matrices o estructura datos que tiene un tamaño fijo 
        Columna = rand() % 3;                  //Generando un rango aleatorio entre 0 y 2
    } while (Tablero[Fila][Columna] != ' ');
    Tablero[Fila][Columna] = 'O';
}

//Realiza la selección de ganador y perdedor 

pair<string, string> JUGAR(string Usuario_1, string Usuario_2, vector<Participant> &Participantes, bool VSmaquina)
{
    char Tablero[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    char TURNO = 'X';
    string GANADOR = "";
    string PERDEDOR = "";
}
