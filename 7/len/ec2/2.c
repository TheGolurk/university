#include<stdio.h>

void q0(char word[10], int index);
void q1(char word[10], int index);

int main(int argc, char const *argv[])
{
    char word[10];
    printf("ingresa una cadena \n");
    fgets(word, sizeof word, stdin);


    q0(word, 0);

    return 0;
}

void q0(char word[10], int index) {
    if (index == 9) {
        printf("El automata termina cadena invalida \n");
        return;
    }
    if (word[index] != 'a' && word[index] != 'b') {
        printf("El automata termina cadena invalida \n");
        return;
    }

    if (word[index] == 'b') {
        q1(word, index+1);
    } else if (word[index] == 'a') {
        q0(word, index+1);
    } else {
        printf("cadena con caracter %c invalida \n", word[index]);
        return;
    }
}

void q1(char word[10], int index) {
    if(index == 9) {
        printf("El automata no debe terminar en q1 y la cadena es valida \n");
        return;
    }
    if (word[index] != 'a' && word[index] != 'b') {
        printf("El automata termina pero la cadena es valida \n");
        return;
    }

    if (word[index] == 'b') {
        q1(word, index+1);
    } else if (word[index] == 'a') {
        q0(word, index+1);
    } else {
        printf("cadena con caracter %c invalida \n", word[index]);
        return;
    }
}