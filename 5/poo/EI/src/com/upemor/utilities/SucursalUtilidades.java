package com.upemor.utilities;

import com.upemor.*;

import java.io.*;
import java.util.EnumMap;
import java.util.Scanner;

public class SucursalUtilidades {

    //case 1
    public boolean AgregarSucursal(String nombreArchivo, Sucursal s) {
        File f = new File(nombreArchivo);

        try {
            var fos = new FileOutputStream(f, true);
            var out = new AppendingObjectOutputStream(fos);

            out.writeObject(s);
            out.close();
            fos.close();
        } catch (Exception ex) {
            return false;
        }

        return true;
    }

    //case 3
    public boolean AgregarClienteSucursal(String clienteNombreArchivo, String nombreArchivo) {
        File clienteArchivo = new File(clienteNombreArchivo);
        ObjectInputStream input = null;

        var nombreCliente = ObtenerNombreCliente();
        Cliente clienteActual = new Cliente();

        try {
            var fis = new FileInputStream(clienteArchivo);
            input = new ObjectInputStream(fis);

            while (true) {
                Cliente obj = (Cliente) input.readObject();
                if (obj.getNombre().equals(nombreCliente)) {
                    clienteActual = obj;
                }
            }

        } catch (IOException | ClassNotFoundException ignored) {
        }

        if (clienteActual.getNombre() == null) {
            System.out.println("No se encontro el cliente");
            return false;
        }

        // Edit sucursal and add client
        File original = new File(nombreArchivo);
        File aux = new File(String.format("tmp_%s", nombreArchivo));

        FileInputStream fis = null;
        ObjectInputStream ois = null;
        FileOutputStream fos = null;
        ObjectOutputStream ous = null;

        var direccionSucursal = ObtenerDireccionSucursal();

        try {
            fis = new FileInputStream(original);
            ois = new ObjectInputStream(fis);

            fos = new FileOutputStream(aux);
            ous = new ObjectOutputStream(fos);

            while (true) {
                Sucursal obj = (Sucursal) ois.readObject();
                if (obj.getDireccion().equals(direccionSucursal)) {
                    obj.AgregarCliente(clienteActual);
                }

                ous.writeObject(obj);
            }

        } catch (Exception ignored) {
        }

        try {
            assert fis != null;
            fis.close();
            assert ois != null;
            ois.close();
            assert fos != null;
            fos.close();
            assert ous != null;
            ous.close();
        } catch (Exception ignored) {
        }

        if (original.delete()) {
            aux.renameTo(original);
        }

        return true;
    }


    //case 5
    public boolean CompraClienteSucursal(String nombreArchivo) {
        var nombreCliente = ObtenerNombreCliente();

        File original = new File(nombreArchivo);
        File aux = new File(String.format("tmp_%s", nombreArchivo));

        FileInputStream fis = null;
        ObjectInputStream ois = null;
        FileOutputStream fos = null;
        ObjectOutputStream ous = null;

        var RFC = ObtenerRFC();
        var direccionSucursal = ObtenerDireccionSucursal();
        var Compra = ObtenerCompra();

        try {
            fis = new FileInputStream(original);
            ois = new ObjectInputStream(fis);

            fos = new FileOutputStream(aux);
            ous = new ObjectOutputStream(fos);

            while (true) {
                Sucursal obj = (Sucursal) ois.readObject();
                if (obj.getDireccion().equals(direccionSucursal)) {

                    obj.getClientes().forEach(cliente -> {
                        if (cliente.getNombre().equals(nombreCliente)) {
                            cliente.AgregarCompra(Compra);
                        }
                    });

                    obj.getEmpleados().forEach(empleado -> {
                        var vendedor = (Vendedor) empleado;
                        if (vendedor.getRFC().equals(RFC)) {
                            vendedor.AgregarCompra(Compra);
                        }
                    });
                }


                ous.writeObject(obj);
            }

        } catch (Exception ignored) {
        }

        try {
            assert fis != null;
            fis.close();
            assert ois != null;
            ois.close();
            assert fos != null;
            fos.close();
            assert ous != null;
            ous.close();
        } catch (Exception ignored) {
        }

        if (original.delete()) {
            aux.renameTo(original);
        }

        return true;
    }

    //case 6
    public boolean ServicioAutoSucursal(String nombreArchivo) {
        var nombreCliente = ObtenerNombreCliente();

        File original = new File(nombreArchivo);
        File aux = new File(String.format("tmp_%s", nombreArchivo));

        FileInputStream fis = null;
        ObjectInputStream ois = null;
        FileOutputStream fos = null;
        ObjectOutputStream ous = null;

        var clienteUtilidades = new ClienteUtilidades();

        var direccionSucursal = ObtenerDireccionSucursal();
        var RFCEmpleado = ObtenerRFC();
        var servicio = ObtenerServicio();

        try {
            fis = new FileInputStream(original);
            ois = new ObjectInputStream(fis);

            fos = new FileOutputStream(aux);
            ous = new ObjectOutputStream(fos);


            while (true) {
                Sucursal obj = (Sucursal) ois.readObject();
                if (obj.getDireccion().equals(direccionSucursal)) {

                    obj.getClientes().forEach(cliente -> {
                        if (cliente.getNombre().equals(nombreCliente)) {
                            cliente.AgregarServicio(servicio);
                        }
                    });

                    obj.getEmpleados().forEach(empleado -> {
                        var tecnico = (Tecnico) empleado;
                        if (tecnico.getRFC().equals(RFCEmpleado)) {
                            tecnico.AgregarServicio(servicio);
                        }
                    });
                }

                ous.writeObject(obj);
            }

        } catch (Exception ignored) {
        }

        try {
            assert fis != null;
            fis.close();
            assert ois != null;
            ois.close();
            assert fos != null;
            fos.close();
            assert ous != null;
            ous.close();
        } catch (Exception ignored) {
        }

        if (original.delete()) {
            aux.renameTo(original);
        }

        return true;
    }


    public void Crear(String nombreArchivo) {
        File f = new File(nombreArchivo);

        try {
            var fos = new FileOutputStream(f);
            var out = new ObjectOutputStream(fos);

            out.writeObject(
                    new Sucursal("Av.Revolucion",
                            new Gerente("Pedro", "PDLI020123DNF", 15000.0),
                            new Taller()
                    )
            );
            fos.close();
            out.close();
        } catch (Exception ignored) {
        }
    }

    //case 7
    public void ConsultarSucursales(String nombreArchivo) {
        File f = new File(nombreArchivo);
        ObjectInputStream input = null;

        try {
            var fis = new FileInputStream(f);
            input = new ObjectInputStream(fis);

            while (true) {
                Sucursal obj = (Sucursal) input.readObject();

                System.out.printf("Sucursal %s \n", obj.getDireccion());

                // CLIENTES
                obj.getClientes().forEach(cliente -> {
                    System.out.printf("Cliente %s. Total compras: %d Total servicios: %d \n",
                            cliente.getNombre(),
                            cliente.getCompras().size(),
                            cliente.getServicios().size()
                    );
                });


                // VENDEDORES
                obj.getEmpleados().forEach(empleado -> {
                    var vendedor = (Vendedor) empleado;
                    System.out.printf("Vendedor %s. Total ventas autos %d \n",
                            vendedor.getNombre(),
                            vendedor.getCompras().size()
                    );
                });

            }

        } catch (IOException | ClassNotFoundException ignored) {
        }

        try {
            assert input != null;
            input.close();
        } catch (Exception ignored) {
        }
    }

    //hacer que pida nombre
    public String ObtenerNombreCliente() {
        Scanner sc = new Scanner(System.in);

        System.out.println("Ingrese el nombre del cliente");
        String nombre = sc.nextLine();

        return nombre;
    }

    public String ObtenerDireccionSucursal() {
        Scanner sc = new Scanner(System.in);

        System.out.println("Ingrese la dirección de la sucursal:");
        String direccion = sc.nextLine();

        return direccion;
    }

    public Sucursal ObtenerSucursal() {
        Scanner sc = new Scanner(System.in);

        System.out.println("Ingrese direccion");
        String direccion = sc.nextLine();

        System.out.println("Datos del gerente (Presione enter)");
        sc.nextLine();

        System.out.println("Nombre");
        String nombre = sc.nextLine();

        System.out.println("RFC");
        String rfc = sc.nextLine();

        System.out.println("Salario");
        Double salario = sc.nextDouble();

        return new Sucursal(direccion, new Gerente(nombre, rfc, salario), new Taller());
    }

    //para el case 5
    public Compra ObtenerCompra() {
        Scanner sc = new Scanner(System.in);

        System.out.println("Ingrese fecha:");
        String fecha = sc.nextLine();

        return new Compra(fecha, ObtenerAuto());

    }

    //para case 6
    public Auto ObtenerAuto() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Ingrese modelo:");
        String modelo = sc.nextLine();

        System.out.println("Ingrese costo:");
        Double costo = sc.nextDouble();

        return new Auto(modelo, costo);
    }

    //para el case 7
    public Servicio ObtenerServicio() {
        Scanner sc = new Scanner(System.in);

        System.out.println("Ingrese Nombre:");
        String nombre = sc.nextLine();

        System.out.println("Ingrese Descripcion:");
        String descripcion = sc.nextLine();

        System.out.println("Ingrese costo:");
        Double costo = sc.nextDouble();

        return new Servicio(nombre, descripcion, costo, ObtenerAuto());
    }

    public String ObtenerRFC() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Ingrese RFC del empleado");
        return sc.nextLine();
    }


}
