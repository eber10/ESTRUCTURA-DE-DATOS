#include<iostream>
#include<string>
#include<windows.h>
#include<algorithm>
using namespace std;
#define MAX 100 // Capacidad máxima de la pila

class Pila{
    private:
        char elementos[MAX];
        int tope;
    public:
        Pila();
        bool pilaVacia();
        bool pilaLlena();
        void agregarPila(char dato);
        char sacarPila();
        char cima();
        void mostrarPila();
        int contarElementosPila();
        bool buscarElementoPila(int valor);
        bool compararCon(Pila& otra);
        bool revisarOperacionMatematica(const string& expmatematica);
        bool esPalindrome(const string& palabra);
        int prioridad(char op);
        string convertirInfijaPostfija(const string& infija);
        string convertirInfijaPrefija(const string& infija);
};
// Constructor
Pila::Pila(){
    tope=-1; // Pila vacía
}
// Método para verificar si la pila está vacía
bool Pila::pilaVacia(){
    if(tope==-1){
        return true;
    }else{
        return false;
    }
}
// Método para verificar si la pila está llena
bool Pila::pilaLlena(){
    if(tope==MAX-1){
        return true;
    }else{
        return false;
    }
}
// Método para agregar un elemento a la pila (push)
void Pila::agregarPila(char dato){
    if (pilaLlena()){
        cout<<"Desbordamiento - Pila llena. No se puede agregar más elementos."<<endl;
        return;
    }else{
        tope++;
        elementos[tope]=dato;
    }
}
// Método para eliminar el elemento superior de la pila (pop)
char Pila::sacarPila(){
    if (pilaVacia()){
        cout<<"Subdesbordamiento - Pila vacía. No se puede sacar elemento."<<endl;
        return (0); // Carácter nulo
    }else{
        char dato=elementos[tope];
        tope--;
        return dato;
    }
}

// Método para ver el elemento en la cima de la pila (peek)
char Pila::cima(){
    if (!pilaVacia()){
        return elementos[tope];
    }else{
        cout<<"Pila vacía."<<endl;
        return -1;
    }
}
// Método para mostrar todos los elementos de la pila
void Pila::mostrarPila(){
    if (pilaVacia()){
        cout<<"Pila vacía."<<endl;
        return;
    }else{
        cout<<"Elementos de la pila (de arriba hacia abajo):"<<endl;
        for (int i=tope; i>=0; i--){
            cout<<elementos[i]<<endl;
        }
        cout<<endl;
    }
}
// Método para contar elementos
int Pila::contarElementosPila(){
    return tope+1;
}
// Método para buscar un elemento en la pila
bool Pila::buscarElementoPila(int dato) {
    for (int i=tope; i>=0; i--) {
        if(elementos[i]==dato) {
            return true;
        }
    }
    return false;
}
// Método para comparar con otra pila
bool Pila::compararCon(Pila& pila2){
    if(tope!=pila2.tope){
        return false;
    }
    for(int i=tope; i>=0; i--){
        if (elementos[i]!=pila2.elementos[i]){
            return false;
        }
    }
    return true;
}
//Método para revisar operaciones matemática
bool Pila::revisarOperacionMatematica(const string& expmatematica){
    Pila pilaParentesis;
    for(char c:expmatematica){
        if(c=='('){
            pilaParentesis.agregarPila(c);
        }else if(c==')'){
            if(pilaParentesis.pilaVacia()){
                return false;
            }
            pilaParentesis.sacarPila();
        }
    }
    return pilaParentesis.pilaVacia();
}
//  Método para verificar palíndromo
bool Pila::esPalindrome(const string& palabra){
    Pila tem;
    for( char c:palabra){
        tem.agregarPila(c);
    }
    for(char t:palabra){
        if(t!=tem.sacarPila()){
            return false;
        }
    }
    return true;
}
//Método para verificar prioridad
int Pila::prioridad(char op){
    if(op == '+' || op == '-') return 1;
    if(op == '*' || op == '/') return 2;
    if(op == '^') return 3;
    return 0;
}
//Método para convertir una expresión infija a postfija
string Pila::convertirInfijaPostfija(const string& infija){
    Pila pila;
    string epos = "";
    for(char simbolo : infija){
        if(simbolo=='('){
            pila.agregarPila(simbolo);
        }else if(simbolo == ')'){
            while(!pila.pilaVacia() && pila.cima()!='('){
                epos += pila.sacarPila();
            }
            pila.sacarPila();
        } else if(isalnum(simbolo)){
            epos += simbolo;
        }else{
            while(!pila.pilaVacia() && prioridad(simbolo)<=prioridad(pila.cima())){
                epos+=pila.sacarPila();
            }
            pila.agregarPila(simbolo);
        }
    }
    while(!pila.pilaVacia()){
        epos+=pila.sacarPila();
    }
    return epos;
}
//Método para convertir una expresión infija a prefija 
string Pila::convertirInfijaPrefija(const string& infija){
    Pila pila;
    string epre="";
    string invertida=infija;
    reverse(invertida.begin(), invertida.end());
    for (char& c:invertida) {
        if(c=='('){
            c=')';
        } 
        else if(c==')'){
            c='(';
        } 
    }
    for (char simbolo : invertida){
        if(isalnum(simbolo)){
            epre += simbolo;
        }else if(simbolo=='('){
            pila.agregarPila(simbolo);
        }else if(simbolo == ')'){
            while(!pila.pilaVacia() && pila.cima() != '('){
                epre += pila.sacarPila();
            }
            pila.sacarPila(); 
        }else{
            while(!pila.pilaVacia() && prioridad(simbolo)<prioridad(pila.cima())){
                epre+=pila.sacarPila();
            }
            pila.agregarPila(simbolo);
        }
    }
    while(!pila.pilaVacia()){
        epre+=pila.sacarPila();
    }
    reverse(epre.begin(), epre.end());
    return epre;
}
// Menú interactivo
void menu() {
    Pila pila1;
    Pila pila2;
    int opcion;
    char dato;
    
    do {
        system("cls");
        cout<< "\n----------------------- MENÚ ----------------------------";
        cout<<"\n==========================================================";
        cout<<"\n1. Apilar en Pila 1                                      =";  
        cout<<"\n2. Desapilar en Pila 1                                   =";
        cout<<"\n3. Mostrar Pila 1                                        =";
        cout<<"\n4. Contar elementos de Pila 1                            =";
        cout<<"\n5. Buscar un elemento en Pila 1                          =";
        cout<<"\n6. Comparar Pila 1 con Pila 2                            =";
        cout<<"\n7. Apilar en Pila 2                                      =";
        cout<<"\n8. Desapilar en Pila 2                                   =";
        cout<<"\n9. Mostrar Pila 2                                        =";
        cout<<"\n10. Contar elementos de Pila 2                           =";
        cout<<"\n11. Buscar un elemento en Pila 2                         =";
        cout<<"\n12. Comparar Pila 2 con Pila 1                           =";
        cout<<"\n13. Verificar Palíndromo                                 =";
        cout<<"\n14. Convertir a posfija                                  =";
        cout<<"\n15. Convertir a prefija                                  =";
        cout<<"\n16. Validar Paréntesis                                   =";
        cout<<"\n17. Salir                                                =";
        cout<<"\n----------------------------------------------------------";
        cout<<"\n\tOpción: ";
        cin>>opcion;  
        switch (opcion){
            case 1:
                system("cls");
                cout << "Ingrese dato a apilar en Pila 1: ";
                cin >> dato;
                pila1.agregarPila(dato);
                system("PAUSE");
                break;
            case 2:
                system("cls");
                pila1.sacarPila();
                system("PAUSE");
                break;
            case 3:
                system("cls");
                pila1.mostrarPila();
                system("PAUSE");
                break;
            case 4:
                system("cls");
                cout<<"Cantidad de elementos en Pila 1:"<< pila1.contarElementosPila()<<endl;
                system("PAUSE");
                break;
            case 5:
                system("cls");
                cout<<"Ingrese el elemento a buscar en Pila 1: ";
                cin >> dato;
                cout << "¿Está el "<<dato<< "?: " << (pila1.buscarElementoPila(dato) ? "Sí" : "No") << endl;
                system("PAUSE");
                break;
            case 6:
                system("cls");
                cout << "Las pilas son iguales?: " << (pila1.compararCon(pila2) ? "Sí" : "No") << endl;
                system("PAUSE");
                break;
            case 7:
                system("cls");
                cout << "Ingrese dato a apilar en Pila 2: ";
                cin >> dato;
                pila2.agregarPila(dato);
                system("PAUSE");
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
                cout << "¿Está el " << dato << "?: " << (pila2.buscarElementoPila(dato) ? "Sí" : "No") << endl;
                system("PAUSE");
                break;
            case 12:
                system("cls");
                cout << "Las pilas son iguales?: " << (pila2.compararCon(pila1) ? "Sí" : "No") << endl;
                system("PAUSE");
                break;
            case 13:{
                system("cls");
                string palabra;
                cout<<"ingrese una palabra: "; cin>>palabra;
                if(pila1.esPalindrome(palabra)){
                    cout<<"es palindromo\n";
                }else{
                    cout<<"no es palindromo\n";
                }
                system("PAUSE");
                break;
            }
            case 14:{
                system("cls");
                string expresion1, expPostfija;
                cout<<"ingrese una expresión: ";cin>>expresion1;
                expPostfija=pila1.convertirInfijaPostfija(expresion1);
                cout<<expPostfija<<endl;
                system("PAUSE");
                break;
            }
            case 15:{
                system("cls"); 
                string expresion2, expPrefija;
                cout<<"ingrese una expresión: ";cin>>expresion2;
                expPrefija=pila1.convertirInfijaPrefija(expresion2);
                cout<<expPrefija<<endl;
                system("PAUSE");
                break;
            }
            case 16:{
                 system("cls");
                 Pila pila;
                 string expresion;
                 cout << "Ingrese la operación matemática: "; cin >> expresion;
                 if(pila.revisarOperacionMatematica(expresion)) {
                    cout << "La expresión matemática " << expresion << " es CORRECTA." << endl;
                } else {
                    cout << "La expresión matemática " << expresion << " es INCORRECTA." << endl;
                }
                system("PAUSE");
                break;
            }
            case 17:
                cout << "Programa finalizado." << endl;
                break;
            default:
                cout << "Opción inválida." << endl;
        }
    } while (opcion !=17);
}

// Función principal para probar la clase Pila
int main() {
    SetConsoleOutputCP(CP_UTF8);
    menu();
    /*
    Pila pila;
    cout << "Agregando elementos a, b, c..." << endl;
    pila.agregarPila('a');
    pila.agregarPila('b');
    pila.agregarPila('c');
    pila.mostrarPila();
    cout << "Elemento en la cima: " << pila.cima() << endl;
    cout << "Contiene el a?: " << (pila.buscarElementoPila('a') ? "Sí" : "No") << endl;
    cout << "Contiene el d?: " << (pila.buscarElementoPila('d') ? "Sí" : "No") << endl;
    cout << "Sacando un elemento..." << endl;
    pila.sacarPila();
    pila.mostrarPila();
    cout << "Total de elementos: " << pila.contarElementosPila() << endl;
    
    // Probar comparación
    Pila pila2;
    pila2.agregarPila('a');
    pila2.agregarPila('b');
    pila2.agregarPila('g');
    pila2.mostrarPila();
    cout << "Las pilas son iguales?: " << (pila.compararCon(pila2) ? "Sí" : "No") << endl;
    
    string expresion;
    //cout << "Ingrese la operación matemática: ";
    //cin >> expresion;
    expresion = "((3+4*(8+3**2))";
    //expresion = "(3+4)*(8+3**2))";
    //expresion = "(3+4)*(8+3**2)";
    //expresion = "(3+4)*(8+3**2)(";
    //expresion = "(())(()";
    if (pila.revisarOperacionMatematica(expresion)) {
        cout << "La expresión matemática " << expresion << " es CORRECTA." << endl;
    } else {
        cout << "La expresión matemática " << expresion << " es INCORRECTA." << endl;
    }*/
    return 0;
}