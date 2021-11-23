/*
EP3 ALGORITMOS DE BUSQUEDA Y ORDENAMIENTO 

AUTORES:
VALLE GONZALEZ LORENA
HERNANDEZ NAJERA CHRISTIAN

*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

struct instancia
{
    int dato;
};

void generarInstancia(int tam, int min, int max);
int* generarDatosBuscadosExistentes(int tam, int porcentaje);
int* generarDatosBuscadosNE(int tam, int min, int max, int porcentaje);
void mostrar();
int* obtenerDatos(int tam, int porcentaje);
void busquedaBinaria(int *datos,int tam, int *datosB, int logs);
int buscar(int* datos, int ultimo, int tam, int numero);
void mostrar_informacion(int encontrado, int dato, int logs);
void obtenerTiempo(clock_t t);

int main()
{
    int tam, tamB, min, max, porcentaje;
    int *datos, *datosB_E, *datosB_NE;    
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

                generarInstancia(tam, min, max);
                
                printf("Desea mostrar instancia creada?.\n 1.Si 2.No.\n");
                scanf("%d",&opc2);
                if (opc2 == 1)
                {
                    mostrar();
                }

                int *datos = obtenerDatos(tam, porcentaje);

                int datosExis;
                printf("Datos existentes? 1.-Si 2.-No\n");
                scanf("%d", &datosExis);

                int *datosB;
                if (datosExis == 1)
                {
                    datosB =  generarDatosBuscadosExistentes(tam, porcentaje);
                } else {
                    int min, max;
                    printf("Ingrese minimo\n");
                    scanf("%d", &min);

                    printf("Ingrese maximo\n");
                    scanf("%d", &max);

                    datosB =  generarDatosBuscadosNE(tam, min, max, porcentaje);
                }
                
                int logs;
                printf("Desea mostrar los datos de busqueda? 1.- si 2.- no");
                scanf("%d", &logs);

                clock_t t;
                t = clock;
                busquedaBinaria(datos, tam, datosB, logs);
                t = clock() - t;
                obtenerTiempo(t);

                break;
            
            case 2:
                printf("Saliendo del programa.......\n");
                break;

            default:
                printf("Opcion incorrecta\n");
                break;
        }
    }

/*
    mostrar(tam, datos);
    tamB=tam*porcentaje/100;
    
    datosB_E=generarDatosBuscadosExistentes(tam,datos,porcentaje);
    mostrar(tamB, datosB_E);
    
    datosB_NE=generarDatosBuscadosNE(tam, min, max, porcentaje);
    mostrar(tamB, datosB_NE);
    */    
    
    return 0;
}

int* obtenerDatos(int tam, int porcentaje)
{
    int *datos;
    int tamNuevo;

    switch (porcentaje)
    {
    case 10:
        tamNuevo = (tam*0.10) - 1;
        break;
    
    case 50:
        tamNuevo = (tam / 2) - 1;
        break;

    case 100:
        tamNuevo = tam -1;
        break;

    default:
        printf("Porcentaje incorrecto");
        return datos;
        break;
    }


    datos=(int *)malloc(sizeof(int)*tamNuevo);

    FILE *ptrArchivo;
    ptrArchivo = fopen("EP3.dat", "r");
    if (ptrArchivo == NULL) {
        return;
    }

    struct instancia e;
    
    int index = 0;
    while(fread(&e, sizeof(struct instancia), 1, ptrArchivo))
    {
        if (index == tamNuevo)
        {
            break;
        }

        datos[index]= e.dato;

        index++;
    }

    fclose(ptrArchivo);
}
    

void mostrar(){
    FILE *ptrArchivo;
    ptrArchivo = fopen("EP3.dat", "r");
    if (ptrArchivo == NULL) {
        return;
    }

    struct instancia e;
    
    printf("\n");
    while(fread(&e, sizeof(struct instancia), 1, ptrArchivo))
    {
        printf("%d ,",e.dato);
    }
    printf("\n");

    fclose(ptrArchivo);
}

void generarInstancia(int tam, int min, int max){
    FILE *ptrArchivo;

    ptrArchivo = fopen("EP3.dat", "a+");
    if (ptrArchivo == NULL) {
        return;
    }

    struct instancia e;

    for(size_t i=0;i<tam;i++){
        e.dato = rand()%(max-min+1)+min;
    }

    fclose(ptrArchivo);
}

int* generarDatosBuscadosExistentes(int tam, int porcentaje){
    int *datosB, tamB, i;
    tamB=tam*porcentaje/100;
    
    datosB=(int *)malloc(sizeof(int)*tamB);

    int* datos = obtenerDatos(tam, porcentaje);

    for(i=0; i<tamB; i++){
        datosB[i]=datos[rand()%tam]; 
    }
    
    return datosB;
}

int* generarDatosBuscadosNE(int tam, int min, int max, int porcentaje){
    int *datosB, tamB, i;
    tamB=tam*porcentaje/100;
    
    datosB=(int *)malloc(sizeof(int)*tamB);

    for(i=0;  i<tam;i++){
        datosB[i]=rand()%(max-min+1)+min; 
    }

    return datosB;
}

int busquedasecuencialExp(int tam, int datos[], int tamB, int datosB[]){
    //tomar  el tiempo
    int  i;
    
    for(i=0; i<tamB;i++){
        if(busquedaSecuencial(datos, tam, datosB[i])==-1){
            
        }else{
            
        }
    }
    
    //tomar el tiempo
    //return diferencia
}

int buscar(int* datos, int u, int t, int numero) {
    while (u <= t) { 
        int medio = u + (t - u) / 2; 
        
        if (datos[medio] == numero) 
            return medio; 

        if (datos[medio] < numero) 
            t = medio + 1; 
        else
            t = medio - 1; 
    }  

    return -1;
}

void busquedaBinaria(int *datos,int tam, int *datosB, int logs) {

    for (size_t i = 0; i < tam; i++)
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

void obtenerTiempo(clock_t t) {
    printf("La funcion tardo: %.2f segundos\n", ((double)t)/CLOCKS_PER_SEC);
}