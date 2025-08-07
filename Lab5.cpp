#include <iostream>
#include<windows.h>
#include<string>
using namespace std;

struct Nodo {
    int info;
    Nodo* liga;
};

class Pila {
	private:
    	Nodo* tope; // Apunta al nodo superior de la pila
	public:
    	Pila() {
        tope = nullptr;
    }

    // Método para agregar un elemento a la pila
    void agregarPila(int dato) {
        Nodo* q = new Nodo;
        q->info = dato;
        q->liga = tope;
        tope = q;
    }

    // Método para eliminar (sacar) el elemento superior de la pila
    void sacarPila() {
        if (tope != nullptr) {
            Nodo* q = tope;
            tope = q->liga;
            delete q;
        } else {
            cout << "Pila vacía, no se puede sacar elemento." << endl;
            return;
        }
    }

    // Método para mostrar todos los elementos de la pila
    void mostrarPila() {
        if (tope != nullptr) {
            Nodo* q = tope;
            cout<<"\n----------------------------------------";
        	cout<<"\n           ELEMENTOS DE LA PILA:        ";
        	cout<<"\n========================================\n\n";
            while (q != nullptr) {
                cout << q->info << " ";
                q = q->liga;
            }
            cout << endl;
        } else {
            cout << "Pila vacía." << endl;
            return;
        }
    }

    // Método para contar los elementos de la pila
    int contarElementosPila() {
    	if(tope!=nullptr){
    		int cont=0;
    		Nodo* q=tope;
    		while(q!=nullptr){
    			cont++;
    			q=q->liga;
			}
			return cont;
		}else{
			return 0;
		}
    }

    // Método para buscar un elemento en la pila
    bool buscarElementoPila(int dato) {
    	bool encontrado=false;
		if(tope!=nullptr){
    		Nodo* q=tope;
    		while(q!=nullptr){
    			if(dato==q->info){
    				encontrado=true;
				}
				q=q->liga;
			}
		}
		return encontrado;
    }
    // Método para comparar pilas
    bool compararCon(Pila& pila) {
    	Nodo* q1=tope;
    	Nodo* q2=pila.tope;
    	while(q1!=nullptr && q2!=nullptr){
    		if(q1->info!=q2->info){
    			return false;
			}
			q1=q1->liga;
			q2=q2->liga;
		}
		return(q1==nullptr &&q2==nullptr);
    }
    // Destructor para liberar memoria
    ~Pila() {
        while (tope != nullptr) {
            sacarPila();
        }
    }
    // Menú interactivo
    void menu() {
        Pila pila;
        Pila pila2;
        int opcion, dato;
        do {
    		system("cls");
            cout<< "\n---------------------- MENÚ ----------------------------";
            cout<<"\n==========================================================";
            cout << "\n1. Apilar en Pila 1";
            cout << "\n2. Desapilar en Pila 1";
            cout << "\n3. Mostrar Pila 1";
            cout << "\n4. Contar elementos de Pila 1";
            cout << "\n5. Buscar un elemento en Pila 1";
            cout << "\n6. Comparar Pila 1 con Pila 2";
            cout << "\n7. Apilar en Pila 2";
            cout << "\n8. Desapilar en Pila 2";
            cout << "\n9. Mostrar Pila 2";
            cout << "\n10. Contar elementos de Pila 2";
            cout << "\n11. Buscar un elementos en Pila 2";
            cout << "\n12. Comparar Pila 2 con Pila 1";
            cout << "\n13. Salir";
            cout<<"\n=========================================================";
            cout<< "\n\n\t\t\tOpción: ";
            cin >> opcion;
            
            switch (opcion) {
                case 1:
                	system("cls");
                    cout << "Ingrese dato a apilar en Pila 1: ";
                    cin >> dato;
                    pila.agregarPila(dato);
                    break;
                case 2:
                	system("cls");
                    pila.sacarPila();
                    system("PAUSE");
                    break;
                case 3:
                	system("cls");
                    pila.mostrarPila();
                    system("PAUSE");
                    break;
                case 4:
                	system("cls");
                    cout << "Cantidad de elementos en Pila 1: " << pila.contarElementosPila() << endl;
                    system("PAUSE");
                    break;
                case 5:
                	system("cls");
                    cout << "Ingrese el elemento a buscar en Pila 1: ";
                    cin >> dato;
                    pila.buscarElementoPila(dato);
                    cout << "¿Está el " << dato << "?: " << (pila.buscarElementoPila(dato) ? "Sí" : "No") << endl;
                    system("PAUSE");
                    break;
                case 6:
                	system("cls");
                    if(pila.tope!=nullptr){
                        if (pila.compararCon(pila2)) {
                            cout << "Las pilas son iguales." << endl;
                        } else {
                            cout << "Las pilas son diferentes." << endl;
                        }
                    }else{
                        cout<<"Pila vacia...\n";
                    }
                    system("PAUSE");
                    break;
                case 7:
                	system("cls");
                    cout << "Ingrese dato a apilar en Pila 2: ";
                    cin >> dato;
                    pila2.agregarPila(dato);
                    break;
                case 8:
                    system("cls");
                    pila2.sacarPila();
                    system("PAUSE");
                    break;
                case 9:
                    system("cls");
                    pila2.mostrarPila();
                    system("PAUSE");
                    break;
                case 10:
                    system("cls");
                    cout << "Cantidad de elementos en Pila 2: " << pila2.contarElementosPila() << endl;
                    system("PAUSE");
                    break;
                case 11:
                    system("cls");
                    cout << "Ingrese el elemento a buscar en Pila 2: ";
                    cin >> dato;
                    pila2.buscarElementoPila(dato);
                    cout<<"¿Está el "<<dato<<"?: "<<(pila2.buscarElementoPila(dato) ? "Sí" : "No") << endl;
                    system("PAUSE");
                    break;
                case 12:
                    system("cls");
                    if(pila2.tope!=nullptr){
                        if (pila2.compararCon(pila)) {
                            cout << "Las pilas son iguales." << endl;
                        } else {
                        cout << "Las pilas son diferentes." << endl;
                        }
                    }else{
                        cout<<"Pila vacia...\n";
                    }
                    system("PAUSE");
                    break;
				case 13:
                    cout << "Programa finalizado." << endl;
                    break;	
                default:
                    cout << "Opción inválida." << endl;
            }
        } while (opcion != 13);
    }
};

int main() {
    SetConsoleOutputCP(CP_UTF8);
    Pila p;
    p.menu();
    return 0;
}