/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package manejodearchivosobjeto;

import java.io.Serializable;

/**
 *
 * @author joyke
 */
public class Venta implements Serializable {
    private double monto;
    private String descripcion;

    public Venta(double monto, String descripcion) {
        this.monto = monto;
        this.descripcion = descripcion;
    }

    public double getMonto() {
        return monto;
    }

    public void setMonto(double monto) {
        this.monto = monto;
    }

    public String getDescripcion() {
        return descripcion;
    }

    public void setDescripcion(String descripcion) {
        this.descripcion = descripcion;
    }
    
}
