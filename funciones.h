#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

///PROVINCIA
void CARGAR_PROVINCIA()
{
    PROVICIA objP;
    int cprovincia;
    cout<<"C_ PROVINCIA:";///HACER UNA FUCNCION PARA VALIDAR C_PROVINCIA
    cin>>cprovincia;

    while(Existencia_PV(cprovincia))
    {
    cout<<"C_ PROVINCIA:";///HACER UNA FUCNCION PARA VALIDAR C_PROVINCIA
    cin>>cprovincia;

    }
    objP.setcprovincia(cprovincia);
    objP.ALTA();

    system("pause>null");
    system("cls");
}

void ELIMINAR_PROVINCIA()
{

    PROVICIA obj;

    int cprovicia, pos=0;

    cout<<"INGRESE CODIGO DE PROVINCIA:";
    cin>>cprovicia;

    pos=BuscarProvincia(cprovicia);

    if(pos!=-1)
    {

    obj.LEER(pos);

    obj.setestado(0);

    obj.MODIFICACION(pos);
    }else
    {
    cout<<"NO SE ENCONTRO EL REG"<<endl;
    }


    system("pause>null");
    system("cls");


}

void MOSTRAR_PROVINCIA()
{
PROVICIA obj;

  int canreg=CantidadReg(ARCHIVO_PROVINCIA,sizeof(PROVICIA));

  cout<<"LISTA DE PROVINCIAS \n"<<endl;

  for(int x=0;x<canreg;x++)
  {
  obj.LEER(x);
  obj.MOSTRAR();
  }
  system("pause>null");
    system("cls");

}


int BuscarProvincia(int cpro)
{
    PROVICIA obj;

    int pos,canreg=CantidadReg(ARCHIVO_PROVINCIA,sizeof(PROVICIA));

    for(int x=0;x<canreg;x++)
    {
    obj.LEER(x);

    if(obj==cpro)
    {
        return x;
    }

    }

  return -1;

}

///CIUDAD

void CARGAR_CIUDAD()
{
    CIUDAD obj;

    char ciudad[5];
    fflush(stdin);
    cout<<"C_CIUDAD:";
    cin.getline(ciudad,5);

    while(Existencia_C(ciudad)!=0)
    {
     fflush(stdin);
    cout<<"C_CIUDAD:";
    cin.getline(ciudad,5);
    }
    obj.setciudad(ciudad);
    obj.CARGAR();
    obj.setcprovincia(Validar_CP_C());
    obj.ALTA();
    system("pause>null");
    system("cls");
}

void ELIMINAR_CIUDAD()
{
    CIUDAD obj;
    char ciudad[5];
    int pos=0;
    cout<<"ELIMAR CIUDAD \n"<<endl;

    fflush(stdin);
    cout<<"C_CIUDAD:";
    cin.getline(ciudad,5);

    pos=BuscarCiudad(ciudad);

    if(pos!=-1)
    {
        obj.LEER(pos);

        obj.setestado(0);

        obj.MODIFICACION(pos);

        cout<<"SE ELIMINO EL REG"<<endl;
    }
    else
    {
    cout<<"NO SE ENCONTRO LA CIUDAD"<<endl;
    }

   system("pause>null");
   system("cls");


}

void MOSTRAR_CIUDAD()
{

   CIUDAD obj;

   int canreg=CantidadReg(ARCHIVO_CIUDAD,sizeof(CIUDAD));

   cout<<"LISTA DE LA CIUDADES \n"<<endl;

   for(int x=0;x<canreg;x++)
   {
        obj.LEER(x);
        obj.MOSTRAR();

   }
   system("pause>null");
   system("cls");

}

int BuscarCiudad(char *ciudad)
{
    CIUDAD obj;

    int canreg=CantidadReg(ARCHIVO_CIUDAD,sizeof(CIUDAD));


    for(int x=0;x<canreg;x++)
    {
        obj.LEER(x);

        if(obj==ciudad)
        {
            return x;
        }
    }

    return -1;

}

/// RUTA

void CARGAR_RUTA()
{
    RUTA obj;
    char Cruta[5];

    fflush(stdin);
    cout<<"C_RUTA:";
    cin.getline(Cruta,5);
/**
    while(Existencia_R(Cruta)!=0)
    {
    fflush(stdin);
    cout<<"C_RUTA:";
    cin.getline(Cruta,5);
    }*/
    obj.setcruta(Cruta);
    obj.CARGAR();

    obj.ALTA();


    system("pause>null");
    system("cls");

}

void MOSTRAR_RUTA()
{
    RUTA obj;


    int canreg=CantidadReg(ARCHIVO_RUTA,sizeof(RUTA));


    for(int x=0;x<canreg;x++)
    {
        obj.LEER(x);
        obj.MOSTRAR();

    }


}


///GENERAL

int Existencia_PV(int provincia)
{

     PROVICIA obj;

     int canreg=CantidadReg(ARCHIVO_PROVINCIA,sizeof(PROVICIA));

     for(int x=0;x<canreg;x++)
     {
         obj.LEER(x);

         if((obj==provincia) && (obj.getestado()==1))
         {
             return 1;
         }

     }

   return 0;
}

int Validar_CP_C()
{

    int cprovincia=0;
     cout<<"C_PROVINCIA:";
     cin>>cprovincia;

     while(Existencia_PV(cprovincia)!=1)
     {
     cout<<"C_PROVINCIA:";
     cin>>cprovincia;
     }

     return cprovincia;


}

int Existencia_C(char *ciudad)
{
    CIUDAD obj;
    int canreg=CantidadReg(ARCHIVO_CIUDAD,sizeof(CIUDAD));


    for(int x=0;x<canreg;x++)
    {
     obj.LEER(x);

     if(obj==ciudad)
     {
         return 1;
     }
    }

    return 0;
}

int Existencia_R(char *ruta)
{

    RUTA obj;

    int canreg=CantidadReg(ARCHIVO_RUTA,sizeof(RUTA));

    for(int x=0;x<canreg;x++)
    {
        obj.LEER(x);

        if(obj==ruta)
        {
         return 1;
        }

    }


    return 0;
}


///OTROS
int CantidadReg(const char *Archivo,int tam)
{
FILE *p;
p=fopen(Archivo,"rb");
if(p==NULL)
{
    exit(1);
}

fseek(p,0,2);

int canreg=ftell(p)/tam;

fclose(p);

return canreg;
}

#endif // FUNCIONES_H_INCLUDED
