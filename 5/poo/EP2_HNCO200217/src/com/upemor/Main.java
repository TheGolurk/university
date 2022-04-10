package com.upemor;

import java.util.Scanner;

public class Main {

    // global
    private static Agencia agencia = new Agencia();
    private static Utilidades utilidades= new Utilidades();

    public static void main(String[] args){

        Scanner sc =new Scanner(System.in);
        int opc = 0;


        do{
            System.out.println("******************************************************");
            System.out.println("************************ MENU ************************");
            System.out.println("******************************************************");
            System.out.println("************* 1.- REGISTRAR UNA SUCURSAL *************");
            System.out.println("************* 2.- REGISTRAR UN CLIENTE ***************");
            System.out.println("* 3.- REGISTRAR UN CLIENTE QUE ACUEDA A UNA SUCURSAL *");
            System.out.println("*** 4.- REGISTRAR LOS EMPLEADOS PARA UNA SUCURSAL ****");
            System.out.println("5.- REGISTRAR LA COMPRA DE UN CLIENTE EN UNA SUCURSAL ");
            System.out.println("******* 6.- SOLICITAR UN SERVICIO PARA UN AUTO *******");
            System.out.println("*** 7.- CALCULAR EL PAGO POR EL SERVICIO DEL AUTO ****");
            System.out.println("******* 8.- MOSTRAR EL INFORME DE UNA SUCURSAL *******");
            System.out.println("********************* 9.- SALIR **********************");
            System.out.println("******************************************************");
            System.out.println("Selecciona la Opcion que Desees (1-9)");
            opc=sc.nextInt();

                switch(opc){
                    case 1:
                        agencia.AgregarSucursal(utilidades.ObtenerSucursal());
                    break;

                    case 2:
                        if (agencia.getSucursales().isEmpty()){
                            System.out.println("No hay sucursales vuelve pronto");
                            break;
                        }

                        agencia.getSucursales().forEach(sucursal -> {
                            sucursal.AgregarCliente(utilidades.ObtenerCliente());
                            return;
                        });
                        break;

                    case 3:
                        System.out.println("Ingresa direccion");
                        sc.nextLine();
                        String direccion3 = sc.nextLine();

                        agencia.getSucursales().forEach(sucursal -> {
                            if (sucursal.getDireccion().equals(direccion3)) {
                                sucursal.AgregarCliente(utilidades.ObtenerCliente());
                            }
                        });
                        break;

                    case 4:

                        System.out.println("Elige el tipo de empleado a registrar: 1.VENDEDOR, 2. TECNICO");
                        var opcionempleado = sc.nextInt();

                        sc.nextLine();
                        System.out.println(" Ingresa direccion");
                        String direccion = sc.nextLine();

                        if(opcionempleado == 1){

                            agencia.getSucursales().forEach(sucursal -> {
                                if (sucursal.getDireccion().equals(direccion)){
                                    //casting
                                    sucursal.AgregarEmpleado(utilidades.ObtenerEmpleado());
                                }

                            });

                        }

                        if(opcionempleado ==2){

                            agencia.getSucursales().forEach(sucursal -> {
                                if (sucursal.getDireccion().equals(direccion)){
                                    sucursal.AgregarEmpleado(utilidades.ObtenerEmpleado());
                                }

                            });

                        }

                        break;

                    case 5:
                        System.out.println("rfc del vendedor que lo atendio");
                        String rfcVendedor = sc.nextLine();

                        agencia.getSucursales().forEach(sucursal -> {
                           sucursal.getEmpleados().forEach(empleado -> {
                               if(empleado.getRFC().equals(rfcVendedor)){
                                   Vendedor vendedoractual = (Vendedor) empleado;
                                   vendedoractual.AgregarCompra(utilidades.ObtenerCompra());
                               }
                           });

                        });

                        break;

                    case 6:
                        System.out.println(" Ingresa direccion");
                        String direccion6 = sc.nextLine();

                        agencia.getSucursales().forEach(agencia -> {
                            if (agencia.getDireccion().equals(direccion6)) {
                                agencia.getTaller().AgregarServicio(utilidades.ObtenerServicio());
                            }
                        });


                        break;

                    case 7:
                        System.out.println("Ingresa nombre del servicio");
                        String ser = sc.nextLine();

                        agencia.getSucursales().forEach(sucursal -> {
                            sucursal.getTaller().getServicios().forEach(servicio -> {
                                if (servicio.getNombre().equals(ser)) {
                                    System.out.printf("El costo del auto %s es %f \n",
                                            servicio.getAuto().getModelo(), servicio.getCosto());
                                }
                            });
                        });

                        break;

                    case 8:
                        agencia.getSucursales().forEach(sucursal -> {
                            // Clientes
                            sucursal.getClientes().forEach(cliente -> {
                                System.out.printf("Cliente: %s \n", cliente.getNombre());
                                cliente.getCompras().forEach(compra -> {
                                    System.out.printf("compra de %s fue en: %s \n", compra.getAuto().getModelo(), compra.getFecha());
                                });
                                cliente.getServicios().forEach(servicio -> {
                                    System.out.printf("servicio %s costo: %f \n", servicio.getNombre(), servicio.getCosto());
                                });
                            });

                            // Vendedores
                            sucursal.getEmpleados().forEach(empleado -> {
                                var empTmp = (Vendedor) empleado;
                                empTmp.getCompras().forEach(compra -> {
                                    System.out.printf("Vendedor %s \n", empTmp.getNombre());
                                    System.out.printf("datos de venta %s %f %s \n",
                                            compra.getAuto().getModelo(), compra.getAuto().getCosto(), compra.getFecha());
                                });
                            });
                        });

                        break;
            }

        }while(opc!=9);

    }


}
