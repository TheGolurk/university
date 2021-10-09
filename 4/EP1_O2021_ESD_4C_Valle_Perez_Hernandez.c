#include <stdio.h>

// struct
struct Register {
    char  carplates;
    char  model;
    char  color;
    int   date;
    float checkin;
    float checkout;
    char  name[30];
    struct Register next;
};


// Links a recursos que nos puede ayudar a hacer esta cosa
// https://gist.github.com/rdleon/d569a219c6144c4dfc04366fd6298554
// https://github.com/rafaeltardivo/C-Queue/blob/master/queue.c
// https://gist.github.com/fenrig/2624655



// aqui las definiciones nadamas. despues del main van las funciones
void check_in();
void check_out();
void show();
void Menu();

int main(int argc, char const *argv[])
{
    Menu();

    return 0;
}

void Menu(){
    int opt;
    scanf("%d", &opt);

    while (opt != 4)
    {

        switch (opt)
        {
        case 1:
            break;
        
        default:
            break;
        }

    }

}

