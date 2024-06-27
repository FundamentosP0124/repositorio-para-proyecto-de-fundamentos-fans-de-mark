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

        switch (opcion)      
        {
        case 1:          // creacion del archivo txt
        
            cout << "\n=== Puntuaciones ===\n";
            ofstream Puntuacionarchivo;
            Puntuacionarchivo.open("Puntuaciones.txt", ios::out);
            if (Puntuacionarchivo.fail())      // verificando posible error de apertura
            {

                cout << "No se pudo abrir el archivo puntuacion. ";
                exit(1);
            }
            break;

        }

        } while (opcion != 6);
    
    return 0;
}