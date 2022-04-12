package com.upemor.utilities;

import com.upemor.*;

import java.io.*;
import java.util.Scanner;

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

            out.writeObject(new Empleado("Liliana", "LFNV020310DF", 13000.00));
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
                System.out.printf("Nombre: %s RFC: %s \n", obj.getNombre(), obj.getRFC());
            }

        } catch (IOException | ClassNotFoundException ignored) {}

        try {
            assert input != null;
            input.close();
        } catch (Exception ignored) {}
    }

    public void EditarEmpleado(String nombreArchivo) {
        File original = new File(nombreArchivo);
        File aux = new File(String.format("tmp_%s", nombreArchivo));

        var RFC = ObtenerRFC();

        FileInputStream fis = null;
        ObjectInputStream ois = null;
        FileOutputStream fos = null;
        ObjectOutputStream ous = null;

        try {
            fis = new FileInputStream(original);
            ois = new ObjectInputStream(fis);

            fos = new FileOutputStream(aux);
            ous = new ObjectOutputStream(fos);

            while (true) {
                var obj = (Empleado) ois.readObject();
                if (obj.getRFC().equals(RFC)) {
                   var auxEmpleado = ObtenerEmpleado();
                   obj.setNombre(auxEmpleado.getNombre());
                   obj.setRFC(auxEmpleado.getRFC());
                   obj.setSalario(auxEmpleado.getSalario());
                }

                ous.writeObject(obj);
            }

        }catch (Exception ignored) {}

        try {
            assert fis != null;
            fis.close();
            assert ois != null;
            ois.close();
            assert fos != null;
            fos.close();
            assert ous != null;
            ous.close();
        }catch (Exception ignored){}

        if (original.delete()) {
            aux.renameTo(original);
        }
    }

    public void EliminarEmpleado(String nombreArchivo) {
        File original = new File(nombreArchivo);
        File aux = new File(String.format("tmp_%s", nombreArchivo));

        var RFC = ObtenerRFC();

        FileInputStream fis = null;
        ObjectInputStream ois = null;
        FileOutputStream fos = null;
        ObjectOutputStream ous = null;

        try {
            fis = new FileInputStream(original);
            ois = new ObjectInputStream(fis);

            fos = new FileOutputStream(aux);
            ous = new ObjectOutputStream(fos);

            while (true) {
                var obj = (Empleado) ois.readObject();
                if (!obj.getRFC().equals(RFC)) {
                    ous.writeObject(obj);
                }
            }

        }catch (Exception ignored) {}

        try {
            assert fis != null;
            fis.close();
            assert ois != null;
            ois.close();
            assert fos != null;
            fos.close();
            assert ous != null;
            ous.close();
        }catch (Exception ignored){}

        if (original.delete()) {
            aux.renameTo(original);
        }
    }

    public Empleado ObtenerEmpleado(){
        Scanner sc = new Scanner(System.in);

        System.out.println("Ingrese nombre:");
        String nombre =sc.nextLine();

        System.out.println("Ingresa rfc:");
        String rfc = sc.nextLine();

        System.out.println("Ingresa salario:");
        Double salario = sc.nextDouble();

        return new Empleado(nombre, rfc,salario);
    }

    public String ObtenerRFC() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Ingresa rfc:");
        return sc.nextLine();
    }

}
