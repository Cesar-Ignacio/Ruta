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
  int estado;
public:


   char *getciudadI(){return CciudadI;}
   char *getciudadF(){return CciudadF;}
   float getlongitud(void){return longitud;}
   char *getcruta(void){return Cruta;}
   void setciudadI(char *ciuI){strcpy(CciudadI,ciuI);}
   void setciudadF(char *ciuF){strcpy(CciudadF,ciuF);}
   void setcruta(char *ruta){strcpy(Cruta,ruta);}
   void setestado(int est){estado=est;}
   void MOSTRAR(void);
   void CARGAR(void);
   void ALTA(void);
   void LEER(int);
   void MODIFICACION(int);
   void ruta(void);

   int operator == (char *ruta)
   {
       if(strcmp(Cruta,ruta)==0)
       {
           return 1;
       }

       return 0;
   }

   int operator >(float longitud)
   {

       if(this->longitud>longitud)
       {
           return 1;
       }
       return 0;
   }


};

void RUTA::CARGAR()
{

    cout<<"LONGITUD:";
    cin>>longitud;
    ruta();
    cout<<"PEAJE 1=si 0=no:";
    cin>>peaje;
    estado=1;

}

void RUTA::MOSTRAR()
{
    if(estado==1)
    {
        cout<<"C_RUTA:"<<Cruta<<endl;
        cout<<"CIUDAD INICIO:"<<CciudadI<<endl;
        cout<<"CIUDAD FIN:"<<CciudadF<<endl;
        cout<<"LONGITUD:"<<longitud<<endl;
        cout<<"TRUTA:"<<Truta<<endl;
        cout<<"PEAJE:" <<peaje<<endl;
        cout<<"*******************"<<endl;
    }


}

void RUTA::ALTA()
{
    FILE *p;
    p=fopen(ARCHIVO_RUTA,"ab");
    if(p==NULL)
    {
        exit(1);
    }

    fwrite(this,sizeof(RUTA),1,p);

    fclose(p);

}

void RUTA::LEER(int pos)
{

    FILE *p;
    p=fopen(ARCHIVO_RUTA,"rb");
    if(p==NULL)
    {
        exit(1);
    }

    fseek(p,sizeof(RUTA)*pos,0);

    fread(this,sizeof(RUTA),1,p);

    fclose(p);

}

void RUTA::MODIFICACION(int pos)
{
    FILE *p;
    p=fopen(ARCHIVO_RUTA,"rb+");
    if(p==NULL)
    {
        exit(1);
    }

    fseek(p,sizeof(RUTA)*pos,0);

    fwrite(this,sizeof(RUTA),1,p);

    fclose(p);

}

void RUTA::ruta()
{
    cout<<"RUTA (1: Autopista, 2: Asfalto, 3: Ripio, 4: Mejorado, 5: Tierra):";
    cin>>Truta;

    while(Truta<=0 || Truta>=6)
    {
    cout<<"RUTA (1: Autopista, 2: Asfalto, 3: Ripio, 4: Mejorado, 5: Tierra):";
    cin>>Truta;
    }

}

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

    void CARGAR(void);
    void MOSTRAR(void);
};


void FECHA::CARGAR()
{
    cout<<"DIA:";
    cin>>dia;
    cout<<"MES:";
    cin>>mes;
    cout<<"ANIO:";
    cin>>anio;
}

void FECHA::MOSTRAR()
{

    cout<<"DIA:"<< dia<<endl;
    cout<<"MES:"<<mes<<endl;
    cout<<"ANIO:"<<anio<<endl;
}

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
    char *getnombre(){return nombre;}
    void setciudad(char *ciud){strcpy(Cciudad,ciud);}
    void setcprovincia(int cpro){cprovincia=cpro;}
    void setestado(int esta){estado=esta;}
    void CARGAR(void);
    void ALTA(void);
    void LEER(int);
    void MOSTRAR(void);
    void MODIFICACION(int);

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

void CIUDAD::MODIFICACION(int pos)
{

    FILE *p;
    p=fopen(ARCHIVO_CIUDAD,"rb+");
    if(p==NULL)
    {
        exit(1);
    }
    fseek(p,sizeof(CIUDAD)*pos,0);

    fwrite(this,sizeof(CIUDAD),1,p);

    fclose(p);
}


class PROVICIA
{
private:

    int cprovincia;
    char nombre[30];
    char region;///(‘S’, ‘N’, ‘E’, ‘O’)
    int estado;
public:


    int getestado(){return estado;}
    char *getnombre(){return nombre;}
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


class CONTROL
{
  private:

    FECHA fch;
    char cruta[5];
    int estado;

  public:

    void Cargar(void);
    void MOSTRAR(void);

};

void CONTROL::Cargar()
{
    fch.CARGAR();
    fflush(stdin);
    cout<<"C_ruta:";
    cin.getline(cruta,5);
    cout<<"ESTADO:";
    cin>>estado;
}

void CONTROL::MOSTRAR()
{
    fch.MOSTRAR();
    cout<<"C_RUTA:"<<endl;
    cout<<"ESTADO:"<<estado<<endl;
    cout<<"*******************"<<endl;
}



#endif // CLASS_H_INCLUDED
