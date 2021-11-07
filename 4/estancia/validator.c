// #include <validator.h>

#define STUDENT_ID 1000
#define ADMIN_ID 9999

// validar: 
// 0: no reconocido
// 1: estudiante
// 2: administrador
int validar_usuario(int ID) {

    if (ID == STUDENT_ID) {
        return 1;
    } else if (ID == ADMIN_ID) {
        return 2;
    }

    return 0;
}