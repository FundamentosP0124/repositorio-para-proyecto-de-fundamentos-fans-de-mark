#include <Funciones.hpp>

int main() {
    int opcion;              // declaracion de variables de tipo entero y de tipo string
    string Usuario_1, Usuario_2;
    pair<string, string> RESULT;
    vector<Participant> Participantes;
    vector<string> JUEGOS;

    do                  // opciones del menu
    {   
        cout << "\n                    <====JUEGO X ^ O====>\n";
        cout << "\n       ====OPCIONES DEL JUEGO====\n\n";
        cout << "1. Listas de Puntuaciones de 'jugadores' en archivo.txt\n";
        cout << "2. Jugar\n";
        cout << "3. Mostrar Ganador o Empate y guardar en .txt\n";
        cout << "4. Ayuda\n";
        cout << "5. Integrantes del Proyecto\n";
        cout << "6. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion)      // switch que evalua la opcion ingresada por el usuario
        {
        case 1:
            cout << "Ingrese el nombre del primer participante: ";
            cin >> Usuario_1;
            cout << "El participante " << Usuario_1 << " A sido inscrito.\n";

            cout << "Ingrese el nombre del segundo participante: ";
            cin >> Usuario_2;
            cout << "El participante " << Usuario_2 << " A sido inscrito.\n";
            break;
        }

    } while (opcion != 7);
    
    return 0;
}