package com.upemor;

public class CuentaBancaria {
    private float Saldo;
    private String RFC;
    private String Nombre;
    private String Cuenta;

    public CuentaBancaria(float saldo, String RFC, String nombre, String cuenta) {
        Saldo = saldo;
        this.RFC = RFC;
        Nombre = nombre;
        Cuenta = cuenta;
    }

    public float getSaldo() {
        return Saldo;
    }

    public void setSaldo(float saldo) {
        Saldo = saldo;
    }

    public String getRFC() {
        return RFC;
    }

    public void setRFC(String RFC) {
        this.RFC = RFC;
    }

    public String getNombre() {
        return Nombre;
    }

    public void setNombre(String nombre) {
        Nombre = nombre;
    }

    public String getCuenta() {
        return Cuenta;
    }

    public void setCuenta(String cuenta) {
        Cuenta = cuenta;
    }

    public void Depositar(float cantidad) {
        setSaldo(getSaldo() + cantidad);
        System.out.println("cantidad = " + cantidad);
        System.out.println("Total = " + getSaldo());
    }

    public void Retirar(float cantidad) {
        if (cantidad > getSaldo()) {
            System.out.println("La cantidad excede el saldo disponible");
            return;
        }

        setSaldo(getSaldo() - cantidad);
        System.out.println("cantidad = " + cantidad);
        System.out.println("Total = " + getSaldo());
    }

    public void Consultar() {
        System.out.println("Saldo = " + getSaldo());
        System.out.println("Cuenta = " + getCuenta());
        System.out.println("Nombre = " + getNombre());
        System.out.println("RFC = " + getRFC());
    }

}
