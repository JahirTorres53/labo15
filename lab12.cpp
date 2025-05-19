#include <iostream>
#include <string>
using namespace std;

// Paso 7: Funciones con estilo
string estiloFormal(string r) {
    return "Estimado usuario: " + r;
}

string estiloAmistoso(string r) {
    return "¡Hey! " + r;
}

// Paso 8: Nodo para lista enlazada
struct Nodo {
    string mensaje;
    Nodo* siguiente;
};

// Función para insertar al final de la lista
void insertarAlFinal(Nodo*& cabeza, const string& nuevoMensaje) {
    Nodo* nuevoNodo = new Nodo;
    nuevoNodo->mensaje = nuevoMensaje;
    nuevoNodo->siguiente = nullptr;

    if (cabeza == nullptr) {
        cabeza = nuevoNodo;
    }
    else {
        Nodo* temp = cabeza;
        while (temp->siguiente != nullptr) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevoNodo;
    }
}

// Mostrar lista enlazada
void mostrarLista(Nodo* cabeza) {
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        cout << actual->mensaje << endl;
        actual = actual->siguiente;
    }
}

// Liberar memoria dinámica de la lista
void liberarLista(Nodo*& cabeza) {
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        Nodo* temp = actual;
        actual = actual->siguiente;
        delete temp;
    }
    cabeza = nullptr;
}

int main() {
    // Paso 2: Puntero básico
    int numero = 5;
    int* ptr = &numero;
    cout << "Valor apuntado: " << *ptr << endl;

    // Paso 3: Array de punteros
    const char* respuestas[] = {
        "Hola, ¿en qué puedo ayudarte?",
        "Estoy aprendiendo a responder.",
        "¿Puedes repetir eso?",
        "Consulta aceptada."
    };

    cout << "\nRespuestas usando arreglo:\n";
    for (int i = 0; i < 4; ++i) {
        cout << respuestas[i] << endl;
    }

    // Paso 4: Aritmética de punteros
    const char** p = respuestas;
    cout << "\nRespuestas usando aritmética de punteros:\n";
    for (int i = 0; i < 4; ++i) {
        cout << *(p + i) << endl;
    }

    // Paso 5: sizeof
    cout << "\nTamaños en bytes:\n";
    cout << "sizeof(int): " << sizeof(int) << endl;
    cout << "sizeof(ptr): " << sizeof(ptr) << endl;

    // Paso 6: Relación entre arreglos y punteros
    int datos[] = { 1, 2, 3 };
    int* pd = datos;
    cout << "\nAcceso a arreglo con punteros:\n";
    cout << "datos[1]: " << datos[1] << endl;
    cout << "pd[1]: " << pd[1] << endl;
    cout << "*(pd + 2): " << *(pd + 2) << endl;

    // Paso 7: Apuntadores a funciones
    string(*responder)(string);
    bool modoFormal = false;

    if (modoFormal) {
        responder = estiloFormal;
    }
    else {
        responder = estiloAmistoso;
    }

    cout << "\nEstilo de respuesta:\n";
    cout << responder("bienvenido al sistema.") << endl;

    // Paso 8: Lista enlazada simulando historial de chat
    Nodo* historial = nullptr;

    insertarAlFinal(historial, "Usuario: Hola");
    insertarAlFinal(historial, "Chatbot: Hola, ¿en qué puedo ayudarte?");
    insertarAlFinal(historial, "Usuario: ¿Qué puedes hacer?");
    insertarAlFinal(historial, "Chatbot: Estoy aprendiendo a responder.");

    cout << "\nHistorial del chatbot:\n";
    mostrarLista(historial);

    liberarLista(historial);

    return 0;
}
