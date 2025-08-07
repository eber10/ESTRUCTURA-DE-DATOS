#include<iostream>
#include<string>
using namespace std;
struct Nodo{
    char info;
    Nodo* liga;
};
class Pila{
    private:
        Nodo* tope;
    public:
        Pila(){
        tope=nullptr;
    }
    void agregarPila(char letra){
        Nodo* q=new Nodo();
        q->info=letra;
        q->liga=tope;
        tope=q;
    }
    char sacarPila(){
        char letra=tope->info;
        Nodo* q=tope;
        tope=tope->liga;
        delete(q);
        return letra;
    }
    bool esPalindromo(string palabra){
        for(char c:palabra){
            agregarPila(c);
        }
        for(char c:palabra){
            if(c!=sacarPila()){
                return false;
            }
        }
        return true;
    }
};
int main(){
    string palabra;
    char op;
    do{
        system("cls");
        cout<<"Ingrese una palabra: "; cin>>palabra;
        Pila p;
        if(p.esPalindromo(palabra)){
            cout<<"Es palindromo\n";
        }else{
            cout<<"No es palindromo\n";
        }
        cout<<"Desea ingresar otra palabra (S:N) ?: "; cin>>op;
    }while(op=='s' or op=='S');
    return 0;
}