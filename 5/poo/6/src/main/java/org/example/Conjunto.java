package org.example;

import javax.print.DocFlavor;

public class Conjunto {

    private int[] ConjuntoA;
    private int[] ConjuntoB;

    public Conjunto(int[] conjuntoA, int[] conjuntoB) {
        ConjuntoA = conjuntoA;
        ConjuntoB = conjuntoB;
    }

    public void Agregar(int dato, int conjunto){
        switch (conjunto){
            case 1 -> {
                for (int i = 0; i < ConjuntoA.length; i++) {
                    if (ConjuntoA[i] == 0) {
                        ConjuntoA[i] = dato;
                        break;
                    }
                }
            }
            case 2 -> {
                for (int i=0; i < ConjuntoB.length; i++){
                    if (ConjuntoB[i] == 0){
                        ConjuntoB[i] = dato;
                        break;
                    }
                }
            }
            default -> System.out.println("No existe el conjunto");
        }
    }

    public void Eliminar(int dato, int conjunto){
        switch (conjunto) {
            case 1 -> {
                for (int i = 0; i < ConjuntoA.length; i++) {
                    if (ConjuntoA[i] == dato){
                        ConjuntoA[i] = 0;
                        break;
                    }
                }
            }
            case 2 -> {
                for (int i = 0; i < ConjuntoB.length; i++) {
                    if (ConjuntoB[i] == dato){
                        ConjuntoB[i] = 0;
                        break;
                    }
                }
            }
            default -> System.out.println("No existe el conjunto");
        }
    }

    public int[] Union(){
        int[] resultado = new int[200];
        var index =0;
        for (int i = 0; i < ConjuntoA.length; i++) {
            if( ConjuntoA[i] != 0) {
                resultado[index] = ConjuntoA[i];
                index++;
            }
        }

        for (int i = 0; i < ConjuntoB.length; i++) {
            if( ConjuntoB[i] != 0) {
                resultado[index] = ConjuntoB[i];
                index++;
            }
        }

       return resultado;
    }

    public int[] UnionSobrecargada(int[] conjunto3) {
        int[] resultado = new int[300];
        var index=0;
        for (int i = 0; i < ConjuntoA.length; i++) {
            if (ConjuntoA[i] != 0) {
                resultado[index] = ConjuntoA[i];
                index++;
            }
        }
        for (int i = 0; i < ConjuntoB.length; i++) {
            if( ConjuntoB[i] != 0) {
                resultado[index] = ConjuntoB[i];
                index++;
            }
        }
        for (int i = 0; i < conjunto3.length; i++) {
            if( conjunto3[i] != 0) {
                resultado[index] = conjunto3[i];
                index++;
            }
        }

        return resultado;
    }

    public int[] Interseccion(){
        int[] resultado = new int[200];
        var index = 0;

        for (int i = 0; i < ConjuntoA.length; i++) {
            if (ConjuntoA[i] != 0){
                var ValorAbuscar = ConjuntoA[i];

                for (int j = 0; j < ConjuntoB.length; j++) {
                    if (ValorAbuscar == ConjuntoB[j]){
                        resultado[index] = ConjuntoB[j];
                        index++;
                        break;
                    }
                }
            }
        }

        return resultado;
    }

    public int[] interseccionSobrecargada(int[] conjunto3) {
        int[] resultado = new int[300];
        var index = 0;

        for (int j : ConjuntoA) {
            if (j != 0) {
                if ( buscarElemento(ConjuntoB, j) && buscarElemento(conjunto3, j) ) {
                    resultado[index] = j;
                    index++;
                }
            }
        }

        return resultado;
    }

    public int[] Diferencia(){
        int[] resultado = new int[300];
        var index = 0;

        return resultado;
    }

    public int[] DiferenciaSobrecargada(int[] conjunto3) {
        int[] resultado = new int[300];
        var index = 0;

        for (int j : ConjuntoA) {
            if (j != 0) {
                if ( !buscarElemento(ConjuntoB, j) && !buscarElemento(conjunto3, j)) {
                    resultado[index] = j;
                    index++;
                }
            }
        }

        return resultado;
    }

    private boolean buscarElemento(int[] elementos, int elemento) {
        for (int i : elementos) {
            if (i == elemento) {
                return true;
            }
        }

        return false;
    }
}
