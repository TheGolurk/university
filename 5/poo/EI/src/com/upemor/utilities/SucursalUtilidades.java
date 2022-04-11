package com.upemor.utilities;

import com.upemor.*;

import java.io.*;
import java.util.Scanner;

public class SucursalUtilidades {

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

        if (clienteActual.getNombre().length() < 1) {
            System.out.println("No se encontro el cliente");
            return false;
        }

        // Edit sucursal
        File original = new File(nombreArchivo);
        File aux = new File(String.format("%s_tmp", nombreArchivo));

        FileInputStream fis = null;
        ObjectInputStream ois = null;
        FileOutputStream fos = null;
        ObjectOutputStream ous = null;

        var clienteUtilidades = new ClienteUtilidades();

        var direccionSucursal = ObtenerDireccionSucursal();

        try {
            fis = new FileInputStream(original);
            ois = new ObjectInputStream(fis);

            fos = new FileOutputStream(aux);
            ous = new ObjectOutputStream(fos);

            while (true) {
                Sucursal obj = (Sucursal) ois.readObject();
                if (obj.getDireccion().equals(direccionSucursal)) {
                    obj.AgregarCliente(clienteUtilidades.ObtenerCliente());
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

            out.writeObject(new Sucursal("", new Gerente("", "", 0.0), new Taller()));
            fos.close();
            out.close();
        } catch (Exception ignored) {
        }
    }

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

    public String ObtenerNombreCliente() {
        return "";
    }

    public String ObtenerDireccionSucursal() {
        return "";
    }

    public Sucursal ObtenerSucursal() {
        Scanner sc = new Scanner(System.in);

        System.out.println("Ingrese direccion");
        String direccion = sc.nextLine();

        System.out.println("Datos del gerente");
        sc.nextLine();

        System.out.println("Nombre");
        String nombre = sc.nextLine();

        System.out.println("RFC");
        String rfc = sc.nextLine();

        System.out.println("Salario");
        Double salario = sc.nextDouble();

        return new Sucursal(direccion, new Gerente(nombre, rfc, salario), new Taller());
    }


}
