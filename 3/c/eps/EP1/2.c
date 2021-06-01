/* El usuario introducirá el año, mes (en número), y el año, este podrá ser un año bisiesto o no.

Se determinará si es un año bisiesto como a su vez, calcular el día que le corresponde en el año.

Se mostrará el número de día correspondiente del año que fue introducido por el usuario */

#include <stdio.h>

#define enero 31
#define marzo 31
#define abril 30
#define mayo 31
#define junio 30
#define julio 31
#define agosto 31
#define septiembre 30
#define octubre 31
#define noviembre 30
#define diciembre 31

int main()
{
   int dia, mes, a, feb=28;

   printf(" Introduzca el dia:\n ");
   scanf("%d",&dia);

   printf(" Introduzca el mes en numero: \n ");
   scanf("%d",&mes);

   printf(" Introduzca el año: \n");
   scanf("%d",&a);

    if (mes >=1 && mes <=12)
        {
            switch (mes)
            {
                case 1:
                case 3:
                case 5:
                case 7:
                case 8:
                case 10:
                case 12: if (dia >=1 && dia <=31)
                            printf(" \nFECHA VALIDA\n");
                        else
                            printf( "\nFECHA INVALIDA\n");
                break;

                case 4:
                case 6:
                case 9:
                case 11: if (dia >=1 && dia <=30)
                            printf(" \nFECHA VALIDA\n");
                        else
                            printf( "\nFECHA INVALIDA\n");
                break;

                case 2: if (a %4 !=0 ||a %100 ==0 && a %400 !=0 )
                            feb=29;
                            if (dia >=1 && dia <=29)
                                printf(" \nFECHA VALIDA\n");
                        else
                          printf( "\nFECHA INVALIDA\n");
                          if (dia >=1 && dia <=28)
                                printf(" \nFECHA VALIDA\n");
                          else
                            printf( "\nFECHA INVALIDA\n");
            }

            int dias=0;
            if (mes ==1){
                    dias=dia;
            }else if (mes==2){
                    dias=enero+dia;
            }else if (mes==3){
                    dias=enero+feb+dia;
            }else if (mes==4){
                    dias=enero+feb+marzo+dia;
            }else if (mes==5){
                    dias=enero+feb+marzo+abril+dia;
            }else if (mes==6){
                    dias=enero+feb+marzo+abril+mayo+dia;
            }else if (mes==7){
                    dias=enero+feb+marzo+abril+mayo+junio+dia;
            }else if (mes==8){
                    dias=enero+feb+marzo+abril+mayo+junio+julio+dia;
            }else if (mes==9){
                    dias=enero+feb+marzo+abril+mayo+junio+julio+agosto+dia;
            }else if (mes==10){
                    dias=enero+feb+marzo+abril+mayo+junio+julio+agosto+septiembre+dia;
            }else if (mes==11){
                    dias=enero+feb+marzo+abril+mayo+junio+julio+agosto+septiembre+octubre+dia;
            }else if (mes==12){
                    dias=enero+feb+marzo+abril+mayo+junio+julio+agosto+septiembre+octubre+noviembre+dia;
            }
            printf(" El numero de dias es %d \n", dias);
        }
        else
            printf( "\nFECHA INVALIDA\n");

    return 0;
   }




