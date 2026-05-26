#include <iostream>
#include <string>

using namespace std;

struct Accion {   // Estructura de la Acción lo que se guarda en la pila

    int idProducto;
    string nombProducto;
    string tipOperacion; 
};

struct NodoPila {   // estructura nodo pila
    Accion dato;
    NodoPila *siguiente;
};

NodoPila *tope = NULL;   // Puntero al tope de la pila que empieza en nulo 
    
void apilarAccion(int id, string nombre, string operacion) {
	cout << endl;
	//creamos nodo
    NodoPila *nuevoNodo = new NodoPila();
    
    nuevoNodo->dato.idProducto = id;  //uso de punteros
    nuevoNodo->dato.nombProducto = nombre;
    nuevoNodo->dato.tipOperacion = operacion;
    
    nuevoNodo->siguiente = tope; // el nuevo nodo apunta a tope
    tope = nuevoNodo; //el nuevo tope es 
    
    cout << "Accion apilada: " << operacion << " de " << nombre << endl;
}

void deshacerUltimo() {
	cout << endl;
    if (tope == NULL) { 
        cout << " No hay acciones para deshacer en la pila. " << endl;
        return;
    }

    NodoPila *aux = tope; 
    Accion ultima = aux->dato;

    cout << " Revirtiendo accion " << ultima.tipOperacion  << " del producto: " << ultima.nombProducto << " (ID: " << ultima.idProducto << ")" << endl;

    tope = tope->siguiente; // El tope baja al siguiente nodo
    delete aux; // Liberar memoria
    cout << "----- Cambio revertido exitosamente. ----------" << endl;
}

	// mostrar estado de la pila
void mostrarPila() {
	cout << endl;
    if (tope == NULL) {
        cout << "[HISTORIAL] La pila de seguridad esta vacia." << endl;
        return;
    }
     
    NodoPila* actual = tope;
    cout << "\n--- HISTORIAL DE ACCIONES  ---" << endl;
    while (actual != NULL) {
        cout << "- [" << actual->dato.tipOperacion << "] Producto: " << actual->dato.nombProducto << endl;
        actual = actual->siguiente; //el puntero avanza al siguiente
    }
}
// MENÚ PRINCIPAL 
int main() {
    int opcion, idTmp; 
    string nomTmp;

    do {
        cout << "\n==============================" << endl;
        cout << "       SISTEMA MINIMARKET  "      << endl;
        cout << "=============================" << endl;
        cout << "1. Registrar Accion (Push)" << endl;
        cout << "2. Deshacer Ultima Accion (Pop)" << endl;
        cout << "3. Ver Historial de la Pila" << endl;
        cout << "4. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese ID del producto: "; cin >> idTmp;
                cout << "Ingrese nombre del producto: "; 
				cin.ignore(); getline(cin, nomTmp);
                apilarAccion(idTmp, nomTmp, "REGISTRO");
                break;
            case 2:
                deshacerUltimo();
                break;
            case 3:
                mostrarPila();
                break;
            case 4:
                cout << "Saliendo del modulo de Pilas..." << endl;
                break;
            default:
                cout << "Opcion invalida." << endl;
        }
    } while (opcion != 4);

    return 0;
}
