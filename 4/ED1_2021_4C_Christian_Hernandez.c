/*
Christian Hernandez Najera
HNCO200217
4-. C
ED1
08/10/2021
*/


#include <stdio.h>

struct Word {
    char Letter;
    struct Word *next;
};

struct Employee {
    char Name[100];
    char CURP[18];
}; 

int main(int argc, char const *argv[])
{
    int opt = 0;
    
    while (opt != 4)
    {
    
        printf("Introduce an option: \n");
        printf(" 1.- Insert employee \n 2.- Test Palindrome word \n 3.- Show Employees \n 4.- Exit \n \n");
        scanf("%d", &opt);

        switch (opt)
        {
        case 1:
            printf("1 \n");
            break;
        
        case 2:
            printf("2 \n");
            break;

        case 3:
            printf("3 \n");
            break;

        case 4:
            printf("bye \n");
            break;

        default:
            printf("incorrect option \n");
            break;
        }
    
    }    

    return 0;
}
