#ifndef CLASS_H_INCLUDED
#define CLASS_H_INCLUDED


///CLASS

class RUTA
{
  private:

  char Cruta[5];
  char CciudadI[5];
  char CciudadF[5];
  float longitud;
  int Truta;///(1: Autopista, 2: Asfalto, 3: Ripio, 4: Mejorado, 5: Tierra)
  int peaje;

  public:




};

class FECHA
{
private:

    int dia;
    int mes;
    int anio;
public:

    int getdia(){return dia;}
    int getmes(){return mes;}
    int getanio(){return anio;}

};


class ESTADO
{

private:

   FECHA fch;
   char Cruta[5];
   int estado;/// (1: Transitable, 2: Intransitable)


public:


};


class CIUDAD
{
private:
    char Cciudad[5];
    char nombre[30];
    int cprovincia;/// 1 a 24)
    int estado;

public:


    int getprovincia(){return cprovincia;}
    char *getciudad(){return Cciudad;}
    void setcprovincia(int cpro){cprovincia=cpro;}
    void CARGAR(void);
    void ALTA(void);
    void LEER(int);
    void MOSTRAR(void);

    int operator==(char *ciudad)
    {
        if(strcmp(Cciudad,ciudad)==0)
        {
            return 1;
        }
        return 0;
    }

} ;

void CIUDAD::CARGAR()
{
 fflush(stdin);
 cout<<"C_CIUDAD:";
 cin.getline(Cciudad,5);
 fflush(stdin);
 cout<<"NOMBRE:";
 cin.getline(nombre,30);
 estado=1;

}

void CIUDAD::ALTA()
{
  FILE *p;
  p=fopen(ARCHIVO_CIUDAD,"ab");
  if(p==NULL)
  {
      exit(1);
  }

  fwrite(this,sizeof(CIUDAD),1,p);
  fclose(p);

}

void CIUDAD::LEER(int pos)
{
    FILE *p;
    p=fopen(ARCHIVO_CIUDAD,"rb");
    if(p==NULL)
    {
        exit(1);
    }

    fseek(p,sizeof(CIUDAD)*pos,0);

    fread(this,sizeof(CIUDAD),1,p);

    fclose(p);
}

void CIUDAD::MOSTRAR()
{
    if(estado==1)
    {
        cout<<"C_CIUDAD:"<<Cciudad<<endl;
        cout<<"NOMBRE:"<< nombre<<endl;
        cout<<"C_PROVINCIA:"<<cprovincia<<endl;
        cout<<"*******************"<<endl;
    }


}

class PROVICIA
{
private:

    int cprovincia;
    char nombre[30];
    char region;///(�S�, �N�, �E�, �O�)
    int estado;
public:


    int getestado(){return estado;}
    void setcprovincia(int prov){cprovincia=prov;}
    void setestado(int esta){estado=esta;}
    void REGI(void);
    void CARGAR(void);
    void MOSTRAR(void);
    void ALTA(void);
    void LEER(int);
    void MODIFICACION(int);

    int operator ==(int cp)
    {
        if(cprovincia==cp)
        {
            return 1;
        }
        return 0;
    }


};

void PROVICIA::CARGAR()
{

    fflush(stdin);
    cout<<"NOMBRE:";
    cin.getline(nombre,30);
    REGI();
    estado=1;


}

void PROVICIA::MOSTRAR()
{
  if(estado==1)
  {
   cout<<"COD_PROVINCIA:"<< cprovincia<<endl;
   cout<<"NOMBRE:"<<nombre<<endl;
   cout<<"REGION:"<<region<<endl;
   cout<<"estafo:"<<estado<<endl;
   cout<<"********************"<<endl;
  }



}
void PROVICIA::ALTA()
{
    FILE *p;

    CARGAR();

    p=fopen(ARCHIVO_PROVINCIA,"ab");
    if(p==NULL)
    {
        exit(1);
    }

    fwrite(this,sizeof(PROVICIA),1,p);

    fclose(p);
}
void PROVICIA::LEER(int pos)
{
    FILE *p;
    p=fopen(ARCHIVO_PROVINCIA,"rb");
    if(p==NULL)
    {
        exit(1);
    }

    fseek(p,sizeof(PROVICIA)*pos,0);

    fread(this,sizeof(PROVICIA),1,p);

    fclose(p);

}
void PROVICIA::MODIFICACION(int pos)
{
    FILE *p;
    p=fopen(ARCHIVO_PROVINCIA,"rb+");
    if(p==NULL)
    {
        exit(1);
    }

    fseek(p,sizeof(PROVICIA)*pos,0);

    fwrite(this,sizeof(PROVICIA),1,p);

    fclose(p);

}


void PROVICIA::REGI()
{
    int con=0;
    cout<<"REGION: ";
    cin>>region;
    while(con!=1)
    {
    if(region=='S' || region=='s')
    {
        con=1;
    }
    if(region=='N' || region=='n')
    {
        con=1;
    }
    if(region=='E' || region=='e')
    {
        con=1;
    }
    if(region=='O' || region=='o')
    {
        con=1;
    }

        if(con!=1)
        {
        cout<<"REGION: ";
        cin>>region;
        }

    }


}


#endif // CLASS_H_INCLUDED
