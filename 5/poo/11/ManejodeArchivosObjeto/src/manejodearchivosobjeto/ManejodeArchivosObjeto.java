/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package manejodearchivosobjeto;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.Scanner;

/**
 *
 * @author joyke
 */
public class ManejodeArchivosObjeto {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args){
        // TODO code application logic here
        Scanner in=new Scanner (System.in);
        int opcion=0;
        do{
            System.out.println("Menu de opciones");
            System.out.println("1.-Crear archivos");
            System.out.println("2.-Consultar informacion");
            System.out.println("3.-Agregar informacion");
            System.out.println("4.-Editar informacion");
            System.out.println("5.-Editar Ventas");
            System.out.println("6.-Borrar informacion");
            System.out.println("7.-salir");
            opcion=in.nextInt();
            switch(opcion){
                case 1:
                    CrearArchivo();
                    break;
                case 2:
                    ConsultarArchivo();
                    break;
                case 3:
                    AgregarInformacion();
                    break;
                case 4:
                    EditarInformacion();
                    break;
                case 5:
                    EditarVenta();
                    break;
                case 6:
                    BorrarInformacion();
                    break;
            }
        }while(opcion!=7);
            
    }

    private static void CrearArchivo() {
        File archivo=new File("Personas.dat");
        ObjectInputStream input=null;
        Scanner in = new Scanner(System.in);
        ObjectOutputStream Output=null;
        FileOutputStream outputFile=null;
        FileInputStream inputFile=null;
        try{
            outputFile = new FileOutputStream(archivo);
            Output = new ObjectOutputStream(outputFile);
            System.out.println("Cuantas personas vas a capturar: ");
            int cant=in.nextInt();
            for(int i=0;i<cant;i++){
                Empleado nuevo=new Empleado();
                in.nextLine();
                System.out.println("Ingresa nombre:");
                nuevo.setNombre(in.nextLine());
                System.out.println("Ingresa edad:");
                nuevo.setEdad(in.nextInt());
                System.out.println("Ingresa salario:");
                nuevo.setSalario(in.nextDouble());
                System.out.println("Ingresa las ventas del empleado:");
                nuevo.RegistrarVentas();
                Output.writeObject(nuevo);
            }
            outputFile.close();
            Output.close();
        }catch(IOException ex){}
    }

    private static void ConsultarArchivo() {
        File archivo=new File("Personas.dat");
        ObjectInputStream input=null;
        FileOutputStream outputFile=null;
        FileInputStream inputFile=null;
        boolean finArchivo=false;
        try{
            inputFile= new FileInputStream(archivo); 
            input = new ObjectInputStream(inputFile);
            while(!finArchivo){
                Empleado objeto=(Empleado)input.readObject();
                System.out.println("Nombre:"+objeto.getNombre()+" Edad:"+objeto.getEdad()+" Salario:"+objeto.geSalario());
                objeto.ImprimirVentas();
            }

            }catch(IOException | ClassNotFoundException ex){
                finArchivo=true;
            }
            try{
               inputFile.close();
               input.close();
            }catch(IOException ex1){}
    }

    private static void AgregarInformacion() {
        File archivo=new File("Personas.dat");
        ObjectInputStream input=null;
        Scanner in = new Scanner(System.in);
        ObjectOutputStream Output=null;
        FileOutputStream outputFile=null;
        FileInputStream inputFile=null;
        try {
            outputFile = new FileOutputStream(archivo, true);
            Output = new AppendingObjectOutputStream(outputFile);
            System.out.println("Cuantas personas vas a capturar: ");
            int cant = in.nextInt();
            for (int i = 0; i < cant; i++) {
                Empleado nuevo = new Empleado();
                in.nextLine();
                System.out.println("Ingresa nombre:");
                nuevo.setNombre(in.nextLine());
                System.out.println("Ingresa edad:");
                nuevo.setEdad(in.nextInt());
                System.out.println("Ingresa salario:");
                nuevo.setSalario(in.nextDouble());
                System.out.println("Ingresa las ventas del empleado:");
                nuevo.RegistrarVentas();
                Output.writeObject(nuevo);
            }
            outputFile.close();
            Output.close();
        } catch (IOException ex) {
        }
    }

    private static void EditarInformacion() {
        Scanner in = new Scanner(System.in);
        File original=new File("Personas.dat");
        File auxiliar=new File("auxiliar.dat");
        boolean finArchivo=false;
        FileInputStream LeerByte=null;
        ObjectInputStream LeerObjeto=null;
        FileOutputStream EscribirByte=null;
        ObjectOutputStream EscribirObjeto=null;
        try{
            LeerByte=new FileInputStream(original);
            LeerObjeto=new ObjectInputStream(LeerByte);
            EscribirByte=new FileOutputStream(auxiliar);
            EscribirObjeto=new ObjectOutputStream(EscribirByte);
            System.out.println("Ingresa el nombre de la persona a editar");
            String nombreBusqueda=in.nextLine();
            
            while(!finArchivo){
                Empleado objeto=(Empleado) LeerObjeto.readObject();
                if(objeto.getNombre().equals(nombreBusqueda)){
                    System.out.println("Ingresa nuevo nombre");
                    objeto.setNombre(in.nextLine());
                }
                EscribirObjeto.writeObject(objeto);

            }
        }catch(IOException | ClassNotFoundException ex){ finArchivo=true;}
        try{
            LeerByte.close();
            LeerObjeto.close();
            EscribirByte.close();
            EscribirObjeto.close();
        }catch(IOException ex1){}
        //Borrar archivo original
        if(original.delete()){
            System.out.println("Archivo Borrado");
            auxiliar.renameTo(original);
        }else{
            System.out.println("No pudo ser eliminado");
        }
        //Nombrar el auxiliar con el nombre original
        
    }
    private static void EditarVenta() {
        Scanner in = new Scanner(System.in);
        File original=new File("Personas.dat");
        File auxiliar=new File("auxiliar.dat");
        boolean finArchivo=false;
        FileInputStream LeerByte=null;
        ObjectInputStream LeerObjeto=null;
        FileOutputStream EscribirByte=null;
        ObjectOutputStream EscribirObjeto=null;
        try{
            LeerByte=new FileInputStream(original);
            LeerObjeto=new ObjectInputStream(LeerByte);
            EscribirByte=new FileOutputStream(auxiliar);
            EscribirObjeto=new ObjectOutputStream(EscribirByte);
            System.out.println("Ingresa el nombre de la persona a editar");
            String nombreBusqueda=in.nextLine();
            
            while(!finArchivo){
                Empleado objeto=(Empleado) LeerObjeto.readObject();
                if(objeto.getNombre().equals(nombreBusqueda)){
                    System.out.println("Ingresa la descripcion a buscar");
                    String Desc=in.nextLine();
                    System.out.println("Ingresa la nueva descripcion");
                    String Desc2=in.nextLine();
                    System.out.println("Ingresa el monto a editar");
                    Double monto=in.nextDouble();
                    objeto.EditarVentas(Desc, Desc2, monto);
                    
                }
                EscribirObjeto.writeObject(objeto);

            }
        }catch(IOException | ClassNotFoundException ex){ finArchivo=true;}
        try{
            LeerByte.close();
            LeerObjeto.close();
            EscribirByte.close();
            EscribirObjeto.close();
        }catch(IOException ex1){}
        //Borrar archivo original
        if(original.delete()){
            System.out.println("Archivo Borrado");
            auxiliar.renameTo(original);
        }else{
            System.out.println("No pudo ser eliminado");
        }
        //Nombrar el auxiliar con el nombre original
        
    }

    private static void BorrarInformacion() {
        Scanner in = new Scanner(System.in);
        File original=new File("Personas.dat");
        File auxiliar=new File("auxiliar.dat");
        boolean finArchivo=false;
        FileInputStream LeerByte=null;
        ObjectInputStream LeerObjeto=null;
        FileOutputStream EscribirByte=null;
        ObjectOutputStream EscribirObjeto=null;
        try{
            LeerByte=new FileInputStream(original);
            LeerObjeto=new ObjectInputStream(LeerByte);
            EscribirByte=new FileOutputStream(auxiliar);
            EscribirObjeto=new ObjectOutputStream(EscribirByte);
            System.out.println("Ingresa el nombre de la persona a editar");
            String nombreBusqueda=in.nextLine();
            
            while(!finArchivo){
                Empleado objeto=(Empleado) LeerObjeto.readObject();
                if(!objeto.getNombre().equals(nombreBusqueda)){
                    EscribirObjeto.writeObject(objeto);
                }
                
            }
        }catch(IOException | ClassNotFoundException ex){ finArchivo=true;}
        try{
            LeerByte.close();
            LeerObjeto.close();
            EscribirByte.close();
            EscribirObjeto.close();
        }catch(IOException ex1){}
        //Borrar archivo original
        if(original.delete()){
            System.out.println("Archivo Borrado");
            auxiliar.renameTo(original);
        }else{
            System.out.println("No pudo ser eliminado");
        }
        //Nombrar el auxiliar con el nombre original
    }
}

