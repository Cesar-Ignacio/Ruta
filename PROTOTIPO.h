#ifndef PROTOTIPO_H_INCLUDED
#define PROTOTIPO_H_INCLUDED


///PROTOTIPO DE PROVINCIA

void CARGAR_PROVINCIA(void);
void ELIMINAR_PROVINCIA(void);
void MOSTRAR_PROVINCIA(void);

int BuscarProvincia(int);

///PROTOTIPO DE CIUDAD

void CARGAR_CIUDAD(void);
void ELIMINAR_CIUDAD(void);
void MOSTRAR_CIUDAD(void);

int BuscarCiudad(char *);


///GENERAL
int Validar_CP_C(void);///VALIDAMOS LA PROVINCIA
int Existencia_C(char *);///DEVUELVE 0=NO EXISTE 1=EXISTE , se envia como parametros el codigo de la coidad
int Existencia_PV(int);///DEVUELVE 0=NO EXISTE 1=EXISTE se envia como parametros el codigo de la provincia

///OTROS

int CantidadReg(const char *,int);

///PUNTOS
void Punto_A(void);
void Punto_B(void);
void Punto_C(void);

#endif // PROTOTIPO_H_INCLUDED
