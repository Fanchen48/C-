#include <iostream>
#include <string>

using namespace std;

// Estructura del nodo
struct Nodo {
    int codigo;
    string cliente;
    int cantidad;
    float total;
    Nodo* siguiente;
};

// 1. Insertar al principio
void insertarInicio(Nodo*& inicio, int cod, string nom, int cant) {
    Nodo* nuevo = new Nodo();
    nuevo->codigo = cod;
    nuevo->cliente = nom;
    nuevo->cantidad = cant;
    nuevo->total = cant * 8; // Suponiendo que cada pastel cuesta 8
    nuevo->siguiente = inicio;
    inicio = nuevo;
    cout << "\nPedido insertado al inicio.\n";
}

// 2. Insertar al final
void insertarFinal(Nodo*& inicio, int cod, string nom, int cant) {
    Nodo* nuevo = new Nodo();
    nuevo->codigo = cod;
    nuevo->cliente = nom;
    nuevo->cantidad = cant;
    nuevo->total = cant * 8;
    nuevo->siguiente = NULL;

    if (inicio == NULL) {
        inicio = nuevo;
    } else {
        Nodo* temp = inicio;
        while (temp->siguiente != NULL) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevo;
    }
    cout << "\nPedido insertado al final.\n";
}

// 3. Eliminar primer nodo
void eliminarPrimero(Nodo*& inicio) {
    if (inicio == NULL) {
        cout << "\nLa lista esta vacia.\n";
        return;
    }
    Nodo* temp = inicio;
    inicio = inicio->siguiente;
    delete temp;
    cout << "\nPrimer pedido eliminado.\n";
}

// 4. Eliminar ultimo nodo
void eliminarUltimo(Nodo*& inicio) {
    if (inicio == NULL) {
        cout << "\nLa lista esta vacia.\n";
        return;
    }
    if (inicio->siguiente == NULL) {
        delete inicio;
        inicio = NULL;
    } else {
        Nodo* temp = inicio;
        while (temp->siguiente->siguiente != NULL) {
            temp = temp->siguiente;
        }
        delete temp->siguiente;
        temp->siguiente = NULL;
    }
    cout << "\nUltimo pedido eliminado.\n";
}

// 5. Eliminar un nodo en especifico (NUEVA FUNCION)
void eliminarEspecifico(Nodo*& inicio, int cod) {
    if (inicio == NULL) {
        cout << "\nLa lista esta vacia.\n";
        return;
    }

    if (inicio->codigo == cod) {
        eliminarPrimero(inicio);
        return;
    }

    Nodo* anterior = inicio;
    Nodo* actual = inicio->siguiente;

    while (actual != NULL && actual->codigo != cod) {
        anterior = actual;
        actual = actual->siguiente;
    }

    if (actual != NULL) {
        anterior->siguiente = actual->siguiente;
        delete actual;
        cout << "\nPedido con DNI " << cod << " eliminado.\n";
    } else {
        cout << "\nNo se encontro el DNI especificado.\n";
    }
}

// 6. Buscar nodo
void buscarPedido(Nodo* inicio, int cod) {
    Nodo* temp = inicio;
    while (temp != NULL) {
        if (temp->codigo == cod) {
            cout << "\nPedido Encontrado:\n";
            cout << "Cliente: " << temp->cliente << " | Cantidad: " << temp->cantidad << " | Total: " << temp->total << endl;
            return;
        }
        temp = temp->siguiente;
    }
    cout << "\nPedido no encontrado.\n";
}

// 7. Verificar si la lista esta vacia
void verificarVacia(Nodo* inicio) {
    if (inicio == NULL) cout << "\nLa lista esta VACIA.\n";
    else cout << "\nLa lista TIENE pedidos.\n";
}

// 8. Eliminar todos los nodos
void eliminarTodo(Nodo*& inicio) {
    while (inicio != NULL) {
        Nodo* temp = inicio;
        inicio = inicio->siguiente;
        delete temp;
    }
    cout << "\nTodos los pedidos han sido eliminados.\n";
}

// Funcion extra para mostrar
void mostrarPedidos(Nodo* inicio) {
    if (inicio == NULL) {
        cout << "\nNada que mostrar, lista vacia.\n";
        return;
    }
    Nodo* temp = inicio;
    cout << "\n--- LISTA DE PEDIDOS ACTUALES ---\n";
    while (temp != NULL) {
        cout << "[" << temp->codigo << "] " << temp->cliente << " - " << temp->cantidad << " pasteles ($" << temp->total << ")" << endl;
        temp = temp->siguiente;
    }
}

int main() {
    Nodo* lista = NULL;
    int opcion, cod, cant;
    string nom;

    do {
        cout << "\n********** MENU REPOSTERIA **********\n";
        cout << "1. Insertar al principio\n";
        cout << "2. Insertar al final\n";
        cout << "3. Eliminar primer pedido\n";
        cout << "4. Eliminar ultimo pedido\n";
        cout << "5. Eliminar un pedido especifico\n";
        cout << "6. Buscar pedido por DNI\n";
        cout << "7. Verificar si esta vacia\n";
        cout << "8. Eliminar TODO\n";
        cout << "9. Mostrar todos los pedidos\n";
        cout << "10. Salir\n";
        cout << "Seleccione: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
            case 2:
                cout << "DNI: "; cin >> cod;
                cout << "Cliente: "; cin >> nom;
                cout << "Cantidad: "; cin >> cant;
                if (opcion == 1) insertarInicio(lista, cod, nom, cant);
                else insertarFinal(lista, cod, nom, cant);
                break;
            case 3: eliminarPrimero(lista); break;
            case 4: eliminarUltimo(lista); break;
            case 5: 
                cout << "DNI a borrar: "; cin >> cod;
                eliminarEspecifico(lista, cod); 
                break;
            case 6: 
                cout << "Codigo a buscar: "; cin >> cod;
                buscarPedido(lista, cod); 
                break;
            case 7: verificarVacia(lista); break;
            case 8: eliminarTodo(lista); break;
            case 9: mostrarPedidos(lista); break;
        }
    } while (opcion != 10);

    return 0;
}
