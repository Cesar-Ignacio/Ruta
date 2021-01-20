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


///PROTOTIPO
void Punto_A(void);
int NombreCiudad(char *,char *);
void NombreProvincia(int,char *);

void Punto_B(void);
void Punto_C(void);


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
        Punto_A();
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
    /**La ruta más larga, indicando los nombres de la ciudad y la provincia de
origen y de fin.*/

  RUTA obj;


  obj.LEER(0);

  int c_prov=0,pos=0,canreg=CantidadReg(ARCHIVO_RUTA,sizeof(RUTA));
  float longitud=obj.getlongitud();
  char  nombre[30];


  for(int x=1;x<canreg;x++)
  {
      obj.LEER(x);

      if(obj>longitud)
      {
        pos=x;
        longitud=obj.getlongitud();
      }

  }
  obj.LEER(pos);

  cout<<"RUTA MAS LARGA :"<< obj.getcruta()<<endl;

  c_prov=NombreCiudad(obj.getciudadI(),nombre);

  cout<<"CIUDAD DE INICIO:"<< nombre<<endl;

  NombreProvincia(c_prov,nombre);

  cout<<"PROVINCIA:"<<nombre<<endl;

  c_prov=NombreCiudad(obj.getciudadF(),nombre);

  cout<<"CIUDAD DE FIN:"<< nombre<<endl;

  NombreProvincia(c_prov,nombre);
  cout<<"PROVINCIA:"<<nombre<<endl;

  system("pause>null");
  system("cls");
}

int NombreCiudad(char *ciudad,char *nombre)
{
    CIUDAD obj;
    int canreg=CantidadReg(ARCHIVO_CIUDAD,sizeof(CIUDAD));
    for(int x=0;x<canreg;x++)
    {
        obj.LEER(x);

        if(obj==ciudad)
        {
         strcpy(nombre,obj.getnombre());
         return obj.getprovincia();
        }
    }
}

void NombreProvincia(int c_pro, char *nombre)
{
    PROVICIA obj;

    int canreg=CantidadReg(ARCHIVO_PROVINCIA,sizeof(PROVICIA));

    for(int x=0;x<canreg;x++)
    {
        obj.LEER(x);

        if(obj==c_pro)
        {
           strcpy(nombre,obj.getnombre());
        }
    }

}


void Punto_B()
{
    /**Generar un archivo con el código de rutay la cantidad de días en que estuvo
intransitable esa ruta en el año 2015. No deben aparecer las rutas que
estuvieron transitables durante todo el año.*/

}

void Punto_C()
{
    /**) La cantidad de rutas de cada tipo.*/

}

