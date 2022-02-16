package org.example;

public class Fraccion {

    private int Numerador;
    private int Denominador;

    public Fraccion() {
        Numerador = 0;
        Denominador =1;
    }

    public Fraccion(int numerador, int denominador) {
        Numerador = numerador;
        Denominador = denominador;
    }

    public int getNumerador() {
        return Numerador;
    }

    public int getDenominador() {
        return Denominador;
    }

    public Fraccion Sumar(int A, int B){
        Fraccion resultado = new Fraccion();

        resultado.Numerador = A*this.Denominador + B*this.Numerador;
        resultado.Denominador = B*this.Denominador;

        return simplificar(resultado);
    }

    public Fraccion Restar(int A, int B ) {
        Fraccion resultado = new Fraccion();

        resultado.Numerador = A*this.Denominador - B*this.Numerador;
        resultado.Denominador = B*this.Denominador;

        return simplificar(resultado);
    }

    public Fraccion Multiplicar(int A, int B) {
        Fraccion resultado = new Fraccion();

        resultado.Numerador= A*this.Numerador;
        resultado.Denominador= B*this.Denominador;

        return simplificar(resultado);
    }

    public Fraccion Division(int A, int B) {
        Fraccion resultado = new Fraccion();
        resultado.Numerador= A*this.Denominador;
        resultado.Denominador= B*this.Numerador;

        return simplificar(resultado);
    }

    private Fraccion simplificar(Fraccion f1){
        var aux= false;
        var i =2;
        boolean encontrado= false;
        boolean encontrado2= false;

        while (aux == true) {
            if(f1.Numerador %i==0 && !encontrado){
                encontrado=true;
                f1.Numerador= f1.Numerador/i;

            }
            if(f1.Denominador%i ==0 && !encontrado2){
                encontrado2=true;
                f1.Denominador= f1.Denominador/i;

            }
            if(encontrado && encontrado2){
                aux=true;
            }
            i++;
        }
        return f1;

    }

    public void Imprimir() {
        System.out.printf("%d/%d\n",this.Numerador,this.Denominador);
    }

    public void ImprimirFlotante() {
        System.out.println(this.Numerador/this.Denominador);
    }

}

