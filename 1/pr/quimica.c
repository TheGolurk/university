#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void clearScreen();
void message();
void alcoholes();
void cetonas();
void carboilicos();
void aldehidos();

int main(void)
{
  printf("Nomenclatura organica \n");

  message();
  clearScreen();

  printf("\n¿QUE SON LOS COMPUESTOS OXIGENADOS?");
  printf("\n\n  Son grupos de compuestos orgánicos que se han formado\n por la sustitución de hidrógenos\n de los hidrocarburos por oxígenos. Son compuestos\n orgánicos oxigenados que contienen el oxígeno entre\n dos radicales y resultan de la deshidratación de dos moléculas de alcohol.");

  printf("\n\nLos compuestos oxigenados son aquellos que contienen un enlace carbono-oxígeno. Este puede ser sencillo o doble.");

  message();
  clearScreen();

  // TODO: ELEGIR SOBRE 1.-Alcoholes. 2.-Cetonas. 3.-Ácidos carboxílicos. 4.-Aldehídos.
  int opcion;
  printf("\n\nElige una opción");
  printf("\n 1.-Alcoholes");
  printf("\n 2.-Cetonas");
  printf("\n 3.-Ácidos carboxílicos");
  printf("\n 4.-Aldehídos");
  printf("\n\n opcion: ");
  scanf("%d", &opcion);

  switch (opcion)
  {
  case 1:
    alcoholes();
    break;
  case 2:
    cetonas();
    break;
  case 3:
    carboilicos();
    break;
  case 4:
    aldehidos();
    break;
  default:
    printf("\nERROR OPCION INCORRECTA");
  }

  return 0;
}

void alcoholes()
{
  printf("\n El alcohol forma parte de un enlace sencillo");
  printf("\nCLASIFICACIÓN DE ALCOHOLES");
  printf("\n\nPrimarios: cuando el OH esta unido a un Carbono primario \nSecundarios: cuando el OH esta unido a un Carbono secundario \nTerciario: cuando el OH esta unido a un Carbono  terciario");

  message();
  clearScreen();

  printf("\nPRIMARIOS");
  printf("\n\n CH3-CH2-OH (Etanol)");
  printf("\n Tiene el grupo hidroxilo conectado a un átomo de carbono primario.");

  message();
  clearScreen();

  printf("\nSECUNDARIOS");
  printf("\n CH3CH(OH)CH3 (Alcoholes isopropilico)");
  printf("Un alcohol es secundario, si el átomo de hidrógeno \n (H) sustituido por el grupo hidroxilo (-OH) pertenece a un carbono (C) secundario");

  message();
  clearScreen();

  printf("\nTERCIARIOS");
  printf("(H3C)3COH Terbutanol");
  printf("\n Un alcohol terciario es aquel en el cual el grupo hidroxilo, OH, se halla enlazado a un carbono terciario");

  message();
  clearScreen();
}

void cetonas()
{
  printf("aca");
}

// lore
void carboilicos()
{

  printf("\n Los acidos carboxilicos se identifican con la terminación -oico -ico");
  printf("\n Se caracterizan por tener un grupo funcional -COOH");
  printf("\n Cuando en un compuesto hay 3 o más -COOH se les asigna el sufijo -carboxilico");

  message();
  clearScreen();

  printf("\n Los derivados de los ácidos carboxilicos son");
  printf("Ésteres, ");
}

// mitzi
void aldehidos()
{
  message();
  clearScreen();

  fflush(stdin);
  printf("Compuestos orgánicos caracterizados por poseer el grupo funcional -CHO");
  printf("\n Se denominan con los alcoholes cambiando la terminación -ol por -al");
  printf("\n Cuando el grupo CHO no es la principal función es nombrada como formil.");

  printf("\n\nNomenclatura Sistemática");
  printf("\nEsta nomenclatura consiste en ");
}

// Limpia la pantalla
void clearScreen()
{
  const char *CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";
  write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);
}

// Mensaje en blanco para continuar
void message()
{
  printf(" ");
  while (getchar() != '\n')
    ;
}
