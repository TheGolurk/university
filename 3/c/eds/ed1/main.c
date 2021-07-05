#include <stdio.h>

float invest(float quantity) {
    float interest_per_month = quantity * 0.02;
    return quantity + interest_per_month;
}

void print_arr(float quantities[]){
    for (size_t i = 1; i < 13; i++)
    {
        printf("Cantidad a invertir en el mes %d es %0.2f \n", i, quantities[i]);
    }
}

int main(int argc, char const *argv[])
{   
    float quantities[13];

    printf("Cantidad de dinero a invertir: \n");
    scanf("%f", &quantities[0]);

    for (size_t i = 1; i < 13; i++)
    {   
        quantities[i] = invest(quantities[i-1]);
    }

    print_arr(quantities);
    

    return 0;
}
