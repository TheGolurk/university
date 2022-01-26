package com.upemor;

public class CBEjecutable {

    public static void main(String[] args) {
	  CuentaBancaria c1 = new CuentaBancaria(10000f, "HRMR010198", "JUAN PEREZ", "11235514");
      CuentaBancaria c2 = new CuentaBancaria(20000f, "FAVW020311", "PEDRO PEREZ", "12345123");

      c1.Depositar(153667.45f);
      c1.Retirar(100f);
      c1.Consultar();

      c2.Depositar(1000f);
      c2.Retirar(1000000f);
      c2.Consultar();

    }

}
