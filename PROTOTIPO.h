#ifndef PROTOTIPO_H_INCLUDED
#define PROTOTIPO_H_INCLUDED


///PROTOTIPO DE PROVINCIA

void CARGAR_PROVINCIA(void);
void ELIMINAR_PROVINCIA(void);
void MOSTRAR_PROVINCIA(void);

int BuscarProvincia(int);

///PROTOTIPO DE CIUDAD

void CARGAR_CIUDAD(void);
void MOSTRAR_CIUDAD(void);

int Validar_CP_C(void);
int Existencia_C(char *,int);///DEVUELVE 0=NO EXISTE 1=EXISTE , se envia como parametros el codigo de la coidad y de la provincia


///GENERAL

int Existencia_PV(int);///DEVUELVE 0=NO EXISTE 1=EXISTE

///OTROS

int CantidadReg(const char *,int);

///PUNTOS
void Punto_A(void);
void Punto_B(void);
void Punto_C(void);

#endif // PROTOTIPO_H_INCLUDED
