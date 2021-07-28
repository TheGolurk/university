#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct arr_data_meta {
    int rows;
    int columns;
};

struct arr_data
{
    int values[10000][10000];
};

void to_file(int rows, int columns, int values[][]) {
    struct arr_data_meta meta;
    struct arr_data arr_data_data;
    
    memcpy(arr_data_data.values, values, sizeof(values));

    FILE *file_meta;
    FILE *file_data;

    file_meta = fopen("file_meta.bin", "a+");
    file_meta = fopen("file_data.bin", "a+");

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
            //fwrite(*values[i][j], sizeof(values), 1, file_data);
            printf("%d", arr_data_data.values[i][j]);
        }        
    }

    fclose(file_data);
}

void average(int rows, int columns, int values[][]) {

}

int main(int argc, char const *argv[])
{
    int rows = 2, columns = 2;
    int arr1[rows][columns]; 
    int arr2[rows][columns];

    arr1[0][0] = 1;
    arr1[0][1] = 2;
    arr1[1][0] = 3;
    arr1[1][1] = 4;
   
   to_file(rows, columns, arr1);

    return 0;
}
