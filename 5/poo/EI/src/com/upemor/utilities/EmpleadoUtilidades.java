package com.upemor.utilities;

import com.upemor.AppendingObjectOutputStream;
import com.upemor.Cliente;
import com.upemor.Empleado;

import java.io.*;

public class EmpleadoUtilidades {


    public boolean AgregarEmpleado(String nombreArchivo, Empleado e) {
        File f = new File(nombreArchivo);

        try {
            var fos = new FileOutputStream(f, true);
            var out = new AppendingObjectOutputStream(fos);

            out.writeObject(e);
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

            out.writeObject(new Empleado("", "", 0.0));
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
                Empleado obj = (Empleado) input.readObject();
                System.out.println(obj.getRFC());
            }

        } catch (IOException | ClassNotFoundException ignored) {}

        try {
            assert input != null;
            input.close();
        } catch (Exception ignored) {}
    }

}
