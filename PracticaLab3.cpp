#include <iostream>
#include<windows.h>
using namespace std;
struct Nodo {
    int info;
    Nodo *ligader;
    Nodo *ligaizq;
};
void recorrerDesdeInicio(Nodo *);
void recorrerDesdeFinal(Nodo *); 
void inserta_principio(Nodo *&, Nodo *&, int); 
void inserta_final(Nodo *&, Nodo *&, int); 
void inserta_antes_X(Nodo *&, int, int); 
void inserta_despues_X(Nodo *&, Nodo *&, int, int);
int contar_ocurrencias(Nodo *, int);
void Invertir(Nodo *&, Nodo *&); 
void menu();
void mostrarLista(Nodo *);
int main() {
	SetConsoleOutputCP(CP_UTF8);
    menu();
    return 0;
}
void recorrerDesdeInicio(Nodo *p) {
    Nodo *q = p;
    if(p!=NULL){
        cout<<"\n----------------------------------------";
        cout<<"\n        Recorrido de inicio a fin:      ";
        cout<<"\n----------------------------------------\n\n";
        while (q != NULL) {
            cout << q->info << " -> ";
            q = q->ligader;
        }
        cout<<"NULL\n";
    }else{
        cout<<"Lista vacia....\n";
    }
   
}
void recorrerDesdeFinal(Nodo *f) {
    Nodo *q = f;
    if(f!=NULL){
        cout<<"\n------------------------------------------";
        cout<<"\n        Recorrido de fin a inicio:        ";
        cout<<"\n-----------------------------------------\n\n";
        while (q != NULL) {
            cout << q->info << " -> ";
            q = q->ligaizq;
        }
        cout<<"NULL\n";
    }else{
        cout<<"Lista vacia...\n";
    }
    
}
void inserta_principio(Nodo *&p, Nodo *&f, int dato) {
    Nodo* q = new Nodo();
    q->info = dato;
    if (p == NULL) {
        p = f = q;
    } else {
        q->ligader = p;
        p->ligaizq = q;
        q->ligaizq = NULL;
        p = q;
    }
}
void inserta_final(Nodo *&p, Nodo *&f, int dato) {
    Nodo* q = new Nodo();
    q->info = dato;
    if (f == NULL) {
        p = f = q;
    } else {
        f->ligader = q;
        q->ligaizq = f;
        q->ligader = NULL;
        f = q;
    }
}
void inserta_antes_X(Nodo *&p, int dato, int x) {
    Nodo *q = p;
    while (q->ligader != NULL && q->info != x) {
        q = q->ligader;
    }
    if (q->info == x) {
        Nodo *t = new Nodo();
        t->info = dato;
        t->ligader = q;
        Nodo *r = q->ligaizq;
        q->ligaizq = t;
        if (p == q) {
            p = t;
            t->ligaizq = NULL;
        } else {
            r->ligader = t;
            t->ligaizq = r;
        }
    } else {
        cout << "No se encontró el dato " << x << " en la lista." << endl;
        return;
    }
}
void inserta_despues_X(Nodo *&p, Nodo *&f, int dato, int x) 
{
    Nodo *q = p;
    while ((q->ligader != NULL) && (q->info != x)) 
	{
        q = q->ligader;
    }
    if (q->info == x) 
	{
       Nodo *t = new Nodo();
       t->info = dato;
       t->ligaizq = q;
       Nodo *r = q->ligader;
       q->ligader = t;
       if( f==q )
       {
       		f = t;
       		t->ligader = NULL;
	   }
	   else
	   {
	   		r->ligaizq = t;
	   		t->ligader = r;
	   }
    } else {
        cout << "No se encontró el dato " << x << " en la lista." << endl;
    }
}
int contar_ocurrencias(Nodo *p, int dato) {
    int contador = 0;
    Nodo *q = p;
    while (q != NULL) {
        if (q->info == dato) {
            contador++;
        }
        q = q->ligader;
    }
    return contador;
}
void Invertir(Nodo *&p, Nodo *&f) {
    Nodo *temp = NULL;
    Nodo *q = p;
    
    while (q!= NULL) {
        temp = q->ligaizq;
        q->ligaizq = q->ligader;
        q->ligader = temp;
        q = q->ligaizq;
    }
   temp=p;
   p=f;
   f=temp;
    
}
void mostrarLista(Nodo *p){
    Nodo *q;
    system("cls");
    q=p;
    cout<<"\n----------------------------------------";
    cout<<"\n           LISTA DE DATOS:              ";
    cout<<"\n========================================\n\n";
    while(q!=NULL){
        cout<<q->info<<" -> ";
        q=q->ligader;
    }
    cout<<"NULL\n";
}
void menu() {
    Nodo *p = NULL;
    Nodo *f = NULL;
    int opcion, dato, x;
    char op;
    do {
        system("cls");
        cout<< "\n-------------------- MENÚ ----------------------------";
        cout<<"\n======================================================";
        cout<< "\n\n1. Insertar al inicio                                =";
        cout<< "\n\n2. Insertar al final                                 =";
        cout<< "\n\n3. Insertar antes de un nodo con dato X              =";
        cout<< "\n\n4. Insertar después de un nodo con dato X            =";
        cout<< "\n\n5. Mostrar lista de inicio a fin                     =";
        cout<< "\n\n6. Mostrar lista de fin a inicio                     =";
        cout<< "\n\n7. Contar ocurrencias de un dato                     =";
        cout<< "\n\n8. Invertir lista                                    =";
        cout<< "\n\n0. S a l i r                                         =";
        cout<<"\n\n======================================================";
        cout<< "\n\n\t\t\tOpción: ";
        
        cin >> opcion;
        switch (opcion) {
            case 1:
                system("cls");
                do{
                    system("cls");
                    cout << "dato a insertar al inicio: "; cin >> dato;
                    inserta_principio(p, f, dato);
                    cout<<"\n\n\t\t\tMAS DATOS (S/N)?: "; cin>>op;
                }while(op=='s' or op=='S');
                break;
            case 2:
                system("cls");
                do{
                    system("cls");
                    cout << "dato a insertar al final: "; cin >> dato;
                    inserta_final(p, f, dato);
                    cout<<"\n\n\t\t\tMAS DATOS (S/N)?: "; cin>>op;
                }while(op=='s' or op=='S');
                break;
            case 3:
                system("cls");
                cout << "dato a insertar: ";
                cin >> dato;
                cout << "Antes del nodo con dato: ";
                cin >> x;
                inserta_antes_X(p, dato, x);
                mostrarLista(p);
                system("PAUSE");
                break;
            case 4:
                system("cls");
                cout << "dato a insertar: ";
                cin >> dato;
                cout << "Después del nodo con dato: ";
                cin >> x;
                inserta_despues_X(p, f, dato, x);
                mostrarLista(p);
                system("PAUSE");
                break;
            case 5:
                system("cls");
                recorrerDesdeInicio(p);
                system("PAUSE");
                break;
            case 6:
                system("cls");
                recorrerDesdeFinal(f);
                system("PAUSE");
                break;
            case 7:
                system("cls");
                cout << "Dato a buscar: "; cin>>dato;
                cout << "El número "<<dato<<" aparece "<<contar_ocurrencias(p, dato) << " veces."<<endl;
                system("PAUSE");
                break;
            case 8:
                system("cls");
                Invertir(p, f);
                cout << "Lista invertida." << endl;
                mostrarLista(p);
                system("PAUSE");
                break;
            case 0:
                cout << "Programa finalizado." << endl;
                break;
            default:
                cout << "Opción inválida." << endl;
        }
    } while (opcion != 0);
}