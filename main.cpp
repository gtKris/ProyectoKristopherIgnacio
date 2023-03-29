#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
#include <iostream>

struct Nodo
{
       int dato;
       Nodo *der, *izq, *padre;     //Estructura del arbol
};

int cantidadDeHojas(Nodo *);
void destruirNodo(Nodo *);
void reemplazar(Nodo *,Nodo *);
Nodo *minimo(Nodo *);
bool busqueda(Nodo *,int);
void eliminarNodo(Nodo *);                    //Prototipos de funcion
void menu();
void menu2();
void preOrden(Nodo *);
void inOrden(Nodo *);
void PosOrden(Nodo *);
Nodo *crearNodo(int,Nodo *);
void insertarNodo(Nodo *&,int,Nodo *);
int alturaDelArbol(Nodo*);
void eliminar(Nodo *,int);

Nodo * arbol=NULL;

int main(){

menu();
getch();
return 0;
}
void menu(){

int dato,opcion;
do{
system("cls");
cout<<"\t.:MENU PRINCIPAL:."<<endl;
cout<<"1. INSERTAR UN NODO"<<endl;
cout<<"2. VISUALIZAR EL CONTENIDO DEL ARBOL "<<endl;
cout<<"3. ELIMINAR UN NODO DEL ARBOL"<<endl;
cout<<"4. BUSCAR UN ELEMENTO EN EL ARBOL"<<endl;         //Menu principal
cout<<"5. Cantidad de hojas del arbol"<<endl;
cout<<"6. Altura del arbol"<<endl;
cout<<"7. Salir"<<endl;
cout<<"DIGITE LA OPCION "<<endl;
cin>>opcion;

switch(opcion){
   system("cls");
case 1:
            cout<<"1. INSERTE UN NUMERO : "<<endl;
cin>>dato;
insertarNodo(arbol,dato,NULL);
cout<<"\n";
system("pause");
break;
case 2:
   system("cls");
menu2();
cout<<"\n";
    system("pause");
break;

case 3:                                                                //Diferentes casos
   system("cls");
   cout<<" INSERTE UN NUMERO A ELIMINAR: "<<endl;
cin>>dato;
eliminar(arbol,dato);
cout<<"\n";
    system("pause");
break;
case 4:
   system("cls");
                cout<<" INSERTE UN NUMERO A BUSCAR: "<<endl;
cin>>dato;
if(busqueda(arbol,dato)==true){
cout<<"\nELEMENTO :  "<<dato<<"   HA SIDO ENCONTRADO EN EL ARBOL";
}
else{
cout<<"\n EL ELEMENTO NO HA SIDO ENCONTRADO";
}
cout<<"\n";
    system("pause");
break;

case 5:
                       cout<<" La cantidad de hojas es: "<<cantidadDeHojas(arbol)<<endl;
                       cout<<"Presione una tecla para continuar"<<endl;
                       getch();

break;

case 6:
                       cout<<" La altura del arbol es: "<<alturaDelArbol(arbol)<<endl;
                       cout<<"Presione una tecla para continuar"<<endl;
                       getch();

break;


}
   }while(opcion !=7);
}
void menu2(){

    system("cls");
int dato,opcion;
do{
        system("cls");
cout<<"\t.:MENU DEL ORDEN DEL ARBOL:."<<endl;
cout<<"1. ORDEN PREVIO "<<endl;
cout<<"2. INORDEN "<<endl;
cout<<"3. ORDEN POSTERIOR "<<endl;
cout<<"4. REGRESAR "<<endl;                                           //Menu 2
cout<<"DIGITE LA OPCION "<<endl;
cin>>opcion;

switch(opcion){
   system("cls");
case 1:
   system("cls");
   cout<<"4. EL RECORRIDO EN PREORDEN ES : "<<endl;
preOrden(arbol);
cout<<"\n";
system("pause");
break;
case 2:
   system("cls");
                cout<<"4. EL RECORRIDO IN ORDEN  ES : "<<endl;
inOrden(arbol);
cout<<"\n";
system("pause");
break;
case 3:
   system("cls");
   cout<<"4. EL RECORRIDO IN ORDEN  ES : "<<endl;
PosOrden(arbol);
cout<<"\n";
system("pause");
}
   }while(opcion !=4);
}

void preOrden(Nodo *arbol){
if(arbol==NULL){

      return;
    }                                      //Recorrido en preorden
    else{
    cout<<arbol->dato<<" "<<endl;
      preOrden(arbol->izq);
      preOrden(arbol->der);
  }
}
void inOrden(Nodo *arbol){
if(arbol==NULL){

      return;
    }
    else{                                  //Recorrido en inorden
    inOrden(arbol->izq);
    cout<<arbol->dato<<" "<<endl;
      inOrden(arbol->der);
  }
}
void PosOrden(Nodo *arbol){
if(arbol==NULL){

      return;
    }
    else{
    PosOrden(arbol->izq);                     //Recorrido posorden
      PosOrden(arbol->der);
      cout<<arbol->dato<<" "<<endl;
  }
}

Nodo* crearNodo(int n, Nodo *padre)
{
Nodo *nuevo_nodo = new Nodo();

    nuevo_nodo ->dato=n;
    nuevo_nodo ->der= NULL;               //Crear nodo
    nuevo_nodo ->izq= NULL;
    nuevo_nodo->padre= padre;

    return  nuevo_nodo;
}

void insertarNodo(Nodo *&arbol,int n, Nodo *padre){
if(arbol==NULL){
Nodo *nuevo_nodo=crearNodo(n,padre);              //Inserta nodo
arbol = nuevo_nodo;


}
else{
int valorRaiz = arbol->dato;
if(n < valorRaiz){
insertarNodo(arbol->izq,n,arbol);      //Inserta a la izquierda

}
else{
insertarNodo(arbol->der,n,arbol);
                                   //Inserta a la derecha
}
}

}

void eliminar(Nodo *arbol,int n){
if(arbol== NULL){
return;
}
else if (n < arbol->dato){
eliminar(arbol->izq,n);             //Elimina del arbol
}
else if (n >arbol->dato){
eliminar(arbol->der,n);
}
else{
eliminarNodo(arbol);
}

}

Nodo *minimo(Nodo *arbol){
if(arbol== NULL){
return NULL;
}
if(arbol->izq){
return minimo(arbol->izq);
}
else{
return arbol;
}

}

void eliminarNodo(Nodo *nodoEmilinar){
if(nodoEmilinar->izq && nodoEmilinar->der){
Nodo *menor = minimo(nodoEmilinar->der);      //Elimina nodo
nodoEmilinar->dato= menor->dato;
eliminarNodo(menor);
}
else if(nodoEmilinar->izq){
reemplazar(nodoEmilinar,nodoEmilinar->izq);
destruirNodo(nodoEmilinar);
}
else if (nodoEmilinar->der){
reemplazar(nodoEmilinar,nodoEmilinar->der);
destruirNodo(nodoEmilinar);
}
else{
reemplazar(nodoEmilinar,NULL);
destruirNodo(nodoEmilinar);

}
}

void reemplazar(Nodo *arbol,Nodo *nuevoNodo){
if(arbol->padre){
if(arbol->dato==arbol->padre->izq->dato){
arbol->padre->izq=nuevoNodo;
}                                                         //Reemplaza del nodo
else if(arbol->dato==arbol->padre->der->dato){
arbol->padre->der = nuevoNodo;
}
}
if(nuevoNodo){
nuevoNodo->padre=arbol->padre;
}
}

void destruirNodo(Nodo *nodo){
nodo->izq= NULL;
nodo->der= NULL;                      //destruye nodo
delete nodo;

}


int alturaDelArbol(Nodo *arbol) {
  if (arbol == NULL) {                              //Calcula la altura
    return -1;
  }
  return 1 + max(alturaDelArbol(arbol->izq), alturaDelArbol(arbol->der));
}



int cantidadDeHojas(Nodo *arbol) {
  if (arbol == NULL) {
    return 0;
  }                                 //Calcula la cantidad de hojas
  if (arbol->izq == NULL && arbol->der == NULL) {
    return 1;
  }
  return cantidadDeHojas(arbol->izq) + cantidadDeHojas(arbol->der);
}

bool busqueda(Nodo *arbol,int n){
if(arbol == NULL){
return false;
}
else if(arbol->dato==n){
return true;
}
else if(n< arbol->dato){
return busqueda(arbol->izq,n);
}
else{
return busqueda(arbol->der,n);
}
}
