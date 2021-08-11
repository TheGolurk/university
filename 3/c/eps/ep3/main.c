/******************************************************************************
PROGRAMA "CATÁLOGO DE PRODUCTOS "
CONTRUCTORA:  CYL Almacén
By: Hernandez Najera Christian & Valle Gonzalez Lorena


Los productos del almacén requieren:
ID(clave)
nombre del producto
marca
unidad de medida
cantidad de existencia
precio de compra
precio de venta 
*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct products
{
    int id; // código con números
    char name_P[20];   // nombre del producto
    char brand[20];    //marca
    char unit_mesure[20]; // unidad de medidad: kg, piezas, m^2, etc.
    int quantity;   // cantidad existente, es decir, cuantas piezas o metros hay de tal prodcuto
    float sale_price; // precio para el cliente
    float buying_price;   // precio a como lo compra el dueño
};

// agregar un nuevo campo
void add()
{   
    FILE *ptrArchivo;
    ptrArchivo = fopen("vuelos.dat", "a+");
    if (ptrArchivo == NULL) {
        return;
    }

    struct products reg_product,reg;

     while(fread(&reg, sizeof(struct products), 1, ptrArchivo))
     {
        if(reg_product.id == reg.id  ||  strcmp(reg_product.name_P, reg.name_P) == 0)
        {
            printf("Clave ya registrado\n");
            printf("Horario de vuelo ya registrado\n");
    
            return;
        }
     }
    
    fwrite(&reg_product, sizeof(struct products), 1, ptrArchivo);
    if (fwrite != 0) {
        printf("Escrito correctamente! \n");
    }

    fclose(ptrArchivo);
}

//consultar todos los productos 
void getAll(){
    FILE *ptrArchivo;
    struct products reg_product;

    ptrArchivo = fopen("products.dat", "r");
    if(ptrArchivo == NULL)
    {
        return;
    }
    while(fread(&reg_product, sizeof(struct products), 1, ptrArchivo))
    {
        if (reg_product.id == 0)
        {
            continue;
        }   

        printf(" id = %d\n name = %s\n brand = %s\n mesure = %s\n quantity = %d\n buying price = %0.2f\n sale price = %0.2f\n\n", 
        reg_product.id, reg_product.name_P, reg_product.brand, reg_product.unit_mesure, reg_product. quantity,
        reg_product.buying_price, reg_product.sale_price);
    }
    
    fclose(ptrArchivo);
}

void _showAll() {
    FILE *ptrArchivo;
    struct products reg_product;

    ptrArchivo = fopen("products.dat", "r");
    if(ptrArchivo == NULL)
    {
        return;
    }
    while(fread(&reg_product, sizeof(struct products), 1, ptrArchivo))
    {  
        printf(" id = %d\n name = %s\n brand = %s\n mesure = %s\n quantity = %d\n buying price = %0.2f\n sale price = %0.2f\n\n", 
        reg_product.id, reg_product.name_P, reg_product.brand, reg_product.unit_mesure, reg_product. quantity,
        reg_product.buying_price, reg_product.sale_price);
    }
    
    fclose(ptrArchivo);
}


//consultar por clave o  nombre
void getByID(int opt){
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

    switch(opt)
    {
        case 1:
            printf("Introduce el id:\n");
            scanf("%d", &id);
            
            if (id == 0)
            {
                printf("No se puede buscar ID's eliminados\n");
                return;
            }

            while(fread(&reg_product, sizeof(struct products), 1, ptrArchivo))
            {
                if(id != reg_product.id)
                {
                    continue;
                }

                printf("id = %d\n name = %s\n brand = %s\n mesure = %s\n quantity = %d\n buying price = %0.2f\n sale price = %0.2f\n\n", 
                reg_product.id, reg_product.name_P, reg_product.brand, reg_product.unit_mesure, reg_product. quantity,
                reg_product.buying_price, reg_product.sale_price);
                
                fclose(ptrArchivo);
                return;
            }
             
            break;

        case 2:
            printf("Introduce el nombre:\n");
            scanf("%s", &name);

            if (strcmp(name, "")==0)
            {
                printf("No se puede consultar un nombre vacio\n");
                return;
            }
            

            while(fread(&reg_product, sizeof(struct products), 1, ptrArchivo))
            {
                 res = strcmp(name, reg_product.name_P);

                 if(res == 0)
                 {   
                    printf ("id = %d\n name = %s\n brand = %s\n mesure = %s\n quantity = %d\n buying price = %0.2f\n sale price = %0.2f\n\n", 
                    reg_product.id, reg_product.name_P, reg_product.brand, reg_product.unit_mesure, reg_product. quantity,
                    reg_product.buying_price, reg_product.sale_price);
                 }

                 fclose(ptrArchivo);
                 return;
            }
        
            break;
    
        default:
            printf("Opcion incorrecta \n");
            return;
    }

    printf("No encontrado\n");
    fclose(ptrArchivo);
} 

//consultar por cantidad
void getPerQuantity(int qty){
    FILE *ptrArchivo;
    struct products reg_product;

    ptrArchivo = fopen("products.dat", "r");
    if(ptrArchivo == NULL)
    {
        return;
    }
    
    while(fread(&reg_product, sizeof(struct products), 1, ptrArchivo))
    {
        if(qty != reg_product.quantity || reg_product.id == 0)
        {
            continue;
        }   
        printf("id = %d\n name = %s\n brand = %s\n mesure = %s\n quantity = %d\n buying price = %0.2f\n sale price = %2f\n\n", 
        reg_product.id, reg_product.name_P, reg_product.brand, reg_product.unit_mesure, reg_product. quantity,
        reg_product.buying_price, reg_product.sale_price);
    }
            
    fclose(ptrArchivo);
}

//modificar 
void modify(int opt, int ID){
    int index = 0;
    FILE *ptrArchivo;
    struct products reg_product;

    ptrArchivo = fopen("products.dat", "r+b");
    if(ptrArchivo == NULL)
    {
        return;
    }

    if (ID == 0)
    {
        printf("No se puede modificar un ID eliminado\n");
        return; 
    }
    
    
    while(fread(&reg_product, sizeof(struct products), 1, ptrArchivo))
    {
        if(ID != reg_product.id)
        {
            index++;
            continue;
        }

        fseek(ptrArchivo, (sizeof(reg_product))*index, SEEK_SET);
        
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

        fwrite(&reg_product, sizeof(reg_product), 1, ptrArchivo);
        if (fwrite != 0) {
            printf("Escrito correctamente! \n");
        }

        fclose(ptrArchivo);
        break;
    }         
         
    printf("ID %d no encontrado\n", ID);
}

void logical_deletion(struct products reg_product, int ID, FILE *ptrArchivo, int index) {
    while(fread(&reg_product, sizeof(struct products), 1, ptrArchivo))
    {   
        if(ID != reg_product.id)
        {
            index++;
            continue;
        }

        fseek(ptrArchivo, (sizeof(reg_product))*index, SEEK_SET);
        reg_product.id = 0; // Inhabilitado    
            
        fwrite(&reg_product, sizeof(reg_product), 1, ptrArchivo);

        if (fwrite == 0) {
            printf("No se pudo borrar logicamente\n");
            return;
        }

        break;
    }
    
    return;
}

void physical_deletion(struct products reg_product, FILE *ptrArchivo, FILE *ptrEscribir, int ID, int index) {
    while(fread(&reg_product, sizeof(struct products), 1, ptrArchivo))
    {
        if(reg_product.id != ID)
        {
            index++;
            continue;
        }

        fseek(ptrArchivo, (sizeof(reg_product))*index, SEEK_SET);
        

        break;
    }

    return;
}

//borrar 
void delete(int opt, int ID){
    int index = 0;
    
    FILE *ptrArchivo;
    FILE *ptrEscribir;

    struct products reg_product;

    if (ID == 0) {
        printf("No se puede eliminar un ID 0\n");
        return;
    } 

    switch (opt)
    {
        case 1:

            ptrArchivo = fopen("products.dat", "r+b");
            if(ptrArchivo == NULL)
            {
                printf("No se pudo abrir el archivo \n");
                return;
            }

            logical_deletion(reg_product, ID, ptrArchivo, index);
            fclose(ptrArchivo);
            
            printf("Borrado correctamente\n");  
            break;

        case 2:

            ptrArchivo = fopen("products.dat", "r");
            ptrEscribir = fopen("products.dat", "r+");
            if(ptrArchivo == NULL || ptrEscribir)
            {
                printf("No se pudo abrir el archivo \n");
                return;
            }

            physical_deletion(reg_product, ptrArchivo, ptrEscribir, ID, index);
            fclose(ptrArchivo);
            fclose(ptrEscribir);

            _showAll();
            
            break;
        
        default:
            printf("Opcion incorrecta\n");
            return;
    }

}


//solo mandar a llamar las funciones y  sección de menú
int main(int argc, char const *argv[])
{
    int option;
    int opt = 0;
    int qty;
    int ID;


    while(option != 7) 
    {
        printf(" 1.-Registar un producto \n 2.- Consulta de Registro completo \n 3.-Consulta con clave/nombre\n 4.-Consulta por cantidad existente \n 5.-Modificar producto\n 6.- Eliminar \n 7.-Salir \n");
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

                printf("Introduce la opción a buscar 1.- ID 2.- Nombre: \n");
                scanf("%d", &opt);

                getByID(opt);
                break;
            
            case 4:

                printf("Introduce la cantidad a buscar: \n");
                scanf("%d", &qty);

                getPerQuantity(qty);
                break;
            
            case 5:

                printf("Ingrese el ID del producto a modificar:\n");
                scanf("%d", &ID);
    
                modify(opt,ID);
                break;
            
            case 6:

                printf("Que tipo de eliminado quiere? 1.-Logico  2.- Fisico \n");
                scanf("%d", &opt);

                printf("Ingrese el ID del producto a eliminar:\n");
                scanf("%d", &ID);
                
                delete(opt, ID);
                
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
