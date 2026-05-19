#include <iostream>
using namespace std;

struct Nodo {
    int codigo;
    string cliente;
    int cantidad;
    float total;
    Nodo* siguiente;
};

void agregarPedido(Nodo*& cima, int cod, string nom, int cant) {
    Nodo* nuevoNodo = new Nodo();

    nuevoNodo->codigo = cod;
    nuevoNodo->cliente = nom;
    nuevoNodo->cantidad = cant;
    nuevoNodo->total = cant * 8;
    nuevoNodo->siguiente = cima;

    cima = nuevoNodo;

    cout << "Pedido agregado a la pila.\n";
}

void eliminarPedidoCima(Nodo*& cima) {
    if (cima == NULL) {
        cout << "La pila esta vacia.\n";
        return;
    }

    Nodo* temp = cima;

    cout << "Pedido eliminado: " << temp->cliente <<"\n";

    cima = cima->siguiente;

    delete temp;
}

void mostrarCima(Nodo* cima) {
    if (cima == NULL) {
        cout << "La pila esta vacia.\n";
        return;
    }

    cout << "\n--- PEDIDO EN LA CIMA ---\n";
    cout << "DNI: " << cima->codigo <<"\n";
    cout << "Cliente: " << cima->cliente << "\n";
    cout << "Cantidad: " << cima->cantidad << "\n";
    cout << "Total: " << cima->total << "$\n";
}

void buscarPedido(Nodo* cima, int cod) {
    Nodo* temp = cima;

    while (temp != NULL) {
        if (temp->codigo == cod) {
            cout << "Pedido encontrado:\n";
            cout << "Cliente: " << temp->cliente << "\n";
            cout << "Cantidad: " << temp->cantidad << "\n";
            cout << "Total: " << temp->total << "$\n";
            return;
        }

        temp = temp->siguiente;
    }

    cout << "Pedido no encontrado.\n";
}

void verificarVacia(Nodo* cima) {
    if (cima == NULL)
        cout << "La pila esta vacia.\n";
    else
        cout << "La pila tiene pedidos.\n";
}

void mostrarPila(Nodo* cima) {
    if (cima == NULL) {
        cout << "\nLa pila esta vacia.\n";
        return;
    }

    Nodo* temp = cima;

    cout <<"\n-----PEDIDOS -----\n";

    while (temp != NULL) {
        cout << "[" << temp->codigo << "] " << temp->cliente << " - " << temp->cantidad << " pasteles total: "<< temp->total << "$" << "\n";
        temp = temp->siguiente;
    }
}

void vaciarPila(Nodo*& cima) {
    while (cima != NULL) {
        Nodo* temp = cima;
        cima = cima->siguiente;
        delete temp;
    }

    cout << "Toda la pila fue eliminada.\n";
}

void actualizarPedido(Nodo* cima, int cod) {

    Nodo* temp = cima;

    while (temp != NULL) {

        if (temp->codigo == cod) {
            cout << "Nuevo nombre: ";
            cin >> temp->cliente;
            cout << "Nueva cantidad: ";
            cin >> temp->cantidad;

            temp->total = temp->cantidad * 8;

            cout << "Pedido actualizado.\n";

            return;
        }

        temp = temp->siguiente;
    }

    cout << "Pedido no encontrado.\n";
}

int main() {
    Nodo* pila = NULL;

    int opcion, cod, cant;
    string nom;

    do {
        cout << "\n********** MENU REPOSTERIA **********\n";
        cout << "1. Agregar pedido\n"; //ingreso de datos
        cout << "2. Eliminar ultimo pedido agregado\n";
        cout << "3. Ver ultimo pedido\n"; // valor cima
        cout << "4. Buscar pedido\n"; //busqueda
        cout << "5. Actualizar pedido\n";
        cout << "6. Verificar si no hay pedidos\n";
        cout << "7. Mostrar pedidos\n"; //mostrar datos
        cout << "8. Eliminar todos los pedidos\n";
        cout << "9. Salir\n";
        cout << "Seleccione: ";

        cin >> opcion;

        switch (opcion) {

            case 1:
                cout << "DNI: ";
                cin >> cod;

                cout << "Cliente: ";
                cin >> nom;

                cout << "Cantidad: ";
                cin >> cant;

                agregarPedido(pila, cod, nom, cant);
                break;

            case 2:
                eliminarPedidoCima(pila);
                break;

            case 3:
                mostrarCima(pila);
                break;

            case 4:
                cout << "DNI a buscar: ";
                cin >> cod;

                buscarPedido(pila, cod);
                break;
            
            case 5:
                cout << "Ingrese DNI a actualizar: ";
                cin >> cod;

                actualizarPedido(pila, cod);
                break;
            case 6:
                verificarVacia(pila);
                break;

            case 7:
                mostrarPila(pila);
                break;

            case 8:
                vaciarPila(pila);
                break;
        }

    } while (opcion != 9);

    return 0;
}
