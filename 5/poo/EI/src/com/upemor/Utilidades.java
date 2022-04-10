package com.upemor;

import java.io.*;

public class Utilidades {

    public boolean AgregarCliente(String nombreArchivo, Cliente c) {
        File f = new File(nombreArchivo);

        try {
            var fos = new FileOutputStream(f, true);
            var out = new AppendingObjectOutputStream(fos);

            out.writeObject(c);
            out.close();
            fos.close();
        }catch (Exception ex) {
            return false;
        }

        return true;
    }

    public void Crear(String nombreArchivo ){
        File f = new File(nombreArchivo);

        try {
            var fos = new FileOutputStream(nombreArchivo);
            var out = new ObjectOutputStream(fos);

            out.writeObject(new Cliente("", 1, ""));
            fos.close();
            out.close();
        }catch (Exception ignored) {}
    }

    public void ConsultarClientes(String nombreArchivo) {
        File f = new File(nombreArchivo);

        var cont = false;

        ObjectInputStream input = null;

        try {
            var fis = new FileInputStream(nombreArchivo);
            input = new ObjectInputStream(fis);

            while (true) {
                Cliente obj = (Cliente) input.readObject();
                System.out.println(obj.getNombre());
            }

        } catch (IOException | ClassNotFoundException ignored) {}

        try {
            assert input != null;
            input.close();
        } catch (Exception ignored) {}

    }

}
