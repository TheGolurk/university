package com.upemor.utilities;

import com.upemor.AppendingObjectOutputStream;
import com.upemor.Cliente;

import java.io.*;
import java.util.Scanner;

public class ClienteUtilidades {

    public boolean AgregarCliente(String nombreArchivo, Cliente c) {
        File f = new File(nombreArchivo);

        try {
            var fos = new FileOutputStream(f, true);
            var out = new AppendingObjectOutputStream(fos);

            out.writeObject(c);
            out.close();
            fos.close();
        } catch (Exception ex) {
            return false;
        }

        return true;
    }

    public void Crear(String nombreArchivo) {
        File f = new File(nombreArchivo);

        try {
            var fos = new FileOutputStream(f);
            var out = new ObjectOutputStream(fos);

            out.writeObject(new Cliente("", 1, ""));
            fos.close();
            out.close();
        } catch (Exception ignored) {
        }
    }

    public void ConsultarClientes(String nombreArchivo) {
        File f = new File(nombreArchivo);
        ObjectInputStream input = null;

        try {
            var fis = new FileInputStream(f);
            input = new ObjectInputStream(fis);

            while (true) {
                Cliente obj = (Cliente) input.readObject();
                System.out.printf("Nombre: %s Edad: %s Correo: %s \n", obj.getNombre(), obj.getEdad(), obj.getCorreo());
            }

        } catch (IOException | ClassNotFoundException ignored) {
        }

        try {
            assert input != null;
            input.close();
        } catch (Exception ignored) {
        }
    }

    public void EditarCliente(String nombreArchivo) {
        File original = new File(nombreArchivo);
        File aux = new File(String.format("%s_tmp", nombreArchivo));

        var nombreCliente = obtenerNombre();

        FileInputStream fis = null;
        ObjectInputStream ois = null;
        FileOutputStream fos = null;
        ObjectOutputStream ous = null;

        var nombre = obtenerNombre();

        try {
            fis = new FileInputStream(original);
            ois = new ObjectInputStream(fis);

            fos = new FileOutputStream(aux);
            ous = new ObjectOutputStream(fos);

            while (true) {
                Cliente obj = (Cliente) ois.readObject();
                if (obj.getNombre().equals(nombre)) {
                    var auxCliente = ObtenerCliente();
                    obj.setNombre(auxCliente.getNombre());
                    obj.setCorreo(auxCliente.getCorreo());
                    obj.setEdad(auxCliente.getEdad());
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
    }

    public void EliminarCliente(String nombreArchivo) {
        File original = new File(nombreArchivo);
        File aux = new File(String.format("%s_tmp", nombreArchivo));

        FileInputStream fis = null;
        ObjectInputStream ois = null;
        FileOutputStream fos = null;
        ObjectOutputStream ous = null;

        var nombre = obtenerNombre();

        try {
            fis = new FileInputStream(original);
            ois = new ObjectInputStream(fis);

            fos = new FileOutputStream(aux);
            ous = new ObjectOutputStream(fos);

            while (true) {
                Cliente obj = (Cliente) ois.readObject();
                if (!obj.getNombre().equals(nombre)) {
                    ous.writeObject(obj);
                }
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
    }

    public Cliente ObtenerCliente() {
        Scanner sc = new Scanner(System.in);

        System.out.println("Ingrese nombre:");
        String nombre = sc.nextLine();

        System.out.println("Ingresa edad:");
        int edad = sc.nextInt();

        sc.nextLine();
        System.out.println("Ingresa correo:");
        String correo = sc.nextLine();

        return new Cliente(nombre, edad, correo);
    }

    public String obtenerNombre() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Ingrese el nombre del cliente");
        return sc.nextLine();
    }

}
