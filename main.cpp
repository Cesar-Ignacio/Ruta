#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <limits>
using namespace std;


const char *ARCHIVO_PROVINCIA={"provincia.dat"};
const char *ARCHIVO_CIUDAD={"ciudad.dat"};
const char *ARCHIVO_RUTA={"ruta.dat"};


#include "CLASS.h"
#include "PROTOTIPO.h"
#include "funciones.h"
#include "MENU.h"


///FUNCION PRINCIPAL
int main()
{


    int opc;

    while(1)
    {

        cout<<"MENU"<<endl;
        cout<<"***************"<<endl;
        cout<<"1- PUNTO A"<<endl;
        cout<<"2- PUNTO B"<<endl;
        cout<<"3- PUNTO C"<<endl;
        cout<<"4- CARGAR DATOS"<<endl;
        cout<<"***************"<<endl;
        cin>>opc;

        system("cls");

        if(opc==1)
        {

        }
        if(opc==2)
        {


        }
        if(opc==3)
        {

        }
        if(opc==4)
        {
            submenu();
        }
        if(opc==0)
        {
            return 0;
        }



    }



    return 0;
}

///DEFCION

void Punto_A()
{
    /**La ruta m�s larga, indicando los nombres de la ciudad y la provincia de
origen y de fin.*/


}

void Punto_B()
{
    /**Generar un archivo con el c�digo de rutay la cantidad de d�as en que estuvo
intransitable esa ruta en el a�o 2015. No deben aparecer las rutas que
estuvieron transitables durante todo el a�o.*/

}

void Punto_C()
{
    /**) La cantidad de rutas de cada tipo.*/

}

