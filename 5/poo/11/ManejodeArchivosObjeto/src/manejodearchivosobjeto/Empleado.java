/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package manejodearchivosobjeto;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.Scanner;

/**
 *
 * @author joyke
 */
public class Empleado implements Serializable{
    private String nombre;
    private int edad;
    private double salario;
    private ArrayList<Venta> VentasRegistradas=new ArrayList<Venta>();

    public Empleado(String nombre, int edad, double salario){
        this.nombre=nombre;
        this.edad=edad;
        this.salario=salario;
    
    }

    public Empleado() {
    }

    public ArrayList<Venta> getVentasRegistradas() {
        return VentasRegistradas;
    }

    public void setVentasRegistradas(ArrayList<Venta> VentasRegistradas) {
        this.VentasRegistradas = VentasRegistradas;
    }


    public String getNombre(){
    return nombre;
    }

    public int getEdad(){
    return edad;
    }

    public double geSalario(){
    return salario;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public void setEdad(int edad) {
        this.edad = edad;
    }

    public void setSalario(double salario) {
        this.salario = salario;
    }

    public void RegistrarVentas() {
        Scanner in = new Scanner(System.in);
        in.nextLine();
        System.out.println("Cuantas ventas registraras");
        int total=in.nextInt();
        
        for(int i = 0;i<total;i++){
            in.nextLine();
            System.out.println("Ingrese Monto");
            double monto=in.nextDouble();
            in.nextLine();
            System.out.println("Ingrese la descripcion de la venta");
            String descripcion=in.nextLine();
            Venta nueva=new Venta(monto,descripcion);
            VentasRegistradas.add(nueva);
            
            //VentasRegistradas.add(new Venta(monto,descripcion));
        }
    }

    public void ImprimirVentas() {
        Iterator itr = VentasRegistradas.iterator();
        while(itr.hasNext()){
            Venta objeto=(Venta)itr.next();
            System.out.println("Monto: "+objeto.getMonto()+" Descripcion: "+objeto.getDescripcion());
            
        }
    }
    
    public void EditarVentas(String ventaBusqueda, String descripcion, double Monto){
        //Venta.forEach(v -> {})
        this.getVentasRegistradas().forEach((v)->{
        if(v.getDescripcion().equals(ventaBusqueda)){
            v.setDescripcion(descripcion);
            v.setMonto(Monto);
        }
        });
        
    }
}
