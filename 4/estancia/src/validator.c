// #include <validator.h>

#define ADMIN_ID 9999

#define ARR_SIZE(x)  (sizeof(x) / sizeof((x)[0]))

extern int users[] = {1,2,3,4,5,6};   

// encontrar_alumno:
// 0 -> encontrado
// -1 -> no encontrado
int encontrar_alumno(int ID) {
    int encontrado = -1;
    for (size_t i = 0; i < ARR_SIZE(users); i++)
    {
        if (users[i] != ID)
        {
            continue;
        }

        encontrado = 0;
    }

    return encontrado;
}

// validar: 
// 0: no reconocido
// 1: estudiante
// 2: administrador
int validar_usuario(int ID) {

    if (encontrar_alumno(ID) == 0) {
        return 1;
    } else if (ID == ADMIN_ID) {
        return 2;
    }

    return 0;
}