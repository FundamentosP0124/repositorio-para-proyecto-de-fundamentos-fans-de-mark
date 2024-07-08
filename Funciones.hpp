#include <iostream>  //Es para la entrada y salida estandar
#include <vector>  // Se utiliza para almacenar datos que ingresamos dentro del vector pero se necesita la libreria iostream
#include <string>  //Para manejar cadenas de texto 
#include <cstdlib> // Sirve para funciones generales de la maquina tales como rand() y srand() posiciones aleatorias
#include <ctime>   //Nos ayuda para obtener el tiempo actual
#include <fstream> //Nos sirve para manejar archivo.txt
#include <limits> //Para numeric_limits
using namespace std; 
//Declaración de la función
struct Participant { 
    string Name;
    int SCORE;
};

bool Tableroempate(char Tablero[][3])  //Es para verificar si hay un empate sea de jugador vs jugador o Vsmaquina
{   

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
        for (int j = 0; j < 3; ++j)
        {
            cout << "| " << Tablero[i][j] << " ";
        }
        cout << "|\n";
        cout << "-------------\n";
    }
}

// Verifica el ganador en diferentes posiciones del tablero sea diagonal, horizontal o vertical

bool VerifiGANADOR(char Tablero[][3], char Jugador) 
{
    for (int i = 0; i < 3; ++i) 
    {
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
    char Tablero[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};           //Pair contendra tanto como vector y bool
    char TURNO = 'X';               //Declaramos 3 variables
    string GANADOR = "";   
    string PERDEDOR = "";


    do
    {
        int Fila, Columna;               //Declaración de las variables que van impresión del tablero
        ImpriTablero(Tablero);

        
        if (TURNO == 'X' || !VSmaquina)    //Los turnos que tendran los jugadores tanto como la maquina al ingresar sus posiciónes
        {
            cout << "El Turno de " << (TURNO == 'X' ? Usuario_1 : Usuario_2) << " (" << TURNO << "):\n";
            cout << "Ingrese la fila (1-3) y la columna (1-3): ";
            cin >> Fila >> Columna;

            //Las Fila-- y Columna-- reducen el valor de Fila y Columna en 1, respectivamente. Este tipo de operaciones es común en bucles 

            Fila--;
            Columna--;
            
            //Verifica si las posiciones en el tablero si es diferente de un espacio en blanco

            if (Tablero[Fila][Columna] != ' ')
            {
                cout << " |=|Posicion ocupada o Invalida.|=|\n";
                continue;
            }
            Tablero[Fila][Columna] = TURNO;
        }
        else                            //Es cuando el jugador haga el su movimiento sera el turno de la maquina en el tablero
        {
            MovimientoMaquina(Tablero);
            cout << "La maquina ha hecho su movimiento.\n";
        }                             //Es para verificar el ganador al momento de terminar una partida 

        if (VerifiGANADOR(Tablero, TURNO))
        {
            ImpriTablero(Tablero);
            GANADOR = (TURNO == 'X' ? Usuario_1 : Usuario_2);
            PERDEDOR = (TURNO == 'X' ? Usuario_2 : Usuario_1);
            cout << "<||>'El jugador " << GANADOR << " (" << TURNO << ") ha ganado'<||>\n";

            //Busca un ganador en la lista de participantes y incrementa su puntaje al que representa ganador y al perdedor

            for (auto &p : Participantes)
            {
                if (p.Name == GANADOR)
                {
                    p.SCORE++;
                    return {GANADOR, PERDEDOR};
                }
            }                                      //En este código agrega el par que es Ganador 1 al vector Participante
            Participantes.push_back({GANADOR, 1}); //y luego lo imprime los participantes
            break;

        } 
           //Altenar el valor del turno entre 'X' Y 'O'
        TURNO = (TURNO == 'X' ? 'O' : 'X');

        // Función si hay empate en el juego
        if (Tableroempate(Tablero))
        {
            ImpriTablero(Tablero);
            cout << "<||>\n 'El juego a terminado en empate' <||>\n";
            return {"Empate", "Empate"};
        }
   
    }while(true);

    cout << "'Gracias por jugar'\n";
    return {GANADOR, PERDEDOR};

}


