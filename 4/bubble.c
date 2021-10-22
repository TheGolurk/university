#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Persona {
    char nombre[30];
    char apPaterno[30];
    char apMaterno[30];
    int altura;
};

int compararPersonas(struct Persona, struct Persona);
void burbujaPersona(struct Persona lista[], int tam);

void burbuja(int lista[], int tam);

int * crearInicializar(int tam);
void mostrar(int lista[], int tam);

int main(int argc, char const *argv[])
{
    int *datos, tam = 20;
    datos = crearInicializar(tam);
    mostrar(datos, tam);
    burbuja(datos, tam);
    mostrar(datos, tam);

    free(datos);
    return 0;
}

void burbuja(int lista[], int tam) {
    int tmp;

    for (size_t i = 1; i < tam; i++)
    {
        // mejora seria en vez de tam - 1, seria i - 1
        for (size_t j = 0; j < tam-1; j++)
        {
            if (lista[j] > lista[j]+1)
            {
                tmp = lista[j];
                lista[j] = lista[j+1];
                lista[j+1] = tmp;
            }
        }
    }
}

int * crearInicializar(int tam) {
    int *datos;

    datos = (int *)malloc(sizeof(int)*tam);

    if (datos == NULL) {
        return NULL;
    }

    for (size_t i = 0; i < tam; i++)
    {
        datos[i] = rand() % 100 + 1;
    }

   return datos;
}

void mostrar(int lista[], int tam) {
    printf("[");
    for (size_t i = 0; i < tam; i++)
    {
        printf("%d ", lista[i]);
    }

    printf("]\n");
    
}

void burbujaPersona(struct Persona lista[], int tam) {
    struct Persona temp;

    for (size_t i = 1; i < tam; i++)
    {
        for (size_t j = 0; j < tam-1; j++)
        {
            if (lista[j].altura > lista[j].altura+1)
            {
                temp = lista[j];
                lista[j] = lista[j+1];
                lista[j+1] = temp;
            }
        }
    }

}

int compararPersonas(struct Persona per1, struct Persona per2) {
    /*if (per1.altura > per2.altura)
    {
        return 1;
    } else {
        if (per1.altura < per2.altura)
        {
            return -1;
        } else {
            return 0;
        }
    } */
    
   //return strcmp(per1.nombre, per2.nombre); 

    if (strcmp(per1.apPaterno, per2.apPaterno) > 0)
    {
        return 1;
    } else {
        if (strcmp(per1.apPaterno, per2.apPaterno) < 0)
        {
            return -1;
        } else {
            
        }
        
    }
    
}