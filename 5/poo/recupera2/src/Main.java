import java.io.*;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner leer = new Scanner(System.in);
        int menu=0;
        String estado, municipio, direccion;
        int numA, edad, numb, nump;
        double metros2 = 0;
        boolean tienjardin;

        ArrayList<clientes> clientes = new ArrayList<clientes>();
        sucursal sucursal = new sucursal(clientes);
        compañia compania = new compañia(sucursal);
        do {
            System.out.println("ingrese una opcion..................");
            System.out.println();
            System.out.println("1 registro casa");
            System.out.println("2 registro depto");
            System.out.println("3 registro cliente");
            System.out.println("4 registro renta o venta");
            System.out.println("5 reporte");
            System.out.println("6 salir");
            menu =  leer.nextInt();
            switch (menu){
                case 1:
                    System.out.println("ingrese una casa presione enter");
                    leer.nextLine();
                    System.out.println("ingrese estado");
                    estado = leer.nextLine();
                    System.out.println("ingrese municipio");
                    municipio = leer.nextLine();
                    System.out.println("ingrese direccion");
                    direccion = leer.nextLine();
                    System.out.println("ingrese numero de habitaciones");
                    numA = leer.nextInt();
                    System.out.println("ingrese metros cuadrados");
                    metros2 = leer.nextDouble();
                    System.out.println("ingrese la edad del inmueble");
                    edad = leer.nextInt();
                    System.out.println("ingrese el numero de baños");
                    numb = leer.nextInt();
                    System.out.println("ingrese numero de pisos");
                    nump = leer.nextInt();
                    System.out.println("ingrese si tiene jardin");
                    tienjardin = leer.nextBoolean();
                    casa casa = new casa(estado,municipio, direccion, numA,metros2, edad,numb,nump,tienjardin);

                    File archivo = new File("casas.dat");
                    if (!archivo.exists()) {
                        System.out.println("no existe");
                        try {
                            FileOutputStream salida = new FileOutputStream(archivo);
                            ObjectOutputStream salidaObj = new ObjectOutputStream(salida);

                            salidaObj.writeObject(casa);
                            salida.close();
                            salidaObj.close();
                        }catch (IOException ex) {

                        }
                    } else {
                        System.out.println("si existe");

                        try {
                            FileOutputStream salida = new FileOutputStream(archivo, true);
                            AppendingObjectOutputStream agregar = new AppendingObjectOutputStream(salida);

                            agregar.writeObject(casa);
                            salida.close();
                            agregar.close();
                        }catch (IOException ex) {

                        }
                    }
                    break;
                case 2:
                    System.out.println("ingrese un depto presione enter");
                    leer.nextLine();
                    System.out.println("ingrese estado");
                    estado = leer.nextLine();
                    System.out.println("ingrese municipio");
                    municipio = leer.nextLine();
                    System.out.println("ingrese direccion");
                    direccion = leer.nextLine();
                    System.out.println("ingrese numero de habitaciones");
                    numA = leer.nextInt();
                    System.out.println("ingrese metros cuadrados");
                    metros2 = leer.nextDouble();
                    System.out.println("ingrese la edad del inmueble");
                    edad = leer.nextInt();
                    System.out.println("ingrese el numero de baños");
                    numb = leer.nextInt();
                    System.out.println("ingrese el piso del departamento");
                    int piso = leer.nextInt();
                    System.out.println("ingrese si tiene elevador");
                    boolean elevador = leer.nextBoolean();
                    System.out.println("ingrese si tiene lavado");
                    boolean lavado = leer.nextBoolean();
                    departamento dpto = new departamento(estado,municipio, direccion, numA,metros2, edad,numb, piso, elevador, lavado);

                    File archivo2 = new File("deptos.dat");
                    if (!archivo2.exists()) {
                        System.out.println("no existe");
                        try {
                            FileOutputStream salida = new FileOutputStream(archivo2);
                            ObjectOutputStream salidaObj = new ObjectOutputStream(salida);

                            salidaObj.writeObject(dpto);
                            salida.close();
                            salidaObj.close();
                        }catch (IOException ex) {

                        }
                    } else {
                        System.out.println("si existe");

                        try {
                            FileOutputStream salida = new FileOutputStream(archivo2, true);
                            AppendingObjectOutputStream agregar = new AppendingObjectOutputStream(salida);

                            agregar.writeObject(dpto);
                            salida.close();
                            agregar.close();
                        }catch (IOException ex) {

                        }
                    }
                    break;
                case 3:
                    ArrayList<casa> vcasa = new ArrayList<>();
                    ArrayList<casa> ccasa = new ArrayList<>();
                    ArrayList<departamento> vdpto = new ArrayList<>();
                    ArrayList<departamento> cdpto = new ArrayList<>();


                    System.out.println("ingrese un cliente presione enter");
                    leer.nextLine();
                    System.out.println("ingrese nombre");
                    String nombrec = leer.nextLine();
                    System.out.println("ingrese edad");
                    int edadc = leer.nextInt();

                    clientes c = new clientes(ccasa,vcasa, cdpto, vdpto, nombrec, edadc);
                    File archivo3 = new File("clientes.dat");
                    if (!archivo3.exists()) {
                        System.out.println("no existe");
                        try {
                            FileOutputStream salida = new FileOutputStream(archivo3);
                            ObjectOutputStream salidaObj = new ObjectOutputStream(salida);

                            salidaObj.writeObject(c);
                            salida.close();
                            salidaObj.close();
                        }catch (IOException ex) {

                        }
                    } else {
                        System.out.println("si existe");

                        try {
                            FileOutputStream salida = new FileOutputStream(archivo3,true);
                            AppendingObjectOutputStream agregar = new AppendingObjectOutputStream(salida);

                            agregar.writeObject(c);
                            salida.close();
                            agregar.close();
                        }catch (IOException ex) {

                        }
                    }

                    break;
                case 4:
                    System.out.println("presione enter");
                    leer.nextLine();
                    System.out.println("ingrese nombre del cliente");
                    String nombrec4 = leer.nextLine();

                    System.out.println("ingrese una opcion.......");
                    System.out.println("1 renta");
                    System.out.println("2 compra");
                    int rentaventa = leer.nextInt();

                    System.out.println("ingrese depto o casa");
                    System.out.println("1 casa");
                    System.out.println("2 depto");
                    int deptocasa = leer.nextInt();

                    File original = new File("clientes.dat");
                    File auxiliar = new File("clientesauxiliar.dat");
                    if (!original.exists()){
                        break;
                    }

                    FileInputStream input = null;
                    ObjectInputStream objectInput = null;
                    FileOutputStream salida = null;
                    ObjectOutputStream salidaobj = null;

                    boolean finarchivo = false;

                    try {
                        input = new FileInputStream(original);
                        objectInput = new ObjectInputStream(input);
                        salida = new FileOutputStream(auxiliar);
                        salidaobj = new ObjectOutputStream(salida);

                        while(finarchivo == false) {
                            clientes clienteoojb = (clientes) objectInput.readObject();
                            if (clienteoojb.getNombreCliente().equals(nombrec4)) {
                               if (deptocasa == 1) {
                                   if (rentaventa == 1) {
                                        clienteoojb.agregarrentaCasa();
                                   } else if (rentaventa == 2) {
                                       clienteoojb.agregarCompracasa();
                                   }
                               } else if (deptocasa == 2) {
                                   if (rentaventa == 1) {
                                       clienteoojb.agregarrentadpto();
                                   } else if (rentaventa == 2) {
                                       clienteoojb.agregarCompraDepto();
                                   }
                               }
                            }

                            salidaobj.writeObject(clienteoojb);
                        }

                    }catch (Exception ex) {
                        finarchivo = true;
                    }

                    try {
                        input.close();
                        objectInput.close();
                        salida.close();
                        salidaobj.close();
                    }catch (IOException ex) {

                    }

                    if (original.delete()) {
                        auxiliar.renameTo(original);
                    }


                    break;
                case 5:
                    leer.nextLine();
                    System.out.println("ingrese el estado");
                    String estado5 = leer.nextLine();

                    System.out.println("ingrese el cliente");
                    String cliente5 = leer.nextLine();

                    File archivo5 = new File("clientes.dat");
                    ObjectInputStream salida5 = null;

                    boolean finarchivo5 = false;

                    try {
                        FileInputStream entrada = new FileInputStream(archivo5);
                        salida5 = new ObjectInputStream(entrada);

                        while (finarchivo5 == false){
                            clientes objcliente5 = (clientes) salida5.readObject();
                            if (objcliente5.getNombreCliente().equals(cliente5)) {
                                System.out.println("ventas cliente");
                                System.out.println("cliente " + objcliente5.getNombreCliente());

                                Iterator<casa> iter1 = objcliente5.getRentascasa().iterator();
                                Iterator<casa> iter12 = objcliente5.getComprascasa().iterator();
                                Iterator<departamento> iter2 = objcliente5.getRentasdeptos().iterator();
                                Iterator<departamento> iter22 = objcliente5.getComprasdepartamentos().iterator();

                                while (iter1.hasNext()){
                                    System.out.println("direccion del inmueble casa rentados");
                                    System.out.println(iter1.next().getDireccion() + "");
                                }

                                while (iter12.hasNext()) {
                                    System.out.println("direccion del inmueble depto comprados");
                                    System.out.println(iter12.next().getDireccion() + "");
                                }

                                while (iter2.hasNext()) {
                                    System.out.println("direccion del inmueble depto rentados");
                                    System.out.println(iter2.next().getDireccion() + "");
                                }

                                while (iter22.hasNext()) {
                                    System.out.println("direccion del inmueble depto compados");
                                    System.out.println(iter22.next().getDireccion() + "");
                                }

                            }
                        }


                    }catch (IOException | ClassNotFoundException ex) {
                        finarchivo5 = true;
                    }

                    break;
            }
        }while (menu != 6);

    }
}