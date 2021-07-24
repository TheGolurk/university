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
    char name_P[20];   // nombre del producto, ya sea cemento, varillas, tornillos, etc.
    int code; // código opción 1 con números, opción 2 con letras
    char brand[20];    //marca
    char unit_mesure[20]; // unidad de medidad: kg, piezas, m^2, etc.
    float quantity;   // cantidad existente, es decir, cuantas piezas o metros hay de tal prodcuto
    float sale_price; // precio para el cliente
    float buying_price;   // precio a como lo compra el dueño
};



void  func_registers()

{
    FILE *ptrArchivo=NULL;
    struct products reg_product, other_product;
    
    printf( "Introduce el nombre del producto a registar:\n");
    scanf("%[^\n]%*c",reg_product.name_P);
    
    printf(" Asignación de clave para el producto:\n");
    scanf("%d%*c", &reg_product.code);
    
    printf(" Introduce la marca:\n");
    scanf("%[^\n]%*c", reg_product.brand);
    
    printf("Unidad de medida");
    scanf("%[^\n]%*c", reg_product.unit_mesure);
    
    printf("Cantidad disponible del producto:\n");
    scanf("%f%*c",reg_product.quantity);
    
    printf("Precio de compra: \n");
    scanf("%f%*c",reg_product.buying_price);
    
    printf("Precio de venta: \n");
    scanf("%f%*c",reg_product.sale_price);
    
    ptrArchivo = fopen("reg_product", "ab");
    
}


//solo mandar a llamar las funciones y la opción de menú

int main(int main(int argc, char const *argv[]);
{
   
    int option;
    
    
    while(opt !=6) 
    {
    
        printf(" 1.-Registar un producto  \n 2.- Consulta de Registro completo \n 3.-Consulta con clave\n");
        printf("4.-Modificar producto\n 5.Consulta por cantidad existente\n 6.-Salir");
        scanf("%d", &option); 
        
    }
 
    switch(option)
    {
        
        case 1:
        
        break;
        
        case 2:
        
        break;
        
        case 3:
        
        break;
        
        case 4:
        
        break;
        
        case 5:
        
        break;
        
        case 6:
        
        break;
        
        default:
        
        
    }
    
 
}



