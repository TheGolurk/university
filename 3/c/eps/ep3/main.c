/******************************************************************************
PROGRAMA "CATÁLOGO DE PRODUCTOS "
CONTRUCTORA:  CYL Almacén
By: Hernandez Najera Christian & Valle Gonzalez Lorena


Los productos del almacén requieren:
nombre del producto
clave única
marca
unidad de medida
cantidad de existencia
precio de compra
precio de venta 


TOMAR EN CEUNTA LAS CONSULTAS DE ACUERDO A LA CANTIDAD existente de x producto 
BORRADO LÓGICO-> Asignar una marca (con un símbolo, etc) a ciertos prodcutos para desarrollar
la función de habilitar y deshabilitar ( es decir, que no los pueda ver el usuario) 
BORRADO FÍSICO->Modificar el nombre del producto ingresando la clave y cambiarle los datos pero dejando la clave
*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct products
{
    int id; // código opción 1 con números, opción 2 con letras
    char name_P[20];   // nombre del producto, ya sea cemento, varillas, tornillos, etc.
    char brand[20];    //marca
    char unit_mesure[20]; // unidad de medidad: kg, piezas, m^2, etc.
    int quantity;   // cantidad existente, es decir, cuantas piezas o metros hay de tal prodcuto
    float sale_price; // precio para el cliente
    float buying_price;   // precio a como lo compra el dueño
};


void add()
{
    FILE *ptrArchivo;
    struct products reg_product;

    printf("Asignación de clave para el producto:\n");
    scanf("%d", &reg_product.id);

    printf("Introduce el nombre del producto a registar:\n");
    scanf("%s", &reg_product.name_P);
    
    printf("Introduce la marca:\n");
    scanf("%s", &reg_product.brand);
    
    printf("Unidad de medida: \n");
    scanf("%s", &reg_product.unit_mesure);
    
    printf("Cantidad disponible del producto:\n");
    scanf("%d", &reg_product.quantity);
    
    printf("Precio de compra: \n");
    scanf("%f", &reg_product.buying_price);
    
    printf("Precio de venta: \n");
    scanf("%f", &reg_product.sale_price);

    ptrArchivo = fopen("products.dat", "a+");
    if (ptrArchivo == NULL) {
        return;
    }

    fwrite(&reg_product, sizeof(struct products), 1, ptrArchivo);
    if (fwrite != 0) {
        printf("Escrito correctamente! \n");
    }
    fclose(ptrArchivo);


    /* Leer todos */
    ptrArchivo = fopen("products.dat", "r");
    if(ptrArchivo == NULL)
    {
        return;
    }
    
    /* recorrer */
    while(fread(&reg_product, sizeof(struct products), 1, ptrArchivo))
    {

        
      printf ("id = %d name = %s brand = %s mesure = %s quantity = %d buying price = %0.2f sale price = %0.2f\n", 
      reg_product.id, reg_product.name_P, reg_product.brand, reg_product.unit_mesure, reg_product. quantity,
      reg_product.buying_price, reg_product.sale_price);
    }

    fclose(ptrArchivo);
}

void getAll(){

}

void getByID(){

    int opt;
    int id;
    char name[50];
    int  res;

    FILE *ptrArchivo;
    struct products reg_product;

    ptrArchivo = fopen("products.dat", "r");
    if(ptrArchivo == NULL)
    {
        return;
    }

    printf("Introduce la opción a buscar 1.- ID 2.- Nombre: \n");
    scanf("%d", &opt);

    switch(opt)
    {
        case 1:
            printf("Introduce el id:\n");
            scanf("%d", &id);

            while(fread(&reg_product, sizeof(struct products), 1, ptrArchivo))
            {
                if(id != reg_product.id)
                {
                    continue;
                }

                printf("id = %d name = %s brand = %s mesure = %s quantity = %d buying price = %0.2f sale price = %0.2f\n", 
                reg_product.id, reg_product.name_P, reg_product.brand, reg_product.unit_mesure, reg_product. quantity,
                reg_product.buying_price, reg_product.sale_price);
            }

            break;

        case 2:
            printf("Introduce el nombre:\n");
            scanf("%s", &name);

            while(fread(&reg_product, sizeof(struct products), 1, ptrArchivo))
            {
                 res = strcmp(name, reg_product.name_P);

                 if(res == 0)
                 {   
                    printf ("id = %d name = %s brand = %s mesure = %s quantity = %d buying price = %0.2f sale price = %0.2f\n", 
                    reg_product.id, reg_product.name_P, reg_product.brand, reg_product.unit_mesure, reg_product. quantity,
                    reg_product.buying_price, reg_product.sale_price);
                 }
            }
        
            break;
    
        default:
            return;
    }
    
    fclose(ptrArchivo);
}

void modify(){

}

void getPerQuantity(){

}

//solo mandar a llamar las funciones y la opción de menú
int main(int argc, char const *argv[])
{
   
    int option;
    while(option != 6) 
    {
        printf(" 1.-Registar un producto  \n 2.- Consulta de Registro completo \n 3.-Consulta con clave/nombre\n 4.-Consulta por cantidad existente \n 5.-Modificar producto\n 6.- Eliminar \n 7.-Salir \n");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                add();
                break;
            
            case 2:
                getAll();
                break;
            
            case 3:
                getByID();
                break;
            
            case 4:
                getPerQuantity();
                break;
            
            case 5:
                modify();
                break;
            
            case 6:
                // delete();
                break;
            
            case 7:
                printf("Adios\n");
                break;
            
            default:
                printf("Respuesta incorrecta");
                return 0;
        }
    }

    return 0;
}



