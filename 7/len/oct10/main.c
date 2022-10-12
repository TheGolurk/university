#include<stdio.h>

int main(int argc, char const *argv[])
{
    int a;
    int b;
    int par = 0, impar = 0;
    scanf("%d", &a);
    
    for (size_t i = 0; i < a; i++)
    {
        scanf("%d", &b);
        if (b % 2 == 0){
            par++; 
            continue;
        } 
        impar++;
    }
    
    printf("%d %d", par, impar);

    return 0;
}
