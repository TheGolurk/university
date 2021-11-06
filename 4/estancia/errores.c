#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constantes.c"

void handlerErr(const char *err) {
    fprintf(stderr,  ANSI_COLOR_RED "An error ocurred. [ %s ] \n" ANSI_COLOR_RED, err);
    exit(EXIT_FAILURE);
}

void WarnErr(const char *err) {
    printf(ANSI_COLOR_YELLOW "%s" ANSI_COLOR_YELLOW "\n", err);
    printf(ANSI_COLOR_RESET);
}

void WrongOption() {
    printf(ANSI_COLOR_YELLOW "OPCION INCORRECTA" ANSI_COLOR_YELLOW "\n");
    printf(ANSI_COLOR_RESET);
}