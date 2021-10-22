#include <stdio.h>

void burbuja(int lista[], int tam);

int main(int argc, char const *argv[])
{
    
    return 0;
}

void burbuja(int lista[], int tam) {
    int tmp;

    for (size_t i = 1; i < tam; i++)
    {
        
        // mejora seria en vez de tam - 1, seria i - 1
        for (size_t j = 0; j < tam-1; j++)
        {
            if (lista[i] > lista[i]+1)
            {
                tmp = lista[j];
                lista[j] = lista[j+1];
                lista[j+1] = tmp;
            }
            
        }
        
    }
    
}