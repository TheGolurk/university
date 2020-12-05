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
  printf("NOMENCLATURA ORGÁNICA: COMPUESTOS OXIGENADOS \n");

  message();
  clearScreen();

  printf("\n¿QUE SON LOS COMPUESTOS OXIGENADOS?");
  printf("\n\n  Son grupos de compuestos orgánicos que se forman \n por la sustitución de hidrógenos\n de los hidrocarburos por oxígenos. \n Contienen el oxígeno entre\n dos radicales y resultan de la deshidratación de dos moléculas de alcohol.");

  printf("\n\n Contienen un enlace carbono-oxígeno. Este puede ser sencillo o doble.");

  message();
  clearScreen();

  // TODO: ELEGIR SOBRE 1.-Alcoholes. 2.-Cetonas. 3.-Ácidos carboxílicos. 4.-Aldehídos.
  int opcion;
  do
  {
    printf("\n\nElige una opción");
    printf("\n 1.-Alcoholes");
    printf("\n 2.-Cetonas");
    printf("\n 3.-Ácidos carboxílicos");
    printf("\n 4.-Aldehídos");
    printf("\n 5.-Salir");
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
    case 5:
      printf("\nHasta luego");
      break;
    default:
      printf("\nERROR OPCION INCORRECTA");
    }

  } while (opcion != 5);
  return 0;
}

void alcoholes()
{
  message();
  clearScreen();

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

  message();
  clearScreen();

  printf("\n Se caracteriza por poseer un grupo funcional carbonilo y doble enlace \n");

  printf(" Se nombran con el sufijo -ona al hidrocarburo del cual provienen como\n propa \n penta\n hexa\n  ");

  printf("EJEMPLOS \n C4H8O Butanona\n C3H6O Propanona \n C6H10O Ciclohexanona\n C5H8O2 2-4Pentanodiona \n C7H14O 2-Heptanona\n C4H6O2 Butanodiona");
  message();
  clearScreen();

  printf("Cuando la cetona no pertenece al  grupo funcional se les nombra como oxo \n EJEMPLOS:\n  C5H8O2 4-oxopentanal \n  C4H6O2 3-oxobutanal ");
}
// lore
void carboilicos()
{
  message();
  clearScreen();

  printf("\n Se caracterizan por tener un grupo funcional -COOH");
  printf("\n Los acidos carboxilicos se identifican con la terminación -oico\n	-ico");

  message();
  printf("EJEMPLOS\n  HCOH Ácido metanoico\n CH3CH2COH Ácido propanoico\n CH3COOH Ácido etanoico\n CH3CH2COOH Ácido hexanoico");
  clearScreen();

  printf("\n Cuando en un compuesto está unido a un hidrocarburo cíclico terminan con el sufijo -carboxilílico\n ");
  message();
  clearScreen();

  printf("\n Los derivados de los ácidos carboxilicos son");
  printf("Ésteres\n Anhídrido de sodio \n Sal \n  Haluro de sodio \n Amida \n Cianuro\n");
}
// mitzi
void aldehidos()
{

  message();
  clearScreen();

  printf("\n Se denominan con los alcoholes cambiando la terminación -ol por -al");
  printf("\n Cuando el grupo CHO no es la principal función es nombrada como formil.");
  printf("\nCompuestos orgánicos caracterizados por poseer el grupo \nfuncional -CHO");
  message();
  clearScreen();

  printf("\n EJEMPLOS con terminación -al\n  CH2O metanal\n C2H4O etanal\n CH6H10O2 hexanodial");
  message();
  clearScreen();

  printf(" \n En dado caso de  que el grupo aldehidos esté enlazado a unidades se utilizará el sufijo -Carbaldehído\n");
  clearScreen();

  printf("EJEMPLOS\n C7H6O benzaldehído\n C2H4O Acetaldehído");
}

// Limpia la pantalla
void clearScreen()
{
  fflush(stdin);
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