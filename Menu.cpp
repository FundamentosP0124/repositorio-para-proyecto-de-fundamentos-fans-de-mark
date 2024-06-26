#include <Funciones.hpp>

int main() {
    int opcion;              // declaracion de variables de tipo entero y de tipo string
    string Usuario_1, Usuario_2;
    pair<string, string> RESULT;
    vector<Participant> Participantes;
    vector<string> JUEGOS;

    do                  // opciones del menu
    {   
        cout << "\n                    |||JUEGO X ^ O|||\n";
        cout << "\n      <=||=||=> OPCIONES DEL JUEGO <=||=||=>\n\n";
        cout << "1. Inscribir Participante\n";
        cout << "2. Listas de Puntuaciones de 'jugadores'\n";
        cout << "3. Jugar\n";
        cout << "4. Mostrar Ganador o Empate\n";
        cout << "5. Ayuda\n";
        cout << "6. Integrantes del Proyecto\n";
        cout << "7. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

    } while (opcion != 7);
    
    return 0;
}