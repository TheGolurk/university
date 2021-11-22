/*
EP3 ALGORITMOS DE BUSQUEDA Y ORDENAMIENTO 

AUTORES:
VALLE GONZALEZ LORENA
HERNANDEZ NAJERA CHRISTIAN

*/
#include <stdio.h>

struct instancia
{
    int dato;
};

void generarInstancia(int tam, int min, int max);
int * generarDatosBuscadosExistentes(int tam, int porcentaje);
int* generarDatosBuscadosNE(int tam, int min, int max, int porcentaje);
void mostrar();
int* obtenerDatos(int tam, int porcentaje);

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

int * generarDatosBuscadosExistentes(int tam, int porcentaje){
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
