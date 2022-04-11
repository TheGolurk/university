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
        }catch (Exception ex) {
            return false;
        }

        return true;
    }

    public void Crear(String nombreArchivo){
        File f = new File(nombreArchivo);

        try {
            var fos = new FileOutputStream(f);
            var out = new ObjectOutputStream(fos);

            out.writeObject(new Sucursal("", new Gerente("","", 0.0), new Taller()));
            fos.close();
            out.close();
        }catch (Exception ignored) {}
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

        } catch (IOException | ClassNotFoundException ignored) {}

        try {
            assert input != null;
            input.close();
        } catch (Exception ignored) {}
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
