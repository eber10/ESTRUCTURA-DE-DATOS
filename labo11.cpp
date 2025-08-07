#include<iostream>
#include<iomanip>
#include<windows.h>
#include<string>
using namespace std;
class Nodo1{
    public:
        int info;
        int fe;
        Nodo1 *izq;
        Nodo1 *der;
        Nodo1(int valor){
            info=valor;
            fe=0;
            izq=der=NULL;
        }
};
class Nodo{
    public:
        int info;
        Nodo *izq;
        Nodo *der;
};
class NodoZodiaco{
    public:
        string info;
        NodoZodiaco *izq;
        NodoZodiaco *der;
};
class Arbol{
    private:
        Nodo *raiz;
    public:
        Arbol();
        Nodo *regresaRaiz();
        void insertarNodo(Nodo *& apnodo, int dato);
        void insertarNodo2(Nodo *& apnodo, int dato);
        void insertarNodoIterativo(Nodo *&apnodo, int dato);
        bool busquedaABB(Nodo *apnodo, int dato);
        bool busquedaABB2(Nodo *apnodo, int dato);
        bool busquedaABBIterativa(Nodo *apnodo, int dato);
        void muestraArbol(Nodo *apnodo, int nivel);
        void preorden(Nodo *apnodo);
        void inorden(Nodo *apnodo);
        void posorden(Nodo *apnodo);
        int altura(Nodo *apnodo);
        int contarNodos(Nodo *apnodo);
        int contarHojas(Nodo *apnodo);
        int encontrarMaximo(Nodo* apnodo);
        int encontrarMinimo(Nodo* apnodo);
        void insertarNodoZodiaco(NodoZodiaco *& apnodo2, string dato);
        void muestraArbolZodiaco(NodoZodiaco* apnodo2, int nivel);
        void eliminarABB(Nodo *&apnodo,int dato);
        void podarArbol(Nodo *&apnodo);
        Nodo *removeRaiz(Nodo *&apnodo);
        void eliminarABB2(Nodo *&apnodo,int dato);
        void gotoxy(int x, int y);
        void graficarArbol(Nodo *apnodo, int x, int y, int n);
        void inserta_balanceado(Nodo1 *&apnodo,bool &bo, int dato3);
        void muestraArbolBalanceado(Nodo1* apnodo, int nivel);
        void graficarArbolBalanceado(Nodo1 *apnodo, int x, int y, int n);
};
Arbol::Arbol(){
    raiz=NULL;
}
Nodo *Arbol::regresaRaiz(){
    return raiz;
}
void Arbol::insertarNodo(Nodo *& apnodo, int dato){
    if(dato<apnodo->info){
        if(apnodo->izq==NULL){
            Nodo *otro=new Nodo();
            otro->info=dato;
            otro->izq=NULL;
            otro->der=NULL;
            apnodo->izq=otro;
        }else{
            insertarNodo(apnodo->izq,dato);
        }
    }else{
        if(dato>apnodo->info){
            if(apnodo->der==NULL){
                Nodo *otro=new Nodo();
                otro->info=dato;
                otro->izq=NULL;
                otro->der=NULL;
                apnodo->der=otro;
            }else{
                insertarNodo(apnodo->der,dato);
            }
        }else{
            cout<<"El nodo "<<dato<<" ya se encuentra en el árbol. "<<endl;
        }      
    }
}
void Arbol::insertarNodo2(Nodo *&apnodo, int dato){
    if(apnodo!=NULL){
        if(dato<apnodo->info){
            insertarNodo2(apnodo->izq,dato);
        }else{
            if(dato>apnodo->info){
                insertarNodo2(apnodo->der,dato);
            }else{
                cout<<"la información ya se encuentra en el árbol.\n";
            }
        }       
    }else{
        Nodo *otro=new Nodo();
        otro->info=dato;
        otro->izq=NULL;
        otro->der=NULL;
        apnodo=otro;
    }
}
void Arbol::insertarNodoIterativo(Nodo *&apnodo,int dato){
    Nodo *otro=new Nodo();
    otro->info=dato;
    otro->izq=NULL;
    otro->der=NULL;
    if(apnodo==NULL){
        apnodo=otro;
    }else{
        Nodo *h=apnodo;
        Nodo *p=NULL;
        while(h!=NULL){
            p=h;
            if(dato<h->info){
                h=h->izq;
            }else{
                h=h->der;
            }
        }
        if(p->info>dato){
            p->izq=otro;
        }else{
            p->der=otro;
        }
    }
}
bool Arbol::busquedaABB(Nodo *apnodo,int dato){
    if(dato<apnodo->info){
        if(apnodo->izq==NULL){
            return false;
        }else{
            busquedaABB(apnodo->izq,dato);
        }
    }else{
        if(dato>apnodo->info){
            if(apnodo->der==NULL){
                return false;
            }else{
                busquedaABB(apnodo->der,dato);

            }
        }else{
            return true;
        }
    }
}
bool Arbol::busquedaABB2(Nodo *apnodo, int dato){
    if(apnodo!=NULL){
        if(dato<apnodo->info){
            busquedaABB2(apnodo->izq,dato);
        }else{
            if(dato>apnodo->info){
               busquedaABB2(apnodo->der,dato);
            }else{
                return true;
            }
        }
    }else{
        return false;
    }
} 
bool Arbol::busquedaABBIterativa(Nodo *apnodo, int dato){
    while((apnodo!=NULL) and (apnodo->info!=dato)){
        if(apnodo->info>dato){
            apnodo=apnodo->izq;
        }else{
            apnodo=apnodo->der;
        }
    }
    if(apnodo!=NULL){
        return true;
    }else{
    }    return false;
}
void Arbol::muestraArbol(Nodo* apnodo, int nivel) {
    if (apnodo == NULL) return;
    
    muestraArbol(apnodo->der, nivel + 1);
    
    for (int i = 0; i < nivel; i++) {
        cout << "    ";
    }
    cout << apnodo->info << endl;
    
    muestraArbol(apnodo->izq, nivel + 1);
}
void Arbol::preorden(Nodo* apnodo) {
    if (apnodo != NULL) {
        cout << apnodo->info << " ";
        preorden(apnodo->izq);
        preorden(apnodo->der);
    }
}

void Arbol::inorden(Nodo* apnodo) {
    if (apnodo != NULL) {
        inorden(apnodo->izq);
        cout << apnodo->info << " ";
        inorden(apnodo->der);
    }
}

void Arbol::posorden(Nodo* apnodo) {
    if (apnodo != NULL) {
        posorden(apnodo->izq);
        posorden(apnodo->der);
        cout << apnodo->info << " ";
    }
}

int Arbol::altura(Nodo* apnodo) {
    if (apnodo == NULL) {
        return 0;
    } else {
        int alturaIzq = altura(apnodo->izq);
        int alturaDer = altura(apnodo->der);
        return max(alturaIzq, alturaDer) + 1;
    }
}

int Arbol::contarNodos(Nodo* apnodo) {
    if (apnodo == NULL) {
        return 0;
    }
    return 1 + contarNodos(apnodo->izq) + contarNodos(apnodo->der);
}

int Arbol::contarHojas(Nodo* apnodo) {
    if (apnodo == NULL) {
        return 0;
    }
    if (apnodo->izq == NULL && apnodo->der == NULL) {
        return 1;
    }
    return contarHojas(apnodo->izq) + contarHojas(apnodo->der);
}

int Arbol::encontrarMaximo(Nodo* apnodo) {
    if (apnodo == NULL) {
        cerr << "El árbol está vacío" << endl;
        return -1;
    }
    while (apnodo->der != NULL) {
        apnodo = apnodo->der;
    }
    return apnodo->info;
}

int Arbol::encontrarMinimo(Nodo* apnodo) {
    if (apnodo == NULL) {
        cerr << "El árbol está vacío" << endl;
        return -1;
    }
    while (apnodo->izq != NULL) {
        apnodo = apnodo->izq;
    }
    return apnodo->info;
}
void Arbol::insertarNodoZodiaco(NodoZodiaco *& apnodo2, string dato){
    if(dato < apnodo2->info){
        if(apnodo2->izq==NULL){
            NodoZodiaco *otro=new NodoZodiaco();
            otro->info=dato;
            otro->izq=NULL;
            otro->der=NULL;
            apnodo2->izq=otro;
        }else{
            insertarNodoZodiaco(apnodo2->izq,dato);
        }
    }else{
        if(dato>apnodo2->info){
            if(apnodo2->der==NULL){
                NodoZodiaco *otro=new NodoZodiaco();
                otro->info=dato;
                otro->izq=NULL;
                otro->der=NULL;
                apnodo2->der=otro;
            }else{
                insertarNodoZodiaco(apnodo2->der,dato);
            }
        }else{
            cout<<"El nodo "<<dato<<" ya se encuentra en el árbol. "<<endl;
        }      
    }
}
void Arbol::muestraArbolZodiaco(NodoZodiaco* apnodo2, int nivel) {
    if (apnodo2 == NULL) return;
    
    muestraArbolZodiaco(apnodo2->der, nivel + 1);
    
    for (int i = 0; i < nivel; i++) {
        cout << "    ";
    }
    cout << apnodo2->info << endl;
    
    muestraArbolZodiaco(apnodo2->izq, nivel + 1);
}
void Arbol::eliminarABB(Nodo *&apnodo, int dato){
     Nodo *aux=new Nodo();
     Nodo *otro=new Nodo();
     Nodo *aux1=new Nodo();
    if(apnodo!=NULL){
        if(dato<apnodo->info){
            eliminarABB(apnodo->izq,dato);
        }else{
            if(dato>apnodo->info){
                eliminarABB(apnodo->der,dato);
            }else{
               
                otro=apnodo;
                if(otro->der==NULL){
                    apnodo=otro->izq;
                }else{
                    if(otro->izq==NULL){
                        apnodo=otro->der;
                    }else{
                        
                        aux=apnodo->izq;
                        bool bo=false;
                        while(aux->der!=NULL){
                           
                            aux1=aux;
                            aux=aux->der;
                            bo=true;
                        }
                        apnodo->info=aux->info;
                        otro=aux;
                        if(bo==true){
                            aux1->der=aux->izq;
                        }else{
                            apnodo->izq=aux->izq;
                        }
                    }
                }
                delete(otro);
            }
        }
    }else{
        cout<<"La información a eliminar no se encuentra en el árbol\n";
    }
}
void Arbol::podarArbol(Nodo *&apnodo){
    if(apnodo==NULL){
        return;
    }
    podarArbol(apnodo->izq);
    podarArbol(apnodo->der);
    delete(apnodo);
    apnodo=NULL;
}
Nodo *Arbol::removeRaiz(Nodo *&apnodo){
    Nodo *p, *q;
    if(apnodo->izq==NULL){
        q=apnodo->der; 
        delete(apnodo);
        return q;
    }
    p=apnodo;
    q=apnodo->izq;
    while(q->der!=NULL){
        p=q;
        q=q->der;
    }
    if(p!=apnodo){
        p->der=q->izq;
        q->izq=apnodo->izq;
    }
    q->der=apnodo->der;
    delete(apnodo);
    return q;
}
void Arbol::eliminarABB2(Nodo *&apnodo,int dato){
    if(apnodo!=NULL){
        if(dato<apnodo->info){
            eliminarABB(apnodo->izq,dato);
        }else{
            if(dato>apnodo->info){
                eliminarABB(apnodo->der,dato);
            }else{
                apnodo=removeRaiz(apnodo);
            }
        }
    }else{
        cout<<"La información a eliminar no se encuentra en el árbol\n";
    }
}
void Arbol::gotoxy(int x, int y){
    COORD coord;
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void Arbol::graficarArbol(Nodo *apnodo, int x, int y, int n){
    if(apnodo==NULL){
        return;
    }
    gotoxy(x,y); cout<<apnodo->info;
    graficarArbol(apnodo->izq,x-15+n*6,y+2,n+1);
    graficarArbol(apnodo->der,x+15-n*6,y+2,n+1);
}

void Arbol::inserta_balanceado(Nodo1 *&apnodo,bool &bo, int dato3){
    if (apnodo!= NULL) {
        if (dato3 < apnodo->info) {
            inserta_balanceado(apnodo->izq,bo,dato3);
            if (bo) {
                switch (apnodo->fe) {
                    case 1:
                        apnodo->fe= 0;
                        bo= false;
                        break;
                    case 0:
                        apnodo->fe=-1;
                        break;
                    case -1: {
                        Nodo1* apnodo1= apnodo->izq;
                        if (apnodo1->fe <= 0) {
                            // Rotación II
                            apnodo->izq=apnodo1->der;
                            apnodo1->der= apnodo;
                            apnodo->fe= 0;
                            apnodo=apnodo1;
                        } else {
                            // Rotación ID
                            Nodo1* apnodo2=apnodo1->der;
                            apnodo->izq=apnodo2->der;
                            apnodo2->der=apnodo;
                            apnodo1->der=apnodo2->izq;
                            apnodo2->izq=apnodo1;
                            
                            if (apnodo2->fe== -1) {
                                apnodo->fe= 1;
                            } else {
                               apnodo->fe = 0;
                            }
                            
                            if (apnodo2->fe== 1) {
                                apnodo1->fe= -1;
                            } else {
                                apnodo1->fe= 0;
                            }
                            
                            apnodo=apnodo2;
                        }
                        apnodo->fe= 0;
                        bo = false;
                        break;
                    }
                }
            }
        } else if (dato3> apnodo->info) {
            inserta_balanceado(apnodo->der,bo,dato3);
            if (bo) {
                switch (apnodo->fe) {
                    case -1:
                        apnodo->fe= 0;
                        bo = false;
                        break;
                    case 0:
                        apnodo->fe = 1;
                        break;
                    case 1: {
                        Nodo1* apnodo1= apnodo->der;
                        if (apnodo1->fe>= 0) {
                            // Rotación DD
                            apnodo->der=apnodo1->izq;
                            apnodo1->izq=apnodo;
                            apnodo->fe= 0;
                            apnodo=apnodo1;
                        } else {
                            // Rotación DI
                            Nodo1* apnodo2= apnodo1->izq;
                            apnodo->der=apnodo2->izq;
                            apnodo2->izq=apnodo;
                            apnodo1->izq =apnodo2->der;
                            apnodo2->der=apnodo1;
                            
                            if (apnodo2->fe== 1) {
                                apnodo->fe= -1;
                            } else {
                                apnodo->fe= 0;
                            }
                            
                            if (apnodo2->fe == -1) {
                                apnodo1->fe= 1;
                            } else {
                                apnodo1->fe= 0;
                            }
                            
                            apnodo=apnodo2;
                        }
                        apnodo->fe= 0;
                        bo = false;
                        break;
                    }
                }
            }
        } else {
            cout << "La información ya se encuentra en el árbol" << endl;
        }
    } else {
       
        apnodo=new Nodo1(dato3);
        bo=true;
    }
}
void Arbol::graficarArbolBalanceado(Nodo1* apnodo, int x, int y, int nivel) {
    if (apnodo == NULL) return;

    int desplazamiento = 32 >> nivel;
    if (desplazamiento < 2) desplazamiento = 2;
    graficarArbolBalanceado(apnodo->der, x + desplazamiento, y + 2, nivel + 1);
    gotoxy(x, y);
    cout << apnodo->info;
    graficarArbolBalanceado(apnodo->izq, x - desplazamiento, y + 2, nivel + 1);
}
void menu() {
    Arbol arbol;
    Nodo* raiz = arbol.regresaRaiz();
    int opcion, dato;
    NodoZodiaco *raiz2=NULL;
    string dato2;
    int dato3;
    Nodo1 *raiz3=NULL;
   bool bo=false;
    do {
        cout << "\n===== MENÚ DE OPCIONES - ÁRBOL BINARIO ====" << endl;
        cout << "1. Insertar nodo (insertarNodo)" << endl;
        cout << "2. Insertar nodo (insertarNodo2)" << endl;
        cout << "3. Insertar nodo (insertarNodoIterativo)" << endl;
        cout << "4. Mostrar árbol (forma estructurada)" << endl;
        cout << "5. Recorrido en Preorden" << endl;
        cout << "6. Recorrido en Inorden" << endl;
        cout << "7. Recorrido en Posorden" << endl;
        cout << "8. Buscar dato (busquedaABB)" << endl;
        cout << "9. Buscar dato (busquedaABB2)" << endl;
        cout << "10. Buscar dato (busquedaABBIterativa)" << endl;
        cout << "11. Altura del árbol" << endl;
        cout << "12. Contar todos los nodos" << endl;
        cout << "13. Contar nodos hoja" << endl;
        cout << "14. Encontrar valor máximo" << endl;
        cout << "15. Encontrar valor mínimo" << endl;
        cout << "16. Insertar nodo Zodiaco" << endl;
        cout << "17. Mostrar árbol zodiaco" << endl;
        cout << "18. eliminar Nodo " << endl;
        cout << "19. podar arbol " << endl;
        cout << "20. remover raiz " << endl;
        cout << "21. eliminar2  nodo" << endl;
        cout << "22. mostrar árbol vertical" << endl;
        cout << "23. insertar balanceado" << endl;
        cout << "24. mostrar árbol balanceado vertical" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;
        switch(opcion) {
            case 1:
                cout << "Ingrese dato a insertar (insertarNodo): ";
                cin >> dato;
                if (raiz == NULL) {
                    raiz = new Nodo{dato,NULL,NULL};
                } else {
                    arbol.insertarNodo(raiz, dato);
                }
                break;
            case 2:
                cout << "Ingrese dato a insertar (insertarNodo2): ";
                cin >> dato;
                arbol.insertarNodo2(raiz, dato);
                break;
            case 3:
                cout << "Ingrese dato a insertar (insertarNodoIterativo): ";
                cin >> dato;
                arbol.insertarNodoIterativo(raiz, dato);
                break;
            case 4:
                if (raiz == NULL)
                    cout << "El árbol está vacío.\n";
                else
                    arbol.muestraArbol(raiz, 0);
                break;
            case 5:
                if (raiz == NULL)
                    cout << "El árbol está vacío.\n";
                else {
                    cout << "Recorrido Preorden : ";
                    arbol.preorden(raiz);
                    cout << endl;
                }
                break;
            case 6:
                if (raiz == NULL)
                    cout << "El árbol está vacío.\n";
                else {
                    cout << "Recorrido Inorden : ";
                    arbol.inorden(raiz);
                    cout << endl;
                }
                break;
            case 7:
                if (raiz == NULL)
                    cout << "El árbol está vacío.\n";
                else {
                    cout << "Recorrido Posorden : ";
                    arbol.posorden(raiz);
                    cout << endl;
                }
                break;
            case 8:
                cout << "Ingrese el dato a buscar: ";
                cin >> dato;
                if (arbol.busquedaABB(raiz, dato))
                    cout << "Dato encontrado en el árbol.\n";
                else
                    cout << "Dato NO encontrado.\n";
                break;
            case 9:
                cout << "Ingrese el dato a buscar: ";
                cin >> dato;
                if (arbol.busquedaABB2(raiz, dato))
                    cout << "Dato encontrado en el árbol.\n";
                else
                    cout << "Dato NO encontrado.\n";
                break;
            case 10:
                cout << "Ingrese el dato a buscar: ";
                cin >> dato;
                if (arbol.busquedaABBIterativa(raiz, dato))
                    cout << "Dato encontrado en el árbol.\n";
                else
                    cout << "Dato NO encontrado.\n";
                break;
            case 11:
                if (raiz == NULL)
                    cout << "El árbol está vacío.\n";
                else
                    cout << "Altura del árbol: "<< arbol.altura(raiz) << endl;
                break;
            case 12:
                if (raiz == NULL)
                    cout << "El árbol está vacío.\n";
                else
                    cout << "Cantidad total de nodos: "<< arbol.contarNodos(raiz) << endl;
                break;
            case 13:
                if (raiz == NULL)
                    cout << "El árbol está vacío.\n";
                else
                    cout << "Cantidad de nodos hoja: "<< arbol.contarHojas(raiz) << endl;
                break;
            case 14:
                if (raiz == NULL)
                    cout << "El árbol está vacío.\n";
                else
                    cout << "Valor máximo: " << arbol.encontrarMaximo(raiz) << endl;
                break;
            case 15:
                if (raiz == NULL)
                    cout << "El árbol está vacío.\n";
                else
                    cout << "Valor mínimo: " << arbol.encontrarMinimo(raiz) << endl;
                break;
            case 16:
                cout << "Ingrese dato a insertar (insertarNodo): ";
                cin >> dato2;
                if (raiz2 == NULL) {
                    raiz2 = new NodoZodiaco{dato2,NULL,NULL};
                } else {
                    arbol.insertarNodoZodiaco(raiz2, dato2);
                }
                break;
            case 17:
                 if (raiz2 == NULL)
                    cout << "El árbol está vacío.\n";
                else
                    arbol.muestraArbolZodiaco(raiz2, 0);
                break;
            case 18:
                if(raiz!=NULL){
                    cout<<"Ingrese dato a eliminar: "; cin>>dato;
                    arbol.eliminarABB(raiz,dato);
                }else{
                    cout<<"Árbol vacio...\n";
                }
                break;
            case 19:
                if(raiz==NULL){
                    cout<<"Árbol vacio..\n";
                }else{
                    arbol.podarArbol(raiz);
                    cout<<"Árbol podado completamente\n";
                }
                break;
            case 20:
                if(raiz==NULL){
                    cout<<"árbol vacio..\n";
                }else{
                    raiz=arbol.removeRaiz(raiz);
                }
                break;
            case 21:
                if(raiz==NULL){
                    cout<<"árbol vacio\n";
                }else{
                    cout<<"ingrese dato: "; cin>>dato;
                    arbol.eliminarABB2(raiz,dato);
                }
                break;
            case 22:
                if(raiz==NULL){
                    cout<<"árbol vacio\n";
            
                }else{
                    system("cls");
                    arbol.graficarArbol(raiz,45,2,0);
                    cout<<"\n\n\n\n\n\n\n\n";
                    
                }
                break;
            case 23:
                cout << "Ingrese dato: ";
                cin >> dato3;
                arbol.inserta_balanceado(raiz3,bo,dato3);
                break;
            case 24:
                system("cls");
                 if(raiz3==NULL){
                    cout<<"árbol vacio\n";
            
                }else{
                    arbol.graficarArbolBalanceado(raiz3,60,2,0);
                    cout<<"\n\n\n\n\n\n\n\n";
                    
                }
                system("PAUSE");
                break;
            case 0:
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opción inválida. Intente nuevamente.\n";
        }
    } while(opcion != 0);
}
int main(){
    SetConsoleOutputCP(CP_UTF8);
    menu();
    return 0;
}