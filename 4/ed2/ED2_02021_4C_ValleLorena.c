#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Producto {
    int ID;
    char descripcion[100];
    float precio;
    float precio_provedor;
    char marca[30];
    int piezas_disponibles;
};

struct Nodo {
   struct product *izq;
    struct product *der;
};


int main(int argc, char const *argv[])
{

    return 0;
}
