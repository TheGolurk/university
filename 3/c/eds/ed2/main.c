#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct arr_data_meta {
    int rows;
    int columns;
};

struct arr_data
{
    int value;
};

void to_file(int rows, int columns, int values[][2]) {
    struct arr_data_meta meta;
    struct arr_data data;

    FILE *file_meta;
    FILE *file_data;

    file_meta = fopen("file_meta.bin", "a+");
    file_data = fopen("file_data.bin", "a+");

    if (file_meta == NULL || file_data == NULL)
    {
        printf("Cannot open files");
        return;
    }

    meta.rows = rows;
    meta.columns = columns;

    fwrite(&meta, sizeof(struct arr_data_meta), 1, file_meta);
    if (fwrite != 0) {
        printf("Escrito correctamente! \n");
    }
    fclose(file_meta);  

    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            data.value = values[i][j];
            
            fwrite(&data, sizeof(struct arr_data_meta), 1, file_data);
            if (fwrite == 0) {
                printf("Hubo un error escribiendo! \n");
            }
        }
        
    }

    fclose(file_data);
}

void read(int *rows, int *columns, int *values[][2]) {
    struct arr_data_meta meta;
    struct arr_data data;

    FILE *file_meta;
    FILE *file_data;

    file_meta = fopen("file_meta.bin", "a+");
    file_data = fopen("file_data.bin", "a+");

    if (file_meta == NULL || file_data == NULL)
    {
        printf("Cannot open files");
        return;
    }

    while(fread(&meta, sizeof(struct arr_data_meta), 1, file_meta))
    {
        printf("rows: %d columns: %d\n", meta.rows, meta.columns);
        rows = meta.rows;
        columns = meta.columns;
    }

    int indexc = 0, indexr = 0;
    printf("{");
    while(fread(&data, sizeof(struct arr_data), 1, file_data))
    {
        if (indexc == 1 || indexr == 1)
        {
            printf("\n");
            indexr = 0;
            indexc = 0;
        }
        
        values[indexr][indexc] = data.value;

        printf("%d,", data.value);
        indexc++;
        indexr++;
        
    }
    printf("}\n");
    

    fclose(file_data);
    fclose(file_meta);
}

void average(int rows, int columns, int values[][2]) {
    int total = rows * columns;
    int sum = 0;

    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            sum += values[i][j];
        }
        
    }
    
    printf("average is %d \n", sum/total);
}

int main(int argc, char const *argv[])
{
    int *rows, *columns;
    int arr1[2][2]; 
    int *arr2[2][2];

    arr1[0][0] = 1;
    arr1[0][1] = 2;
    arr1[1][0] = 3;
    arr1[1][1] = 4;
   
   to_file(2, 2, arr1);
   read(rows, columns, arr2);
   average(rows,columns,arr2);

    return 0;
}
