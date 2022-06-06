#include <stdio.h>

int main(int argc, char const *argv[])
{
    // 5+1*3/3    
    int n1, n2;
    char op;
        int res = 10;

        // preguntar al usuario otro numero
        printf("ingrese un oper: ");
        scanf("%c", &op);

        printf("ingresa un numero\n");
        scanf("%d", &n1);

        printf("ingresa otro numero\n");
        scanf("%d", &n2);

        res += resultado(&n1, &n2, &op);
        printf("%d", res);
    
    

    return 0;
}

int resultado(int *n1, int *n2, char *op) {
    int abc = 0;
    switch (*op)
    {
    case '+':
        abc = *n1 + *n2;
        break;
    case '*':
    break;
    case '-':
    break;
    
    default:
        break;
    }

    return abc;
}