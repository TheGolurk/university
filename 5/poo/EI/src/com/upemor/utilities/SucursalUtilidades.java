package com.upemor.utilities;

import com.upemor.*;

import java.io.*;

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

    public void ConsultarEmpleado(String nombreArchivo) {
        File f = new File(nombreArchivo);
        ObjectInputStream input = null;

        try {
            var fis = new FileInputStream(f);
            input = new ObjectInputStream(fis);

            while (true) {
                Sucursal obj = (Sucursal) input.readObject();
                System.out.println(obj.getDireccion());
            }

        } catch (IOException | ClassNotFoundException ignored) {}

        try {
            assert input != null;
            input.close();
        } catch (Exception ignored) {}
    }



}
