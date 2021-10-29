#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct autos{
    char modelo[50];//Modelo del automovil//
    char color[50];//Color del automovil//
    char nombre[50];//Nombre del dueño del auto//
    int placas;//Numero de placas//
    int dia;//Dia en que el auto entro//
    int mes;//Mes en el que el auto entro//
    int anio;//Año en el que el auto entro//
    int hentrada;//Hora de entrada del auto//
    int mentrada;//Minuto de entrada//
    int hsalida;//Hora de salida//
    int msalida;//Minuto de salida//
    int edad;//Edad del dueño del auto//
    int aniomodelo;//Año de compra del auto//
};

struct elemento{
    struct autos dato;
    struct elemento *sig;
};

int insertar(struct elemento **cima, struct autos datoNuevo);

struct autos eliminar(struct elemento **cima);

int estaVacia(struct elemento *cima);

struct autos primero(struct elemento *cima);

struct autos registro();

//void menu();//Declaracion de funcion menu//

void impresionxd(struct elemento *cima, int tipoFuncion);

void historial(struct elemento **cima, struct elemento **pila2);

void vaciarPilas(struct elemento **cima, struct elemento **pila2);

int main()
{
   // menu();
    int i=0, opcion, tipoFuncion;
    struct elemento *pila = NULL, *pila2 = NULL;
    struct autos aux;
    
    do{
        printf("\n\tBienvenido al estacionamiento UPEMOR por favor seleccione una opcion: \n");
        printf("\n\t ----------------------     ------------------     -----------------------------     -----------------------");
        printf("\n\t| 1. Registrar un auto |   | 2. Sacar un auto |   | 3. Mostrar datos de un auto |   | 4. Salir del programa |");
        printf("\n\t ----------------------     ------------------     -----------------------------     -----------------------");
        printf("\n\tRespuesta: ");
        scanf("%d%*c", &opcion);
        switch (opcion)
        {
            case 1:
                aux = registro();
                if (insertar(&pila, aux)){
                    printf ("\nSe han ingresado los datos con exito");
                    i+=1;
                }else{
                    printf ("\nError");
                }
                break;
            case 2:
                historial(&pila, &pila2);
                aux = primero(pila2);
                printf ("\n%s", aux.modelo);
                i-=1;
                break;
            case 3:
                tipoFuncion = 1;
                impresionxd(pila, tipoFuncion);
                break;
            case 4:
                vaciarPilas(&pila, &pila2);
                break;
            default:
                printf("\n\tPorfavor selecciona una opcion valida :(\n\n\n");
                break;
        }
    }
    while(opcion!=4);
    printf("\n\tGracias por usar el estacionamiento tenga buen dia 🙂 \n");
   
}

int insertar(struct elemento **cima, struct autos datoNuevo){

    struct elemento *nuevo;

    nuevo = (struct elemento *)malloc(sizeof (struct elemento));
    
    if (nuevo==NULL){
        return 0;
    }

    nuevo->dato = datoNuevo;
    
    nuevo->sig = *cima;
    
    *cima = nuevo;
    
    nuevo->sig=*cima;
            
    *cima = nuevo;
 
    return 1; 
}

struct autos eliminar(struct elemento **cima){
    
    struct autos datoE = {"No hay nada"};
    
    if (estaVacia(*cima)==1){
        return datoE;
    }
    
    struct elemento *eliminado;
    eliminado = *cima;
    datoE = eliminado->dato;
    *cima = eliminado->sig;
    
    free(eliminado);

    return datoE;
}

int estaVacia(struct elemento *cima){
    if (cima==NULL){
        return 1;
    }
    return 0;
}

struct autos primero(struct elemento *cima){
    struct autos info = {"No hay nada"};
    if (estaVacia(cima)==1){
        return info;
    }
    return cima->dato;
}

//void menu(){

void impresionxd(struct elemento *cima, int tipoFuncion){
    struct autos datos;
    datos = primero(cima);
    if(tipoFuncion == 1){
        if(strcmp(datos.modelo, "No hay nada")==0){
            printf ("\n%s", datos.modelo);
        }else{
            printf ("\nPlacas: %d", datos.placas);
            printf ("\nModelo: %s", datos.modelo);
            printf ("\nColor: %s", datos.color);
            printf ("\nFecha: %d/%d/%d ", datos.dia,datos.mes,datos.anio);
            printf ("\nHora de entrada: %d:%d", datos.hentrada, datos.mentrada);
            printf ("\nNombre del condutctor: %s", datos.nombre);
            printf ("\nEdad: %d", datos.edad);
            printf ("\nAnnio Modelo: %d", datos.aniomodelo);
        }
    }else{
        printf ("\nPlacas: %d", datos.placas);
        printf ("\nModelo: %s", datos.modelo);
        printf ("\nColor: %s", datos.color);
        printf ("\nFecha: %d/%d/%d ", datos.dia,datos.mes,datos.anio);
        printf ("\nHora de entrada: %d:%d", datos.hentrada, datos.mentrada);
        printf ("\nNombre del condutctor: %s", datos.nombre);
        printf ("\nEdad: %d", datos.edad);
        printf ("\nAnnio Modelo: %d", datos.aniomodelo);
        printf ("\nHora de salida: %d:%d", datos.hsalida, datos.msalida);
    }
}

struct autos registro(){
    struct autos datos;
    
    printf ("\nIngresa el modelo del auto por favor: ");
    scanf ("%[^\n]%*c", datos.modelo);
    printf ("\nIngresa el nombre del conductor por favor: ");
    scanf ("%[^\n]%*c", datos.nombre);
    printf ("\nIngresa el color del auto por favor: ");
    scanf ("%[^\n]%*c", datos.color);
    printf ("\nIngresa las placas por favor: ");
    scanf ("%d%*c", &datos.placas);
    printf ("\nIngresa el dia por favor: ");
    scanf ("%d%*c", &datos.dia);
    printf ("\nIngresa el mes por favor: ");
    scanf ("%d%*c", &datos.mes);
    printf ("\nIngresa el annio por favor: ");
    scanf ("%d%*c", &datos.anio);
    printf ("\nIngresa la hora de entrada por favor: ");
    scanf ("%d%*c", &datos.hentrada);
    printf ("\nIngresa los minutos de entrada por favor: ");
    scanf ("%d%*c", &datos.mentrada);
    printf ("\nIngresa la edad del conductor por favor: ");
    scanf ("%d%*c", &datos.edad);
    printf ("\nIngresa el año del modelo del coche: ");
    scanf ("%d%*c", &datos.aniomodelo);
    
    return datos;
}

void historial(struct elemento **cima, struct elemento **pila2){
    if (estaVacia(*cima)){
        printf ("\nNo hay datos");
    }else{
        int idAuto;
        struct autos aux, aux2, aux3;
        printf ("\nIngresa las placas: ");
        scanf ("%d%*c", &idAuto);
        
        while(!estaVacia(*cima)){
            if ((*cima)->dato.placas == idAuto ){
                break;
            }else{
                aux = eliminar(&(*cima));
                insertar(&(*pila2), aux);
            }
        }
    
        aux2 = eliminar(&(*cima));//Aqui ya eliminamos datos
        
        printf ("\nIngresa la hora de salida: ");
        scanf ("%d%*c", &aux2.hsalida);
        
        printf ("\nIngresa la hora de salida: ");
        scanf ("%d%*c", &aux2.msalida);
        
        aux3 = aux2;
        
        while(!estaVacia(*pila2)){
            if ((*pila2)->dato.placas == aux3.placas){
                break;
            }else{
                aux = eliminar(&(*pila2));
                insertar(&(*cima), aux);
            }
        }
        
        insertar(&(*pila2), aux2);
    }
    
}

void vaciarPilas(struct elemento **cima, struct elemento **pila2){
    struct autos aux;
    int tipoFuncion;
    while (!estaVacia(*pila2)){
        eliminar(&(*pila2));
        tipoFuncion = 2;
        impresionxd(*pila2, tipoFuncion);
    }
    while (!estaVacia(*cima)){
        eliminar(&(*cima));
        tipoFuncion = 2;
        impresionxd(*cima, tipoFuncion);
    }
}

/*
#include <stdio.h>

void validar();

int main (){
    validar();
    return 0;
}

void validar(){
    int dia, mes, annio;
    int a = 0, b = 0, c = 0;
    
    printf("Inserte fecha [dia]: ");
    scanf ("%d%*c", &dia);
    
    printf("Inserte fecha [mes]: ");
    scanf ("%d%*c", &mes);
    
    printf("Inserte fecha [annio]: ");
    scanf ("%d%*c", &annio);
    
    while(a == 0 || b == 0 || c == 0){
        if(annio<1000){
            printf ("\nIngresa de nuevo el annio: ");
            scanf ("%d%*c", &annio);
        }else if (annio>999 && annio%4==0){
            c = 1;
            if(mes < 1 || mes >12){
               printf ("\nIngresa nuevamente el mes: ");
               scanf ("%d%*c", &mes);
            }else{
                b = 1;
                if(mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12){
                    if (dia >= 1 && dia<=31){
                        printf ("\nFecha introducida correctamente");
                        a = 1;
                    }else{
                        printf ("\nIngresa el dia nuevamente: ");
                        scanf ("%d%*c", &dia);
                    }
                }else if(mes == 4 || mes == 6 || mes == 9 || mes == 11){
                    if(dia >=1 && dia<=30){
                        printf ("\nFecha introducida correctamente");
                        a = 1;
                    }else{
                        printf ("\nIngresa el dia nuevamente: ");
                        scanf ("%d%*c", &dia);
                    }
                }else{
                    if (dia>= 1 || dia<=28){
                        printf ("\nFecha introducida correctamente");
                        a = 1;
                    }else{
                        printf ("\nIngresa el dia nuevamente: ");
                        scanf ("%d%*c", &dia);
                    }
                }
            }
        }else{
            c = 1;
            if(mes < 1 || mes >12){
                printf ("\nIngresa nuevamente el mes: ");
                scanf ("%d%*c", &mes);
            }else{
                b = 1;
                if(mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12){
                    if (dia >= 1 && dia<=31){
                        printf ("\nFecha introducida correctamente");
                        a = 1;
                    }else{
                        printf ("\nIngresa el dia nuevamente: ");
                        scanf ("%d%*c", &dia);
                    }
                }else if(mes == 4 || mes == 6 || mes == 9 || mes == 11){
                    if(dia >=1 && dia<=30){
                        printf ("\nFecha introducida correctamente");
                        a = 1;
                    }else{
                        printf ("\nIngresa el dia nuevamente: ");
                        scanf ("%d%*c", &dia);
                    }
                }else{
                    if (dia>= 1 || dia<=29){
                        printf ("\nFecha introducida correctamente");
                        a = 1;
                    }else{
                        printf ("\nIngresa el dia nuevamente: ");
                        scanf ("%d%*c", &dia);
                    }
                }
            }
        }
    }
}

*/