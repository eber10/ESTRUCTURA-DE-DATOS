#include <iostream>
#include <iomanip>
#include <windows.h>
#include <cmath>
using namespace std;
class Nodo
{
public:
    int info;
    Nodo *izq;
    Nodo *der;
};
class Arbol
{
private:
    Nodo *raiz; // apuntador al inicio del arbol

public:
    Arbol(); // constructor

    Nodo *creaArbol();
    void muestraArbol(Nodo *apnodo, int nivel);

    // Métodos de recorrido
    void preorden(Nodo *apnodo);
    void inorden(Nodo *apnodo);
    void posorden(Nodo *apnodo);
    int altura(Nodo *apnodo);
    int contarNodos(Nodo *apnodo);
    int contarHojas(Nodo *apnodo);
    void mostrarHojas(Nodo *apnodo);
    bool esCompleto(Nodo *apnodo);
};

// constructor predeterminado
Arbol::Arbol()
{
    raiz = NULL;
}

void Arbol::muestraArbol(Nodo *apnodo, int nivel)
{
    if (apnodo == NULL)
    {
        return;
    }

    muestraArbol(apnodo->der, nivel + 1);

    for (int i = 0; i < nivel; i++)
    {
        cout << "    ";
    }
    cout << apnodo->info << endl;

    muestraArbol(apnodo->izq, nivel + 1);
}

Nodo *Arbol::creaArbol()
{
    bool resp;
    Nodo *apnodo = new Nodo();

    cout << "\nIngrese el valor del nodo: ";
    cin >> apnodo->info;

    cout << "\n ¿Existe nodo por izquierda: 1 (Sí) - 0 (No)? ";
    cin >> resp;
    if (resp == 1)
    {
        apnodo->izq = creaArbol();
    }
    else
    {
        apnodo->izq = NULL;
    }

    cout << "\n ¿Existe nodo por derecha: 1 (Sí) - 0 (No)? ";
    cin >> resp;
    if (resp == 1)
    {
        apnodo->der = creaArbol();
    }
    else
    {
        apnodo->der = NULL;
    }
    return apnodo;
}

// Recorrido en Preorden: Raíz - Subárbol izquierdo - Subárbol Derecho
void Arbol::preorden(Nodo *apnodo)
{
    if (apnodo != NULL)
    {
        cout << apnodo->info << " - ";
        preorden(apnodo->izq);
        preorden(apnodo->der);
    }
}

// Recorrido en Inorden: Subárbol izquierdo - Raíz - Subárbol Derecho
void Arbol::inorden(Nodo *apnodo)
{
    if (apnodo != NULL)
    {
        inorden(apnodo->izq);
        cout << apnodo->info << " - ";
        inorden(apnodo->der);
    }
}

// Recorrido en Posorden: Subárbol izquierdo - Subárbol Derecho - Raíz
void Arbol::posorden(Nodo *apnodo)
{
    if (apnodo != NULL)
    {
        posorden(apnodo->izq);
        posorden(apnodo->der);
        cout << apnodo->info << " - ";
    }
}

// Altura del árbol
int Arbol::altura(Nodo *apnodo)
{
    if (apnodo == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + max(altura(apnodo->izq), altura(apnodo->der));
    }
}

int Arbol::contarNodos(Nodo *apnodo)
{
    if (apnodo == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + contarNodos(apnodo->izq) + contarNodos(apnodo->der);
    }
}

int Arbol::contarHojas(Nodo *apnodo)
{
    if (apnodo == NULL)
    {
        return 0;
    }
    if (apnodo->izq == NULL && apnodo->der == NULL)
    {
        return 1;
    }
    else
    {
        return contarHojas(apnodo->izq) + contarHojas(apnodo->der);
    }
}

void Arbol::mostrarHojas(Nodo *apnodo)
{
    if (apnodo == NULL)
    {
        return;
    }
    if (apnodo->izq == NULL && apnodo->der == NULL)
    {
        cout << "Nodo hoja encontrado: " << apnodo->info << endl;
    }
    mostrarHojas(apnodo->izq);
    mostrarHojas(apnodo->der);
}
bool Arbol::esCompleto(Nodo *apnodo)
{
    if (apnodo == NULL)
    {
        return true;
    }
    int h = altura(apnodo);
    int n = contarNodos(apnodo);
    return (n == pow(2, h) - 1);
}
void menu()
{
    Arbol arbol;
    Nodo *raiz = NULL;
    int opcion;

    do
    {
        cout << "\n===== MENÚ DE OPCIONES - ÁRBOL BINARIO =====" << endl;
        cout << "1. Crear árbol" << endl;
        cout << "2. Mostrar árbol (forma estructurada)" << endl;
        cout << "3. Recorrido en Preorden" << endl;
        cout << "4. Recorrido en Inorden" << endl;
        cout << "5. Recorrido en Posorden" << endl;
        cout << "6. Altura del árbol" << endl;
        cout << "7. Contar todos los nodos" << endl;
        cout << "8. Contar nodos hoja y mostrarlos" << endl;
        cout << "9. verificar arbol " << endl;
        cout << "10. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            raiz = arbol.creaArbol();
            break;
        case 2:
            if (raiz == NULL)
                cout << "El árbol está vacío.\n";
            else
                arbol.muestraArbol(raiz, 0);
            break;
        case 3:
            if (raiz == NULL)
            {
                cout << "El árbol está vacío.\n";
            }
            else
            {
                cout << "Recorrido Preorden : ";
                arbol.preorden(raiz);
                cout << endl;
            }
            break;
        case 4:
            if (raiz == NULL)
            {
                cout << "El árbol está vacío.\n";
            }
            else
            {
                cout << "Recorrido Inorden : ";
                arbol.inorden(raiz);
                cout << endl;
            }
            break;
        case 5:
            if (raiz == NULL)
            {
                cout << "El árbol está vacío.\n";
            }
            else
            {
                cout << "Recorrido Posorden : ";
                arbol.posorden(raiz);
                cout << endl;
            }
            break;
        case 6:
            if (raiz == NULL)
                cout << "El árbol está vacío.\n";
            else
                cout << "Altura del árbol: " << arbol.altura(raiz) << endl;
            break;
        case 7:
            if (raiz == NULL)
                cout << "El árbol está vacío.\n";
            else
                cout << "Cantidad total de nodos: " << arbol.contarNodos(raiz) << endl;
            break;
        case 8:
            if (raiz == NULL)
                cout << "El árbol está vacío.\n";
            else
            {
                cout << "Nodos hoja encontrados:\n";
                arbol.mostrarHojas(raiz);
                cout << "Cantidad de nodos hoja: " << arbol.contarHojas(raiz) << endl;
            }
            break;
        case 9:
            if ((arbol.esCompleto(raiz) == true))
            {
                cout << "arbol completo" << endl;
            }
            else
            {
                cout << "arbol incompleto" << endl;
            }
            break;
        case 10:
            cout << "Saliendo del programa...\n";
            break;
        default:
            cout << "Opción inválida. Intente nuevamente.\n";
        }
    } while (opcion != 10);
}
int main()
{
    // setlocale(LC_ALL, "");
    SetConsoleOutputCP(CP_UTF8);
    menu();
    return 0;
}