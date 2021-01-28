#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

///PROVINCIA
void CARGAR_PROVINCIA()
{
    PROVICIA objP;
    int cprovincia;
    cout<<"C_ PROVINCIA:";///HACER UNA FUCNCION PARA VALIDAR C_PROVINCIA
    cprovincia=validarNumero();

    while(Existencia_PV(cprovincia))
    {

    cout<<"C_ PROVINCIA:";///HACER UNA FUCNCION PARA VALIDAR C_PROVINCIA
    cprovincia=validarNumero();
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

int validarNumero()
{
  int numero;
  numero=filtro();

  while(numero==-1)
  {
    numero=filtro();
  }

  return numero;
}

int filtro()
{
    int valor;
    int z=0;

    std::cin >> valor;

    if( !std::cin.good() )///SE CUMPLE LA CONDICION CUANDO SE INGRESA UN CARACTER
    {


      gotoxy(50,1);cout<<"ERROR"<<endl;
      ///atencion1("ERROR : ",87,8,"SE A DETECTADOS UN CARACTER ",87,9,"O A INGRESADO UN ALGO MAL !!!",87,10);
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

      Sleep(5000);

      gotoxy(50,1);cout<<"        "<<endl;
     /// atencion1("",88,8,"",88,9,"",88,10);///BORRAMOS

      return -1;
    }
    else
     {return valor;}



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
    char Cruta[5],CciudadI[5],CciudadF[5];

    fflush(stdin);
    cout<<"C_RUTA:";
    cin.getline(Cruta,5);

    while(Existencia_R(Cruta)!=0)
    {
    fflush(stdin);
    cout<<"C_RUTA:";
    cin.getline(Cruta,5);
    }
    obj.setcruta(Cruta);

    Cargar_Ciudades(CciudadI,CciudadF);

    obj.setciudadI(CciudadI);
    obj.setciudadF(CciudadF);

    obj.CARGAR();

    obj.ALTA();


    system("pause>null");
    system("cls");

}

void ELIMINAR_RUTA()
{

  RUTA obj;

  char cruta[5];
  int pos=0;
  fflush(stdin);
  cout<<"INGRESE C_RUTA:";
  cin.getline(cruta,5);
  pos=BuscarRuta(cruta);
  if(pos!=-1)
  {
      obj.LEER(pos);
      obj.setestado(0);
      obj.MODIFICACION(pos);
      cout<<"SE ELIMINO EL REG"<<endl;
  }
  else
  {
      cout<<"NO SE ENCONTRO EL REG"<<endl;
  }

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
system("pause>null");
system("cls");

}

void Cargar_Ciudades(char *CciudadI,char *CciudadF)
{

    fflush(stdin);
    cout<<"C_CIUDAD_INICIO:";
    cin.getline(CciudadI,5);


    while(Existencia_C(CciudadI)!=1)
    {
    fflush(stdin);
    cout<<"C_CIUDAD_INICIO:";
    cin.getline(CciudadI,5);
    }

    fflush(stdin);
    cout<<"C_CIUDAD_FIN:";
    cin.getline(CciudadF,5);

    while(Existencia_C(CciudadF)!=1)
    {
    fflush(stdin);
    cout<<"C_CIUDAD_FIN:";
    cin.getline(CciudadF,5);
    }


}

int BuscarRuta(char *ruta)
{
    RUTA obj;

    int canreg=CantidadReg(ARCHIVO_RUTA,sizeof(RUTA));


    for(int x=0;x<canreg;x++)
    {
       obj.LEER(x);

       if(obj==ruta)
       {
           return x;
       }

    }
    return -1;
}

void menu_estado()
{

CONTROL obj;

int opc=1;

while(opc!=0)
{

    cout<<"MUNE"<<endl;
    cout<<"**************"<<endl;
    cout<<"1_CARGAR"<<endl;
    cout<<"2_MOSTRAR"<<endl;
    cout<<"0_SALIR"<<endl;
    cout<<"**************"<<endl;
    cin>>opc;
    system("cls");
    if(opc==1)
    {
     Cargar_Estado();
    }
    if(opc==2)
    {
     Mostrar_Estado();
    }

}

system("cls");
system("pause>null");

}

void Cargar_Estado()
{

  CONTROL obj;


  cout<<"ESTADO DE RUTA"<<endl;

  obj.ALTA();

  system("cls");
  system("pause>null");

}

void Mostrar_Estado()
{
    CONTROL obj;

    int canreg=CantidadReg(ARCHIVO_ESTADO,sizeof(CONTROL));

    cout<<"ESATDO DE RUTAS"<<endl;


   for(int x=0;x<canreg;x++)
   {

       obj.LEER(x);
       obj.MOSTRAR();
   }



    system("pause>null");
    system("cls");
}

void Mostrar_A_N()
{
    NUEVO obj;
    int canreg=CantidadReg(ARCHIVO_NUEVA,sizeof(NUEVO));
 cout<<"ANIO 2015"<<endl;
    for(int x=0;x<canreg;x++)
    {
        obj.LEER(x);
        obj.MOSTRAR();

    }

    system("pause>null");
    system("cls");
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

    if(canreg!=-1)
    {

    for(int x=0;x<canreg;x++)
    {
        obj.LEER(x);

        if(obj==ruta)
        {
         return 1;
        }

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
    return -1;
}

fseek(p,0,2);

int canreg=ftell(p)/tam;

fclose(p);

return canreg;
}

void gotoxy(int x, int y)
{
    HANDLE hcon= GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X=x;
    dwPos.Y=y;
    SetConsoleCursorPosition(hcon,dwPos);
}
#endif // FUNCIONES_H_INCLUDED
