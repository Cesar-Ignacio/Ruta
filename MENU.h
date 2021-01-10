#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

/// PROTOTIPOS

void submenu(void);
void submenuProvincia(void);
void submenuCiudad(void);
void submenuRuta(void);

///FUNCIONES

void submenu()
{
    int opc=1;

    while(opc!=0)
    {
        cout<<"MENU"<<endl;
        cout<<"************"<<endl;
        cout<<"1- PROVICIA"<<endl;
        cout<<"2- CIUDAD"<<endl;
        cout<<"3- RUTA"<<endl;
        cout<<"0- VOLVER"<<endl;
        cout<<"************"<<endl;
        cin>>opc;

        system("cls");

        if(opc==1)
        {
          submenuProvincia();
        }
        if(opc==2)
        {
        submenuCiudad();
        }
        if(opc==3)
        {
        submenuRuta();
        }

    }


    system("pause>null");
    system("cls");


}

void submenuProvincia()
{
    int opc=1;

    while(opc!=0)
    {
       cout<<"MENU PROVINCIA"<<endl;
       cout<<"*************"<<endl;
       cout<<"1- ALTA"<<endl;
       cout<<"2- BAJA"<<endl;
       cout<<"3- MOSTRAR"<<endl;
       cout<<"4- MODIFICAR"<<endl;
       cout<<"0- VOLVER"<<endl;
       cout<<"*************"<<endl;
       cin>>opc;

       system("cls");


       if(opc==1)
       {
        CARGAR_PROVINCIA();
       }
       if(opc==2)
       {
        ELIMINAR_PROVINCIA();
       }
       if(opc==3)
       {
        MOSTRAR_PROVINCIA();
       }
       if(opc==4)
       {

       }


    }

    system("pause>null");

}

void submenuCiudad()
{
        int opc=1;

    while(opc!=0)
    {
       cout<<"MENU CIUDAD"<<endl;
       cout<<"*************"<<endl;
       cout<<"1- ALTA"<<endl;
       cout<<"2- BAJA"<<endl;
       cout<<"3- MOSTRAR"<<endl;
       cout<<"4- MODIFICAR"<<endl;
       cout<<"0- VOLVER"<<endl;
       cout<<"*************"<<endl;
       cin>>opc;

       system("cls");


       if(opc==1)
       {
       CARGAR_CIUDAD();
       }
       if(opc==2)
       {

       }
       if(opc==3)
       {
        MOSTRAR_CIUDAD();
       }
       if(opc==4)
       {

       }


    }

    system("pause>null");

}
void submenuRuta()
{
    int opc=1;

    while(opc!=0)
    {
       cout<<"MENU RUTA"<<endl;
       cout<<"*************"<<endl;
       cout<<"1- ALTA"<<endl;
       cout<<"2- BAJA"<<endl;
       cout<<"3- MOSTRAR"<<endl;
       cout<<"4- MODIFICAR"<<endl;
       cout<<"0- VOLVER"<<endl;
       cout<<"*************"<<endl;
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

       }


    }

    system("pause>null");
}


#endif // MENU_H_INCLUDED
