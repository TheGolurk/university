package com.upemor;

public abstract class NUMERO {
    private String digito;

    public String getDigito() {
        return digito;
    }

    public NUMERO(String digito) {
        this.digito = digito;
    }

    public void setDigito(String digito) {
        this.digito = digito;
    }

    public abstract int obtenerValor();

}
