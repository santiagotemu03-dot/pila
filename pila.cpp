#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

struct pilas
{
    int d;
    pilas *a;
}*c,*e;

const int MAX_ELEM = 5;

int contar(void)
{
    int n=0;
    pilas *t=c;
    while(t)
    {
        n++;
        t=t->a;
    }
    return n;
}

void ingresar (void)
{
    if(contar() >= MAX_ELEM)
    {
        cout<<"\n\nLa pila esta LLENA, no se puede ingresar mas elementos!!";
        return;
    }
    if(!c)
    {
        c=new(pilas);
        cout<<"Ingrese elemento: ";
        cin>>c->d;
        c->a=NULL;
        return;
    }

    e=new(pilas);
    cout<<"\nIngrese elemento: ";
    cin>>e->d;
    e->a=c;
    c=e;
}

void ultimo(void)
{
    e = c;
    while(e != NULL)
    {
        if(e->a == NULL)
        {
            cout << "el primer dato ingresado fue: " << e->d;
        }
        e = e->a;
    }
}

void sacar(void)
{
    if(!c)
    {
        cout<<"\n\nNo hay elementos!!";
        return;
    }

    e=c;
    cout<<"\n\nElemento eliminado: " <<e->d;
    c=e->a;
    delete(e);
}

void actualizar_pila(void)
{
    int i,ca=0;
    e=c;
    while(e)
    {
        ca++;
        e=e->a;
    }

    for(i=0;i<=ca;i++)
    {
        cout<<" ";
    }
    i=0;
    e=c;
    while(e)
    {
        cout<<"\n";
        cout<<++i<<" - "<<e->d;
        e=e->a;
    }
}

void primero(void)
{
    if(!c)
    {
        cout<<"\n\nPila vacia! No hay elemento para salir.";
        return;
    }
    cout<<"\n\nEl primero en salir es: "<<c->d;
}

void estado(void)
{
    if(!c)
        cout<<"\n\nLa pila esta VACIA (0/"<<MAX_ELEM<<")";
    else if(contar() >= MAX_ELEM)
        cout<<"\n\nLa pila esta LLENA ("<<contar()<<"/"<<MAX_ELEM<<")";
    else
        cout<<"\n\nLa pila NO esta llena ("<<contar()<<"/"<<MAX_ELEM<<")";
}

void vaciar(void)
{
    while(c)
    {
        e=c;
        c=c->a;
        delete(e);
    }
    e=NULL;
    cout<<"\n\nPila vaciada!!";
}

void menu(void)
{
    int opc;
    for(;;)
    {
        cout<<"\n1. Ingresar datos";
        cout<<"\t2. extraer datos";
        cout<<"\t3. el ultimo salir";
        cout<<"\n4. Primero en salir";
        cout<<"\t5. Pila llena o vacia";
        cout<<"\t6. Vaciar pila";
        cout<<"\t0. Terminar";
        cout<<"\n Ingrese opcion: ";
        if(!(cin>>opc))
            exit(0);
        switch(opc)
        {
            case 1:
                ingresar();
                break;
            case 2:
                sacar();
                break;
            case 3:
                ultimo();
                break;
            case 4:
                primero();
                break;
            case 5:
                estado();
                break;
            case 6:
                vaciar();
                break;
            case 0:
                exit(0);
            default:
                cout<<"\n Opcion no valida!!";
                break;
        }

        actualizar_pila();
        cout<<"\n\nOprima ENTER para continuar";
        cin.ignore(10000,'\n');
        cin.get();
    }
}

int main()
{
    menu();
    return 0;
}