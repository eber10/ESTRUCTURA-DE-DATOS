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
void recorre(Nodo *);
void elimina_inicio(Nodo *&, Nodo *&);
void elimina_ultimo(Nodo *&, Nodo *&);
void elimina_x(Nodo *&, Nodo *&, int x);
void elimina_antes_x(Nodo *&, Nodo *&, int x);
void elimina_despues_x(Nodo *&, Nodo *&, int x);
void MoverMenor(Nodo *&, Nodo *&);
void MoverMayor(Nodo *&, Nodo *&);
void eliminarRepetidos(Nodo *&, Nodo *&);
void eliminarCoincidentes(Nodo *&p, Nodo *&f, int x);
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
void recorre(Nodo *p){
    Nodo *q=p;
    if(q!=NULL){
        system("cls");
        cout<< "Proceso completado con éxito...." << endl;
        system("PAUSE");
        cout<<"\n----------------------------------------";
        cout<<"\n           LISTA DE DATOS:              ";
        cout<<"\n========================================\n\n";
        while(q!=NULL){
            cout<<q->info<<" -> ";
            q=q->ligader;
        }
        cout<<"NULL\n";
    }else{
        cout<<"Lista vacia....\n";
    }
   
}
void elimina_inicio(Nodo *&p, Nodo *&f){
    Nodo *q=p;
    if(q->ligader!=NULL){
        p=q->ligader;
        p->ligaizq=NULL;
    }else{
        p=NULL;
        f=NULL;
    }
    delete(q);
}
void elimina_ultimo(Nodo *&p, Nodo *&f){
    Nodo *q=f;
    if(q->ligaizq!=NULL){
        f=q->ligaizq;
        f->ligader=NULL;
    }else{
        p=NULL;
        f=NULL;
    }
    delete(q);
}
void elimina_x(Nodo *&p, Nodo *&f, int x){
    Nodo *q=p;
    Nodo *t;
    Nodo *r;
    if(q!=NULL){
        while((q->ligader!=NULL)&&(q->info!=x)){
            q=q->ligader;
        }
        if(q->info==x){
            if(q==p && q==f){
                p=NULL;
                f=NULL;
            }else{
                if(q==p){
                    p=q->ligader;
                    p->ligaizq=NULL;
                }else{
                    if(q==f){
                        f=q->ligaizq;
                        f->ligader=NULL;
                    }else{
                        t=q->ligaizq;
                        r=q->ligader;
                        t->ligader=r;
                        r->ligaizq=t;
                    }
    
                }
            }
            recorre(p);
        }else{
            cout<<"El valor a eliminar no existe en la lista...\n";
        }
    }else{
        cout<<"Lista vacia.....\n";
    }

}
void elimina_antes_x(Nodo *&p, Nodo *&f, int x){
    Nodo *q=p;
    Nodo *t;
    Nodo *r;
    if(q!=NULL){
        while((q->ligader!=NULL)&&(q->info!=x)){
            q=q->ligader;
        }
        if(q->info==x){
            if(q==p){
                cout<<"no existe un nodo anterior..\n";
            }else{
                t=q->ligaizq;
                if(t==p){
                    p=q;
                    p->ligaizq=NULL;
                }else{
                    r=t->ligaizq;
                    q->ligaizq=r;
                    r->ligader=q;
                }
                delete(t);
                recorre(p);
            }
        }else{
            cout<<"El valor "<<x<<" no se encuentra en lista... \n";
        }
    }else{
        cout<<"Lista vacia...\n";
    }

}
void elimina_despues_x(Nodo *&p, Nodo *&f, int x){
    Nodo *q=p;
    Nodo *t;
    Nodo *r;
    if(q!=NULL){
        while((q->ligader!=NULL)&&(q->info!=x)){
            q=q->ligader;
        }
        if(q->info==x){
            if(q==f){
                cout<<"No existe un nodo posterior..\n";
            }else{
                t=q->ligader;
                if(t==f){
                    f=q;
                    f->ligader=NULL;
                }else{
                    r=t->ligader;
                    q->ligader=r;
                    r->ligaizq=q;
                }
                delete(t);
                recorre(p);
            }
        }else{
            cout<<"El valor "<<x<<" no se encuentra en lista... \n";
        }

    }else{
        cout<<"Lista vacia..\n";
    }

}
void MoverMenor(Nodo *&p, Nodo *&f){
    Nodo *q=p;
    Nodo *menor=p;
    Nodo *t;
    Nodo *r;
    if(q!=NULL){
        while(q!=NULL){
            if(q->info<menor->info){
                menor=q;
            }
            q=q->ligader;
        }
        if(menor==p){
            cout<<"El menor valor se encuentra en la posición inicial..\n";
        }else{
            if(menor==f){
                f=menor->ligaizq;
                f->ligader=NULL;
            }else{
                r=menor->ligaizq;
                t=menor->ligader;
                r->ligader=t;
                t->ligaizq=r;
            }
            menor->ligader=p;
            menor->ligaizq=NULL;
            p->ligaizq=menor;
            p=menor;
            recorre(p);
        }

    }else{
        cout<<"Lista vacia...\n";
    }
}
void MoverMayor(Nodo *&p, Nodo *&f){
    Nodo *q=p;
    Nodo *mayor=p;
    Nodo *t;
    Nodo *r;
    if(q!=NULL){
        if(q->ligader!=NULL){
            while(q!=NULL){
                if(q->info>mayor->info){
                    mayor=q;
                }
                q=q->ligader;
            }
            if(mayor==f){
                cout<<"El mayor valor se encuentra en la posición final..\n";
            }else{
                if(mayor==p){
                    p=mayor->ligader;
                    p->ligaizq=NULL;
                }else{
                    r=mayor->ligaizq;
                    t=mayor->ligader;
                    r->ligader=t;
                    t->ligaizq=r;
                }
                mayor->ligader=NULL;
                mayor->ligaizq=f;
                f->ligader=mayor;
                f=mayor;
                recorre(p);
            }

        }else{
            cout<<"La lista tiene un solo elemento\n";
        }
        
    }else{
        cout<<"Lista vacia...\n";
    }

}
void eliminarRepetidos(Nodo *&p, Nodo *&f){
    Nodo *q=p;
    Nodo *t;
    Nodo *r;
    Nodo *s;
    if(q!=NULL){
        if(q->ligader!=NULL){
            while(q!=NULL){
                if((q->ligader!=NULL) && (q->info==q->ligader->info)){
                    t=q;
                    if(p==t){
                        p=q->ligader;
                        p->ligaizq=NULL;
                    }else{
                        r=t->ligaizq;
                        s=t->ligader;
                        r->ligader=s;
                        s->ligaizq=r;
                    }
                    q=q->ligader;
                    delete(t);
                }else{
                    q=q->ligader;
                }
        }
        recorre(p);
        }else{
            cout<<"La lista tiene un solo elemento\n";

        }
        
    }else{
        cout<<"Lista vacia...\n";
    }
}
void eliminarCoincidentes(Nodo *&p, Nodo *&f, int x){
    Nodo *q=p;
    Nodo *t;
    Nodo *r;
    Nodo *s;
    if(q!=NULL){
        while(q!=NULL){
            if(q->info==x){
                t=q;
                if(q==p && q==f){
                    p=f=NULL;
                }else{
                    if(q==p){
                        p=q->ligader;
                        p->ligaizq=NULL;
                    }else{
                        if(q==f){
                            f=q->ligaizq;
                            f->ligader=NULL;
                        }else{
                            r=t->ligaizq;
                            s=t->ligader;
                            r->ligader=s;
                            s->ligaizq=r;
                        }
                    }
                }
                q=q->ligader;
                delete(t);
            }else{
                q=q->ligader;
            }
        }
        recorre(p);
    }else{
        cout<<"Lista vacia...\n";
    }
}

void menu() {
    Nodo *p = NULL;
    Nodo *f = NULL;
    int opcion, dato, x;
    char op;
    do {
        system("cls");
        cout<< "\n---------------------- MENÚ ----------------------------";
        cout<<"\n==========================================================";
        cout<< "\n1.  Insertar al inicio                                   =";
        cout<< "\n2.  Insertar al final                                    =";
        cout<< "\n3.  Insertar antes de un nodo con dato X                 =";
        cout<< "\n4.  Insertar después de un nodo con dato X               =";
        cout<< "\n5.  Mostrar lista de inicio a fin                        =";
        cout<< "\n6.  Mostrar lista de fin a inicio                        =";
        cout<< "\n7.  Contar ocurrencias de un dato                        =";
        cout<< "\n8.  Invertir lista                                       =";
        cout<< "\n9.  Eliminar el primer nodo                              =";
        cout<< "\n10. Eliminar el último nodo                              =";
        cout<< "\n11. Eliminar el nodo con información x                   =";
        cout<< "\n12. Eliminar el nodo anterior al nodo con información x  =";
        cout<< "\n13. Eliminar el nodo posterior al nodo con información x =";
        cout<< "\n14. Mover el menor elemento a la primera posición        =";
        cout<< "\n15. Mover el mayor elemento a la última posición         =";
        cout<< "\n16. Eliminar valores repetidos                           =";
        cout<< "\n17. Eliminar valores coincidentes                        =";
        cout<< "\n0. S a l i r                                             =";
        cout<<"\n=========================================================";
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
                recorre(p);
                system("PAUSE");
                break;
            case 4:
                system("cls");
                cout << "dato a insertar: ";
                cin >> dato;
                cout << "Después del nodo con dato: ";
                cin >> x;
                inserta_despues_X(p, f, dato, x);
                recorre(p);
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
                recorre(p);
                system("PAUSE");
                break;
            case 9:
                system("cls");
                elimina_inicio(p,f);
                recorre(p);
                system("PAUSE");
                break;
            case 10:
                system("cls");
                elimina_ultimo(p,f);
                recorre(p);
                system("PAUSE");
                break;
            case 11:
                system("cls");
                cout<<"Ingrese el valor a eliminar: "; cin>>x;
                elimina_x(p,f,x);
                system("PAUSE");
                break;
            case 12:
                system("cls");
                cout<<"Ingrese el valor: "; cin>>x;
                elimina_antes_x(p,f,x);
                system("PAUSE");
                break;
            case 13:
                system("cls");
                cout<<"Ingrese el valor: "; cin>>x;
                elimina_despues_x(p,f,x);
                system("PAUSE");
                break;
            case 14:
                system("cls");
                MoverMenor(p,f);
                system("PAUSE");
                break;
            case 15:
                system("cls");
                MoverMayor(p,f);
                system("PAUSE");
                break;
            case 16:
                system("cls");
                eliminarRepetidos(p,f);
                system("PAUSE");
                break;
            case 17:
                system("cls");
                cout<<"Ingrese el valor a eliminar: "; cin>>x;
                eliminarCoincidentes(p,f,x);
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