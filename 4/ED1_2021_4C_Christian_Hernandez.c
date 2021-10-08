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
    int opt;

    printf("Introduce an option: \n");
    printf("1.- Insert employee \n 2.- Test Palindrome word \n 3.- Show Employees \n");
    scanf("%d", opt);
    
    return 0;
}
