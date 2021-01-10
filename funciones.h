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

    int provicia=0;

    obj.CARGAR();

    provicia=Validar_CP_C();

    if(Existencia_C(obj.getciudad(),provicia)!=1)
    {
    obj.setcprovincia(provicia);

    obj.ALTA();
    }
    else
    {
        cout<<"LA CIUDAD YA EXISTE"<<endl;
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

int Existencia_C(char *ciudad,int provincia)
{
    CIUDAD obj;
    int canreg=CantidadReg(ARCHIVO_CIUDAD,sizeof(CIUDAD));


    for(int x=0;x<canreg;x++)
    {
     obj.LEER(x);

     if((obj==ciudad) && (obj.getprovincia()==provincia))
     {
         return 1;
     }
    }

    return 0;
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
