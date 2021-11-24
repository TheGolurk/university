/*
EP3 ALGORITMOS DE BUSQUEDA Y ORDENAMIENTO 

AUTORES:
VALLE GONZALEZ LORENA
HERNANDEZ NAJERA CHRISTIAN

*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

int* generarInstancia(int tam, int min, int max);
int* generarDatosBuscadosExistentes(int tam, int porcentaje, int* datos);
int* generarDatosBuscadosNE(int tam, int min, int max, int porcentaje);

int buscar(int* arr, int l, int r, int x);
int obtenerTam(int tam, int porcentaje);

double obtener_tiempo();

void busquedaBinaria(int *datos,int tam, int *datosB, int logs, int tamb);
void mostrar_informacion(int encontrado, int dato, int logs);
void mostrar(int tam, int* datos);


int main ()
{
    int tam, tamB, min, max, porcentaje;
    int *datos, *datosb;  
    int opc=1;
    int opc2;

  while(opc != 2)
    {
        printf("ingrese una opcion: \n1.-Correr prueba \n2.-Salir\n");
        scanf("%d", &opc);

        switch(opc)
        {
            case 1:
                printf("Ingresa el tamaño:\n");
                scanf("%d", &tam);

                printf("Ingresa el porcentaje: %(10,50,100)\n");
                scanf("%d", &porcentaje);

                printf("Ingrese minimo para generar los numeros\n");
                scanf("%d", &min);

                printf("Ingrese maximo\n");
                scanf("%d", &max);

                datos = generarInstancia(tam, min, max);
                mostrar(tam, datos);

                int tamb = obtenerTam(tam, porcentaje);
                
                int datosExis;
                printf("Datos existentes? 1.-Si 2.-No\n");
                scanf("%d", &datosExis);
                
                datosb = generarDatosBuscadosExistentes(tam, porcentaje, datos);

                if (datosExis == 2)
                {
                    printf("Ingrese minimo de datos a generar para los datos no existentes\n");
                    scanf("%d", &min);

                    printf("Ingrese maximo\n");
                    scanf("%d", &max);

                    datosb = generarDatosBuscadosNE(tam, min, max, porcentaje);
                }

                int logs;
                printf("Desea mostrar los datos de busqueda? 1.- si 2.- no\n");
                scanf("%d", &logs);
                
                double start = obtener_tiempo();
                
                busquedaBinaria(datos, tam, datosb, logs, tamb);
                
                double end = obtener_tiempo();
                printf("TOTAL DE TIEMPO = %f secs\n", end-start);

                printf("Eliminando archivo binario \n");
                remove("EP3.dat");

                break;

            case 2:
                printf("Saliendo del programa.......\n");
                break;

            default:
                printf("Opcion incorrecta\n");
                break;

        }

    }


    return 0;
}

int obtenerTam(int tam, int porcentaje) {
    int tamNuevo;

    switch (porcentaje)
    {
    case 10:
        tamNuevo = (tam*0.10);
        break;
    
    case 50:
        tamNuevo = (tam / 2);
        break;

    case 100:
        tamNuevo = tam;
        break;
    default:
        tamNuevo = 0;
    }

    return tamNuevo;
}

void mostrar(int tam, int* datos){
    printf("\n");

    for(size_t i=0; i<tam; i++){
        printf("%d, ", datos[i]);
        
    }
    printf("\n");
}

int* generarInstancia(int tam, int min, int max){
    int* datos=(int *)malloc(sizeof(int)*tam);

    for(size_t i=0; i<tam; i++){
        datos[i] = rand()%(max-min+1)+min;
    }
    
    return datos;
}

int* generarDatosBuscadosExistentes(int tam, int porcentaje, int* datos){
    int *datosB, tamB;
    tamB=tam*porcentaje/100;
    
    datosB=(int *)malloc(sizeof(int)*tamB);

    for(size_t i=0; i<tamB; i++){
        datosB[i]=datos[rand()%tam]; 
    }
    
    return datosB;
}

int* generarDatosBuscadosNE(int tam, int min, int max, int porcentaje){
    int *datosB, tamB;
    tamB=tam*porcentaje/100;
    
    datosB=(int *)malloc(sizeof(int)*tamB);

    for(size_t i=0; i<tamB; i++){
        datosB[i]=rand()%(max-min+1)+min; 
    }

    return datosB;
}

int buscar(int* arr, int l, int r, int x) {
    if (r >= l) { 
        int mid = l + (r - l) / 2; 
        if (arr[mid] == x) 
            return mid; 
        if (arr[mid] > x) 
            return buscar(arr, l, mid - 1, x); 
        return buscar(arr, mid + 1, r, x); 
    } 
    return -1; 
}

void busquedaBinaria(int *datos,int tam, int *datosB, int logs, int tamb) {
    for (size_t i = 0; i < tamb; i++)
    {
        int encontrado =  buscar(datos, 0, tam, datosB[i]);
        mostrar_informacion(encontrado, datosB[i], logs); 
    }
    
}

void mostrar_informacion(int encontrado, int dato, int logs) {
    if (logs == 1)
    {
        if (encontrado == -1) {
            printf("%d no encontrado\n", dato);
        } else {
            printf("%d encontrado\n", dato);
        }
    }
} 

double obtener_tiempo() {
    struct timeval t;
    gettimeofday(&t, NULL);
    return t.tv_sec + t.tv_usec/10000.000;
}
