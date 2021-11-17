#include <time.h>

struct alumno {
    int  id_alumno;
    char nombre[30];
    char grupo[5];
    int  opcionRealizar;
    char modelo[20];
};

struct productos{
    int   id_producto;
    char  modelo[20];
    char  talla[15];
    float precio;
    int   cant_disponible;
};

struct compras{
    int id_usuario;
    int id_producto;
    struct tm fecha;
};