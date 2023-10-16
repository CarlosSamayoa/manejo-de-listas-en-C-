#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <string.h>
#include <locale.h>
using namespace std;

struct Nodo{
    int dato;
    Nodo *siguiente;
};

void insertarInicio(Nodo *&lista, int n){
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dato = n;
    nuevo_nodo->siguiente = lista;
    lista = nuevo_nodo;
    cout << "Elemento " << n << " insertado al inicio de la lista" << endl;
}

void insertarFinal(Nodo *&lista, int n){
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dato = n;
    nuevo_nodo->siguiente = NULL;
    if(lista == NULL){
        lista = nuevo_nodo;
    }else{
        Nodo *aux = lista;
        while(aux->siguiente != NULL){
            aux = aux->siguiente;
        }
        aux->siguiente = nuevo_nodo;
    }
    cout << "Elemento " << n << " insertado al final de la lista" << endl;
}

void insertarPosicion(Nodo *&lista, int n, int pos){
    if(pos <= 0){
        cout << "Posicion invalida" << endl;
        return;
    }
    if(pos == 1){
        insertarInicio(lista, n);
        return;
    }
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dato = n;
    Nodo *aux = lista;
    int i = 1;
    while(aux != NULL && i < pos-1){
        aux = aux->siguiente;
        i++;
    }
    if(aux == NULL){
        cout << "Posicion invalida" << endl;
        return;
    }
    nuevo_nodo->siguiente = aux->siguiente;
    aux->siguiente = nuevo_nodo;
    cout << "Elemento " << n << " insertado en la posicion " << pos << " de la lista" << endl;
}

void eliminarElemento(Nodo *&lista, int n){
    if(lista == NULL){
        cout << "Lista vacia" << endl;
        return;
    }
    if(lista->dato == n){
        Nodo *aux = lista;
        lista = lista->siguiente;
        delete aux;
        cout << "Elemento " << n << " eliminado de la lista" << endl;
        return;
    }
    Nodo *aux = lista;
    while(aux->siguiente != NULL && aux->siguiente->dato != n){
        aux = aux->siguiente;
    }
    if(aux->siguiente == NULL){
        cout << "Elemento no encontrado en la lista" << endl;
        return;
    }
    Nodo *eliminar = aux->siguiente;
    aux->siguiente = eliminar->siguiente;
    delete eliminar;
    cout << "Elemento " << n << " eliminado de la lista" << endl;
}

void eliminarLista(Nodo *&lista){
    if(lista == NULL){
        cout << "Lista vacia" << endl;
        return;
    }
    char opcion;
    cout << "Esta seguro que desea eliminar la lista? (S/N)" << endl;
    cin >> opcion;
    if(opcion == 'S' || opcion == 's'){
        Nodo *aux = lista;
        while(aux != NULL){
            Nodo *eliminar = aux;
aux = aux->siguiente;
delete eliminar;
}
lista = NULL;
cout << "Lista eliminada" << endl;
}else{
cout << "Operacion cancelada" << endl;
}
}

void mostrarLista(Nodo *lista){
if(lista == NULL){
cout << "Lista vacia" << endl;
return;
}
int i=0;
Nodo *aux = lista;
cout << "Lista: \n";
while(aux != NULL){
	i=i+1;
cout <<i<< ") "<< aux->dato << "\n";
aux = aux->siguiente;
}
cout <<  endl;
}

int main(){
Nodo *lista = NULL;
int opcion, num, pos;
system("color 90");
		setlocale(LC_ALL, "es_ES");

		cout << "\t\t\t\t Proyecto Final \n\n\n\n\n";

		system("PAUSE");
		system("cls");
		system("color 70");
do{
	system("cls");
cout << "\n|--------------------------------|\n";
cout <<   "|             Menu               |\n";	
cout <<   "|--------------------------------|\n";
cout <<   "| 1. Ingresar al inicio          |\n";
cout <<   "|--------------------------------|\n";
cout <<   "| 2. Ingresar al final           |\n";
cout <<   "|--------------------------------|\n";
cout <<   "| 3. Ingresar posicion especifica|\n";
cout <<   "|--------------------------------|\n";
cout <<   "| 4. Eliminar elemento           |\n";
cout <<   "|--------------------------------|\n";
cout <<   "| 5. Eliminar lista completa     |\n";
cout <<   "|--------------------------------|\n";
cout <<   "| 6. Mostrar lista               |\n";
cout <<   "|--------------------------------|\n";
cout <<   "| 7. Salir                       |\n";
cout <<   "|--------------------------------|\n";
cout << "Ingrese una opcion: ";
cin >> opcion;
    switch(opcion){
        case 1:
        	system("cls");
            cout << "Ingrese un numero par: ";
            cin >> num;
            if(num%2 == 0){
                insertarInicio(lista, num);
            }else{
                cout << "Numero impar, ingreso invalido" << endl;
            }
            system("pause");
            break;
        case 2:
        	system("cls");
            cout << "Ingrese un numero impar: ";
            cin >> num;
            if(num%2 == 1){
                insertarFinal(lista, num);
            }else{
                cout << "Numero par, ingreso invalido" << endl;
            }
            system("pause");
            break;
        case 3:
        	system("cls");
            cout << "Ingrese un numero: ";
            cin >> num;
            cout << "Ingrese la posicion: ";
            cin >> pos;
            insertarPosicion(lista, num, pos);
            system("pause");
            break;
        case 4:
        	system("cls");
            cout << "Ingrese el elemento a eliminar: ";
            cin >> num;
            eliminarElemento(lista, num);
            system("pause");
            break;
        case 5:
        	system("cls");
            eliminarLista(lista);
            system("pause");
            break;
        case 6:
        	system("cls");
            mostrarLista(lista);
            system("pause");
            break;
        case 7:
        	system("cls");
            cout << "Saliendo del programa..." << endl;
            break;
        default:
            cout << "Opcion invalida" << endl;
    }

}while(opcion != 7);

return 0;
}